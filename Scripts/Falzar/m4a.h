#ifndef SCRIPT_FALZAR_M4A_H
#define SCRIPT_FALZAR_M4A_H

#include "../../include/inttypes.h"
#include "../../Constants/_Constants.h"
#include "../../Structs/_Structs.h"
#include "../../include/IDADefinitions.h"


// VERSION UNIQUE ------------------------------------
#define m4a_814E950 ((int __fastcall (*) (int musicOffset)) (0x0814E950 +1))
#define m4a_playBG_noreset_814E99C ((int __fastcall (*) (int a1)) (0x0814E99C +1))

// VERSION DEPENDENT ---------------------------------
#define m4a_SongNumStart ((int __fastcall (*) (int a1)) (0x0814E924 +1))
#define m4a_814E9F0 ((int __fastcall (*) (int a1)) (0x0814E9F0 +1))
#define m4a_814EA24 ((int __fastcall (*) (int a1)) (0x0814EA24 +1))
#define m4a_814F104 ((int __fastcall (*) (int a1, unsigned __int8 *a2)) (0x0814F104 +1))

#endif // SCRIPT_FALZAR_M4A_H
