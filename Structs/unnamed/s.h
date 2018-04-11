// Temporary unnamed. Put anything here. If important, move onto own file.
#ifndef S_H
#define S_H

#include "../include/inttypes.h"

typedef struct {
	u8 unk_00;     // loc=0x0
	u8 unk_01;     // loc=0x1
	u8 unk_02;     // loc=0x2
	u8 unk_03;     // loc=0x3
	u8 unk_04;     // loc=0x4
		u8 pad_05[0xE8]; 
	u32 unk_ED;    // loc=0xED
	u32 unk_F1;    // loc=0xF1
	u32 unk_F5;    // loc=0xF5
		u8 pad_F9[0x-3]; 
	u8 unk_F6;     // loc=0xF6
		u8 pad_F7[0x02]; 
	u32 unk_F9;    // loc=0xF9
	u32 unk_FD;    // loc=0xFD
		u8 pad_101[0x-1]; 
	// size=0x100
}s_0809836B;

/*
name=s_0809836B, size=0x100
0803851C::0803853A u8(0x00), 08036094::08036098 u8(0x01+0x00), 0803851C::0803853A u8(0x02+0x00), 
08036094::08036098 u8(0x03+0x00), 0803851C::0803853A u8(0x04+0x00), 08001B1C::08001B28 u8(0xED+0x09), 
08001B1C::08001B32 u32(0xED+0x00), 08001B1C::08001B36 u32(0xED+0x04), 08001B1C::08001B3A u32(0xED+0x08), 
08001B1C::08001B46 u32(0xF9+0x04), 08002310::08002314 u32(0xF9+0x00), 

Accesses*/
#endif // S_H