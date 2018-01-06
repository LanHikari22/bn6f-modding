#ifndef DATA_LOCATIONS_H
#define DATA_LOCATIONS_H

#include "../include/inttypes.h"
#include "../include/version.h"
#include "../Structs/BattleSettings.h"

/*
Add to tables by copying entries like '02025A04 ; u8 *reqBBS_requestNames_textualData' to
one of the RAM or ROM Data tables. Remove the semicolon, copy the table, 
and call the batfile dataRecordUpdate to format things right.
Define macros are generated automatically by copying the table and calling the dataRecordToMacro bat file.
Those bat files can be found in .vscode\userTools
File Maintainance Usage*/

#pragma region FALZAR
#ifdef FALZAR

/* ROM ------------------------------------------------------------------------------------------- */

#define jumpTable_4              ((void**)0x080030FC)
#define jumpTable_3              ((void**)0x08003114)
#define jumpTable_2              ((void**)0x080045BC)
#define chatbox_jt3              ((u32**)0x08041E94)
#define chatbox_jt2              ((u32**)0x08041F7C)
#define chatbox_FB_jt            ((void**)0x0804239C)
#define chatbox_jt1              ((void**)0x08042624)
#define jumpTable_0              ((void**)0x0809E6A4)
#define jumpTable_1              ((void**)0x0809EC30)
#define battle_settings_list0    ((BattleSettings*)0x080AEE70)
#define battle_settings_list1    ((BattleSettings*)0x080B0D88)
#define reqBBS_draw_jt1          ((void**)0x0813E0CC)
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
08041E94 u32            *chatbox_jt3[7]
08041F7C u32            *chatbox_jt2[14]
0804239C void           *chatbox_FB_jt[16]
    This is involved with the mini scripting language! It's basically
    the callback table for its FB mode!
08042624 void           *chatbox_jt1[21]
0809E6A4 void           *jumpTable_0[7]
0809EC30 void           *jumpTable_1[81]
080AEE70 BattleSettings *battle_settings_list0
080B0D88 BattleSettings *battle_settings_list1
0813E0CC void           *reqBBS_draw_jt1[11]
0813EF44 u8             *reqBBS_entries_graphics
0813F34C void           *reqBBS_textualPointers[2]
0813F380 u8             reqBBS_difficultyEntries[0x64]
0813F42C void           *reqBBS_jumpTable[18]
087EFBC8 u8             *reqBBS_texual_shades
087EE2F0  u8 reqBBS_request_ROM_textData[176]
08140238  u8 reqBBS_tiles_checkmark
08140244  u8 reqBBS_tiles_yellowIcon
ROM Data Table*/


/* RAM ------------------------------------------------------------------------------------------- */

#define reqBBS_requestEntries_list      ((u8*)0x02000290)
#define stru_2005780                    ((reqBBS_GUI*)0x02005780)
#define reqBBS_num_requests_sent        ((u8*)0x020065B0)
#define sChief                          ((ChiefStruct*)0x020093B0)
#define reqBBS_tile_data                ((u8*)0x02018204)
#define reqBBS_requestEntries_IDs       ((u8*)0x02023A00)
#define reqBBS_requestNames_textualData ((u8*)0x02025A04)
#define reqBBS_requestInfo_textualData  ((u8*)0x02029A04)
#define reqBBS_dialog_list              ((u16*)0x02033A04)
#define sBtlPlayer                      ((Battle*)0x0203A9B0)
#define sBtlEnemyA                      ((Battle*)0x0203AA88)
#define sBtlEnemyB                      ((Battle*)0x0203AB60)
#define sBtlEnemyC                      ((Battle*)0x0203AC38)


/*
Address  Type        Variable
02000290 u8          reqBBS_requestEntries_list[36]
02005780 reqBBS_GUI  stru_2005780
020065B0 u8          reqBBS_num_requests_sent
020093B0 ChiefStruct sChief
    The Chief struct is a table of pointers to most of the most important structs in the game
02018204 u8          *reqBBS_tile_data
02023A00 u8          reqBBS_requestEntries_IDs[48]
02025A04 u8          *reqBBS_requestNames_textualData
02033A04 u16         *reqBBS_dialog_list
0203A9B0 Battle      sBtlPlayer
0203AA88 Battle      sBtlEnemyA
    Check those values, they may only be valid for gregar?
0203AB60 Battle      sBtlEnemyB
0203AC38 Battle      sBtlEnemyC
02001150  u8 reqBBS_draw_jt1_bxo
02029A04  u8 reqBBS_requestInfo_textOffsets[200]

RAM Data Table*/


#endif // FALZAR
#pragma endregion FALZAR

#pragma region GREGAR
#ifdef GREGAR

/* ROM ------------------------------------------------------------------------------------------- */

/* RAM ------------------------------------------------------------------------------------------- */

#define sChief     ((ChiefStruct*)0x020093B0)
#define sBtlPlayer ((Battle*)0x0203A9B0)
#define sBtlEnemyA ((Battle*)0x0203AA88)
#define sBtlEnemyB ((Battle*)0x0203AB60)
#define sBtlEnemyC ((Battle*)0x0203AC38)


/*
Address  Type        Variable
020093B0 ChiefStruct *sChief
    The Chief struct is a table of pointers to most of the most important structs in the game
0203A9B0 Battle      sBtlPlayer
0203AA88 Battle      sBtlEnemyA
    Check those values, they may only be valid for gregar?
0203AB60 Battle      sBtlEnemyB
0203AC38 Battle      sBtlEnemyC
RAM Data Table*/





#endif // GREGAR
#pragma endregion GREGAR

#endif // DATA_LOCATIONS_H