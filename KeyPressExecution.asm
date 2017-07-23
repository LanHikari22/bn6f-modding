/**
 * KeyPressExecution.asm
 * Author: Lan
 * Date created: MM/DD/20XX
 * Description
 * MMBN6 asm script. This was written to provide ACE based on key press events.
 * onTrigger and onActive subroutines define logic that gets executed when an event occurs, 
 * or when a flag is active, respectively.
 * onStart defines logic that is executed ONLY ONCE. put initilizations here!
*/



//.ifndef KEYPRESSEXECUTION_ASM
//.def KEYPRESSEXECUTION_ASM
.thumb
// Headers
.include "../GBA_header.asm"
.include "../mmbn6_header.asm"
.include "../mmbn6_globalvariables.asm"

// handle key press logic <090000>
b prog
bl onTrigger    // just to show its location
bl onActive 	
// just to show its location
bl onStart		// just to show its location
prog: 
// APIs and Drivers
.include "../cheatcodes.asm"
.include "../CheatcodeACE_api.asm"
.include "../KeyPressEntrypoints.asm"
	
	push {lr} // Stack
	
	// Do Overwritten Code <400>
	mov r6, r4
	and r6, r5
	mov r1, #0x8
	mov r3, #0x0

	bl main
	
	pop {pc} // Return
	
main: 
	// Stack
	PUSH	{R0-R7, LR}
	
	// if this is the first time this is executed, onStart will be executed.
	LDR		R0, =onStartExecuted_0
	LDR		R0, [R0]
	LDR		R1, =0xADD2FEED
	CMP		R0, R1
	BEQ		0f
	BL		onStart
	
0:	// if onActive is enabled, onActive will be executed.
	LDR		R3, =onActive_enabled_0
	LDRB	R3, [R3]
	CMP		R3, #1
	BNE		0f
	// check if shortcutsEnabled_0
	LDR		R0, =shortcutsEnabled_0
	LDR		R0, [R0]
	CMP		r0, #1
	BNE		0f
	BL		onActive

0:	// When a certain keystate is entered, check if this is the first time.
	LDR 	R1, =pKeyState
	LDRH 	R1, [R1]
	BL 		cc_isFirstPress
	CMP 	R0, #1
	BNE 99f
	
	// This keystate has been entered for the FIRST time!
	LDRH 	R1, =KeyS 
	BL 		cc_isPressed
	CMP		R0, #1 // is it SELECT??
	BNE		0f 
	// check if shortcutsEnabled_0
	LDR		R0, =shortcutsEnabled_0
	LDR		R0, [R0]
	CMP		r0, #1
	BNE		0f
	BL onTrigger
	
0:	// <<Input all logic that should be executed only on keyState trigger>>
	bl handle_onActive
	bl cc_handleCheatcodeExecution
	
99:	POP	  {R0-R7, PC} // Return!

handle_onActive:
	push {r0-r2,lr}
	
	ldrh r1, =KeyR
	bl cc_isPressed
	cmp r0, #1 // is it SELECT??
	bne 99f
	
	// if activationCounter_0 == 1, set it to 0 and toggle onActive_enabled_0
	ldr r1, =activationCounter_0
	ldrb r2, [r1]
	cmp r2, #1
	bne 0f
	// set activationCounter_0 to 0
	mov r2, #0
	strb r2, [r1]
	// toggle onActive_enabled_0
	mov r1, #0x01
	ldr r2, =onActive_enabled_0
	ldrb r3, [r2]
	eor r3, r1
	strb r3, [r2]
	b 99f

0:	// increment activationCounter_0
	ldr r1, =activationCounter_0
	ldrb r2, [r1]
	add r2, #1
	strb r2, [r1]
	
99:	pop {r0-r2,pc}
	
#endif
