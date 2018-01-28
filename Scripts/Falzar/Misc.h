#ifndef SCRIPT_MISC_H
#define SCRIPT_MISC_H

#include "../../include/inttypes.h"



#define testfunc ((int (*)(int a1, int a2))(0x802F164+1))

// #define __main ((void (*)())(0x080002BC+1))

// #define render_background_gfx ((int (*)())(0x080304E8+1))

/* unnamed */

// Involved with a lot. Might have to do with loading data in game state/ launching menus... Chatbox too????
// #define sub_8006E50 ((int (*)())(0x08006E50+1))

// Very long... Seems super involved. Zennies? Bugs? And the reqBBS?? Battle?
// #define sub_8004DF0 ((int (*)())(0x08004DF0+1))

// A simple chiefstruct function to analyze (sub_802F164 is based on it)
// When disabled, you get stuck in an infinite mail box!
// #define sub_802F168 ((void (*)(unsigned int a1))(0x802F168+1))

// Cutscene related function?!
// #define sub_803851C ((void (*)())(0x0803851C+1))

// A BBS Function Detected through access data.
// #define sub_814084C ((void (*)(int a1))(0x814084C+1))

// #define sub_803FE10 ((void (*)(u16 *scriptList, u16 offset))(0x803FE10+1))

// calls Chatbox_run_script and glitches screen?
// #define sub_803FE74 ((void (*)(u16 *scriptList, u16 offset))(0x803FE74+1))

// Nostalgic function pffft
// :0800117C calcAngle

#endif // SCRIPT_LOAD_H