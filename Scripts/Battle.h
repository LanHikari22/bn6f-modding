#ifndef SCRIPT_BATTLE_H
#define SCRIPT_BATTLE_H

#include "../include/inttypes.h"
#include "../Constants/_Constants.h"
#include "../Structs/_Structs.h"
#include "../include/IDADefinitions.h"

#define Battle_8005360 ((int __fastcall (*) (int a1, int a2, int a3, int a4, int (__fastcall *a5)) (0x08005360 +1))
#define Battle_is_paused ((int (*) ()) (0x0800A03C +1))
#define Battle_is_timestop ((int (*) ()) (0x0800A098 +1))
#define Battle_is_battle_over ((signed int (*) ()) (0x0800A18E +1))
#define Battle_set_flags ((__int16 __fastcall (*) (__int16 result)) (0x0800A2D8 +1))
#define Battle_clear_flags ((__int16 __fastcall (*) (__int16 result)) (0x0800A2E4 +1))
#define Battle_get_flags ((int (*) ()) (0x0800A2F0 +1))
#define Battle_network_invert ((int __fastcall (*) (int a1)) (0x0800A9EC +1))
#define Battle_clear_enemy_fadein_list ((void (*) ()) (0x0800A9F6 +1))
#define Battle_800C8F0 ((int (*) ()) (0x0800C8F0 +1))
#define Battle_800EC56 ((unsigned __int64 __fastcall (*) (signed int a1)) (0x0800EC56 +1))
#define Battle_801986C ((int (*) ()) (0x0801986C +1))
#define BattleMenu_check_80269E2 ((signed int (*) ()) (0x080269E2 +1))
#define BattleMenu_cb_8026A28 ((int (*) ()) (0x08026A28 +1))
#define BattleMenu_8026A50 ((int (*) ()) (0x08026A50 +1))
#define BattleMenu_8026BF4 ((int (*) ()) (0x08026BF4 +1))
#define BattleMenu_8026DB0 ((int (*) ()) (0x08026DB0 +1))
#define BattleMenu_cp_8026E98 ((int __fastcall (*) (int a1)) (0x08026E98 +1))
#define BattleMenu_cp_8027044 ((int (*) ()) (0x08027044 +1))
#define BattleMenu_cb_80271F8 ((int (*) ()) (0x080271F8 +1))
#define BattleMenu_802721C ((signed int (*) ()) (0x0802721C +1))
#define BattleMenu_802723A ((unsigned int (*) ()) (0x0802723A +1))
#define BattleMenu_cp_802728C ((int (*) ()) (0x0802728C +1))
#define BattleMenu_cp_80273A4 ((int (*) ()) (0x080273A4 +1))
#define BattleMenu_cp_8027406 ((int (*) ()) (0x08027406 +1))
#define BattleMenu_802753E ((int (*) ()) (0x0802753E +1))
#define BattleMenu_8027548 ((int (*) ()) (0x08027548 +1))
#define BattleMenu_cp_80275EC ((int (*) ()) (0x080275EC +1))
#define BattleMenu_cb_802770C ((int (*) ()) (0x0802770C +1))
#define BattleMenu_8027738 ((signed int (*) ()) (0x08027738 +1))
#define BattleMenu_802777C ((int (*) ()) (0x0802777C +1))
#define BattleMenu_8027806 ((int __fastcall (*) (int a1)) (0x08027806 +1))
#define BattleMenu_syscall_8027834 ((int (*) ()) (0x08027834 +1))
#define BattleMenu_802790C ((int (*) ()) (0x0802790C +1))
#define BattleMenu_joystick_802794A ((int (*) ()) (0x0802794A +1))
#define BattleMenu_80279C8 ((int __fastcall (*) (int a1)) (0x080279C8 +1))
#define BattleMenu_cp_8027A58 ((int (*) ()) (0x08027A58 +1))
#define BattleMenu_8027A90 ((int (*) ()) (0x08027A90 +1))


#endif // SCRIPT_BATTLE_H