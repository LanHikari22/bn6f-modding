/**
 * textGeneration_api.asm
 * Author: Lan
 * Date created: 7/21/2017
 * Description
 * TODO
*/
#ifndef TEXTGENERATION_API_ASM
#define TEXTGENERATION_API_ASM
.thumb
// headers
.include "../GBA_header.asm"
.include "../mmbn6_header.asm"
.include "../mmbn6_globalvariables.asm"

b TEXTGENERATION_API_ASM_EOF // this is an API, the data should be accounted for but not executed

/**
 * Converts a r1_pText to gametext. Generates gametext at specified r2_pGameText
 * [params]
 * r1_pText, r2_pText
 * [side effects]
 * [return]
*/
tg_toGameText:
	push {r0-r7, lr}
	
	pop {r0-r7, pc}

/**
 * Copies r3_length bytes of r1_pArray to specified r2_pOut.
 * [params]
 * r1_pString, r2_pOut, r3_length
 * [side effects]
 * [return]
*/
tg_copyTo:
	push {r0-r7, lr}
	
	mov r4, #0 // r4_cursor
2:	ldrb r5, [r1] // r1_pString[N]
	strb r5, [r2] // r2_pOut[N] = r1_pString[N]
	// advance both pointers and cursor
	add r1, #1
	add r2, #1	
	add r4, #1
	// do while r4_cursor < r3_size
	cmp r4, r3
	blt 2b
	
	pop {r0-r7, pc}
	
/**
 * Copies content of null terminated r1_pString to specified r2_pOut.
 * [params]
 * r1_pString, r2_pOut
 * [side effects]
 * [return]
*/
tg_strcopyTo:
	push {r0-r7, lr}
	
2:	ldrb r3, [r1] // r1_pString[N]
	strb r3, [r2] // r2_pOut[N] = r1_pString[N]
	// advance both pointers
	add r1, #1
	add r2, #1	
	// do while r1_pString[N] != \0
	cmp r3, #0x00
	bne 2b
	
	pop {r0-r7, pc}

TEXTGENERATION_API_ASM_EOF:
#endif
