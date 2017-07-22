.thumb
.include "../code/GBA_header.asm"
.include "../code/mmbn6_header.asm"

// handle key press logic
b prog
// << Put Custom code inside this subroutine>>	
subroutine: # <090036>
	// Stack
	push {r0-r7, lr}
	
	/*
	ldr r0, =EnemyA 			// pointer to enemyA struct
	ldr r1, =PlayerBattleStruct // pointer to player battle struct
	ldrh r2, [r0, #0x24] 		// EnemyA->HP
	ldrh r3, [r1, #0x24] 		// PlayerBattleStruct->HP
	strh r2, [r1, #0x24]
	strh r3, [r0, #0x24]
	*/
	
	mov r0, #0
	LOOP:
	add r0, #1
	ldr r1, =#640000
	cmp r0, r1
	blt LOOP
	
	// return
	pop {r0-r7, pc}


prog: # <090000>
	# Stack
	push {lr} 
	
	# Do Overwritten Code <400>
	mov r6, r4
	and r6, r5
	mov r1, #0x8
	mov r3, #0x0
	
	bl main
	
	# Return
	pop {pc}
	
main:
	# Stack
	PUSH	{R0-R7, LR}
		
	LDR		R3, =p_keyState
	LDRH	R2, [R3]
	LDR 	R3, =KeyS
	CMP		R2, R3
	BEQ		1f
	
	ldr r0, =isPressed
	mov r1, #0
	str r1, [r0]
0:
	# Return
	POP	  {R0-R7, PC}

1:	# Execused when SELECT is pressed, hold doesn't count
	ldr r0, =isPressed
	ldr r1, [r0]
	cmp r1, #1
	beq stillPressed
	
	mov r1, #1
	str r1, [r0]
	bl subroutine
	
stillPressed:
	B		0b
