#ifndef SCRIPT_FALZAR_MAIN_H
#define SCRIPT_FALZAR_MAIN_H

#include "../../include/inttypes.h"
#include "../../Constants/_Constants.h"
#include "../../Structs/_Structs.h"
#include "../../include/IDADefinitions.h"

/**
This is it... The main function!!!
*/
#define main__ ((void __cdecl __noreturn (*) ()) (0x080002BC+1))
#define main_8000454 ((int __fastcall (*) (int a1)) (0x08000454+1))
#define main_80004AA ((int __fastcall (*) (int a1)) (0x080004AA+1))
#define main_8000570 ((__int16 * (*) ()) (0x08000570+1))
#define main_803D1AE ((signed int __fastcall (*) (char a1)) (0x0803D1AE+1))
#define main_803EBC8 ((void * (*) ()) (0x0803EBC8+1))
#define main_803FCF0 ((int (*) ()) (0x0803FCF0+1))

#define main_jumpout_803D1A8 ((signed int (*) ()) (0x0803D1A8+1))
#define main_803DE5C ((u32 * (*) ()) (0x0803DE5C+1))


#endif // SCRIPT_FALZAR_MAIN_H