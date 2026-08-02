	.include "include/macros.inc"                                                                                                        
	.include "constants/constants.inc"

    .section .text, "ax"

	.syntax divided

    .ifdef USE_MOD

    .include "modding/asm/start_screen.s"

    thumb_func_start main_hook
main_hook:
    push {r0-r7, lr} // Hi!

    // Do Overwritten Code
    // *main_subsystemJumptable[*tk->oToolkit_MainJumptableIndexPtr])()
    ldr r0, =main_subsystemJumpTable
    mov r1, r10
    ldr r1, [r1,#oToolkit_MainJumptableIndexPtr]
    ldrb r1, [r1]
    ldr r0, [r0,r1]
    mov lr, pc
    bx r0

    // Link elsewhere!
    push {r0-r7}
    ldr r0, =modding_main+1
    mov r1, pc
    add r1, #5
    mov lr, r1
    bx r0
    pop {r0-r7}

    pop {r0-r7, pc} // Bye!

    .pool
    thumb_func_end main_hook


/* 
  (mgba) Memory is at 0x2040000
*/

    .equiv g_modding_init_magic, 0x2040000 // size 4
    .equiv g_modding_main_counter, 0x2040004 // size 1
    .equiv g_end, 0x2040005

    .equiv D_INIT_MAGIC, 0xDEADFEED


    thumb_func_start modding_main
modding_main:
    push {lr}

    // See if we need to call modding_init

    // if D_INIT_MAGIC is not set
    ldr r0, =D_INIT_MAGIC
    ldr r1, =g_modding_init_magic
    ldr r2, [r1]
    cmp r2, r0
    beq .endif2

    ldr r0, =D_INIT_MAGIC
    ldr r1, =g_modding_init_magic
    str r0, [r1]

    bl modding_init

.endif2:

    mov r5, r10
    ldr r5, [r5, #oToolkit_JoypadPtr]

    ldrh r0, [r5, #oJoypad_Pressed]

    // if command button is pressed two times
    ldr r1, =#JOYPAD_SELECT
    tst r0, r1
    beq .endif1

    // increment g_modding_main_counter
    ldr r1, =g_modding_main_counter
    ldrb r0, [r1]
    add r0, r0, #1
    strb r0, [r1]

    // if g_modding_main_counter >= 2
    ldr r1, =g_modding_main_counter
    ldrb r0, [r1]
    cmp r0, #2
    blt .endif1

    // Set g_modding_main_counter back to 0
    ldr r1, =g_modding_main_counter
    mov r0, #0
    strb r0, [r1]

    .ifdef USE_MODULE_START_SCREEN_ASM_MOD
        bl mod_startscr_modding_on_command
    .else
        bl modding_on_command
    .endif // USE_MODULE_START_SCREEN_ASM_MOD

.endif1:

    pop {pc}
    .pool
    thumb_func_end modding_main


    thumb_func_start modding_init
modding_init:
    push {lr}

    // It should already be set to 0, but we shouldn't guess
    ldr r1, =g_modding_main_counter
    mov r0, #0x0
    strb r0, [r1]
    
    pop {pc}
    .pool
    thumb_func_end modding_init

    thumb_func_start modding_on_command
modding_on_command:
    push {lr}

    ldr r0, =TextScriptBattleRunDialog
    mov r1, #0
    bl chatbox_runScript // (archive: *const TextScriptArchive, script_idx: u8) -> ()

    pop {pc}
    .pool
    thumb_func_end modding_on_command

    .endif // USE_MOD
