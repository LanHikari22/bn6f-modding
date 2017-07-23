/**
 * CheatcodeACE_api.asm
 * Author: Lan
 * Date created: 7/21/2017
 * Description
 * TODO
 * cc_cheatLength can be modified in mmbn6_globalvariables.asm
*/
#ifndef CHEATCODEACE_API_ASM
#define CHEATCODEACE_API_ASM
.thumb
// headers
.include "../code/GBA/GBA_header.asm"
.include "../code/GBA/MMBN6/mmbn6_header.asm"
.include "../code/GBA/MMBN6/mmbn6_globalvariables.asm"

b EOF // this is an API, the data should be accounted for but not executed

/**
 * Will check if any cheatcodes have been inserted, and if so, will execute the corresponding functions of them.
 * cheatcodes_1 must be initialized on onStart for this to behave correctly.
 * [side effects] 
 * 
*/
cc_handleCheatcodeExecution:
	push {lr}

	// insert keystate into buffer
	ldr r0, =pKeyState
	ldrh r0, [r0]
	bl cc_insertKeystate
	// Check against cheatcode patterns...
	ldr r1, =cheatcodes_1
	bl cc_checkPattern
	
	// TODO: DEBUG
	ldr r1, =testVar_0
	strb r0, [r1]
	
	pop {pc}

	
/**
 * Initializes all cheatcodes to known, defined patterns. This must only be executed once.
 * [side effects] 
 * 
*/
cc_initCheatcodes:
	push {lr}
	
	
	
	pop {pc}

/**
 * Checks whether buffer_1 is equivalent to r1_pPattern.
 * Assumes r1_pPattern is of the same length as buffer_1.
 * [params]
 * r1_pPattern
 * [side effects] 
 * buffer_1
 * [return]
 * r0_patternMatches (0: false, 1: true)
*/
cc_checkPattern:
	push {r1-r7, lr}
	
	mov r6, #0
	mov r5, #0 // cursor
	ldr r3, =buffer_1
	mov r0, #0x1
0:	// Loop through each element of both. if an unmatch is found, return 0
	ldrh r2, [r1, r5] // r2 = pattern[r5_cursor]
	ldrh r4, [r3, r5] // r4 = buffer_1[r5_cursor]
	cmp r2, r4
	beq 1f
	and r0, r6  // huh... We failed... Return.
	b 99f

1:	// Increment r5_cursor
	add r5, #2
	// do while(r5_cursor < 2*cc_cheatLength)
	mov r7, #cc_cheatLength
	lsl r7, #1
	cmp r5, r7
	blt 0b

99:	pop {r1-r7, pc}

/**
 * Inserts r0_keyState into buffer_1. Behavior is circular.
 * The length of the buffer is cc_cheatLength.
 * if r0_keyState == KeyIDLE, this subroutine will return immediately!
 * if only enter is pressed, cursor is reset, and it's inserted at the start.
 * [params]
 * r0_keyState
 * [side effects] 
 * (mmbn6_header.asm: KeyIDLE, KeyS), buffer_1, bufferCsr_1, cc_cheatLength
*/
cc_insertKeystate:
	push {r0-r3, lr}
	
	// if r0_keyState == KeyIDLE, return
	ldr r1, =KeyIDLE
	cmp r0, r1
	beq 99f
	
	// if r0_keyState == KeyE, reset cursor
	ldr r1, =KeyE
	cmp r0, r1
	bne 0f
	bl cc_resetCursor
	
0:	// If bufferCsr_1 >= cc_cheatLength, it is set to 0.
	ldr r1, =cc_cheatLength
	ldr r2, =bufferCsr_1
	ldrb r3, [r2]
	cmp r3, r1
	blt 0f
	bl cc_resetCursor

0:	// Insert r0_keyState into buffer_1 at 2*bufferCsr_1 (2x because it's an array of halfwords)
	ldr r1, =bufferCsr_1
	ldrb r1, [r1]
	lsl r1, #1
	ldr r2, =buffer_1
	strh r0, [r2, r1]
	
	// Increment bufferCsr_1
	ldr r1, =bufferCsr_1
	ldrb r2, [r1]
	add r2, #1
	strb r2, [r1]
	
99:	pop {r0-r3, pc}

/**
 * sets buffer_1 to all zeros and resets bufferCsr_1
 * [side effects] 
 * buffer_1, bufferCsr_1, cc_cheatLength
*/
cc_resetBuffer:
	push {r0-r3,lr}
	
	bl cc_resetCursor
	mov r0, #0 // r0_cursor
	mov r1, #0x0000
	ldr r2, =buffer_1
0:	// zero out all of buffer_1!
	strh r1, [r2, r0] // buffer_1[r0_cursor] = 0
	add r0, #2
	// do while(r5_cursor < 2*cc_cheatLength)
	mov r3, #cc_cheatLength
	lsl r3, #1
	cmp r0, r3
	blt 0b
	
99:	pop {r0-r3,pc}
	
/**
 * sets bufferCsr_1 to 0
 * [side effects] 
 * bufferCsr_1
*/
cc_resetCursor:
	push {r0-r1,lr}
	
	mov r0, #0
	ldr r1, =bufferCsr_1
	strb r0, [r1]
	
99:	pop {r0-r1,pc}

/**
 * Checks if it is the first time a certain Keystate has been pressed.
 * [params]
 * r1_keyState
 * [side effects] 
 * pKeyState from mmbn6_header.asm
 * [return] 
 * r0_isPressed (0: false, 1: true)
*/
cc_isPressed:
	push {r1-r2, lr}

	mov r0, #0
	ldr r2, =pKeyState
	ldrh r2, [r2]
	cmp r1, r2
	bne 99f
	mov r0, #1

99:	pop {r1-r2, pc}


/**
 * Checks if it is the first time a certain Keystate has been pressed.
 * [params]
 * r1_keyState
 * [side effects] 
 * pKeyState from mmbn6_header.asm, savedKeystate_1, isPressed_1
 * [return] 
 * r0_isFirstpress (0: false, 1: true)
*/
.thumb_func
cc_isFirstPress:
	push {r1-r2, lr}

	// Was the key present before?
	ldr r2, =savedKeystate_1
	ldrh r2, [r2]
	cmp r1, r2
	beq 0f // Yo, you registered this before :(
	
	// First time I've seen this. Better register it!
	ldr r2, =savedKeystate_1
	strh r1, [r2]

	// Congratulations. You made it this far... You must be a first press!
	mov r0, #1
	b 99f
	
0:	mov r0, #0

99:	pop {r1-r2, pc}

EOF:
#endif
