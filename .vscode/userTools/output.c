typedef struct {
	u8 jto_0;                         // loc=0x0
		u8 pad_01[0x03];                 
	u8 unk_04;                        // loc=0x4
	u8 numNewRequests;                // loc=0x5
		u8 pad_06[0x02];                 
	u8 animationTimer0;               // loc=0x8
	u8 animationTimer1;               // loc=0x9
		u8 pad_0A[0x01];                 
	u8 unk_0B;                        // loc=0xB
		u8 pad_0C[0x01];                 
	u8 numPoints;                     // loc=0xD
	u8 totalPointsIndex;              // loc=0xE
	u8 unk_0F;                        // loc=0xF
		u8 pad_10[0x0E];                 
	u16 totalNewRequests;             // loc=0x1E
	u16 cursorPos;                    // loc=0x20
	u16 RO_cursorPos;                 // loc=0x22
	u16 pagePos;                      // loc=0x24
	u16 RO_pagePos;                   // loc=0x26
	void *reqBBS_textualPointers;     // loc=0x28
		u8 pad_2C[0x04];                 
	u8 unk_30;                        // loc=0x30
	u8 unk_31;                        // loc=0x31
	u8 unk_32;                        // loc=0x32
		u8 pad_33[0x05];                 
	u8 unk_38;                        // loc=0x38
	u8 unk_39;                        // loc=0x39
	u16 unk_3A;                       // loc=0x3A
	u16 unk_3C;                       // loc=0x3C
	u8 unk_3E;                        // loc=0x3E
	u8 unk_3F;                        // loc=0x3F
		u8 pad_40[0x01];                 
	u8 unk_41;                        // loc=0x41
	u8 unk_42;                        // loc=0x42
	u8 unk_43;                        // loc=0x43
	u8 unk_44;                        // loc=0x44
	u8 unk_45;                        // loc=0x45
	u8 unk_46;                        // loc=0x46
	u8 unk_47;                        // loc=0x47
	u8 unk_48;                        // loc=0x48
	u8 unk_49;                        // loc=0x49
		u8 pad_4A[0x05];                 
	u8 unk_4F;                        // loc=0x4F
	u16 unk_50;                       // loc=0x50
		u8 pad_52[0x02];                 
	u32 unk_54;                       // loc=0x54
	u32 unk_58;                       // loc=0x58
	u32 unk_5C;                       // loc=0x5C
		u8 pad_60[0x0C];                 
	u16 unk_6C;                       // loc=0x6C
	u16 unk_6E;                       // loc=0x6E
		u8 pad_70[0x0C];                 
	u32 unk_7C;                       // loc=0x7C
	// size=0x80
}reqBBS_GUI;