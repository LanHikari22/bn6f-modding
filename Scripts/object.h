#ifndef SCRIPT_OBJECT_H
#define SCRIPT_OBJECT_H

#include "../include/inttypes.h"

#define object_subtract_hp ((int (*)((int amt)))(0x0800E2D8+1))
#define object_add_hp ((int (*)((int amt)))(0x0800E2EC+1))

#endif // SCRIPT_SPRITE_H