/**
 * sub_08040358
 * Author: Lan
 * Date created: 07/23/2017
 * Description
*/
.thumb
// headers
//.include "../../headers/GBA_header.asm"
//.include "../../headers/mmbn6_header.asm"


/**
 * [params]
 * Unknown
 * [registers]
 * r10(sChiefStruct)
 * [side effects]
 * [return]
 *
*/
main: // <099000 redirected from 040358>
	push    {r4-r7,r14}
	
	// load data from r5_sChiefStruct[0x2C]
	// They seem not to affect script executed even when fixed to 0.
	mov     r5,r10
	ldr     r5,[r5,#0x2C]	// r5(s_02009CD0)
	ldr     r2,[r5,#0x4C]	
	ldr     r3,[r5,#0x50]	
	ldr     r4,[r5,#0x54]	
	ldr     r6,[r5,#0x58]	
	
	/* Debug 
	ldr     r2,=0x00000000
	ldr     r3,=0x00000000
	ldr     r4,=0x00000000
	ldr     r6,=0x00000000
	/* Debug */
	
	//
	push    {r0-r3}
	mov     r0,r10
	ldr     r0,[r0,#0x2C] // r0 = s_02009CD0
	ldr     r1,=#0x230 // 0x230. can make Lan teleport or disappear??
	
	// [params] r0(s_02009CD0) r1(?)
	// [return] nothing
	ldr r7, =0x80008E0 // undocumented call
	bl blx

	
	pop     {r0-r3}
	// r1 might not be a scriptID. it changes depending on iteration.
//D	swi		0x03 //D r0=0x02034a04, r1(RelScriptID?)= 0 @ L-chat
	str     r2,[r5,#0x4C] // ?
	str     r3,[r5,#0x50] // ?
	str     r4,[r5,#0x54] // ?
	str     r6,[r5,#0x58] // ?
	str     r0,[r5,#0x30] // ?
	strb    r1,[r5,#0x1]  // r5(s_02009CD0)->scriptID? = r1(RelScriptID)
	mov     r2,#0x9C	  
//D	mov		r1, #0x1E	  //D
	strb    r1,[r5,r2]	  // r5(s_02009CD0)[0x9C] = r1(RelScriptID?)
	lsl     r1,r1,#0x1
	ldrh    r1,[r0,r1]
	add     r0,r0,r1
//D	swi		0x03 		  //D r0 = 0x02034ad0, r1=0x0cc @ L-chat
	str     r0,[r5,#0x2C] // r5(s_02009CD0)->pCurrScript = r0
	str     r0,[r5,#0x34]
	mov     r0,#0x1
	strb    r0,[r5]
	mov     r0,#0x2
	strb    r0,[r5,#0x8]
	ldr     r0,=#0x200B2B0
	str     r0,[r5,#0x38]
	mov     r0,#0x1
	strb    r0,[r5,#0xC]
	mov     r0,#0x1
	str     r0,[r5,#0x74]
	strb    r0,[r5,#0x11]
	mov     r0,#0x4
	str     r0,[r5,#0x78]
	ldr     r0,=#0x8040468
	mov     r1,r5
	add     r1,#0x68
	mov     r2,#0x8
	
	ldr r7, =0x800092A
	bl blx

	mov     r1,#0xC
	strb    r1,[r5,#0x1D]
	mov     r2,#0x1E
	strb    r2,[r5,#0x1E]
	mov     r3,#0x8
	strb    r3,[r5,#0x1F]
	mov     r0,#0xE2
	strb    r0,[r5,#0x1A]
	mov     r1,#0x8D
	strb    r1,[r5,#0x1B]
	mov     r0,#0x33
	strb    r0,[r5,#0x18]
	mov     r0,#0x6C
	strb    r0,[r5,#0x19]
	mov     r0,#0x19
	mov     r1,#0x84
	str     r0,[r5,r1]
	mov     r0,#0x80
	mov     r1,#0x88
	str     r0,[r5,r1]
	mov     r0,#0x2
	ldr     r1,=#0x1F0
	strb    r0,[r5,r1]
	ldr     r1,=#0x1F1
	strb    r0,[r5,r1]
	mov     r0,#0x0
	ldr     r1,=#0x1F2
	strb    r0,[r5,r1]
	ldr     r1,=#0x1F3
	strb    r0,[r5,r1]
	mov     r0,#0x3
	ldr     r1,=#0x1F4
	strb    r0,[r5,r1]
	ldr     r1,=#0x1F5
	strb    r0,[r5,r1]
	mov     r0,#0x0
	ldr     r1,=#0x2009F38
	str     r0,[r1]
	mov     r0,#0x80

	ldr r7, =0x8045EEC
	bl blx
	ldr r7, =0x8045F30
	bl blx

	ldr     r0,=#0x100 // 0x100.

	ldr r7, =0x80408F4
	bl blx

	ldrb    r0,[r5,#0x18]
	mov     r1,r5
	add     r1,#0x94
	strb    r0,[r1]
	mov     r0,#0xD
	mov     r2,#0x90
	str     r0,[r5,r2]
	ldr     r0,=#0x86BCA6C
	ldr     r1,=#0x600DC80
	ldr     r2,=#0x160

	// does this deal with filling script??
	ldr r7, =0x8000AC8 
	bl blx

	ldr     r0,=#0x86BCBCC
	ldr     r1,=#0x3001B40
	mov     r2,#0x20 // 0x20

	// back layer of text box generation?
	ldr r7, =0x8000950
	bl blx

	ldr     r0,=#0x86B5A0C
	ldr     r1,=#0x3001710
	mov     r2,#0x20

	ldr r7, =0x8000950
	bl blx

	pop     {r4-r7,r15}

/**
 * Register used for bx should not be used by the caller function
 * [params]
 * r7_pInstruction
*/	
blx:
	push {r7, lr}
	add r7, #1
	mov lr, pc
	bx r7
	pop {r7, pc}
