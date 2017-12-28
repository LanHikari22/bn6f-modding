/**
 * mainHook.s
 * Author: Lan
 * Date created: MM/DD/20XX
 * Description
 * This assembly file intercepts game code so that this projects' code executes every frame
*/

.thumb

.section .intercept_08000402, "ax"
mov		r2, r14
.word	0xFDFCF08F 	// bl	#0x8090000
mov		r14, r2

.section .mainHook, "ax"
// hook <08090000>
	push {lr} // Stack
	
	// Do Overwritten Code <400>
	mov r6, r4
	and r6, r5
	mov r1, #0x8
	mov r3, #0x0

	// link to C project's main instead, no need to link to this one!
	push {r0-r7}
	ldr r0, =0x08900001
	mov r1, pc
	add r1, #5 // A2
	mov lr, r1
	bx r0
	pop {r0-r7}
	
	pop {pc} // Bye!
