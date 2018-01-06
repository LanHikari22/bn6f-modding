#ifndef SCRIPT_SOUND_H
#define SCRIPT_SOUND_H

#include "../include/inttypes.h"

#define sound_play ((void (*)(int a1, int a2, int a3))(0x080005CC+1))

#endif // SCRIPT_SOUND_H