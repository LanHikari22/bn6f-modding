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
 * It seems to do something to structures passing in r0, up to r1 bytes?
 * Since it always updates r0=0x020081D0, r1=0x280, It kept updating those values
 * UP to 0x280! I could write at 0x280.
 [params]
 * r0(struct), r1(size?)
 * [side effects] 
 * [return]
*/
main: // <099000>
	push    {r0-r3,r7,r14}
//D	mov		r1, #0x02 //D can cause npcs to be dummies, or crash when battles start
//D	ldr		r0,=0x02009CD0 //D glitches. Expects more than one struct.
	
	ldr     r2,=#0x5000000 // 0x5000000
	lsr     r1,r1,#0x2
	orr     r2,r1
	mov     r1,r0
	add     sp,#-0x4 // -#0x4 to #-0x4...
	mov     r0,#0x0
	str     r0,[sp]
	mov     r0,r13		

	ldr r7, =0x814F408 // Swi table: Executes CpuSet and returns
	bl		blx
	mov		r1, #0x00 //D
	mov		r0, #0
	add     sp,#0x4
	pop     {r0-r3,r7,r15}

/**
 * Register used for bx should not be used by the caller function
 * [params]
 * r7_pInstruction
*/	
blx:
	push {r6,r7, lr}
	add r7, #1
	mov r6, pc // bx r14 is executed. must add 1 (and account for lag)
	add r6, #5
	mov lr, r6
	bx r7
	pop {r6,r7, pc}
	
/**
---	Dynamic Analysis ---
Reporting some values passed and returned by function.
[params]
	r0: 0200A490 0200A6A0 02000780 02001010 02009F34 02009F40 020010E0
	r1: 0000020C 00000050 00000048 00000048 00000004 000000C8 00000004
	---
	r0: 020057B0 02011E50 02011EE0 02009CD0 02001060 02003134 02000780
	r1: 00000D80 00000008 00001A40 00000230 00000080 00000190 00000048
	--
	r0: 02001010]02001800 02001850 020032C8 02000070 02000DC0 02002178
	r1: 00000048]00000048 00000060 00000E80 00000020 00000100 000000B4
	--
	At other instances, (after launch) r0=0x020081D0, r1=0x280 is executed lots.
	@ACDC, 02011EE0 seems to be NPC struct for Chip trader!
	@ACDC, 
[return]
*/