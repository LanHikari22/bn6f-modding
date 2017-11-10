/**
 * cheatcodes.asm
 * Author: Lan
 * Date created: 7/23/2017
 * Description
 * Defines behavior of all cheatcodes, as well as what happens whenever a certain cheatcode is executed!
 * global variables for modification can be found in mmbn6_globalvariables.asm
*/
#ifndef CHEATCODES_ASM
#define CHEATCODES_ASM
.thumb
// headers
//.include "../headers/GBA_header.asm"
//.include "../headers/mmbn6_header.asm"
//.include "../headers/mmbn6_globalvariables.asm"
// APIs and Drivers
//.include "../CheatcodeACE_api.asm"
//.include "../KeyPressEntrypoints.asm"


b CHEATCODES_ASM_EOF // this is an API, the data should be accounted for but not executed


/**
 * Executes cheatfunctions based on detected cheatcodes.
 * [side effects] 
 * pKeyState, bufferCsr_1, cc_cheatLength
*/
cc_handleCheatcodeExecution:
	push {r0-r1, lr}
	
	// insert keystate into buffer
	ldr r0, =pKeyState
	ldrh r0, [r0]
	bl cc_insertKeystate

	// Only execute when a whole sequence is entered
	ldr r1, =bufferCsr_1
	ldr r1, [r1]
	cmp r1, #cc_cheatLength
	bne 99f
	
	bl cc_getCheatCodeID // r0_cheatID
	cmp r0, #0x00
	bne 0f
	bl onTrigger
0:	cmp r0, #0x01
	bne 0f
	bl cc_toggle_onActive
0:	cmp r0, #0x02
	bne 0f
	bl cc_toggleShortcuts 
0:	cmp r0, #0x03
	bne 0f
	nop
0:	cmp r0, #0x04
	bne 0f
	nop
0: 
	bl cc_resetBuffer
99:	pop {r0-r1, pc}
	

/**
 * Initializes all cheatcodes to known, defined patterns. This must only be executed once.
 * [side effects] 
 * cheatcodes_1
*/
cc_initCheatcodes:
	push {r0-r1,lr}
	
	ldr r0, =cheatcodes_1
	// 0: ENTER SELECT SELECT SELECT
	ldr r1, =0xFC04FC08
	str r1, [r0]
	add r0, #4
	ldr r1, =0xFC04FC04
	str r1, [r0]
	add r0, #4
	
	// 1: ENTER R R R
	ldr r1, =0xFD00FC08
	str r1, [r0]
	add r0, #4
	ldr r1, =0xFD00FD00
	str r1, [r0]
	add r0, #4
	
	// 2: ENTER L L L
	ldr r1, =0xFE00FC08
	str r1, [r0]
	add r0, #4
	ldr r1, =0xFE00FE00
	str r1, [r0]
	add r0, #4
	
	// 3
	ldr r1, =0x3333FC08
	str r1, [r0]
	add r0, #4
	ldr r1, =0x00000000
	str r1, [r0]
	add r0, #4
	
	// 4
	ldr r1, =0x4444FC08
	str r1, [r0]
	add r0, #4
	ldr r1, =0x00000000
	str r1, [r0]
	add r0, #4
	
	pop {r0-r1,pc}


/**
 * toggles entrypoint ACE shortcuts. When that is off, they can only be executed with cheatcodes.
 * [side effects] 
 * shortcutsEnabled_0
*/
cc_toggleShortcuts:
	push {r0-r2, lr}
	
	ldr r0, =shortcutsEnabled_0
	ldrb r1, [r0]
	mov r2, #0x01
	eor r1, r2
	strb r1, [r0]

	pop {r0-r2, pc}
	
/**
 * toggles onActive flag to execute onActive entrypoint function
 * [side effects] 
 * 
*/
cc_toggle_onActive:
	push {r0-r2, lr}
	
	mov r0, #0x01
	ldr r1, =onActive_enabled_0
	ldrb r2, [r1]
	eor r2, r0
	strb r2, [r1]
	
	pop {r0-r2, pc}
	
CHEATCODES_ASM_EOF:
#endif
