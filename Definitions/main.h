#ifndef DEF_MAIN_H
#define DEF_MAIN_H

#include "../include/inttypes.h"
#include "../Constants/_Constants.h"
#include "../Structs/_Structs.h"
#include "../include/IDADefinitions.h"

// weird jumpout (testing reading comments with IDAPython)
// for realz
#define main_jumpout_80004A4 ((int (*) ()) (0x080004A4 +1))

#define main_80007B2 ((void (*) ()) (0x080007B2 +1))

#define main_80007BE ((int (*) ()) (0x080007BE +1))

#define main_80015B4 ((int (*) ()) (0x080015B4 +1))

#define main_80017EC ((int (*) ()) (0x080017EC +1))

#define main_80019A0 ((int (*) ()) (0x080019A0 +1))

#define main_80071B4 ((int (*) ()) (0x080071B4 +1))


#endif // DEF_MAIN_H
