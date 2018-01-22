#ifndef SCRIPT_CHATBOX_H
#define SCRIPT_CHATBOX_H

#include "../../include/inttypes.h"

/**
 * Runs the Chatbox program based on a structure passed to it
 * r5_sNPC may be NULL, in that case a preselected NPC on the map is used.
 * @param r5_sNPC An NPC object within the map. If available, its script plays.
 */
#define fpRunChatbox ((void (*)())(0x080A0058+1))

#define chatbox_run_script ((void (*)(u16 *scriptList, u16 offset))(0x08040358+1))

#define chatbox_interprete_script_char ((void (*)())(0x0803FF24+1))


#endif // SCRIPT_CHATBOX_H