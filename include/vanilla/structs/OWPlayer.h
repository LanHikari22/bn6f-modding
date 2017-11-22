#ifndef S_02009F40_H
#define S_02009F40_H

#include "../../inttypes.h"

typedef struct{
	uint8_t invisCtrlSwitch;  // loc=0x0
	uint8_t unk_01;           // loc=0x1
	uint8_t unk_02;           // loc=0x2
		uint8_t pad_3[0x1];      // loc=0x3
	uint32_t unk_04;          // loc=0x4
	uint8_t contTrigger;      // loc=0x8 Freezes game.
	uint8_t walkingFlag;      // loc=0x9 No effect. Got from NPC struct
	uint8_t unk_0A;           // loc=0xA
		uint8_t pad_B[0x1];      // loc=0xB
	uint8_t collision;        // loc=0xC
		uint8_t pad_D[0x3];      // loc=0xD
	uint8_t unk_10;           // loc=0x10
	uint8_t unk_11;           // loc=0x11
		uint8_t pad_12[0x2];     // loc=0x12
	uint8_t animationSelect;  // loc=0x14
	uint8_t ROAnimationSel;   // loc=0x15
		uint8_t pad_16[0x6];     // loc=0x16
	uint32_t x;               // loc=0x1C
	uint32_t y;               // loc=0x20
	uint32_t unk_24;          // loc=0x24
	uint32_t RO_x;            // loc=0x28
	uint32_t RO_y;            // loc=0x2C
		uint8_t pad_30[0x1C];    // loc=0x30
	uint16_t unk_4C;          // loc=0x4C
		uint8_t pad_4E[0x8];     // loc=0x4E
	uint8_t unk_56;           // loc=0x56
		uint8_t pad_57[0x51];    // loc=0x57
	uint32_t *unk_A8;         // loc=0xA8
	uint32_t *unk_AC;         // loc=0xAC
		uint8_t pad_B0[0x100];   // loc=0xB0
	// size=0x1B0
} OWPlayer;

#pragma region Docs
/*
s_02009F40 <>:
	Description
		TODO
	Size
		Hypothesis: 0x8C (0x02009FCC - 0x02009F40)
*/
#pragma endregion Docs

#pragma region Accesses
/*
Format: <subroutine_Addr>::<Address of access> <type>(<value>)
If an access has eben shown before: subAddr, type and register are not shown.
Writes:
    A: (Entering a submenu)
    08003B86::08003B9A u8(0x00)
    B: (Exiting a submenu)
    08003B4C::08003B6E u8(0x00), 08003B4C::08003B72 u8(0x01) u32(0x1C) u32(0x20) u32(0x24) u32(0x04)
    08003B4C::08003B7E u32(0x08), 0809F59C::0809F5B2 u32(0x1C), 0809F59C::0809F5B6 u32(0x20),
    08003B4C::0809F5BA u32(0x24), 0809E7A8::0809E7AC u8(0x00), 0809E7A8::0809E7F6 u8(0x14),
    0809E7A8::0809E7FA u8(0x15), 0809E7A8::0809E808 u8(0x08) CONFLICT, 0809E7A8::0809E828 u8(0x11),
    0809E9A8::0809E9B6 u8(0x14), 0809E9A8::0809E9BA u8(0xA), 
    C: (U/D/L/R)
    0809EF18::0809EFBC u16(0x4C), 0809EF18::0809EFC6 u8(0x10), 0809F53C::0809F540 u8(0x0A),
    0809F53C::0809F54C u8(0x09), 0809F4F8::0809F520 u8(0x56), 0809EF18::0809EF4C u8(0x11),
    ::0809EFBC, ::0809F54C, ::0809F510, ::0809E9B6, ::0809E9BA, ::0809E71C u8(0x15),
    D0: (BEFORE Jacking in chat)
    ::0809F540, ::0809F54C, ?::0809F7EC u8(0x10), 0809ED38::0809ED5C u8(0x14),
    ::0809E71C
    D1: (Jacking in AFTER chat)
    ::0809ED5C, ::0809E71C
    D2: (BEFORE Jacking in animation)
    0809ED38::0809ED7A u32(0x08), A, B?
---
*/
#pragma endregion Accesses

#pragma region memo
/*
a new struct found at s_02009F5C due to overestimating size.
However, s_02009F5C is actually accessed through this... 
It might be a struct within a struct.

Callbacks encountered in Accesses:
    0809ED38

*/
#pragma endregion memo

#endif /* S_02009F40_H */