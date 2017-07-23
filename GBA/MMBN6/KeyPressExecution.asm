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
	LDR		R3, =continuous_on_0
	LDRB	R3, [R3]
	CMP		R3, #1
	BNE		0f
	BL		onActive

0:	// Handle trigger code
	LDR		R3, =p_keyState
	LDRH	R2, [R3]
	LDR 	R3, =KeyS
	/* Input other key logic Only one can be processed.*/
	/* Such subroutines must return a value in R4 */
	BL		handle_continuous_trigger
	CMP		R4, #1 // R4_conditionFulfilled
	BEQ		0f 
	CMP		R2, R3 // Check R3_Key is pressed
	BEQ		1f
	
	ldr r0, =isPressed_0
	mov r1, #0
	str r1, [r0]
	/* Nothing is pressed. Account for that.*/
	bl handle_continuous_trigger_OFF
	b 0f // return
	
1:	# Execused when SELECT is pressed, hold doesn't count
	ldr r0, =isPressed_0
	ldr r1, [r0]
	cmp r1, #1
	beq 0f
	
	mov r1, #1
	str r1, [r0]
	bl onTrigger
	
0:	POP	  {R0-R7, PC} // Return!
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
	
	
	
handle_continuous_trigger:
	push {r0-r2, lr} // Stack
	mov r4, #0 // Action not executed unless it is
	
	// If S is pressed
	ldr r0, =p_keyState
	ldr r0, [r0]
	ldr r1, =KeyR // R
	cmp r0, r1
	bne 0f // no? nothing to do here
	
	mov r4, #1 // Ayy, Condition met!
	// no hold. is this the first press?
	ldr r0, =cont_isPressed_0
	ldrb r1, [r0]
	cmp r1, #1
	beq 0f // stillPressed? do nothing.
	// Welcome, you're a first press!
	mov r1, #1
	strb r1, [r0]
	ldr r0, =cont_activationCounter_0
	ldrb r1, [r0]
	add r1, #1 // every press, counter increments
	strb r1, [r0]
	
	// Trigger onActive upon activation
	ldr r0, =cont_activationCounter_0
	ldrb r1, [r0]
	cmp r1, #2
	bne 0f
	// Activated!! Reset counter and trigger!
	mov r1, #0
	strb r1, [r0]
	ldr r0, =continuous_on_0
	ldrb r1, [r0]
	mov r2, #0x01
	eor r1, r2
	strb r1, [r0]
	
0:	// Return
	pop {r0-r2, pc}

handle_continuous_trigger_OFF:
	// stack
	push {r0-r1, lr}
	ldr r0, =cont_isPressed_0
	mov r1, #0
	strb r1, [r0]
	// return
	pop {r0-r1, pc}
	
#endif
