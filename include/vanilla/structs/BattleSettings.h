#ifndef BATTLE_SETTINGS_H
#define BATTLE_SETTINGS_H

#include "../../inttypes.h"


/**
 * TODO: fill
 */
typedef struct {
	uint8_t battlefield;                  // loc=0x0
		uint8_t pad_01[0x01];                
	uint8_t music;                        // loc=0x2
	uint8_t battleType;                   // loc=0x3
	uint8_t background;                   // loc=0x4
	uint8_t battleNumber;                 // loc=0x5
	uint8_t battlefieldSidesModifier;     // loc=0x6
		uint8_t pad_07[0x01];                
	uint32_t UnknownOptionalSettings;     // loc=0x8
	uint32_t *pEnemySetup;                // loc=0xC
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
