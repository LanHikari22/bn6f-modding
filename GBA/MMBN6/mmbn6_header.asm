/**
 * mmbn6_header.asm
 * Author: Lan
 * Date created: 7/21/2017
 * Description
 * This header file contains .equ definitions of pointers and structures found in MMBN6. 
 * These resources can be used in other asm files!
*/
#ifndef MMBN6_HEADER
#define MMBN6_HEADER
.thumb

.equ p_keyState, 0x0200A270

// Keys
.equ KeyR, 0xFD00
.equ KeyS, 0xFC04

.equ s_chiefStruct, 0x020093B0
.equ p_currBattle, 0x020348BC
.equ p_currScript, 0x02009CFC
.equ p_coords, 	0x02009F60  // those are sorta weird
.equ p_battleLauncher_navi, 0x0809A72C
.equ s_battle_playerStatus, 0x020384F0
.equ s_npc_copybotNearDog, 	0x02005BE8

// Battle structs
.equ s_enemyA, 0x0203AA88
.equ s_enemyB, 0x0203AB60
.equ s_enemyC, 0x0203AC38
.equ s_battle_player, 0x0203A9B0

/* <<CUSTOM GLOBAL VARIABLES>> */
// KeyPressExecution.asm
// Used to execute trigger code upon key press
.equ isPressed, 0x02020000
// A trigger flag to activate sub_continous
.equ continuous_on, 0x02020004
.equ cont_isPressed,0x02020005
.equ cont_activationCounter, 0x02020006

#endif
