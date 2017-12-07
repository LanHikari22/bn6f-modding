typedef struct {
	uint8_t invisCollSwitch;          // loc=0x0
	uint8_t unk_01;                   // loc=0x1
	uint8_t objTypeSpriteOff;         // loc=0x2
	uint8_t unk_03;                   // loc=0x3
	uint8_t walkingSpeed;             // loc=0x4
	uint8_t walkingTimer;             // loc=0x5
		uint8_t pad_06[0x01];            
	uint8_t unk_07;                   // loc=0x7
	uint8_t contTrigger;              // loc=0x8
	uint8_t walkingFlag;              // loc=0x9
	uint8_t walkingFlag2;             // loc=0xA
		uint8_t pad_0B[0x01];            
	uint8_t volume;                   // loc=0xC
	uint8_t unk_0D;                   // loc=0xD
	uint8_t walkingConfig;            // loc=0xE
	uint8_t RO_walkingConfig;         // loc=0xF
	uint8_t unk_10;                   // loc=0x10
	uint8_t unk_11;                   // loc=0x11
	uint8_t unk_12;                   // loc=0x12
	uint8_t unk_13;                   // loc=0x13
	uint8_t animationSelect;          // loc=0x14
	uint8_t RO_AnimationSel;          // loc=0x15
	uint8_t palleteIndx;              // loc=0x16
	uint8_t interactionLocked;        // loc=0x17
	uint8_t triggerChat;              // loc=0x18
	uint8_t animationTimerActive;     // loc=0x19
		uint8_t pad_1A[0x02];            
	uint8_t convoSelect;              // loc=0x1C
	uint8_t unk_1D;                   // loc=0x1D
	uint8_t unk_1E;                   // loc=0x1E
	uint8_t timerActive;              // loc=0x1F
	uint16_t animationTimer;          // loc=0x20
	uint16_t timer;                   // loc=0x22
	uint32_t x;                       // loc=0x24
	uint32_t y;                       // loc=0x28
	uint32_t z;                       // loc=0x2C
	uint32_t nextX;                   // loc=0x30
	uint32_t nextY;                   // loc=0x34
	uint32_t nextZ;                   // loc=0x38
	uint16_t NPCSelect;               // loc=0x3C
	uint16_t RO_NPCSelect;            // loc=0x3E
	uint32_t deltaX;                  // loc=0x40
	uint32_t deltaY;                  // loc=0x44
	uint32_t deltaZ;                  // loc=0x48
	uint32_t *animationData;          // loc=0x4C
	uint32_t hyp_IQR0;                // loc=0x50
	uint32_t hyp_IQR1;                // loc=0x54
	uint32_t hyp_IQR2;                // loc=0x58
	uint32_t hyp_IQR3;                // loc=0x5C
	uint32_t configFlags1;            // loc=0x60
	uint32_t unk_64;                  // loc=0x64
	uint32_t configFlags2;            // loc=0x68
	uint32_t RO_configFlags2;         // loc=0x6C
	uint32_t unk_70;                  // loc=0x70
	uint32_t unk_74;                  // loc=0x74
	uint32_t unk_78;                  // loc=0x78
		uint8_t pad_7C[0x05];            
	uint8_t unk_81;                   // loc=0x81
	uint8_t unk_82;                   // loc=0x82
	uint8_t unk_83;                   // loc=0x83
		uint8_t pad_84[0x08];            
	uint32_t unk_8C;                  // loc=0x8C
		uint8_t pad_90[0x04];            
	uint32_t *pScript;                // loc=0x94
	// size=0x98
}NPC;