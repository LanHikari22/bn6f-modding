#ifndef DEF_BATTLE_H
#define DEF_BATTLE_H

#include "../include/inttypes.h"
#include "../Constants/_Constants.h"
#include "../Structs/_Structs.h"
#include "../include/IDADefinitions.h"

#define Battle_8005360 ((int (*) ()) (0x08005360 +1))

#define Battle_8007A0C ((signed int (*) ()) (0x08007A0C +1))

#define Battle_is_paused ((int (*) ()) (0x0800A03C +1))

#define Battle_is_timestop ((int (*) ()) (0x0800A098 +1))

#define Battle_is_battle_over ((signed int (*) ()) (0x0800A18E +1))

#define Battle_set_flags ((int __fastcall (*) (int result)) (0x0800A2D8 +1))

#define Battle_clear_flags ((int __fastcall (*) (int result)) (0x0800A2E4 +1))

#define Battle_get_flags ((int (*) ()) (0x0800A2F0 +1))

#define Battle_network_invert ((int __fastcall (*) (int a1)) (0x0800A9EC +1))

#define Battle_clear_enemy_fadein_list ((void (*) ()) (0x0800A9F6 +1))

#define Battle_800C8F0 ((int (*) ()) (0x0800C8F0 +1))

#define Battle_800EC56 ((signed __int64 __fastcall (*) (signed int a1)) (0x0800EC56 +1))

#define Battle_801986C ((int (*) ()) (0x0801986C +1))


#endif // DEF_BATTLE_H
