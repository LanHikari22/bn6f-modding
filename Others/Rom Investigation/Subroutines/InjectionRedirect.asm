/**
 * Injection Entrypoint
 * Author: Lan
 * Date created: 07/23/2017
 * Description
 * This is meant to be injected where a subroutine is, and creating
 * a new location to import the subroutine back in for easy modification.
*/
.thumb

main: // <injection at: 8E0>
	push    {r7,r14}
	ldr 	r7, =0x08099001
	mov		lr, pc
	bx		r7
	pop     {r7,r15}
