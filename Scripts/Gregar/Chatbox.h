#ifndef SCRIPT_GREGAR_CHATBOX_H
#define SCRIPT_GREGAR_CHATBOX_H

#include "../../include/inttypes.h"
#include "../../Constants/_Constants.h"
#include "../../Structs/_Structs.h"
#include "../../include/IDADefinitions.h"

#define Chatbox_run_script_202da04 ((int *__fastcall (*) (int a1)) (0x0803FD3C +1))
#define Chatbox_runScript_803FD70 ((void (*) ()) (0x0803FD70 +1))
#define Chatbox_8040128 ((int (*) ()) (0x08040128 +1))
#define Chatbox_run_train_script ((int *__fastcall (*) (int scriptListOffset)) (0x08040348 +1))
#define Chatbox_8040704 ((int  (*) (*__fastcall(int a1)) (0x08040704 +1))
#define Chatbox_8040768 ((int (*) ()) (0x08040768 +1))
#define Chatbox_804079C ((int (*) ()) (0x0804079C +1))
#define Chatbox_set_flags_3e ((int __fastcall (*) (int result)) (0x080408F4 +1))
#define Chatbox_clear_flags_3e ((int __fastcall (*) (int result)) (0x08040900 +1))
#define Chatbox_mask_flags_3e ((int __fastcall (*) (unsigned __int16 a1)) (0x0804090C +1))
#define Chatbox_8040C18 ((void (*) ()) (0x08040C18 +1))
#define Chatbox_8040C70 ((void __spoils<> (*) ()) (0x08040C70 +1))
#define Chatbox_8040D30 ((int __fastcall (*) (int a1, int a2)) (0x08040D30 +1))
/**
hyp: not E5???
*/
#define Chatbox_e5_cb ((signed int (*) ()) (0x08040E64 +1))
#define Chatbox_e7_cb ((int (*) ()) (0x08040EC8 +1))
#define Chatbox_8041012 ((signed int (*) ()) (0x08041012 +1))
#define Chatbox_80410CC ((signed int (*) ()) (0x080410CC +1))
#define Chatbox_e9_cb ((int (*) ()) (0x08041108 +1))
#define Chatbox_ea_cb ((signed int (*) ()) (0x08041134 +1))
#define Chatbox_eb_cb ((signed int (*) ()) (0x08041218 +1))
#define Chatbox_ec_cb ((signed int (*) ()) (0x0804125C +1))
#define Chatbox_8041c54 ((signed int (*) ()) (0x08041C24 +1))
#define Chatbox_jt3_callback ((int (*) ()) (0x08041540 +1))
#define Chatbox_jt2_callback ((int (*) ()) (0x08041540 +1))
#define Chatbox_8042154 ((signed int (*) ()) (0x08042154 +1))
#define Chatbox_804225C ((void (*) ()) (0x0804225C +1))
#define Chatbox_cb_8041540 ((int (*) ()) (0x08041540 +1))
/**
# determined while launching reqBBS from asterland
exp: r4= 020336E0 (pScriptCursor)
This is called trhough dialog script: FB 0E
*/
#define Chatbox_fb_modecallback ((int (*) ()) (0x08041540 +1))
#define Chatbox_jt1_callback ((int (*) ()) (0x08041540 +1))
#define Chatbox_8041540 ((int (*) ()) (0x08041540 +1))
#define Chatbox_8042cf8 ((int (*) ()) (0x08041540 +1))
#define Chatbox_8042fd8 ((int (*) ()) (0x08041540 +1))
#define Chatbox_8041540 ((int (*) ()) (0x08041540 +1))


#endif // SCRIPT_GREGAR_CHATBOX_H