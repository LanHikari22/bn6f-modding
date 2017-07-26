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
//.include "../headers/GBA_header.asm"
//.include "../headers/mmbn6_header.asm"
//.include "../headers/mmbn6_globalvariables.asm"

b TEXTGENERATION_API_ASM_EOF // this is an API, the data should be accounted for but not executed

/**
 * This should be called everytime pCurrScript changes. It updates global variables pActiveScript_2.
 * if pActiveScript_2 == 0, there is no active script at the moment. This is toggled upon the 
 * [side effects]
*/
tg_handleScriptEvent:
	push	{r0-r7, lr}
	
	ldr		r1, =pCurrScript
	ldr		r1, [r1] // pScript
	bl		tg_atScriptStart
	cmp		r0, #1
	bne		99f
	
	mov		r3, r1
	add		r3, #0x02 // actual text, not message popup!
	b		1f

	// there are some weird glitches that happen with SOME NPCs when using this...
tg_s0:	.string "DUMMY. CANNOT TALK!\0 \1"
	.align 4
1:	ldr		r2, =tg_s0
	ldr		r1, =injectionAddress
	add		r2, r1
	bl		tg_toGameText
	
99:	pop		{r0-r7, pc}

/**
 * Converts a r1_pText to gametext. Generates gametext at specified r2_pGameText
 * [params]
 * r2_pText, r3_pGameText
 * [side effects]
 * [return]
*/
tg_toGameText:
	push 	{r0-r7, lr}
	
2:	ldrb	r1, [r2]
	bl		tg_toGameChar
	strb	r0, [r3]
	add		r2, #1
	add		r3, #1
	cmp		r1, #0xE7
	bne		2b
	
	pop 	{r0-r7, pc}

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
	
/**
 * 
 * [params]
 * r1_asciiChar
 * [return]
 * r0_gameChar
*/
tg_toGameChar:
	push	{r1-r2, lr}

	ldr		r2, =pAsciiGametext
	ldrb	r0, [r2, r1]
	
	pop		{r1-r2, pc}
	

/**
 * Determines if given r1_pScript is at its start.
 * This is done by checking by checking if it's currently at
 * the command msgOpen (0xE8 0x00).
 * [params]
 * r1_pScript
 * [return]
 * r0_atScriptStart (false: 0, true: 1)
*/
tg_atScriptStart:
	push	{r1-r3, lr}
	mov		r0, #0
	ldrb	r2, [r1]		
	ldrb	r3, [r1, #0x01]
	cmp		r2, #0xE8
	bne		99f
	cmp		r3, #0x00
	bne		99f
	mov		r0, #1
99:	pop		{r1-r3, pc}

TEXTGENERATION_API_ASM_EOF:
#endif
