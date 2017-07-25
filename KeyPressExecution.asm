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
.include "../headers/GBA_header.asm"
.include "../headers/mmbn6_header.asm"
.include "../headers/mmbn6_globalvariables.asm"

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
	
0:	BL 		handle_onEvent
	BL		handle_onState
	
	// if onActive is enabled, onActive will be executed.
	LDR		R3, =onActive_enabled_0
	LDRB	R3, [R3]
	CMP		R3, #1
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
	CMP		R0, #1
	BNE		0f
	BL onTrigger
	
0:	// <<Input all logic that should be executed only on keyState trigger>>
	bl handle_onActive
	bl cc_handleCheatcodeExecution
	
99:	POP	  {R0-R7, PC} // Return!

handle_onActive:
	push {r0-r2,lr}
	
	// check if shortcutsEnabled_0, if not, reset activationCounter_0 and return.
	ldr r0, =shortcutsEnabled_0
	ldr r0, [r0]
	cmp r0, #1
	beq 1f
	// reset activationCounter_0
	ldr r0, =activationCounter_0
	mov r1, #0
	str r1, [r0]
	b 99f
1:	
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
	
/**
 * [params]
 * [side effects]
*/
handle_onEvent:
	push	{r0-r3, lr}
	
	ldr 	r1, =onEvent_pEvent
	ldr 	r2, =onEvent_watcher_0
	mov		r3, #onEvent_mask
	bl		eventOccured
	cmp 	r0, #1
	bne 	99f
	bl		onEvent
	
99:	pop		{r0-r3, pc}
	
/**
 * [params]
 * [side effects]
*/
handle_onState:
	push 	{r0-r7, lr}
	
	ldr 	r1, =onState_pEvent
	ldr 	r2, =onState_watcher_0
	ldr		r3, =onState_mask
	bl		eventOccured
	cmp 	r0, #1
	bne 	99f
	// check if state is onState_activationState
	ldr		r1, [r1]
	and		r1, r3
	ldr		r2, =onState_activationState
	cmp		r1, r2
	bne		99f
	bl		onState
	
99:	pop		{r0-r7, pc}
	
/**
 * Determines whether the r3_mask filtered value at r1_pEvent changed.
 * This is based on r2_pEventWatcher, which records that masked value when it is first encountered.
 * if this subroutine is executed frequently enough, r2_pEventWatcher should accurate with detecting change.
 * [params]
 * r1_pEvent, r2_pEventWatcher, r3_mask
 * [side effects]
 * r2_pEventWatcher
 * [return] 
 * r0_eventOccured (0: false, 1: true)
*/
.thumb_func
eventOccured:
	push 	{r1-r4, lr}
	
	// load masked value
	ldr 	r1, [r1]
	and 	r1, r3
	
	// Is the value registered in *r2_pEventWatcher?
	ldr 	r4, [r2]
	cmp 	r1, r4
	beq 	0f 		// Yo, you registered this before :(
	
	// First time I've seen this. Better register it!
	str 	r1, [r2]

	// What an eventful time to live in....
	mov 	r0, #1
	b 		99f
	
0:	mov 	r0, #0

99: pop 	{r1-r4, pc}	

#endif
