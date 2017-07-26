/**
 * KeyPressEntrypoints.asm
 * Author: Lan
 * Date created: 07/23/2017
 * Description
 * Entrypoint functions are defined here! Those are functions of different execution conditions that can be taken advantage of!
 * onStart will aways execute the first time the game is run.
 * Press R twice to toggle onActive code.
 * onTrigger code is executed whenever (SELECT) is pressed.
 * global variable shortcutsEnabled_0 can be disabled to disable onActive and onTrigger shortcuts.
*/
#ifndef KEYPRESSENTRYPOINTS_ASM
#define KEYPRESSENTRYPOINTS_ASM
.thumb
b		KEYPRESSENTRYPOINTS_ASM_EOF
// Headers
//.include "../headers/GBA_header.asm"
//.include "../headers/mmbn6_header.asm"
//.include "../headers/mmbn6_globalvariables.asm"
.include "../textGeneration_api.asm"

onTrigger:
	push {r0-r7, lr}
	
	
/*  ldr r0, =sEnemyA 			// pointer to enemyA struct
	ldr r1, =sBattle_player 	// pointer to player battle struct
	ldrh r2, [r0, #0x24] 		// sEnemyA->HP
	ldrh r3, [r1, #0x24] 		// PlayerBattleStruct->HP
	strh r2, [r1, #0x24]
	strh r3, [r0, #0x24] */

	b 3f
someText:	.string "Hello andy! look I can print strings now!!\0"
.align 4
3:	ldr 	r1, =someText
	ldr 	r2, =0x08090000 // to make location absolute!
	add 	r1, r2
	ldr 	r2, =0x02034B50 // r2_pOut
	bl 		tg_strcopyTo
	
	// swi 0x03 // stop!
		
	pop 	{r0-r7, pc}

onActive:
	push 	{r0-r7, lr}
	
	ldr 	r0, =sEnemyA // yay literal pool!
	ldr 	r1, [r0, #0x24] // HP
	add 	r1, #1
	str 	r1, [r0, #0x24] // HP
	
	pop 	{r0-r7, pc}

	
onEvent:
	push 	{r0-r7, lr}

	// debug @ 0809021A
	bl		tg_handleScriptEvent

99:	pop		{r0-r7, pc}

onState:
	push 	{r0-r7, lr}
	
	// debug @ 0809021E	
	b		3f
text: .string "Zeros and ones.\nIf you doubt yourself...\nYou will lose.\0 \1"
.align 4
3:	ldr		r2, =text
	ldr		r3, =0x08090000
	add		r2, r3
	
	ldr		r3, =0x020305E1
//	bl		tg_toGameText
	
	
	pop		{r0-r7, pc}
	
onCountdown:
	push	{r0-r7, lr}
	
	ldr 	r0, =sEnemyA // yay literal pool!
	ldr 	r1, [r0, #0x24] // HP
	add 	r1, #1
	str 	r1, [r0, #0x24] // HP
	
	pop		{r0-r7, pc}
	
onPWM:
	push	{r0-r7, lr}
	
	pop		{r0-r7, pc}

onStart:
	push {r0-r7, lr}
	
	// init shortcutsEnabled_0: Disabled by default.
	ldr r0, =shortcutsEnabled_0
	mov r1, #0x00
	strb r1, [r0]
	
	// onCountdown_counter_0 is initialized to countdown
	ldr r0, =onCountdown_counter_0
	ldr r1, =countdown
	str r1, [r0]
	
	bl cc_initCheatcodes
	
	// Make sure this doesn't get executed again: Set onStartExecuted_0 to 0xADD2FEED
	ldr r0, =0xADD2FEED
	ldr r1, =onStartExecuted_0
	str r0, [r1]
	
	pop {r0-r7, pc}
	
KEYPRESSENTRYPOINTS_ASM_EOF:
#endif
