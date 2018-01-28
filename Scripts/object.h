#ifndef SCRIPT_OBJECT_H
#define SCRIPT_OBJECT_H

#include "../include/inttypes.h"
#include "../Constants/_Constants.h"
#include "../Structs/_Structs.h"
#include "../include/IDADefinitions.h"

#define object_get_panel_parameters ((int __fastcall (*) (int a1, int a2)) (0x0800C8F8+1))
#define object_crack_panel ((signed int __fastcall (*) (int a1, int a2)) (0x0800C938+1))
#define object_crack_panel_dup1 ((void __fastcall __noreturn (*) (int a1, int a2)) (0x0800C998+1))
#define object_break_panel ((void __fastcall __noreturn (*) (int a1, int a2)) (0x0800C9F8+1))
#define object_break_panel_dup1 ((void __fastcall __noreturn (*) (int a1, int a2)) (0x0800CA34+1))
#define object_break_panel_dup2 ((void __fastcall __noreturn (*) (int a1, int a2)) (0x0800CA8C+1))
#define object_break_panel_dup3 ((void __fastcall __noreturn (*) (int a1, int a2)) (0x0800CAE8+1))
#define object_break_panel_loud ((void __fastcall __noreturn (*) (int a1, int a2)) (0x0800CB44+1))
#define object_panel_set_poison ((void __fastcall __noreturn (*) (int a1, int a2)) (0x0800CBA0+1))
#define object_highlight_panel ((void __spoils<R2,R3,R12> (*) ()) (0x0800CBD8+1))
#define object_highlight_panel_blue ((void __spoils<R2,R3,R12> (*) ()) (0x0800CBEE+1))
#define object_set_panel_type ((void __noreturn (*) ()) (0x0800CC0A+1))
#define object_set_panel_alliance ((void __fastcall __noreturn (*) (int a1)) (0x0800CC14+1))
#define object_800E2AC ((int (*) ()) (0x0800E2AC+1))
#define object_subtract_hp ((int __fastcall (*) (int amt)) (0x0800E2D8+1))
#define object_add_hp ((int __fastcall (*) (int amt)) (0x0800E2EC+1))
#define object_calculate_final_damage2 ((void __noreturn (*) ()) (0x0800E420+1))
#define object_can_move ((BOOL (*) ()) (0x0800E5E2+1))
#define object_set_counter_time ((int __fastcall (*) (int result)) (0x0800E9DC+1))
#define object_set_invulnerable_time ((int __fastcall (*) (__int16 a1)) (0x0800EAFA+1))
#define object_get_enemy_by_name_range ((int __fastcall (*) (_DWORD *a1, int a2, int a3, int a4)) (0x0800EBD4+1))
#define object_create_ai_data ((ChatBoxPropreties * (*) ()) (0x0800ED2C+1))
#define object_set_flag ((int __fastcall (*) (int result)) (0x0801A152+1))
#define object_clear_flag ((int __fastcall (*) (int result)) (0x0801A15C+1))
#define object_get_flag ((int (*) ()) (0x0801A166+1))


#endif // SCRIPT_OBJECT_H