#ifndef SCRIPT_CHECK_H
#define SCRIPT_CHECK_H

#include "../include/inttypes.h"
#include "../Constants/_Constants.h"
#include "../Structs/_Structs.h"
#include "../include/IDADefinitions.h"

/**
returns... zf
*/
#define check_802F168 ((int __cdecl (*) (int a1)) (0x0802F168 +1))


#endif // SCRIPT_CHECK_H