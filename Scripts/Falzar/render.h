#ifndef SCRIPT_FALZAR_RENDER_H
#define SCRIPT_FALZAR_RENDER_H

#include "../../include/inttypes.h"
#include "../../Constants/_Constants.h"
#include "../../Structs/_Structs.h"
#include "../../include/IDADefinitions.h"


// VERSION UNIQUE ------------------------------------
#define render_30068E8 ((signed int __fastcall (*) (signed int result, __int16 a2, int a3, int a4)) (0x030068E8 +1))
#define render_background_gfx ((int __cdecl (*) ()) (0x080304E8 +1))

// VERSION DEPENDENT ---------------------------------
#define render_graphicalText_8045F8C ((int __fastcall (*) (void *p1, int text_off, int a3, int a4)) (0x08045F8C +1))

#endif // SCRIPT_FALZAR_RENDER_H
