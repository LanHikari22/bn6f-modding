#ifndef SCRIPT_GREGAR_OBJECT_H
#define SCRIPT_GREGAR_OBJECT_H

#include "../../include/inttypes.h"
#include "../../Constants/_Constants.h"
#include "../../Structs/_Structs.h"
#include "../../include/IDADefinitions.h"

#define object_update_panel_parameters ((void __noreturn (*) ()) (0x0800024C +1))
#define object_is_current_panel_solid ((void __noreturn (*) ()) (0x0800CC66 +1))
#define object_jumpout_8005246 ((int (*) ()) (0x08005246 +1))


#endif // SCRIPT_GREGAR_OBJECT_H