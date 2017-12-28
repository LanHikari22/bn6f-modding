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