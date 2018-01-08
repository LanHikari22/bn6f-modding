#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../include/inttypes.h"
#include "Bios.h"
#include "Chatbox.h"
#include "Memory.h"
#include "NPC.h"
#include "reqBBS.h"
#include "Save.h"
#include "Sound.h"
#include "Sprite.h"
#include "subsystem.h"


#pragma region FALZAR
#ifdef FALZAR

#define testfunc ((int (*)(int a1, int a2))(0x802F164+1))

/* unnamed */

// Involved with a lot. Might have to do with loading data in game state/ launching menus... Chatbox too????
#define sub_8006E50 ((int (*)())(0x08006E50+1))

// Very long... Seems super involved. Zennies? Bugs? And the reqBBS?? Battle?
#define sub_8004DF0 ((int (*)())(0x08004DF0+1))

// A simple chiefstruct function to analyze (sub_802F164 is based on it)
// When disabled, you get stuck in an infinite mail box!
#define sub_802F168 ((void (*)(unsigned int a1))(0x802F168+1))

// Cutscene related function?!
#define sub_803851C ((void (*)())(0x0803851C+1))

// A BBS Function Detected through access data.
#define sub_814084C ((void (*)(int a1))(0x814084C+1))

#define sub_803FE10 ((void (*)(u16 *scriptList, u16 offset))(0x803FE10+1))

// calls chatbox_run_script and glitches screen?
#define sub_803FE74 ((void (*)(u16 *scriptList, u16 offset))(0x803FE74+1))

#endif // FALZAR
#pragma endregion FALZAR

#pragma region GREGAR
#ifdef GREGAR
/**
 * Runs the Chatbox program based on a structure passed to it
 * r5_sNPC may be NULL, in that case a preselected NPC on the map is used.
 * @param r5_sNPC An NPC object within the map. If available, its script plays.
 */
#define fpRunChatbox ((void (*)())(0x080A0058+1))

#define chatbox_run_script ((void (*)(u16 *scriptList, u16 offset))(0x08040358+1))

#define chatbox_interprete_script_char ((void (*)())(0x0803FF24+1))
 

/**
 * This might be only for multiplayer. It might also do more.
 * TODO: investigate this function
 */
#define fpGenBattleStageAndBackgrounds ((void (*)())(0x081209DC+1))
/*
 * Modified first word in 0x02034880 to 0x00001400
 * Exits battles very nicely. If battling someone, a You-Lost scene plays too.
 */
#define fpEndBattleNoGM ((void (*)())(0x0800AABC+1))

#define apply_NCP_effect ((void (*)())(0x0801379F+1))

#define u8Arrayo_u32 ((void (*)())(0x080A0B3A+1))
#endif // GREGAR
#pragma endregion GREGAR

#endif // FUNCTIONS_H