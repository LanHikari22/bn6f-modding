#ifndef DATA_LOCATIONS_H
#define DATA_LOCATIONS_H

#include "../../inttypes.h"
#include "../version.h"

#ifdef FALZAR

#define jumpTable_2                     ((void**)0x080045BC)
#define jumpTable_0                     ((void**)0x0809E6A4)
#define jumpTable_1                     ((void**)0x0809EC30)
#define BBS_asterland_textualPointers   ((void**)0x0813F34C)
#define BBS_asterland_difficultyEntries ((u8*)0x0813F380)
#define BBS_asterland_jumpTable         ((void**)0x0813F42C)

/*
    Address  Type   Variable
    080045BC void   *jumpTable_2[1]
    0809E6A4 void   *jumpTable_0[7]
    0809EC30 void   *jumpTable_1[81]
    0813F34C void   *BBS_asterland_textualPointers[2]
    0813F380 u8     BBS_asterland_difficultyEntries[0x64]
    0813F42C void   *BBS_asterland_jumpTable[18]

Data Table*/

#endif // FALZAR

#endif // DATA_LOCATIONS_H