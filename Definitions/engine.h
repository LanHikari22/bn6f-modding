#ifndef DEF_ENGINE_H
#define DEF_ENGINE_H

#include "../include/inttypes.h"
#include "../Constants/_Constants.h"
#include "../Structs/_Structs.h"
#include "../include/IDADefinitions.h"

#define engine_set_screeneffect ((int __fastcall (*) (int result, int a2)) (0x08006270 +1))

#define engine_is_screeneffect_animating ((int (*) ()) (0x080062F8 +1))


#endif // DEF_ENGINE_H
