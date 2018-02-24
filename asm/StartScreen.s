.include "slinkydependencies.s"

.thumb
.section .l__StartScreen, "ax"

StartScreen_802f574:
	PUSH    {LR}
	MOV     R0, #0xB
	BL      sub_80015FC
	LDR     R0, off_802F7E4
	BL      sub_8001778
	BL      sub_8001788
	BL      sub_80017A0
	BL      Load_802FCC0
	MOV     R0, #0xC
	MOV     R1, #0xFF
	BL      engine_set_screeneffect
	BL      sub_8000784
	LDR     R0, off_802F5EC
	BL      sub_8002354
	MOV     R0, #4
	STRB    R0, [R5]
	MOV     R0, #0
	STRB    R0, [R5,#2]
	BL      sub_803FA42
	BL      Load_803F838
	BNE     loc_802F5BE
	MOV     R0, #1
	STRB    R0, [R5,#2]
	BL      sub_8000EE4
	STRB    R0, [R5,#0xC]
	STRH    R1, [R5,#0xA]
 loc_802F5BE:
	LDRB    R0, [R5,#2]
	TST     R0, R0
	BNE     loc_802F5D4
	MOV     R6, #0
	MOV     R7, #1
	BL      sub_803E930
	BEQ     loc_802F5E2
	MOV     R0, #0
	MOV     R7, #2
	B       loc_802F5E2
 loc_802F5D4:
	MOV     R6, #1
	MOV     R7, #2
	BL      sub_803E930
	BEQ     loc_802F5E2
	MOV     R6, #1
	MOV     R7, #3
 loc_802F5E2:
	STRB    R6, [R5,#8]
	STRB    R7, [R5,#9]
	MOV     R0, #0
	STRB    R0, [R5,#3]
	POP     {PC}
off_802F5EC:
	.word off_802F5F0
off_802F5F0:
	.word off_802F350
	.word off_802F3A0
	.word off_802F3F0
	.word off_802F440
	.word off_802F490
	.word off_802F4E0
	.word 0xFFFFFFFF

StartScreen_cb_802f60c:
	PUSH    {LR}
	LDR     R0, off_802F61C
	LDRB    R1, [R5,#1]
	LDR     R0, [R0,R1]
	MOV     LR, PC
	BX      R0
	POP     {PC}
	.byte 0x0, 0x0

off_802F61C:
	.word StartScreen_jt
StartScreen_jt:
	.word StartScreen_802f624+1

StartScreen_802f624:
	PUSH    {LR}
	LDR     R0, dword_802F638
	BL      sub_8001778
	MOV     R0, #8
	STRB    R0, [R5]
	MOV     R0, #0
	STRB    R0, [R5,#1]
	POP     {PC}
	.byte 0x0, 0x0

dword_802F638:
	.word 0x1741

StartScreen_cb_802f63c:
	PUSH    {LR}
	LDR     R0, off_802F650
	LDRB    R1, [R5,#1]
	LDR     R0, [R0,R1]
	MOV     LR, PC
	BX      R0
	BL      StartScreen_802FB10
	POP     {PC}
	.byte 0x0, 0x0

off_802F650:
	.word StartScreen_jt_0
StartScreen_jt_0:
	.word StartScreen_802f668+1
	.word StartScreen_802f6a4+1
	.word StartScreen_802f6b2+1
	.word StartScreen_802F704+1
	.word StartScreen_802f710+1

StartScreen_802f668:
	PUSH    {LR}
	MOV     R0, #0
	STRB    R0, [R5,#0xE]
	STRB    R0, [R5,#0xF]
	LDR     R0, dword_802F69C
	STRH    R0, [R5,#4]
	MOV     R0, #1
	BL      sub_80005F2
	MOV     R0, #0xA
	BL      sub_80015FC
	LDR     R0, off_802F6A0
	BL      sub_8001778
	MOV     R0, #0
	STRB    R0, [R5,#6]
	BL      Load_802FD3C
	MOV     R0, #8
	MOV     R1, #0x10
	BL      engine_set_screeneffect
	MOV     R0, #4
	STRB    R0, [R5,#1]
	POP     {PC}
dword_802F69C:
	.word 0xA46
off_802F6A0:
	.word loc_1340

StartScreen_802f6a4:
	PUSH    {R4,LR}
	BL      engine_is_screeneffect_animating
	BEQ     locret_802F6B0
	MOV     R0, #8
	STRB    R0, [R5,#1]
 locret_802F6B0:
	POP     {R4,PC}

StartScreen_802f6b2:
	PUSH    {R4,LR}
	LDRH    R0, [R5,#4]
	CMP     R0, #0
	BGT     loc_802F6C8
	MOV     R0, #0x10
	STRB    R0, [R5,#1]
	MOV     R0, #0xC
	MOV     R1, #0x10
	BL      engine_set_screeneffect
	B       locret_802F6FA
 loc_802F6C8:
	SUB     R0, #1
	STRH    R0, [R5,#4]
	LDR     R1, off_802F6FC
	CMP     R0, R1
	BNE     loc_802F6E0
	PUSH    {R0,R5}
	MOV     R0, #0x1F // a1
	MOV     R1, #0x10 // a2
	BL      sub_800068A // a comment
	POP     {R0,R5}
	B       locret_802F6FA
 loc_802F6E0:
	LDRH    R0, [R5,#4]
	LDR     R1, dword_802F700
	CMP     R0, R1
	BGE     locret_802F6FA
	BL      sub_803E928
	BNE     locret_802F6FA
	BL      Load_802FD54
	BL      StartScreen_802f7e8
	BL      StartScreen_802F88E
 locret_802F6FA:
	POP     {R4,PC}
off_802F6FC:
	.word dword_12C
dword_802F700:
	.word 0xA0A

StartScreen_802F704:
	PUSH    {LR}
	BL      StartScreen_802f81c
	BL      StartScreen_802f8d8
	POP     {PC}

StartScreen_802f710:
	PUSH    {LR}
	LDRH    R0, [R5,#4]
	CMP     R0, #0
	BLE     loc_802F71C
	BL      StartScreen_802f8d8
 loc_802F71C:
	BL      engine_is_screeneffect_animating
	BEQ     locret_802F754
	LDRH    R0, [R5,#4]
	CMP     R0, #0
	BLE     loc_802F72E
	MOV     R0, #0xC
	STRH    R0, [R5]
	B       locret_802F754
 loc_802F72E:
	BL      sub_8001AFC
	BL      sub_80023A8
	BL      sub_803D1AC
	BL      sub_81440D8
	BL      sub_813D960
	BL      sub_803F4C8
	MOV     R0, #0
	BL      sub_803F6B0
	BL      loc_803F512
	BL      sub_803E900
 locret_802F754:
	POP     {PC}

StartScreen_802f756:
	PUSH    {LR}
	MOV     R7, R10
	LDR     R0, [R7]
	MOV     R1, #4
	STRB    R1, [R0]
	LDR     R0, off_802F7E4
	BL      sub_8001778
	BL      sub_813D960
	LDRB    R0, [R5,#8]
	CMP     R0, #0
	BEQ     loc_802F776
	CMP     R0, #1
	BEQ     loc_802F79A
	B       loc_802F7B6
 loc_802F776:
	BL      sub_800260C
	BL      sub_8004DF0
	BL      sub_8004D48
	BL      sub_81440D8
	BL      sub_8149644
	LDRB    R0, [R5,#2]
	TST     R0, R0
	BEQ     locret_802F7E0
	MOV     R0, #0x17
	MOV     R1, #4
	BL      jumpout_802F110
	B       locret_802F7E0
 loc_802F79A:
	LDRB    R0, [R5,#2]
	TST     R0, R0
	BEQ     loc_802F7B6
	BL      sub_8004D48
	MOV     R0, #0x17
	MOV     R1, #4
	BL      jumpout_802F110
	BL      sub_81440D8
	BL      sub_8149644
	B       locret_802F7E0
 loc_802F7B6:
	MOV     R0, #0
	BL      sub_813D90C
	BL      sub_8004D48
	BL      sub_8039570
	BL      sub_803EBAC
	MOV     R0, #0xC
	BL      sub_803EA70
	LDRB    R0, [R5,#2]
	TST     R0, R0
	BEQ     loc_802F7DC
	MOV     R0, #0x17
	MOV     R1, #4
	BL      jumpout_802F110
 loc_802F7DC:
	BL      sub_81440D8
 locret_802F7E0:
	POP     {PC}
	.byte 0x0, 0x0

off_802F7E4:
	.word loc_1140

StartScreen_802f7e8:
	PUSH    {LR}
	MOV     R7, R10
	LDR     R0, [R7,#4]
	LDRH    R0, [R0,#2]
	MOV     R1, #8
	TST     R1, R0
	BEQ     locret_802F810
	BL      sub_813D960
	MOV     R0, #0xC
	STRB    R0, [R5,#1]
	MOV     R0, #0x67  // 'g'
	BL      sound_play
	LDR     R0, off_802F814
	BL      loc_8001B1C
	LDR     R0, off_802F818
	BL      loc_8001B1C
 locret_802F810:
	POP     {PC}
	.byte 0x0, 0x0

off_802F814:
	.word dword_802F2E4
off_802F818:
	.word dword_802F334

StartScreen_802f81c:
	PUSH    {LR}
	MOV     R7, R10
	LDR     R7, [R7,#4]
	LDRH    R0, [R7,#2]
	MOV     R1, #9
	TST     R1, R0
	BEQ     loc_802F848
	BL      engine_is_screeneffect_animating
	BEQ     locret_802F88C
	BL      sub_8000784
	MOV     R0, #0x9D
	BL      sound_play
	MOV     R0, #0x10
	STRB    R0, [R5,#1]
	MOV     R0, #0xC
	MOV     R1, #0x10
	BL      engine_set_screeneffect
	B       locret_802F88C
 loc_802F848:
	LDRH    R0, [R7,#4]
	MOV     R1, #0x40  // '@'
	TST     R1, R0
	BEQ     loc_802F86A
	LDRB    R0, [R5,#8]
	ADD     R1, R0, #0
	SUB     R0, #1
	BGE     loc_802F85C
	LDRB    R0, [R5,#9]
	SUB     R0, #1
 loc_802F85C:
	STRB    R0, [R5,#8]
	CMP     R0, R1
	BEQ     locret_802F88C
	MOV     R0, #0x66  // 'f'
	BL      sound_play
	B       locret_802F88C
 loc_802F86A:
	LDRH    R0, [R7,#4]
	MOV     R1, #0x80
	TST     R1, R0
	BEQ     locret_802F88C
	LDRB    R0, [R5,#8]
	ADD     R1, R0, #0
	ADD     R0, #1
	LDRB    R2, [R5,#9]
	CMP     R0, R2
	BLT     loc_802F880
	MOV     R0, #0
 loc_802F880:
	STRB    R0, [R5,#8]
	CMP     R0, R1
	BEQ     locret_802F88C
	MOV     R0, #0x66  // 'f'
	BL      sound_play
 locret_802F88C:
	POP     {PC}

StartScreen_802F88E:
	PUSH    {R4-R7,LR}
	MOV     R0, R10
	LDR     R0, [R0,#0x24]
	LDRH    R0, [R0]
	MOV     R1, #0x3F  // '?'
	AND     R0, R1
	CMP     R0, #0x20  // ' '
	BGT     locret_802F8A4
	LDR     R0, off_802F8A8
	BL      sub_8001158
 locret_802F8A4:
	POP     {R4-R7,PC}
	.byte 0x0, 0x0

off_802F8A8:
	.word dword_802F8AC
dword_802F8AC:
	.word 0x80344078, 0x2001, 0x80544078, 0x2009, 0x80744078
	.word 0x2011, 0x80944078, 0x2019, 0xB48078, 0x2021
	.word 0x0

StartScreen_802f8d8:
	PUSH    {R4-R7,LR}
	LDRB    R0, [R5,#6]
	ADD     R0, #1
	CMP     R0, #0x12
	BLT     loc_802F8E4
	MOV     R0, #0
 loc_802F8E4:
	STRB    R0, [R5,#6]
	LDRB    R0, [R5,#7]
	ADD     R0, #1
	CMP     R0, #0x40  // '@'
	BLT     loc_802F8F0
	MOV     R0, #0
 loc_802F8F0:
	STRB    R0, [R5,#7]
	LDRB    R0, [R5,#6]
	LSL     R0, R0, #1
	LDR     R1, off_802F96C
	LDRH    R1, [R1,R0]
	LDRB    R2, [R5,#8]
	LSL     R2, R2, #2
	LDR     R0, off_802F95C
	LDR     R0, [R0,R2]
	MOV     R2, #0
	MOV     R3, #0
	BL      render_call_render_30068E8
	LDRB    R0, [R5,#8]
	BL      StartScreen_802F994
	LDRB    R0, [R5,#2]
	TST     R0, R0
	BNE     loc_802F924
	BL      sub_803F524
	BNE     loc_802F936
	BL      sub_803E930
	BEQ     loc_802F936
	B       loc_802F936
 loc_802F924:
	LDRB    R0, [R5,#8]
	BL      StartScreen_802F9EC
	BL      sub_803F524
	BNE     loc_802F936
	BL      sub_803E930
	BEQ     loc_802F936
 loc_802F936:
	BL      StartScreen_802fc9c
	BL      StartScreen_802fc70
	BL      StartScreen_802fb64
	BL      StartScreen_802fb90
	BL      StartScreen_802fbb4
	BL      StartScreen_802fbd8
	BL      StartScreen_802fbfc
	BL      StartScreen_802fc28
	BL      StartScreen_802fc4c
	POP     {R4-R7,PC}
off_802F95C:
	.word dword_802F960
dword_802F960:
	.word 0x40490071, 0x40490080, 0x40490091

off_802F96C:
	.word byte_802F970
byte_802F970:
	.byte 0x40
	.byte 0x11
	.byte 0x40
	.byte 0x11
	.byte 0x40
	.byte 0x11
	.byte 0x40
	.byte 0x11
	.byte 0x40
	.byte 0x11
	.byte 0x40
	.byte 0x11
	.byte 0x44
	.byte 0x11
	.byte 0x44
	.byte 0x11
	.byte 0x44
	.byte 0x11
	.byte 0x44
	.byte 0x11
	.byte 0x44
	.byte 0x11
	.byte 0x44
	.byte 0x11
	.byte 0x48
	.byte 0x11
	.byte 0x48
	.byte 0x11
	.byte 0x48
	.byte 0x11
	.byte 0x48
	.byte 0x11
	.byte 0x48
	.byte 0x11
	.byte 0x48
	.byte 0x11

StartScreen_802F994:
	PUSH    {R4-R7,LR}
	LDR     R1, off_802F9A4
	LSL     R0, R0, #2
	LDR     R0, [R0,R1]
	BL      sub_8001158
	POP     {R4-R7,PC}
	.byte 0x0, 0x0

off_802F9A4:
	.word off_802F9A8
off_802F9A8:
	.word dword_802F9B4
	.word dword_802F9D0
	.word dword_802F9D0
dword_802F9B4:
	.word 0x80584070, 0x3023, 0x80784070, 0x302B, 0x40980070
	.word 0x3033, 0x0
dword_802F9D0:
	.word 0x80584070, 0x4023, 0x80784070, 0x402B, 0x40980070
	.word 0x4033, 0x0

StartScreen_802F9EC:
	PUSH    {R4-R7,LR}
	LDR     R1, off_802F9FC
	LSL     R0, R0, #2
	LDR     R0, [R0,R1]
	BL      sub_8001158
	POP     {R4-R7,PC}
	.byte 0x0, 0x0

off_802F9FC:
	.word off_802FA00
off_802FA00:
	.word dword_802FA28
	.word dword_802FA0C
	.word dword_802FA28
dword_802FA0C:
	.word 0x8058407F, 0x3037, 0x8078407F, 0x303F, 0x4098007F
	.word 0x3047, 0x0
dword_802FA28:
	.word 0x8058407F, 0x4037, 0x8078407F, 0x403F, 0x4098007F
	.word 0x4047, 0x0
	PUSH    {R4-R7,LR}
	LDRB    R1, [R5,#9]
	CMP     R1, #3
	BLT     loc_802FA58
	LDR     R1, off_802FA70
	LSL     R0, R0, #2
	LDR     R0, [R0,R1]
	BL      sub_8001158
	B       locret_802FA62
loc_802FA58:
	LDR     R1, off_802FA64
	LSL     R0, R0, #2
	LDR     R0, [R0,R1]
	BL      sub_8001158
locret_802FA62:
	POP     {R4-R7,PC}
off_802FA64:
	.word off_802FA68
off_802FA68:
	.word dword_802FAEC
	.word dword_802FAC8
off_802FA70:
	.word off_802FA74
off_802FA74:
	.word dword_802FAA4
	.word dword_802FAA4
	.word dword_802FA80
dword_802FA80:
	.word 0x80584080, 0x304B, 0x80784080, 0x3053, 0x40980080
	.word 0x305B, 0xA88080, 0x305F, 0x0
dword_802FAA4:
	.word 0x80584080, 0x404B, 0x80784080, 0x4053, 0x40980080
	.word 0x405B, 0xA88080, 0x405F, 0x0
dword_802FAC8:
	.word 0x80584070, 0x304B, 0x80784070, 0x3053, 0x40980070
	.word 0x305B, 0xA88070, 0x305F, 0x0
dword_802FAEC:
	.word 0x80584070, 0x404B, 0x80784070, 0x4053, 0x40980070
	.word 0x405B, 0xA88070, 0x405F, 0x0

StartScreen_802FB10:
	PUSH    {R4-R7,LR}
	LDR     R0, off_802FB1C
	BL      sub_8001158
	POP     {R4-R7,PC}
	.byte 0x0, 0x0

off_802FB1C:
	.word dword_802FB20
dword_802FB20:
	.word 0x8000007E, 0x6180, 0x8020007E, 0x6190, 0x8040007E
	.word 0x61A0, 0x8060007E, 0x61B0, 0x8080007E, 0x61C0
	.word 0x80A0007E, 0x61D0, 0x80C0007E, 0x61E0, 0x80E0007E
	.word 0x61F0, 0x0

StartScreen_802fb64:
	PUSH    {LR}
	LDRH    R0, [R5,#0xA]
	MOV     R1, #0x80
	TST     R0, R1
	BEQ     locret_802FB74
	LDR     R0, off_802FB78
	BL      sub_8001158
 locret_802FB74:
	POP     {PC}
	.byte 0x0, 0x0

off_802FB78:
	.word dword_802FB7C
dword_802FB7C:
	.word 0x80044002, 0x9280, 0x40044012, 0x9288, 0x0


StartScreen_802fb90:
	PUSH    {LR}
	LDRH    R0, [R5,#0xA]
	MOV     R1, #0x40  // '@'
	TST     R0, R1
	BEQ     locret_802FBA0
	LDR     R0, off_802FBA4
	BL      sub_8001158
 locret_802FBA0:
	POP     {PC}
	.byte 0x0, 0x0

off_802FBA4:
	.word dword_802FBA8
dword_802FBA8:
	.word 0x802C4004, 0x8220, 0x0


StartScreen_802fbb4:
	PUSH    {LR}
	LDRH    R0, [R5,#0xA]
	MOV     R1, #0x20  // ' '
	TST     R0, R1
	BEQ     locret_802FBC4
	LDR     R0, off_802FBC8
	BL      sub_8001158
 locret_802FBC4:
	POP     {PC}
	.byte 0x0, 0x0

off_802FBC8:
	.word dword_802FBCC
dword_802FBCC:
	.word 0x80544004, 0x8230, 0x0


StartScreen_802fbd8:
	PUSH    {LR}
	LDRH    R0, [R5,#0xA]
	MOV     R1, #0x10
	TST     R0, R1
	BEQ     locret_802FBE8
	LDR     R0, off_802FBEC
	BL      sub_8001158
 locret_802FBE8:
	POP     {PC}
	.byte 0x0, 0x0

off_802FBEC:
	.word dword_802FBF0
dword_802FBF0:
	.word 0x807C4004, 0x8240, 0x0


StartScreen_802fbfc:
	PUSH    {LR}
	LDRH    R0, [R5,#0xA]
	MOV     R1, #8
	TST     R0, R1
	BEQ     locret_802FC0C
	LDR     R0, off_802FC10
	BL      sub_8001158
 locret_802FC0C:
	POP     {PC}
	.byte 0x0, 0x0

off_802FC10:
	.word dword_802FC14
dword_802FC14:
	.word 0x808E4014, 0x7210, 0x408E4024, 0x7218, 0x0


StartScreen_802fc28:
	PUSH    {LR}
	LDRH    R0, [R5,#0xA]
	MOV     R1, #4
	TST     R0, R1
	BEQ     locret_802FC38
	LDR     R0, off_802FC3C
	BL      sub_8001158
 locret_802FC38:
	POP     {PC}
	.byte 0x0, 0x0

off_802FC3C:
	.word dword_802FC40
dword_802FC40:
	.word 0x80A44004, 0x8250, 0x0


StartScreen_802fc4c:
	PUSH    {LR}
	LDRH    R0, [R5,#0xA]
	MOV     R1, #2
	TST     R0, R1
	BEQ     locret_802FC5C
	LDR     R0, off_802FC60
	BL      sub_8001158
 locret_802FC5C:
	POP     {PC}
	.byte 0x0, 0x0

off_802FC60:
	.word dword_802FC64
dword_802FC64:
	.word 0x80CC4004, 0x8260, 0x0


StartScreen_802fc70:
	PUSH    {LR}
	LDRH    R0, [R5,#0xA]
	MOV     R1, #0x10
	LSL     R1, R1, #4
	TST     R0, R1
	BEQ     locret_802FC82
	LDR     R0, off_802FC84
	BL      sub_8001158
 locret_802FC82:
	POP     {PC}
off_802FC84:
	.word dword_802FC88
dword_802FC88:
	.word 0x80404014, 0x7200, 0x40404024, 0x7208, 0x0


StartScreen_802fc9c:
	PUSH    {LR}
	LDRH    R0, [R5,#0xA]
	MOV     R1, #0x20  // ' '
	LSL     R1, R1, #4
	TST     R0, R1
	BEQ     locret_802FCAE
	LDR     R0, off_802FCB0
	BL      sub_8001158
 locret_802FCAE:
	POP     {PC}
off_802FCB0:
	.word dword_802FCB4
