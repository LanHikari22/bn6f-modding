.include "slinkydependencies.s"

.thumb
.section .l__object_subtract_hp, "ax"
object_subtract_hp:
	PUSH    {R4,LR}
	LDRH    R1, [R5,#0x24]
	SUB    R1, R1, R0
	BGE     loc_800E2E2
	MOV    R1, #0
loc_800E2E2:
	STRH    R1, [R5,#0x24]
	POP     {R4,PC}
	.byte 0x0, 0x0

	.word 0x40000000
