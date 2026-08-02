    .ifdef USE_MODULE_START_SCREEN_ASM_MOD

    thumb_func_start mod_startscr_modding_on_command
mod_startscr_modding_on_command:
    push {lr}

    ldr r0, =TextScriptBattleRunDialog
    mov r1, #0
    bl chatbox_runScript // (archive: *const TextScriptArchive, script_idx: u8) -> ()

    pop {pc}
    .pool
    thumb_func_end mod_startscr_modding_on_command

    thumb_func_start mod_startscr_init
mod_startscr_init:
    push {r0, lr}

    ldr r0, =startScreen_init_802F530
    mov lr, pc
    bx r0

    pop {r0, pc}
    .pool
    thumb_func_end mod_startscr_init

   thumb_func_start mod_startscr_render
mod_startscr_render:
    push {r0, lr}

    ldr r0, =startscreen_render_802F544
    mov lr, pc
    bx r0

    pop {r0, pc}
    .pool
    thumb_func_end mod_startscr_render


    thumb_func_start mod_startscr_init_gfx
mod_startscr_init_gfx:
    push {r0, lr}

    ldr r0, =startScreen_initGfx_802F574
    mov lr, pc
    bx r0

    pop {r0, pc}
    .pool
    thumb_func_end mod_startscr_init_gfx


    thumb_func_start mod_startscr_off04
mod_startscr_off04:
    push {r0, lr}

    ldr r0, =startscreen_802F60C
    mov lr, pc
    bx r0

    pop {r0, pc}
    .pool
    thumb_func_end mod_startscr_off04


    thumb_func_start mod_startscr_off08
mod_startscr_off08:
    push {r0, lr}

    ldr r0, =ho_802F63C
    mov lr, pc
    bx r0

    pop {r0, pc}
    .pool
    thumb_func_end mod_startscr_off08

    thumb_func_start mod_startscr_load_game
mod_startscr_load_game:
    push {r0, lr}

    ldr r0, =load_game_802F756
    mov lr, pc
    bx r0

    pop {r0, pc}
    .pool
    thumb_func_end mod_startscr_load_game

    .endif // USE_MODULE_START_SCREEN_ASM_MOD
