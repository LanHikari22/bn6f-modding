#ifndef SCRIPT_FALZAR_OBJECT_H
#define SCRIPT_FALZAR_OBJECT_H

#include "../../include/inttypes.h"
#include "../../Constants/_Constants.h"
#include "../../Structs/_Structs.h"
#include "../../include/IDADefinitions.h"

#define object_800E2FC ((signed int __fastcall (*) (int a1, int a2)) (0x0800E2FC +1))
#define object_spawn_hiteffect ((int (*) ()) (0x0800EB9E +1))

#define object_update_panel_parameters ((void __noreturn (*) ()) (0x0800C928 +1))
#define object_is_current_panel_solid ((void __noreturn (*) ()) (0x0800CCA6 +1))
#define object_jumpout_800E2CA ((int (*) ()) (0x0800E2CA +1))


#endif // SCRIPT_FALZAR_OBJECT_H