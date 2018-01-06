#ifndef BATTLE_SETTINGS_H
#define BATTLE_SETTINGS_H

#include "../include/inttypes.h"


/**
 * TODO: fill
 */
typedef struct {
	u8 battlefield;                  // loc=0x0
		u8 pad_01[0x01];                
	u8 music;                        // loc=0x2
	u8 battleType;                   // loc=0x3
	u8 background;                   // loc=0x4
	u8 battleNumber;                 // loc=0x5
	u8 battlefieldSidesModifier;     // loc=0x6
		u8 pad_07[0x01];                
	u32 UnknownOptionalSettings;     // loc=0x8
	u32 *pEnemySetup;                // loc=0xC
	// size=0x10
}BattleSettings;

#pragma region sBattleSettings
/*
[Header]
	[Name] BattleSettings
	[Size] 0x10
	[Description]
	this structure defines the battle settings for a battle.
	[Instances]
	Can be found through  <pCurrBattle> = 0x02001B9C
Offset  Type  Name                        
0x00    u8    battlefield                 
0x02    u8    music                       
0x03    u8    battleType                  
0x04    u8    background                  
0x05    u8    battleNumber                
0x06    u8    battlefieldSidesModifier    
0x08    u32   UnknownOptionalSettings
	[0xZZZZZZ] [Me to past me]: only 6 Z's?
0x0C    u32   *pEnemySetup
*/
#pragma endregion sBattleSettings
#endif /* BATTLE_SETTINGS_H */
