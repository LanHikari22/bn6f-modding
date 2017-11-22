#ifndef S_02001B80_H
#define S_02001B80_H

#include "../../../inttypes.h"
#include "../OWPlayer.h"

typedef struct {
	uint8_t unk_00;  // loc=0x0
	uint8_t unk_01;  // loc=0x1
		uint8_t pad_2[0x1]; // loc=0x2
	uint8_t unk_03;  // loc=0x3
	uint16_t unk_04; // loc=0x4
	uint8_t unk_06;  // loc=0x6
		uint8_t pad_7[0x7]; // loc=0x7
	uint8_t unk_0E;  // loc=0xE
		uint8_t pad_F[0x1]; // loc=0xF
	uint8_t unk_10;  // loc=0x10
	uint8_t unk_11;  // loc=0x11
	uint8_t unk_12;  // loc=0x12
		uint8_t pad_13[0x2]; // loc=0x13
	uint8_t unk_15;  // loc=0x15
		uint8_t pad_16[0x2]; // loc=0x16
	OWPlayer *player; // loc=0x18
		uint8_t pad_1C[0x8]; // loc=0x1C
	uint32_t unk_24; // loc=0x24
	uint32_t unk_28; // loc=0x28
		uint8_t pad_2C[0x3C]; // loc=0x2C
	uint32_t unk_68; // loc=0x68
		uint8_t pad_6C[0x18]; // loc=0x6C
	// size=0x84
}s_02001B80;

#pragma region Docs
/*
s_02001B80 <>:
	Description
		TODO
	Size
		Hypothesis: 0x84 (0x02001C04 - 0x02001B80)
	Other Instances
		Unknown
	0x00 [0xZZ]
		.# Deadly parameter. Many values cause gfx glitches and crash.
		.# Z=0x00 Causes all NPC objects to disappear.
	0x08 [0xZZ]
		.# This can change L chat to Dummy Text, or other predefined text.
		.# or it can crash the game.
	0x1C [0xPPPPPPPP] <pCurrBattleData>
*/
#pragma endregion Docs

#pragma region Accesses
/*
Format: <subroutine_Addr>::<Address of access> <type>(<value>)
If an access has eben shown before: subAddr, type and register are not shown.
Writes:
	A: (When interacting with an NPC & object)
	0809EF18::0809EF96 u8(0x11), 0809E880::0809E888 u8(0x11), 
	0809F438 u8(0x10)
	B: (Chatbox window going down after (A & C'))
	0809ED10 u8(0x10), 
	C: (When interacting with an Object)
	?::0809F454 u8(0x0E), 0809F438::0809F45A u8(0x03),
	08005268::08005274 u8(0xE),
	D: (When JUST Pressing A ('Z'))
	0809EF18::0809EF96, 0809E880::0809E888,
	E: (Accessing main menu through pressing START)
	?::08001082 u32(0x24), ?::08001086 u32(0x28), 08005AF4::08005B66 u8 (0x00),
	F: (Exiting submenu)
	08121504::08121514 u8(0x00), ?::080051BE u8(0x15) u8(0x0E) u8(0x03) u32(r5->0x68)
	?::08005260 u8(0x00), ::08005B66, 
	G: (Exiting main menu)
	::080054F2 u8(0x00)
Reads: (Way too many, only unique acccesses)
	u8(0x04), u8(0x0A), u16(0x04) CONFLICT, u8(0x01), u8(0x00), u8(0x10)
	u32(0x18), u8(0x06), u8(0x0E), u8(0x12), u8(0x11)
---
*/
#pragma endregion Accesses

#pragma region memo
/*
A structure was found at s_02001C04 due to overestimating Size
*/
#pragma endregion memo

#endif /* S_02001B80_H */