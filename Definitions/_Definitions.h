#ifndef DEF__DEF_H
#define DEF__DEF_H

#include "../include/inttypes.h"
#include "Battle.h"
#include "BattleMenu.h"
#include "cb.h"
#include "check.h"
#include "engine.h"
#include "Load.h"
#include "main.h"
#include "object.h"
#include "render.h"
#include "Save.h"
#include "sprite.h"
#include "subsystem.h"


#ifdef FALZAR

#include "Falzar/Battle.h"
#include "Falzar/BattleMenu.h"
#include "Falzar/cb.h"
#include "Falzar/Chatbox.h"
#include "Falzar/check.h"
#include "Falzar/Load.h"
#include "Falzar/main.h"
#include "Falzar/MenuControl.h"
#include "Falzar/NCP.h"
#include "Falzar/NPC.h"
#include "Falzar/object.h"
#include "Falzar/render.h"
#include "Falzar/reqBBS.h"
#include "Falzar/Save.h"
#include "Falzar/Sound.h"
#include "Falzar/subsystem.h"
#include "Falzar/uncomp.h"


#endif // FALZAR

#ifdef GREGAR

#include "Gregar/Battle.h"
#include "Gregar/BattleMenu.h"
#include "Gregar/cb.h"
#include "Gregar/Chatbox.h"
#include "Gregar/libc.h"
#include "Gregar/Load.h"
#include "Gregar/m4a.h"
#include "Gregar/main.h"
#include "Gregar/MenuControl.h"
#include "Gregar/NCP.h"
#include "Gregar/NPC.h"
#include "Gregar/object.h"
#include "Gregar/render.h"
#include "Gregar/reqBBS.h"
#include "Gregar/Save.h"
#include "Gregar/Sound.h"
#include "Gregar/sprite.h"


#endif // GREGAR

#endif // DEF__DEF_H