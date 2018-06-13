#ifndef DATA_REQBBS_H
#define DATA_REQBBS_H

#include "../../include/inttypes.h"
#include "../../Structs/reqBBS_GUI.h"

/* ROM ------------------------------------------------------------------------------------------- */
#define reqBBS_draw_jt1             ((void**)0x0813E0CC)
#define reqBBS_entries_graphics     ((u8*)0x0813EF44)
#define reqBBS_textualPointers      ((void**)0x0813F34C)
#define reqBBS_difficultyEntries    ((u8*)0x0813F380)
#define reqBBS_jumpTable            ((void**)0x0813F42C)
#define reqBBS_tiles_checkmark      ((u8*)0x08140238)
#define reqBBS_tiles_yellowIcon     ((u8*)0x08140244)
#define reqBBS_request_ROM_textData ((u8*)0x087EE2F0)
#define reqBBS_texual_shades        ((u8*)0x087EFBC8)

/* RAM ------------------------------------------------------------------------------------------- */
#define reqBBS_requestEntries_list      ((u8*)0x02000290)
#define reqBBS_draw_jt1_bxo             ((u8*)0x02001150)
#define stru_2005780                    ((reqBBS_GUI*)0x02005780)
#define reqBBS_num_requests_sent        ((u8*)0x020065B0)
#define reqBBS_tile_data                ((u8*)0x02018204)
#define reqBBS_requestEntries_IDs       ((u8*)0x02023A00)
#define reqBBS_requestNames_textualData ((u8*)0x02025A04)
#define reqBBS_requestInfo_textOffsets  ((u8*)0x02029A04)
#define reqBBS_dialog_list              ((u16*)0x02033A04)

#endif // DATA_REQBBS_H