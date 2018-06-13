#ifndef DEF_FALZAR_NPC_H
#define DEF_FALZAR_NPC_H

#include "../../include/inttypes.h"
#include "../../Constants/_Constants.h"
#include "../../Structs/_Structs.h"
#include "../../include/IDADefinitions.h"


// VERSION UNIQUE ------------------------------------
#define NPC_init_809E590 ((int (*) ()) (0x0809E590 +1))

#define NPC_809E5E2 ((int (*) ()) (0x0809E5E2 +1))

#define NPC_809EADA ((int (*) ()) (0x0809EADA +1))

#define NPC_RunChatbox ((int __cdecl (*) ()) (0x0809EB20 +1))

#define NPC_809EBBC ((int (*) ()) (0x0809EBBC +1))

#define NPC_809F612 ((int (*) ()) (0x0809F612 +1))


// VERSION DEPENDENT ---------------------------------
#define NPC_cb_jt_2_809EB04 ((int (*) ()) (0x0809EB04 +1))

#define NPC_809EBDC ((int (*) ()) (0x0809EBDC +1))

#define NPC_809F506 ((int __fastcall (*) (int a1)) (0x0809F506 +1))


#endif // DEF_FALZAR_NPC_H