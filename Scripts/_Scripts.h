#ifndef SCRIPTS__SCRIPTS_H
#define SCRIPTS__SCRIPTS_H

#include "../include/inttypes.h"
#include "Bios.h"
#include "NPC.h"
#include "object.h"
#include "Sound.h"
#include "sprite.h"

#ifdef FALZAR

#include "Falzar/Battle.h"
#include "Falzar/BattleMenu.h"
#include "Falzar/Chatbox.h"
#include "Falzar/Load.h"
#include "Falzar/Memory.h"
#include "Falzar/MenuControl.h"
#include "Falzar/Misc.h"
#include "Falzar/NCP.h"
#include "Falzar/reqBBS.h"
#include "Falzar/Save.h"
#include "Falzar/StartScreen.h"
#include "Falzar/subsystem.h"

#endif // FALZAR

#ifdef GREGAR

#include "Chatbox.h"
#include "Gregar/Misc.h"

#endif // GREGAR

#endif // SCRIPTS__SCRIPTS_H