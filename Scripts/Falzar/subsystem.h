#ifndef SCRIPT_SUB_SYSTEM_H
#define SCRIPT_SUB_SYSTEM_H

#include "../../include/inttypes.h"

#define subsystem_launch_reqBBS ((signed int (*)(int a1))(0x8005D08+1))
#define subsystem_launch_mail   ((signed int (*)(int a1))(0x8005EC0+1))
#define subsystem_launch_BBS    ((signed int (*)(int a1))(0x8005CE8+1))

#endif //SCRIPT_SUB_SYSTEM_H