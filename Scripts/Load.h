#ifndef SCRIPT_LOAD_H
#define SCRIPT_LOAD_H

#include "../include/inttypes.h"
#include "../Constants/_Constants.h"
#include "../Structs/_Structs.h"
#include "../include/IDADefinitions.h"

#define Load_802F704 ((int __fastcall (*) (int a1, int a2, int a3)) (0x0802F704 +1))
#define Load_802F88E ((int (*) ()) (0x0802F88E +1))
#define Load_802F994 ((int __fastcall (*) (int a1)) (0x0802F994 +1))
#define Load_802F9EC ((int __fastcall (*) (int a1)) (0x0802F9EC +1))
#define Load_802FB10 ((int (*) ()) (0x0802FB10 +1))
#define Load_802FCC0 ((void *__fastcall (*) (int a1, int a2, int a3, int a4)) (0x0802FCC0 +1))
#define Load_802FD3C ((int (*) ()) (0x0802FD3C +1))


#endif // SCRIPT_LOAD_H