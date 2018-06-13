#ifndef DEF_SAVE_H
#define DEF_SAVE_H

#include "../include/inttypes.h"
#include "../Constants/_Constants.h"
#include "../Structs/_Structs.h"
#include "../include/IDADefinitions.h"

#define Save_8006E0E ((int __cdecl (*) (int a1, int a2)) (0x08006E0E +1))

#define Save_8006E26 ((int __fastcall (*) (int result)) (0x08006E26 +1))


#endif // DEF_SAVE_H
