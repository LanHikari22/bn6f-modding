/**
 * Injection Entrypoint
 * Author: Lan
 * Date created: 07/23/2017
 * Description
*/
.thumb

main: // <injection at: 040358>
	push    {r3-r6,r14}
	ldr 	r3, =0x08099001
	mov		lr, pc
	//swi		0x03
	bx		r3
	pop     {r3-r6,r15}
