#ifndef SCRIPT_RENDER_H
#define SCRIPT_RENDER_H

#include "../include/inttypes.h"
#include "../Constants/_Constants.h"
#include "../Structs/_Structs.h"
#include "../include/IDADefinitions.h"

#define render_80015D0 ((int (*) ()) (0x080015D0 +1))
#define render_800172C ((int (*) ()) (0x0800172C +1))
#define renderPalletes_8001808 ((void (*) ()) (0x08001808 +1))
#define renderPalletes_and_objs_8002650 ((void (*) ()) (0x08002650 +1))
#define render_call_render_30068E8 ((signed int __fastcall (*) (signed int a1, __int16 a2, int a3, int a4)) (0x0802FE28 +1))

#endif // SCRIPT_RENDER_H
