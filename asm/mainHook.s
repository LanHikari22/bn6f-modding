/**
 * mainHook.s
 * Author: Lan
 * Date created: MM/DD/20XX
 * Description
 * This assembly file intercepts game code so that this projects' code executes every frame
*/
.include "main.inc"
.extern main_jt_subsystem
.thumb
mainHook:
    push {lr}
// Do Overwritten Code
    ldr r0, =main_jt_subsystem
    mov r1, r10
    ldr r1, [r1]
    ldrb r1, [r1]
    ldr r0, [r0,r1]
    mov lr, pc
    bx r0

// link to C project's main instead, no need to link to this one!
  	push {r0-r7}
  	ldr r0, =0x08900001
    mov r1, pc
    add r1, #5
    mov lr, r1
  	bx r0
  	pop {r0-r7}


  	pop {pc} // Bye!
    .pool
