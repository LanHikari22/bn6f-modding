#ifndef DEF_GREGAR_REQBBS_H
#define DEF_GREGAR_REQBBS_H

#include "../../include/inttypes.h"
#include "../../Constants/_Constants.h"
#include "../../Structs/_Structs.h"
#include "../../include/IDADefinitions.h"

#define reqBBS_draw_jt1_callBack ((int (*) ()) (0x0813FE84 +1))

#define reqBBS_draw_813FFA8 ((void __noreturn (*) ()) (0x0813FFA8 +1))

#define reqBBS_draw_814011C ((void __noreturn (*) ()) (0x0814011C +1))

#define reqBBS_callBack_00 ((int (*) ()) (0x0813FE84 +1))

#define reqBBS_8141370 ((void __noreturn (*) ()) (0x08141370 +1))

#define reqBBS_81414D8 ((int (*) ()) (0x081414D8 +1))

#define reqBBS_8141A10 ((void __noreturn (*) ()) (0x08141A10 +1))

#define reqBBS_jumpout_draw_star ((int __fastcall (*) (int a1, int a2)) (0x081420A8 +1))

#define reqBBS_jumpout_81420E8 ((int __fastcall (*) (int a1, int a2, int a3, int a4)) (0x081420E8 +1))

#define reqBBS_get_totalPointsIndex ((int (*) ()) (0x08142578 +1))

// hyp: totalPointsIndex corresponding to rank
#define reqBBS_rankLessThan ((bool __fastcall (*) (int a1)) (0x08142664 +1))

#define reqBBS_get_selectedEntry_ID ((int __cdecl (*) ()) (0x081426A8 +1))

#define reqBBS_set_selectedEntry_rank_to_0F ((int (*) ()) (0x081426BC +1))

#define reqBBS_GUI_get_0F ((int (*) ()) (0x08142754 +1))

#define reqBBS_clear_points_and_rank ((reqBBS_GUI * (*) ()) (0x08142764 +1))


#endif // DEF_GREGAR_REQBBS_H
