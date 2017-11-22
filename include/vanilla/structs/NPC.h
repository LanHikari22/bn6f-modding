#ifndef NPC_H
#define NPC_H
#include "../../inttypes.h"

/**
 * Description:
 * This structure represents NPC overworld parameters, as well as other components such as script.
 * The absolute addresses in memory of this object are not static to every NPC in the game.
 * Length: 0x1B0
 */
typedef struct {
	uint8_t invisCollSwitch;      // loc=0x0
		uint8_t pad_1[0x7];          // loc=0x1
	uint8_t contTrigger;		  // loc=0x8
	uint8_t walkingFlag;		  // loc=0x9
	uint8_t unk_0A;               // loc=0xA
		uint8_t pad_B[0x1];          // loc=0xB
	uint16_t volume;              // loc=0xC 
		uint8_t pad_E[0x6];          // loc=0xE
	uint8_t animationSelect;  // loc=0x14
	uint8_t ROAnimationSel;   // loc=0x15
	uint8_t palleteIndx;          // loc=0x16 
		uint8_t pad_17[0x5];         // loc=0x17
	uint8_t convoSelect;          // loc=0x1C 
		uint8_t pad_1D[0x7];         // loc=0x1D
	uint32_t x;                   // loc=0x24 
	uint32_t y;                   // loc=0x28 
	uint32_t z;                   // loc=0x2C
		uint8_t pad_30[0xC];         // loc=0x30
	uint16_t NPCSelect;              // loc=0x3C
		uint8_t pad_3E[0x22];        // loc=0x3E
	uint32_t flConfig;              // loc=0x60
		uint8_t pad_64[0x30];        // loc=0x64
	uint32_t *pScript;            // loc=0x94
		uint8_t pad_98[0x117];       // loc=0x98
	// size=0x1B0
}NPC;

/**
 * Enum for flConfig. The meanings of different bits.
 */
typedef enum{
	nACTIVATE = 0x001, nTURN = 0x002, nSOLID = 0x004,
	SCRIPT_SELECT = 0x400, UNK_800 = 0x800
}NPC_FLCFG;


/* Instances */
#pragma region Instances
#define sNPC_chaud 			((NPC*)0x02005F48)
#define sNPC_copybotneardog ((NPC*)0x02005BE8)
#define sNPC_ACDC_Boy		((NPC*)0x02005888)
#pragma endregion Instances

#pragma region Doc
/**
s_02005F48 <sNPC_chaud>
	TODO
		Formatting. Still didnt settle on a good reporting format...
	Description
		// Overworld parameters and encapsulation of NPC objs?
	Length
		0x1B0 bytes
	Other Instances (?)
		s_02005BE8 # sNPC_copybotneardog
		s_02005F48 # chaud (ACDC), Subchip seller guy
		s_020062A8 # Another copybot
		s_02006458 # Enemy copybot, sigh
		s_02005C38 # seems to be a struct of its own? (0x50)
	0x00 [0x0Z] <invisCollSwitch>
		// This seems to hold 4 states. All others are repeated. 00 through 04
		// covers all cases of INVISIBLE = TRUE/FALSE and COLLIDABLE = TRUE/FALSE!
	0x01 [0x0Z]
		// ??? Most values crash the game. May be tied to a function pointer calculation...
	0x08 [0x000Z] <convTrigger>
		// Z = 8: Trigger a certain conversation
		// Many other values just crash?

	0x0C [0xAABB] <volume>
		// This specifies the width of the collision walls, in two components parallel and anti-parallel to
		// the streets in the game.
	0x14 [0X0Z] <facingDirection>
		// X not sure, but it is always identical or close to Z. It might be a flag.
		// Z determines direction of NPC based on 2<<n-1
	0x16 [0xZZ] <palleteIndx>
		// This seems like a pallete index
	0x18 [0x000Z]
		// Another conversation switch at Z...
	0x1C [0x00ZZ] <convoSelect>
		// Changes conversation of copybot!!
	0x24 [u32] <x>
	0x28 [u32] <y>
	0x2C [u32] <z>
	0x3C [u32] <NPCSelect>
		// Changes sprite! some are neat, some are weird.
	0x50 [0x000Z]
		// For any Z, a certain conversation is triggered
		// Value constantly written to unless PET is open, for example
		// <0800385C> breaks whenever you talk to a character hmm..
	0x60 [u32] <flConfig>
		// Flags! 0xUUUUU_0bXcUU_UUUs_osta
		// a(0x001): !activate. 1 = interaction w/ NPC is disabled.
		// t(0x002): !turn. 1 = disabled. NPC won't turn when you interact.
		// s(0x004): !solid. 1 = Can walk through NPC.
		// o(0x008): orientation. 0 = Facing direction parallel to Lan's old house. 1 = perpendicular
		// s(0x010): also solid. No other effects observed.
		// c(0x400): conversation select of some sort. 
		// X(0x800): If c, This enters a weird state where game
		// pauses for a while until a conversation is reached...
		// Unknown. Dangerous.
		

	0x94 [pointer] <pScript>
		// This points to the script that is played by the chat engine when you "talk" to the NPC.
*/
#pragma endregion Doc

/*
s_02035280 <sNoname>:
	Description
		// This seems to be a structure responsible for gui properties in battles
	0x00 [0xZZZZ]
		// Weird effect when it comes to HP bars
	0x48 [0xPPPPPPPP] <pStatusSettings>
		// Seems to be an active pointer to Megamans status settings or something?
*/
#endif /* NPC_H */