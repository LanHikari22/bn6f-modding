#ifndef CHIEF_STRUCT_H
#define CHIEF_STRUCT_H
#include "../../inttypes.h"
#include "unnamed/s_02001B80.h"
#include "ChatboxPropreties.h"

/**
 * This structure is essential in game. It is always available in R10,
 * and hosts important other structures the game accesses.
 */
typedef struct{
	void *unk_00;                // loc=0x0
	void *unk_04;                // loc=0x4
	void *unk_08;                // loc=0x8
	void *unk_0C;                // loc=0xC
	void *unk_10;                // loc=0x10
	void *unk_14;                // loc=0x14
	void *unk_18;                // loc=0x18
	void *unk_1C;                // loc=0x1C
	void *unk_20;                // loc=0x20
	void *unk_24;                // loc=0x24
	void *unk_28;                // loc=0x28
	ChatboxPropreties *chatbox;  // loc=0x2C
	void *unk_30;                // loc=0x30
	void *unk_34;                // loc=0x34
	void *unk_38;                // loc=0x38
	s_02001B80 *unk_3C;          // loc=0x3C
	void *unk_40;                // loc=0x40
	void *unk_44;                // loc=0x44
	void *unk_48;                // loc=0x48
	void *unk_4C;                // loc=0x4C
	void *unk_50;                // loc=0x50
	void *unk_54;                // loc=0x54
	void *unk_58;                // loc=0x58
	void *unk_5C;                // loc=0x5C
	void *unk_60;                // loc=0x60
	void *unk_64;                // loc=0x64
	void *unk_68;                // loc=0x68
	void *unk_6C;                // loc=0x6C
	void *unk_70;                // loc=0x70
	void *unk_74;                // loc=0x74
	void *unk_78;                // loc=0x78
	void *unk_7C;                // loc=0x7C
	void *unk_80;                // loc=0x80
	void *unk_84;                // loc=0x84
	void *unk_88;                // loc=0x88
	void *unk_8C;                // loc=0x8C
	uint32_t unk_90;             // loc=0x90
	// size=0x94
}ChiefStruct;

#define sChiefStruct ((ChiefStruct*)0x020093B0)


#pragma region Docs
/*
s_020093B0 <sChiefStruct>:
	Description
		Table of other structs.
		Always accessible. Seems to be the toolkit to everything else.
	Length
		Unknown
	Other Instances
		Probably None
	0x00 [ptr] <> value=0x0200A480
	0x04 [ptr] <> value=0x0200A270
	0x08 [ptr] <> value=0x0200AC40
	0x0C [ptr] <> value=0x02009980
	0x10 [ptr] <> value=0x02011C50
	0x14 [ptr] <> value=0x02011BB0
	0x18 [ptr] <> value=0x02034880
	0x1C [ptr] <> value=0x0200F3A0
	0x20 [ptr] <> value=0x02009740
	0x24 [ptr] <> value=0x0200A210
	0x28 [ptr] <> value=0x030025C0
	0x2C [ptr] <ChatBoxPropreties> value=0x02009CD0
	0x30 [ptr] <> value=0x020384F0
	0x34 [ptr] <> value=0x02009A30
	0x38 [ptr] <> value=0x0200A220
	0x3C [ptr] <s_02001B80> value=0x02001B80
	0x40 [ptr] <> value=0x02001C04
	0x44 [ptr] <> value=0x02001C88
	0x48 [ptr] <> value=0x02002178
	0x4C [ptr] <> value=0x02002230
	0x50 [ptr] <> value=0x02003134
	0x54 [ptr] <> value=0x020032C8
	0x58 [ptr] <> value=0x0200414C
	0x5C [ptr] <> value=0x02004190
	0x60 [ptr] <> value=0x0200431C
	0x64 [ptr] <> value=0x02004330
	0x68 [ptr] <> value=0x02004334
	0x6C [ptr] <> value=0x02004338
	0x70 [ptr] <> value=0x02004348
	0x74 [ptr] <> value=0x020047CC
	0x78 [ptr] <> value=0x02004A8C
	0x7C [ptr] <> value=0x02004C20
	0x80 [ptr] <> value=0x02004E24
	0x84 [ptr] <> value=0x02005028
	0x88 [ptr] <> value=0x02005030
	0x8C [ptr] <> value=0x02005038
	0x90 [u32] <> value=0x4F4DD170
*/
#pragma endregion Docs

#endif /* CHIEF_STRUCT_H */