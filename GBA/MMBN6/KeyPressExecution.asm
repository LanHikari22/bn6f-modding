/**
 * KeyPressExecution.asm
 * Author: Lan
 * Date created: MM/DD/20XX
 * Description
 * MMBN6 asm script. This was written to provide ACE based on key press events.
 * onTrigger and onActive subroutines define logic that gets executed when an event occurs, 
 * or when a flag is active, respectively.
*/
#ifndef KEYPRESSEXECUTION_ASM
#define KEYPRESSEXECUTION_ASM
.thumb


// Headers
.include "../code/GBA/GBA_header.asm"
.include "../code/GBA/MMBN6/mmbn6_header.asm"
.include "../code/GBA/MMBN6/mmbn6_globalvariables.asm"

// handle key press logic <090000>
b prog
bl onTrigger    // just to show its location
bl onActive 	// just to show its location
prog: 
// APIs and Drivers
.include "../code/GBA/MMBN6/CheatcodeACE_api.asm"
	
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
	
	// if onActive is enabled, onActive is executed.
	LDR		R3, =onActive_enabled_0
	LDRB	R3, [R3]
	CMP		R3, #1
	BNE		0f
	BL		onActive

0:	// When a certain keystate is entered, check if this is the first time.
	ldr r1, =p_keyState
	ldrh r1, [r1]
	bl isFirstPress
	cmp r0, #1
	bne 99f
	
	// This keystate has been entered for the FIRST time!
	ldrh r1, =KeyS 
	bl isPressed
	cmp r0, #1 // is it SELECT??
	bne 0f 
	bl onTrigger
	
0:	// <<Check other keyState logic as needed.>>
	bl handle_onActive
	
99:	POP	  {R0-R7, PC} // Return!
/*********************************/
// Custom Code!
// Edit onTrigger for trigger activated code (SELECT)
// While pressing R, Press UP to TRIGGER Continous code
// Edit sub_continous code to handle what happens when it's triggered
/********************************/
onTrigger: // <09004E>
	push {r0-r7, lr} // Stack
	
	ldr r0, =s_enemyA 			// pointer to enemyA struct
	ldr r1, =s_battle_player 	// pointer to player battle struct
	ldrh r2, [r0, #0x24] 		// s_enemyA->HP
	ldrh r3, [r1, #0x24] 		// PlayerBattleStruct->HP
	strh r2, [r1, #0x24]
	strh r3, [r0, #0x24]
	
	// swi 0x03 // stop!
		
	pop {r0-r7, pc} // Return

onActive:
	// Stack
	push {r0-r7, lr}
	
	ldr r0, =s_enemyA // yay literal pool!
	ldr r1, [r0, #0x24] // HP
	add r1, #1
	str r1, [r0, #0x24] // HP
	
	// Return
	pop {r0-r7, pc}
	
handle_onActive:
	push {r0-r2,lr}
	
	ldrh r1, =KeyR
	bl isPressed
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
