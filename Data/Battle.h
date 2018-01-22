#ifndef DATA_BATTLE_H
#define DATA_BATTLE_H

#include "../include/inttypes.h"
#include "../Structs/BattleSettings.h"
#include "../Structs/Battle.h"

/* ROM ------------------------------------------------------------------------------------------- */
#define battle_settings_list0       ((BattleSettings*)0x080AEE70)
#define battle_settings_list1       ((BattleSettings*)0x080B0D88)

/* RAM ------------------------------------------------------------------------------------------- */
#define pCurrBattle			            ((u32*)0x02001B9C)
#define pCurrBattle0 		            ((u32*)0x020348BC) // todo seems to be more involved with battle. MIGHT BE A STRUCT
#define sBtlPlayer                      ((Battle*)0x0203A9B0)
#define sBtlEnemyA                      ((Battle*)0x0203AA88)
#define sBtlEnemyB                      ((Battle*)0x0203AB60)
#define sBtlEnemyC                      ((Battle*)0x0203AC38)

#endif // DATA_BATTLE_H