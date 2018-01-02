typedef struct {
	uint8_t unk_00;     // loc=0x0
		u8 pad_01[0x03];   
	uint8_t unk_04;     // loc=0x4
	uint8_t unk_05;     // loc=0x5
		u8 pad_06[0x02];   
	uint8_t unk_08;     // loc=0x8
	uint8_t unk_09;     // loc=0x9
		u8 pad_0A[0x01];   
	uint8_t unk_0B;     // loc=0xB
		u8 pad_0C[0x01];   
	uint8_t unk_0D;     // loc=0xD
	uint8_t unk_0E;     // loc=0xE
	uint8_t unk_0F;     // loc=0xF
		u8 pad_10[0x0E];   
	uint16_t unk_1E;    // loc=0x1E
	uint16_t unk_20;    // loc=0x20
	uint16_t unk_22;    // loc=0x22
	uint16_t unk_24;    // loc=0x24
	uint16_t unk_26;    // loc=0x26
	uint32_t unk_28;    // loc=0x28
		u8 pad_2C[0x04];   
	uint8_t unk_30;     // loc=0x30
	uint8_t unk_31;     // loc=0x31
	uint8_t unk_32;     // loc=0x32
		u8 pad_33[0x05];   
	uint8_t unk_38;     // loc=0x38
	uint8_t unk_39;     // loc=0x39
	uint16_t unk_3A;    // loc=0x3A
	uint16_t unk_3C;    // loc=0x3C
	uint8_t unk_3E;     // loc=0x3E
	uint8_t unk_3F;     // loc=0x3F
		u8 pad_40[0x01];   
	uint8_t unk_41;     // loc=0x41
	uint8_t unk_42;     // loc=0x42
	uint8_t unk_43;     // loc=0x43
	uint8_t unk_44;     // loc=0x44
	uint8_t unk_45;     // loc=0x45
	uint8_t unk_46;     // loc=0x46
	uint8_t unk_47;     // loc=0x47
	uint8_t unk_48;     // loc=0x48
	uint8_t unk_49;     // loc=0x49
		u8 pad_4A[0x05];   
	uint8_t unk_4F;     // loc=0x4F
	uint16_t unk_50;    // loc=0x50
		u8 pad_52[0x02];   
	uint32_t unk_54;    // loc=0x54 CONFLICT u16 loc_56
	uint32_t unk_58;    // loc=0x58 CONFLICT u16 loc_5A
	uint32_t unk_5C;    // loc=0x5C CONFLICT u16 loc_5E
		u8 pad_60[0x0C];   
	uint16_t unk_6C;    // loc=0x6C
	uint16_t unk_6E;    // loc=0x6E
		u8 pad_70[0x0C];   
	uint32_t unk_7C;    // loc=0x7C
	// size=0x80
}s_02005780;