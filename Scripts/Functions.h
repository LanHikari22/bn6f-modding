#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <inttypes.h>

#pragma region FALZAR
#ifdef FALZAR

#define testfunc ((int (*)(int a1, int a2))(0x802F164+1))


/* sound */
#define sound_play ((void (*)(int a1, int a2, int a3))(0x080005CC+1))

/* sprite */
#define sprite_load_animation_data ((void (*)())(0x080026A4+1))

/* chatbox */
#define chatbox_run_script ((void (*)(u16 *scriptList, u16 offset))(0x08040384+1)) // 0x08040358 (diff: 0x2C)

#define run_train_script ((void (*)(int scriptListOffset))(0x8040374+1))

/* reqBBS */
#define reqBBS_get_selectedEntry_ID ((int (*)())(0x081408C8+1))
// might return a status of some sort?
#define reqBBS_81408F0 ((int (*)())(0x081408F0+1))


/* subsystem */
#define subsystem_launch_reqBBS ((signed int (*)(int a1))(0x8005D08+1))
#define subsystem_launch_mail   ((signed int (*)(int a1))(0x8005EC0+1))
#define subsystem_launch_BBS    ((signed int (*)(int a1))(0x8005CE8+1))


/* Bios Functions */
#define CpuFastSet ((void (*)(void *src, void *dest, int mode))(0x0814D8B4+1))
#define CpuSet ((void (*)(void *src, void *dest, int mode))(0x0814D8B8+1))
#define CpuSet_ZeroFillWord ((void (*)((void* memBlock, unsigned int numWords))(0x080008E0+1))

/* Memory */
#define init_memblock_to_byte ((void (*)(u8 *memblock, int size, char initByte))(0x08000964+1))

/* unnamed */

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