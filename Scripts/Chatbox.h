#ifndef SCRIPT_CHATBOX_H
#define SCRIPT_CHATBOX_H

#include "../include/inttypes.h"

#define chatbox_run_script ((void (*)(u16 *scriptList, u16 offset))(0x08040384+1)) // 0x08040358 (diff: 0x2C)

#define run_train_script ((void (*)(int scriptListOffset))(0x8040374+1))


#endif // SCRIPT_CHATBOX_H