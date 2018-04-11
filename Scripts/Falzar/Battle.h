#ifndef SCRIPT_FALZAR_BATTLE_H
#define SCRIPT_FALZAR_BATTLE_H

#include "../../include/inttypes.h"
#include "../../Constants/_Constants.h"
#include "../../Structs/_Structs.h"
#include "../../include/IDADefinitions.h"


// VERSION UNIQUE ------------------------------------
#define Battle_renderViruses_80029A8 ((int __fastcall (*) (_BYTE *a1, int a2, int a3, int a4, char *a5, int a6, int *a7, int a8, int *a9)) (0x080029A8 +1))
#define Battle_80052D8 ((int __fastcall (*) (int a1, int a2, int a3, int a4, int (__fastcall *a5)) (0x080052D8 +1))
#define Battle_render_panelGfx_80075CA ((void __fastcall (*) (int a1, int a2, int a3, int a4, int a5, int (*a6)) (0x080075CA +1))
#define Battle_801E574 ((void __fastcall (*) (int a1, int a2, int a3, int a4, int a5, int a6, int a7, int (__fastcall *a8)) (0x0801E574 +1))
#define BattleMenu_8026A6C ((int __fastcall (*) (int a1, int a2, int a3, int a4, int (__fastcall *a5)) (0x08026A6C +1))
#define BattleMenu_cb_8026A88 ((int __cdecl (*) ()) (0x08026A88 +1))
#define BattleMenu_joystick_8026CCC ((int __fastcall (*) (int a1, int a2, int a3, int a4, int a5, int (*a6)) (0x08026CCC +1))
#define BattleMenu_8026D06 ((int __fastcall (*) (int a1, int a2, int a3, int a4, int a5, int a6, int (__fastcall *a7)) (0x08026D06 +1))
#define BattleMenu_8026DC4 ((int __fastcall (*) (int a1, int a2, int a3, int a4, int (*a5)) (0x08026DC4 +1))
#define BattleMenu_8026E4C ((int __fastcall (*) (int a1, int a2, int a3, int a4, int (__fastcall *a5)) (0x08026E4C +1))
#define BattleMenu_8026E78 ((int __fastcall (*) (int a1, int a2, int a3, int a4, int (__fastcall *a5)) (0x08026E78 +1))
#define BattleMenu_Chatbox_8026FC0 ((int *__fastcall (*) (int a1, int a2, int a3, int a4, int a5, int (__fastcall *a6)) (0x08026FC0 +1))
#define BattleMenu_80273EC ((int __fastcall (*) (int a1, int a2, int a3, int a4, int (__fastcall *a5)) (0x080273EC +1))
#define BattleMenu_802774C ((void __fastcall (*) (int a1, int a2, int a3, int a4, int (*a5)) (0x0802774C +1))
#define BattleMenu_8027796 ((int __fastcall (*) (int a1, int a2, int a3, int a4, char *a5, int a6, int (*a7)) (0x08027796 +1))
#define BattleMenu_8027AAE ((int __fastcall (*) (int a1, int a2, int a3, int a4, int a5, int a6, int (*a7)) (0x08027AAE +1))
#define BattleMenu_decompOptimized_chatbox_8027ADE ((int __fastcall (*) (int a1, int a2, int a3, int a4, int (*a5)) (0x08027ADE +1))
#define Battle_cb_80F2330 ((int __fastcall (*) (int a1, int a2, int a3, int a4, int (__fastcall *a5)) (0x080F2330 +1))

// VERSION DEPENDENT ---------------------------------
#define BattleMenu_8027A84 ((int __fastcall (*) (int a1, int a2, int a3, int a4, int (*a5)) (0x08027A84 +1))
#define Battle_cb_80B81EC ((int __fastcall (*) (int a1, int a2, int a3, int a4, int a5, int (__fastcall *a6)) (0x080B81EC +1))

#endif // SCRIPT_FALZAR_BATTLE_H
