#ifndef SCRIPT_FALZAR_BIOS_H
#define SCRIPT_FALZAR_BIOS_H

#include "../../include/inttypes.h"
#include "../../Constants/_Constants.h"
#include "../../Structs/_Structs.h"
#include "../../include/IDADefinitions.h"


// VERSION UNIQUE ------------------------------------
#define Bios_UserHandler ((unsigned int (*) ()) (0x03005B00 +1))

#endif // SCRIPT_FALZAR_BIOS_H
