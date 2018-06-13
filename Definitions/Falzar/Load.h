#ifndef DEF_FALZAR_LOAD_H
#define DEF_FALZAR_LOAD_H

#include "../../include/inttypes.h"
#include "../../Constants/_Constants.h"
#include "../../Structs/_Structs.h"
#include "../../include/IDADefinitions.h"


// VERSION UNIQUE ------------------------------------
#define Load_8000F86 ((int __fastcall (*) (int a1)) (0x08000F86 +1))

#define Load_8006E3C ((int __fastcall (*) (int result)) (0x08006E3C +1))

#define Load_cb_802F544 ((int (*) ()) (0x0802F544 +1))

#define Load_802FD54 ((int (*) ()) (0x0802FD54 +1))

#define Load_803E978 ((signed int (*) ()) (0x0803E978 +1))

#define Load_803F838 ((int __cdecl (*) ()) (0x0803F838 +1))


// VERSION DEPENDENT ---------------------------------
#define Load_803E938 ((signed int (*) ()) (0x0803E938 +1))

#define Load_803E964 ((int (*) ()) (0x0803E964 +1))

#define Load_803EA1C ((int __fastcall (*) (int a1)) (0x0803EA1C +1))


#endif // DEF_FALZAR_LOAD_H
