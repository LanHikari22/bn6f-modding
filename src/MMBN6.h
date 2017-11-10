/**
 * MMBN6.h
 * Author: Lan
 * Date created: 11/4/2017
 * Description
 * This header file contains definitions of pointers and structures of interest found in MMBN6. 
 * Modules in the game may be complex and deserving of their own module headers.
 * In that case, this header will make sure to include their header in, as well.
*/

#ifndef MMBN6_H
#define MMBN6_H

#include "inttypes.h"

/* ************************************************************************/
/* Game-intrinsic Module **************************************************/


/* Accessing Key input ****************************************************/
#define pKeyState ((int*) 0x0200A270)
// Keys
#define KeyR 		0xFD00
#define KeyS 		0xFC04
#define KeyE		0xFC08
#define KeyIDLE 	0xFC00

/* pointers of interest **************************************************/
#define pCurrBattle 		((int*)0x020348BC)
#define pCurrBattleData 	((int*)0x02001B9C)
#define pCurrScript 		((int*)0x02009CFC)
#define pCoords 			((int*)0x02009F60)  // those are sorta weird
#define pBtlLauncher_navi 	((int*)0x0809A72C)

/* Game function pointers of interest ***********************************/
#ifndef function_pointers
/**
 * Runs the Chatbox program based on a structure passed to it
 * r5_sNPC may be NULL, in that case a preselected NPC on the map is used.
 * @param r5_sNPC An NPC object within the map. If available, its script plays.
 */
#define fpRunChatbox 0x080A0058
#endif

#ifndef Game_Structures
/* The Chief Structure ***************************************************/
typedef struct {
	// TODO: construct ChiefStruct
}ChiefStruct;
#define sChiefStruct ((ChiefStruct*)0x020093B0)

/* Battle Structure, and variations of it in memory ********************/
/**
* Description: Holds some battle parameters such as battle of a battle
* object.
* Length: 0xD8 bytes
*/
typedef struct{
	uint16_t ctrl;				// 0x00
		uint8_t pad1202 [0x12 - 0x02];
	uint16_t attackCoord;		// 0x12
		uint8_t pad2414 [0x24 - 0x14];
	uint16_t HP;				// 0x24
		uint8_t pad3626 [0x36 - 0x26];
	uint16_t x;					// 0x36
		uint8_t pad3A38 [0x3A - 0x38];
	uint16_t y;					// 0x3A
		uint8_t pad3E3C [0x3E - 0x3C];
	uint16_t z;					// 0x3E
		uint8_t pad943F [0x94 - 0x40]; 
	uint16_t pallete;			// 0x94
		uint8_t padA696 [0xA6 - 0x96];
	uint16_t facingDirection;	// 0xA6
		uint8_t padD8A8 [0xD8 - 0xA8];
	// END						// 0xD8	
}Battle;

#define sBtlEnemyA 	((Battle*)0x0203AA88)
#define sBtlEnemyB 	((Battle*)0x0203AB60)
#define sBtlEnemyC 	((Battle*)0x0203AC38)
#define sBtlPlayer 	((Battle*)0x0203A9B0)

/* Battle Structures: Player Status Structure ************************8***/
typedef struct {
	// TODO: construct Battle_playerStatus
}Btl_playerStatus;
#define sBtl_playerStatus ((Btl_playerStatus*)0x020384F0)

/* NPC Structure and various NPCs ***************************************/
/**
 * Description:
 * This structure represents NPC overworld parameters, as well as other components such as script.
 * The absolute addresses in memory of this object are not static to every NPC in the game.
 * Length: 0x1B0
 */
typedef struct {
	// TODO: Not padded
	uint8_t  invisCollSwitch;	// 0x00
	uint16_t convTrigger; 		// 0x08
	uint16_t volume;			// 0x0C
	uint16_t facingDirection;	// 0x14
	uint8_t  palleteIndx;		// 0x16
	uint16_t convoSelect;		// 0x1C
	uint32_t x;					// 0x24
	uint32_t y;					// 0x28
	uint32_t z;					// 0x32
	uint16_t sprite;			// 0x3C
	uint32_t *pScript;			// 0x94
	
	// TODO: construct NPC struct
}NPC;
#define sNPC_chaud 			((NPC*)0x02005F48)
#define sNPC_copybotneardog ((NPC*)0x02005BE8)
#endif /* Structures Section */

#endif /* MMBN6_H */
//DF050302
//020305DF
