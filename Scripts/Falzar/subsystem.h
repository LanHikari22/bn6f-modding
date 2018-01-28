#ifndef SCRIPT_FALZAR_SUBSYSTEM_H
#define SCRIPT_FALZAR_SUBSYSTEM_H

#include "../../include/inttypes.h"
#include "../../Constants/_Constants.h"
#include "../../Structs/_Structs.h"
#include "../../include/IDADefinitions.h"

#define subsystem_launch_BBS ((signed int __fastcall (*) (int a1)) (0x08005CE8+1))
/**
freezes for a1 != 0?
*/
#define subsystem_launch_reqBBS ((signed int __fastcall (*) (int BBS_index)) (0x08005D08+1))
#define subsystem_launch_shop ((int __fastcall (*) (int shop_index)) (0x08005D28+1))
#define subsystem_launch_chipTrader ((signed int __fastcall (*) (int a1, int a2)) (0x08005D48+1))
/**
mailbox_index can be 00 or 01
*/
#define subsystem_launch_mail ((int __fastcall (*) (int mailbox_index)) (0x08005EC0+1))



#endif // SCRIPT_FALZAR_SUBSYSTEM_H