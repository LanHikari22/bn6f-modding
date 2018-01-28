#ifndef SCRIPT_FALZAR_SOUND_H
#define SCRIPT_FALZAR_SOUND_H

#include "../../include/inttypes.h"
#include "../../Constants/_Constants.h"
#include "../../Structs/_Structs.h"
#include "../../include/IDADefinitions.h"

#define Sound_playBG_814E950 ((int __fastcall (*) (int musicOffset)) (0x0814E950 +1))
#define Sound_playBG_noreset_814E99C ((int __fastcall (*) (int a1)) (0x0814E99C +1))

#define Sound_playBG ((int __fastcall (*) (MusicOffset musicOffset)) (0x0814E924 +1))
#define Sound_814F104 ((int __fastcall (*) (int a1, unsigned __int8 *a2)) (0x0814F104 +1))


#endif // SCRIPT_FALZAR_SOUND_H