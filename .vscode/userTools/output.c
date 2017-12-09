typedef struct {
	uint8_t visible;                    // loc=0x0
	uint8_t scriptID;                   // loc=0x1
	uint8_t currLine;                   // loc=0x2
	uint8_t unk_03;                     // loc=0x3
	uint8_t chatPageState;              // loc=0x4
	uint8_t unk_05;                     // loc=0x5
		uint8_t pad_06[0x01];              
	uint8_t mugshotPalleteSel;          // loc=0x7
	uint8_t typingSpeed;                // loc=0x8
	uint8_t nCharacterTyped;            // loc=0x9
	uint8_t unk_0A;                     // loc=0xA
	uint8_t unk_0B;                     // loc=0xB
	uint8_t chatbox_y;                  // loc=0xC
	uint8_t chatbox_x;                  // loc=0xD
	uint8_t unk_0E;                     // loc=0xE
	uint8_t amount_of_box_appeared;     // loc=0xF
	uint8_t chatboxOpenState;           // loc=0x10
	uint8_t bxoff_11;                   // loc=0x11
	uint8_t unk_12;                     // loc=0x12
	uint8_t choiceCursorPos;            // loc=0x13
	uint8_t unk_14;                     // loc=0x14
	uint8_t unk_15;                     // loc=0x15
	uint8_t unk_16;                     // loc=0x16
	uint8_t unk_17;                     // loc=0x17
	uint8_t textCoord;                  // loc=0x18
	uint8_t unk_19;                     // loc=0x19
	uint8_t csrCoord;                   // loc=0x1A
	uint8_t unk_1B;                     // loc=0x1B
	uint8_t unk_1C;                     // loc=0x1C
	uint8_t unk_1D;                     // loc=0x1D
	uint8_t unk_1E;                     // loc=0x1E
	uint8_t unk_1F;                     // loc=0x1F
		uint8_t pad_20[0x02];              
	uint16_t keyState;                  // loc=0x22
	uint16_t keyPress;                  // loc=0x24
	uint16_t keysFlags;                 // loc=0x26
		uint8_t pad_28[0x04];              
	uint8_t *pScriptCursor;             // loc=0x2C
	uint16_t *pScriptArray;             // loc=0x30
	uint8_t *pCurrScript;               // loc=0x34
	uint32_t unk_38;                    // loc=0x38
		uint8_t pad_3C[0x01];              
	uint8_t unk_3D;                     // loc=0x3D
	uint16_t flags_3E;                  // loc=0x3E
	uint32_t mugshot_color_filter;      // loc=0x40
	uint32_t unk_44;                    // loc=0x44
		uint8_t pad_48[0x04];              
	uint32_t unk_4C;                    // loc=0x4C
	uint32_t unk_50;                    // loc=0x50
	uint32_t unk_54;                    // loc=0x54
	uint32_t unk_58;                    // loc=0x58
		uint8_t pad_5C[0x08];              
	uint16_t unk_64;                    // loc=0x64
		uint8_t pad_66[0x02];              
	uint16_t unk_68;                    // loc=0x68
	uint16_t unk_6A;                    // loc=0x6A
	uint16_t unk_6C;                    // loc=0x6C
	uint16_t unk_6E;                    // loc=0x6E
	uint32_t unk_70;                    // loc=0x70
	uint32_t unk_74;                    // loc=0x74
	uint32_t unk_78;                    // loc=0x78
	uint32_t unk_7C;                    // loc=0x7C
	uint8_t unk_80;                     // loc=0x80
		uint8_t pad_81[0x03];              
	uint32_t unk_84;                    // loc=0x84
	uint32_t unk_88;                    // loc=0x88
		uint8_t pad_8C[0x04];              
	uint32_t unk_90;                    // loc=0x90
	uint8_t unk_94;                     // loc=0x94
		uint8_t pad_95[0x03];              
	// size=0x98
}ChatBoxPropreties;