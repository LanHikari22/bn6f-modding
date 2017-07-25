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

.equ pKeyState, 0x0200A270

// Keys
.equ KeyR, 		0xFD00
.equ KeyS, 		0xFC04
.equ KeyE,		0xFC08
.equ KeyIDLE, 	0xFC00

.equ sChiefStruct, 0x020093B0
.equ pCurrBattle, 0x020348BC
.equ pCurrBattleData, 0x02001B9C
.equ pCurrScript, 0x02009CFC
.equ pCoords, 	0x02009F60  // those are sorta weird
.equ pBattleLauncher_navi, 0x0809A72C
.equ sBattle_playerStatus, 0x020384F0

// NPC Structs
.equ sNPC_chaud, 0x02005F48
.equ sNPC_copybotneardog, 0x02005BE8


// Battle structs
.equ sEnemyA, 0x0203AA88
.equ sEnemyB, 0x0203AB60
.equ sEnemyC, 0x0203AC38
.equ sBtlPlayer, 0x0203A9B0


#endif
