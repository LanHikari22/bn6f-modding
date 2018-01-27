#ifndef SCRIPT_CHATBOX_H
#define SCRIPT_CHATBOX_H

#include "../../include/inttypes.h"

#define Chatbox_onUpdate_803FEB4 ((int (*)())(0x0803FEB4+1)) // 0x08040358 (diff: 0x2C)

#define chatbox_run_script ((void (*)(u16 *scriptList, u16 offset))(0x08040384+1)) // 0x08040358 (diff: 0x2C)
#define Chatbox_loadObjScripts_0803FD08 ((int (*)())(0x0803FD08+1))

#define run_train_script ((void (*)(int scriptListOffset))(0x8040374+1))


#endif // SCRIPT_CHATBOX_H