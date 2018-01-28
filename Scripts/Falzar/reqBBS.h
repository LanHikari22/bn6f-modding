#ifndef SCRIPT_FALZAR_REQBBS_H
#define SCRIPT_FALZAR_REQBBS_H

#include "../../include/inttypes.h"
#include "../../Constants/_Constants.h"
#include "../../Structs/_Structs.h"
#include "../../include/IDADefinitions.h"

/**
hyp
*/
#define reqBBS_80384DC ((signed int (*) ()) (0x080384DC+1))
#define reqBBS_draw_813E0F8 ((int (*) ()) (0x0813E0F8+1))
#define reqBBS_draw_813E188 ((void __noreturn (*) ()) (0x0813E188+1))
#define reqBBS_draw_813E224 ((int (*) ()) (0x0813E224+1))
#define reqBBS_draw_813E2AC ((int (*) ()) (0x0813E2AC+1))
#define reqBBS_draw_813E398 ((void __noreturn (*) ()) (0x0813E398+1))
#define reqBBS_draw_813E3F4 ((void __noreturn (*) ()) (0x0813E3F4+1))
#define reqBBS_draw_813E450 ((void __noreturn (*) ()) (0x0813E450+1))
#define reqBBS_draw_813E4AC ((void __noreturn (*) ()) (0x0813E4AC+1))
#define reqBBS_draw_813E4F4 ((void __noreturn (*) ()) (0x0813E4F4+1))
#define reqBBS_813E534 ((int (*) ()) (0x0813E534+1))
#define reqBBS_813E834 ((int (*) ()) (0x0813E834+1))
#define reqBBS_813E890 ((int (*) ()) (0x0813E890+1))
#define reqBBS_draw_chatbox ((int (*) ()) (0x0813ECC0+1))
/**
hyp: it seems to set the header text in boxes?
*/
#define reqBBS_draw_header_text ((int (*) ()) (0x0813ED0C+1))
/**
draws the last selected request' name on the screen in white?
*/
#define reqBBS_813ED40 ((int (*) ()) (0x0813ED40+1))
#define reqBBS_draw_RquestBBS ((int (*) ()) (0x0813EF2C+1))
/**
hyp: whenever this is called, it seems like the reqBBS screen resets to the beginning?
*/
#define reqBBS_init_s_2005780 ((void **__cdecl (*) (int a1)) (0x0813F3C0+1))
/**
exp: r5= 02005780
*/
#define reqBBS_813F474 ((int (*) ()) (0x0813F474+1))
#define reqBBS_813F550 ((void __noreturn (*) ()) (0x0813F550+1))
#define reqBBS_813F5EC ((void __noreturn (*) ()) (0x0813F5EC+1))
#define reqBBS_813F65C ((int (*) ()) (0x0813F65C+1))
#define reqBBS_813F754 ((int (*) ()) (0x0813F754+1))
#define reqBBS_813F7B0 ((void __noreturn (*) ()) (0x0813F7B0+1))
#define reqBBS_813F80C ((void __noreturn (*) ()) (0x0813F80C+1))
#define reqBBS_813F868 ((void __noreturn (*) ()) (0x0813F868+1))
#define reqBBS_813F8B0 ((void __noreturn (*) ()) (0x0813F8B0+1))
#define reqBBS_813F8F0 ((int (*) ()) (0x0813F8F0+1))
#define reqBBS_copy_textData_to_RAM ((void (*) ()) (0x0813F964+1))
#define reqBBS_memory_init_813F9DA ((void (*) ()) (0x0813F9DA+1))
#define reqBBS_memory_init_813F9F8 ((void __fastcall (*) (int a1)) (0x0813F9F8+1))
#define reqBBS_813FA54 ((int (*) ()) (0x0813FA54+1))
#define reqBBS_813FAB0 ((int (*) ()) (0x0813FAB0+1))
#define reqBBS_813FB24 ((int (*) ()) (0x0813FB24+1))
#define reqBBS_813FBC0 ((int (*) ()) (0x0813FBC0+1))
#define reqBBS_813FC8C ((int (*) ()) (0x0813FC8C+1))
#define reqBBS_813FD14 ((void __noreturn (*) ()) (0x0813FD14+1))
#define reqBBS_813FE54 ((int (*) ()) (0x0813FE54+1))
#define reqBBS_813FEB0 ((int (*) ()) (0x0813FEB0+1))
#define reqBBS_render_requestNames ((void *__fastcall (*) (int pagePos)) (0x0813FEEC+1))
#define reqBBS_anim_814004C ((void (*) ()) (0x0814004C+1))
#define reqBBS_render_request_status ((int (*) ()) (0x081401C8+1))
#define reqBBS_render_rankStars ((int (*) ()) (0x0814024C+1))
#define reqBBS_draw_star ((int (*) ()) (0x081402CC+1))
#define reqBBS_814030C ((int (*) ()) (0x0814030C+1))
#define reqBBS_81403C0 ((int __fastcall (*) (int a1, int a2, int a3)) (0x081403C0+1))
#define reqBBS_draw_chatbox_dup ((int (*) ()) (0x081404A0+1))
#define reqBBS_draw_select_chatbox ((int (*) ()) (0x081404B8+1))
#define reqBBS_render_selectedEntry_headerText ((int (*) ()) (0x081404E8+1))
#define reqBBS_set_chatbox_header_basedOn_0F ((int (*) ()) (0x0814051C+1))
/**
changes header text of a BBS chatbox based on something?
hyp
*/
#define reqBBS_change_chatbox_header ((int (*) ()) (0x08140554+1))
#define reqBBS_8140604 ((void __fastcall (*) (int a1, int a2, int a3, int a4)) (0x08140604+1))
#define reqBBS_animate_cursor ((int (*) ()) (0x08140688+1))
#define reqBBS_81408A0 ((unsigned int __fastcall (*) (int ID)) (0x081408A0+1))
#define reqBBS_check_81408F0 ((int __cdecl (*) ()) (0x081408F0+1))
#define reqBBS_run_dialog_8140A70 ((int *__fastcall (*) (int a1, int a2)) (0x08140A5C+1))

#define reqBBS_draw_jt1_callBack ((int (*) ()) (0x0813E0A4+1))
#define reqBBS_draw_813E1C8 ((void __noreturn (*) ()) (0x0813E1C8+1))
#define reqBBS_draw_813E33C ((void __noreturn (*) ()) (0x0813E33C+1))
#define reqBBS_callBack_00 ((int (*) ()) (0x0813F404+1))
#define reqBBS_813F590 ((void __noreturn (*) ()) (0x0813F590+1))
#define reqBBS_813F6F8 ((int (*) ()) (0x0813F6F8+1))
#define reqBBS_813FC30 ((void __noreturn (*) ()) (0x0813FC30+1))
#define reqBBS_jumpout_draw_star ((int __fastcall (*) (int a1, int a2)) (0x081402C8+1))
#define reqBBS_jumpout_8140308 ((int __fastcall (*) (int a1, int a2, int a3, int a4)) (0x08140308+1))
#define reqBBS_get_totalPointsIndex ((int (*) ()) (0x08140798+1))
/**
hyp: totalPointsIndex corresponding to rank
*/
#define reqBBS_rankLessThan ((BOOL __fastcall (*) (int a1)) (0x08140884+1))
#define reqBBS_get_selectedEntry_ID ((int __cdecl (*) ()) (0x081408C8+1))
#define reqBBS_set_selectedEntry_rank_to_0F ((int (*) ()) (0x081408DC+1))
#define reqBBS_GUI_get_0F ((int (*) ()) (0x08140974+1))
#define reqBBS_clear_points_and_rank ((reqBBS_GUI * (*) ()) (0x08140984+1))


#endif // SCRIPT_FALZAR_REQBBS_H