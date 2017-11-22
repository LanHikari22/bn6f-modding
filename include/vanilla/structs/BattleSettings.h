#ifndef BATTLE_SETTINGS_H
#define BATTLE_SETTINGS_H
/**
 * TODO: fill
 */
typedef struct{
	uint8_t battlefield;
	uint8_t pad01;
	uint8_t music;
	uint8_t battleType;
	uint8_t background;
	uint8_t battleNumber;
	uint8_t battlefieldSidesModifier;
	uint8_t pad07;
	uint32_t UnknownOptionalSettings; // TODO investigate this
	uint32_t pEnemySetup;
}BattleSettings;

#pragma region sBattleSettings
/*
<sBattleSettings>:
	Description
		this structure defines the battle settings for a battle.
	Length
		0x10
	Instances
		Can be found through  <pCurrBattle> = 0x02001B9C
	[Definition]
	0x00 <battlefield>
	0x01 <pad01> // unkwown
	0x02 <music>
	0x03 <battleType>
	0x04 <background>
	0x05 <battleNumber>
	0x06 <battlefieldSidesModifier>
	0x07 <pad07> // unknown
	0x08 <UnkownOptionalSettings> [0xZZZZZZ]
	0x0C <pEnemySetup>
*/
#pragma endregion sBattleSettings
#endif /* BATTLE_SETTINGS_H */
