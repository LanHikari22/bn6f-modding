/**
 * CheatcodeACE_api.asm
 * Author: Lan
 * Date created: 7/21/2017
 * Description
 * TODO
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
 * Checks if it is the first time a certain Keystate has been pressed.
 * Params:
 * 	r1_keyState
 * Side effect: 
 * 	p_keyState from mmbn6_header.asm
 * returns r0_isPressed (0: false, 1: true)
*/
isPressed:
	push {r1-r2, lr}

	mov r0, #0
	ldr r2, =p_keyState
	ldrh r2, [r2]
	cmp r1, r2
	bne 99f
	mov r0, #1

99:	pop {r1-r2, pc}


/**
 * Checks if it is the first time a certain Keystate has been pressed.
 * Params:
 * 	r1_keyState
 * Side effect: 
 * 	p_keyState from mmbn6_header.asm, savedKeystate_1, isPressed_1
 * returns r0_isFirstpress (0: false, 1: true)
*/
.thumb_func
isFirstPress:
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
