#ifndef SCRIPT_FALZAR_CHATBOX_H
#define SCRIPT_FALZAR_CHATBOX_H

#include "../../include/inttypes.h"
#include "../../Constants/_Constants.h"
#include "../../Structs/_Structs.h"
#include "../../include/IDADefinitions.h"


// VERSION UNIQUE ------------------------------------
#define Chatbox_loadObjScripts_0803FD08 ((int (*) ()) (0x0803FD08 +1))
#define Chatbox_uncomp_lmsgdialog_803fd3c ((int (*) ()) (0x0803FD3C +1))
#define Chatbox_uncomp_803FD54 ((int (*) ()) (0x0803FD54 +1))
#define Chatbox_803FD78 ((int __fastcall (*) (u16 *a1, int a2)) (0x0803FD78 +1))
#define Chatbox_803FD9C ((int __fastcall (*) (u16 *a1, int a2)) (0x0803FD9C +1))
#define Chatbox_runScript_803FE10 ((int *__fastcall (*) (u16 *scriptList, int offset)) (0x0803FE10 +1))
/*Dunno how to form complete function*/
#define Chatbox_runScript_803FE74 ((void __fastcall (*) (u16 *a1, int a2)) (0x0803FE74 +1))
#define Chatbox_onUpdate_803FEB4 ((int __cdecl (*) ()) (0x0803FEB4 +1))
#define Chatbox_interprete_script_char ((int (*) ()) (0x0803FF50 +1))
#define Chatbox_804005C ((signed int (*) ()) (0x0804005C +1))
#define Chatbox_804021C ((signed int (*) ()) (0x0804021C +1))
#define Chatbox_8040344 ((int (*) ()) (0x08040344 +1))
#define Chatbox_runScript ((int *__fastcall (*) (u16 *scriptList, int offset)) (0x08040384 +1))
#define Chatbox_reqBSS_80404C0 ((void __fastcall (*) (int a1, int a2)) (0x080404C0 +1))
#define Chatbox_80405F8 ((int __fastcall (*) (u16 *a1, int a2, int a3, int a4)) (0x080405F8 +1))
#define Chatbox_8040818 ((int (*) ()) (0x08040818 +1))
#define Chatbox_804082C ((int (*) ()) (0x0804082C +1))
#define Chatbox_80409E0 ((void (*) ()) (0x080409E0 +1))
#define Chatbox_8040B8C ((int (*) ()) (0x08040B8C +1))
#define Chatbox_8040CD0 ((void (*) ()) (0x08040CD0 +1))
#define Chatbox_8040DBC ((void (*) ()) (0x08040DBC +1))
#define Chatbox_8040DDC ((void __fastcall (*) (int a1)) (0x08040DDC +1))
/*exp: r5= 02009CD0 (chatbox)*/
#define Chatbox_e6_cb ((int (*) ()) (0x08040E98 +1))
#define Chatbox_8041090 ((signed int (*) ()) (0x08041090 +1))
#define Chatbox_804110C ((signed int (*) ()) (0x0804110C +1))
#define Chatbox_8041adc ((signed int (*) ()) (0x08041ADC +1))
#define Chatbox_8041ba4 ((signed int (*) ()) (0x08041BA4 +1))
#define Chatbox_8041bd8 ((signed int (*) ()) (0x08041BD8 +1))
#define Chatbox_8041c84 ((signed int __fastcall (*) (int a1, int a2, int a3, int a4)) (0x08041C84 +1))
#define Chatbox_8041cf4 ((signed int (*) ()) (0x08041CF4 +1))
#define Chatbox_8041dbc ((signed int (*) ()) (0x08041DBC +1))
#define Chatbox_8041DF4 ((int __fastcall (*) (int a1, int a2, int a3, int a4, int (__fastcall *a5)) (0x08041DF4 +1))
#define Chatbox_8041EB0 ((signed int (*) ()) (0x08041EB0 +1))
#define Chatbox_8041EE8 ((int (*) ()) (0x08041EE8 +1))
#define Chatbox_8041F10 ((signed int __fastcall (*) (int a1)) (0x08041F10 +1))
#define Chatbox_8041F1C ((BOOL (*) ()) (0x08041F1C +1))
#define Chatbox_8041F44 ((int (*) ()) (0x08041F44 +1))
#define Chatbox_8041FB4 ((signed int (*) ()) (0x08041FB4 +1))
#define Chatbox_80420BC ((signed int (*) ()) (0x080420BC +1))
#define Chatbox_8042128 ((signed int (*) ()) (0x08042128 +1))
#define Chatbox_80421D8 ((signed int (*) ()) (0x080421D8 +1))
#define Chatbox_804222C ((signed int (*) ()) (0x0804222C +1))
#define Chatbox_fb_givechip ((signed int (*) ()) (0x08042418 +1))
#define Chatbox_fb_startrandomencounter ((int (*) ()) (0x0804244C +1))
#define Chatbox_fb_startbattle ((int (*) ()) (0x0804247C +1))
#define Chatbox_fb_openshop ((int (*) ()) (0x080424BC +1))
#define Chatbox_fb_chiptrader ((signed int (*) ()) (0x080424E0 +1))
#define Chatbox_fb_restorehp ((int (*) ()) (0x0804252C +1))
#define Chatbox_fb_openbbs ((int (*) ()) (0x08042580 +1))
#define Chatbox_fb_80425a0 ((int (*) ()) (0x080425A0 +1))
/*Can be launched through dialog script:
FB 0E (found in r4:pScriptCursor)
This function is jumpTable_3[0x0E]
*/
#define Chatbox_fb_openrequestbss ((int (*) ()) (0x080425C0 +1))
#define Chatbox_fb_setextrafolder ((int (*) ()) (0x080425E0 +1))
#define Chatbox_fb_openmailbox ((int (*) ()) (0x080425F0 +1))
#define Chatbox_Save_8042678 ((signed int (*) ()) (0x08042678 +1))
#define Chatbox_run_8098370 ((int (*) ()) (0x08098370 +1))
#define Chatbox_run_lmsg_8099218 ((int __fastcall (*) (int a1)) (0x08099218 +1))
/*is this really in the chatbox module, though?*/
#define Chatbox_809E14C ((int __fastcall (*) (char a1)) (0x0809E14C +1))

// VERSION DEPENDENT ---------------------------------
#define Chatbox_run_script_202da04 ((int *__fastcall (*) (int a1)) (0x0803FD68 +1))
#define Chatbox_runScript_803FE08 ((void (*) ()) (0x0803FE08 +1))
#define Chatbox_8040154 ((int (*) ()) (0x08040154 +1))
#define Chatbox_run_train_script ((int *__fastcall (*) (int scriptListOffset)) (0x08040374 +1))
#define Chatbox_8040730 ((int  (*) (*__fastcall(int a1)) (0x08040730 +1))
#define Chatbox_8040794 ((int (*) ()) (0x08040794 +1))
#define Chatbox_80407C8 ((int (*) ()) (0x080407C8 +1))
#define Chatbox_set_flags_3e ((int __fastcall (*) (int result)) (0x08040920 +1))
#define Chatbox_clear_flags_3e ((int __fastcall (*) (int result)) (0x0804092C +1))
#define Chatbox_mask_flags_3e ((int __fastcall (*) (unsigned __int16 a1)) (0x08040938 +1))
#define Chatbox_8040C44 ((void (*) ()) (0x08040C44 +1))
#define Chatbox_8040C9C ((void (*) ()) (0x08040C9C +1))
#define Chatbox_8040D5C ((int __fastcall (*) (int a1, int a2)) (0x08040D5C +1))
/*hyp: not E5???*/
#define Chatbox_e5_cb ((signed int (*) ()) (0x08040E90 +1))
#define Chatbox_e7_cb ((int (*) ()) (0x08040EF4 +1))
#define Chatbox_804103E ((signed int (*) ()) (0x0804103E +1))
#define Chatbox_80410F8 ((signed int (*) ()) (0x080410F8 +1))
#define Chatbox_e9_cb ((int (*) ()) (0x08041134 +1))
#define Chatbox_ea_cb ((signed int (*) ()) (0x08041160 +1))
#define Chatbox_eb_cb ((signed int (*) ()) (0x08041244 +1))
#define Chatbox_ec_cb ((signed int (*) ()) (0x08041288 +1))
#define Chatbox_8041c54 ((signed int (*) ()) (0x08041C54 +1))
#define Chatbox_jt3_callback ((int (*) ()) (0x08041E80 +1))
#define Chatbox_jt2_callback ((int (*) ()) (0x08041F68 +1))
#define Chatbox_8042184 ((void (*) ()) (0x08042184 +1))
#define Chatbox_804228C ((void (*) ()) (0x0804228C +1))
#define Chatbox_cb_8042290 ((int (*) ()) (0x08042290 +1))
/*# determined while launching reqBBS from asterland
exp: r4= 020336E0 (pScriptCursor)
This is called trhough dialog script: FB 0E*/
#define Chatbox_fb_modecallback ((int (*) ()) (0x08042388 +1))
#define Chatbox_jt1_callback ((int (*) ()) (0x08042610 +1))
#define Chatbox_8042830 ((int (*) ()) (0x08042830 +1))
#define Chatbox_8042cf8 ((int (*) ()) (0x08042CF8 +1))
#define Chatbox_8042fd8 ((int (*) ()) (0x08042FD8 +1))
#define Chatbox_8043020 ((int (*) ()) (0x08043020 +1))

#endif // SCRIPT_FALZAR_CHATBOX_H
