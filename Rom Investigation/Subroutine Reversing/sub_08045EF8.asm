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
 * [side effects]
 * [return]
 *
*/
main: // <099000>
	push    {r1,r2}
	ldr     r1,=#0x2009F38
	ldr     r2,[r1]
	orr     r2,r0
	str     r2,[r1]
	pop     {r1,r2}
	mov     r15,r14
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
