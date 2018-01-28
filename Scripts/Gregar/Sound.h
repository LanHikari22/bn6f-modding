#ifndef SCRIPT_GREGAR_SOUND_H
#define SCRIPT_GREGAR_SOUND_H

#include "../../include/inttypes.h"
#include "../../Constants/_Constants.h"
#include "../../Structs/_Structs.h"
#include "../../include/IDADefinitions.h"

#define Sound_playBG ((int __fastcall (*) (MusicOffset musicOffset)) (0x08150474+1))
#define Sound_8150C54 ((int __fastcall (*) (int a1, unsigned __int8 *a2)) (0x08150C54+1))


#endif // SCRIPT_GREGAR_SOUND_H