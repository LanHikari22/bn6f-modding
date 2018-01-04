#ifndef DATA_LOCATIONS_H
#define DATA_LOCATIONS_H

#include "../../inttypes.h"
#include "../version.h"
#include "../structs/BattleSettings.h"

#ifdef FALZAR

/* ROM */

#define jumpTable_4              ((void**)0x080030FC)
#define jumpTable_3              ((void**)0x08003114)
#define jumpTable_2              ((void**)0x080045BC)
#define chatbox_FB_jt            ((void**)0x0804239C)
#define jumpTable_0              ((void**)0x0809E6A4)
#define jumpTable_1              ((void**)0x0809EC30)
#define battle_settings_list0    ((BattleSettings*)0x080AEE70)
#define battle_settings_list1    ((BattleSettings*)0x080B0D88)
#define reqBBS_entries_graphics  ((u8*)0x0813EF44)
#define reqBBS_textualPointers   ((void**)0x0813F34C)
#define reqBBS_difficultyEntries ((u8*)0x0813F380)
#define reqBBS_jumpTable         ((void**)0x0813F42C)
#define reqBBS_texual_shades     ((u8*)0x087EFBC8)

/*
    Address  Type           Variable
    080030FC void           *jumpTable_4[6]
    08003114 void           *jumpTable_3[6]
    080045BC void           *jumpTable_2[1]
    0804239C void           *chatbox_FB_jt[16]
        This is involved with the mini scripting language! It's basically
        the callback table for its FB mode!
    0809E6A4 void           *jumpTable_0[7]
    0809EC30 void           *jumpTable_1[81]
    080AEE70 BattleSettings *battle_settings_list0
    080B0D88 BattleSettings *battle_settings_list1
    0813EF44 u8             *reqBBS_entries_graphics
    0813F34C void           *reqBBS_textualPointers[2]
    0813F380 u8             reqBBS_difficultyEntries[0x64]
    0813F42C void           *reqBBS_jumpTable[18]
    087EFBC8 u8             *reqBBS_texual_shades

ROM Data Table*/

/* RAM */

#define reqBBS_requestEntries_list      ((u8*)0x02000290)
#define reqBBS_tile_data                ((u8*)0x02018204)
#define reqBBS_requestEntries_IDs       ((u8*)0x02023A00)
#define reqBBS_dialog_list              ((u16*)0x02033A04)

/*
    Address  Type Variable
    02000290 u8   reqBBS_requestEntries_list[36]
    02018204 u8   *reqBBS_tile_data
    02023A00 u8   reqBBS_requestEntries_IDs[48]
    02033A04 u16  *reqBBS_dialog_list
RAM Data Table*/

#endif // FALZAR

#endif // DATA_LOCATIONS_H