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
#ifndef KEYPRESSEXECUTION_ASM
#define KEYPRESSEXECUTION_ASM
.thumb


// Headers
.include "../GBA_header.asm"
.include "../mmbn6_header.asm"
.include "../mmbn6_globalvariables.asm"

// handle key press logic <090000>
b prog
bl onTrigger    // just to show its location
bl onActive 	// just to show its location
bl onStart		// just to show its location
prog: 
// APIs and Drivers
.include "../CheatcodeACE_api.asm"
	
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
	LDR		R1, =0xADD2BEEF
	CMP		R0, R1
	BEQ		0f
	BL		onStart
	
0:	// if onActive is enabled, onActive will be executed.
	LDR		R3, =onActive_enabled_0
	LDRB	R3, [R3]
	CMP		R3, #1
	BNE		0f
	BL		onActive

0:	// When a certain keystate is entered, check if this is the first time.
	ldr r1, =pKeyState
	ldrh r1, [r1]
	bl cc_isFirstPress
	cmp r0, #1
	bne 99f
	
	// This keystate has been entered for the FIRST time!
	ldrh r1, =KeyS 
	bl cc_isPressed
	cmp r0, #1 // is it SELECT??
	bne 0f 
	bl onTrigger
	
0:	// <<Input all logic that should be executed only on keyState trigger>>
	bl handle_onActive
	bl cc_handleCheatcodeExecution
	
99:	POP	  {R0-R7, PC} // Return!
/*********************************/
// Custom Code!
// Edit onTrigger for trigger activated code (SELECT)
// While pressing R, Press UP to TRIGGER Continous code
// Edit sub_continous code to handle what happens when it's triggered
/********************************/
onTrigger: // <09004E>
	push {r0-r7, lr} // Stack
	
	ldr r0, =sEnemyA 			// pointer to enemyA struct
	ldr r1, =sBattle_player 	// pointer to player battle struct
	ldrh r2, [r0, #0x24] 		// sEnemyA->HP
	ldrh r3, [r1, #0x24] 		// PlayerBattleStruct->HP
	strh r2, [r1, #0x24]
	strh r3, [r0, #0x24]
	
	// swi 0x03 // stop!
		
	pop {r0-r7, pc} // Return

onActive:
	// Stack
	push {r0-r7, lr}
	
	ldr r0, =sEnemyA // yay literal pool!
	ldr r1, [r0, #0x24] // HP
	add r1, #1
	str r1, [r0, #0x24] // HP
	
	// Return
	pop {r0-r7, pc}
	
onStart:
	push {r0-r7, lr}
	
	bl cc_initCheatcodes
	
	// Make sure this doesn't get executed again: Set onStartExecuted_0 to 0xADD2BEEF
	ldr r0, =0xADD2BEEF
	ldr r1, =onStartExecuted_0
	str r0, [r1]
	
	
	pop {r0-r7, pc}
	
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
