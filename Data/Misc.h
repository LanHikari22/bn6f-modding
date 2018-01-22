#ifndef DATA_MISC_H
#define DATA_MISC_H

#include "../include/inttypes.h"



/* ROM ------------------------------------------------------------------------------------------- */
#define pCoords 			        ((u32*)0x02009F60)  // those are sorta weird
#define pBtlLauncher_navi 	        ((u32*)0x0809A72C)
#define pNPCSprites                 ((u32*)0x08031CDC)
#define pSpriteListSections         ((u32*)0x08031CC4)
#define pSpriteList_Sections0To4    ((u32*)0x08031CEC)



/* RAM ------------------------------------------------------------------------------------------- */
#define sChief                          ((ChiefStruct*)0x020093B0)

/* Docs ------------------------------------------------------------------------------------------ */
/*
Address  Type Variable
WARNING: You need a tool to translate from Macro to Docs.
08031CDC u32  *pNPCSprites
    * Modifying the address of this pointer changes Lan's spirit.
    * But this poitns to an array of addresses of NPC Sprites. So modifying the first entry
    * changes Lan's address.
    * This is an array of pointers to actual data.
    *
08031CC4 u32 *pSpriteListSections
    Contains 10 sections:
    a) 08031CEC
    b) 08031D24
    c) 08031DA4
    d) 08031E00
    e) 08031FA4
    f) 08032114
    g) 08032194 // NPC Sprites, Lan's spirit is also at this location.
    h) 08032314
    i) 08032598
    j) 0803271C
-
ROM*/

/*
RAM*/

#endif // DATA_MISC_H