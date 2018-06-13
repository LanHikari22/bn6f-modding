#ifndef DEF_GREGAR_MAIN_H
#define DEF_GREGAR_MAIN_H

#include "../../include/inttypes.h"
#include "../../Constants/_Constants.h"
#include "../../Structs/_Structs.h"
#include "../../include/IDADefinitions.h"

#define main_jumpout_80004A4 ((signed int (*) ()) (0x080004A4 +1))

#define main_803DE30 ((int * (*) ()) (0x0803DE30 +1))


#endif // DEF_GREGAR_MAIN_H
