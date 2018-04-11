#ifndef SCRIPT_SPRITE_H
#define SCRIPT_SPRITE_H

#include "../include/inttypes.h"
#include "../Constants/_Constants.h"
#include "../Structs/_Structs.h"
#include "../include/IDADefinitions.h"

#define sprite_load_animation_data ((int (*) ()) (0x080026A4 +1))
#define sprite_make_unscalable ((int (*) ()) (0x08002D52 +1))
#define sprite_set_pallete ((int __fastcall (*) (int result)) (0x08002D80 +1))

#endif // SCRIPT_SPRITE_H
