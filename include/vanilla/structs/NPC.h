#ifndef NPC_H
#define NPC_H
#include "../../inttypes.h"

/**
 * Description:
 * This structure represents NPC overworld parameters, as well as other components such as script.
 * The absolute addresses in memory of this object are not static to every NPC in the game.
 * Length: 0x1B0
 */
typedef struct {
	uint8_t invisCollSwitch;         // loc=0x0
		uint8_t pad_1[0x7];             
	uint8_t contTrigger;             // loc=0x8
	uint8_t walkingFlag;             // loc=0x9
	uint8_t unk_0A;                  // loc=0xA
		uint8_t pad_B[0x1];             
	uint16_t volume;                 // loc=0xC 
		uint8_t pad_E[0x6];             
	uint8_t animationSelect;         // loc=0x14
	uint8_t ROAnimationSel;          // loc=0x15
	uint8_t palleteIndx;             // loc=0x16 
		uint8_t pad_17[0x5];            
	uint8_t convoSelect;             // loc=0x1C 
		uint8_t pad_1D[0x7];            
	uint32_t x;                      // loc=0x24 
	uint32_t y;                      // loc=0x28 
	uint32_t z;                      // loc=0x2C
		uint8_t pad_30[0xC];            
	uint16_t NPCSelect;              // loc=0x3C
		uint8_t pad_3E[0x22];           
	uint32_t flConfig;               // loc=0x60
		uint8_t pad_64[0x30];           
	uint32_t *pScript;               // loc=0x94
		uint8_t pad_98[0x118];          
	// size=0x1B0
}NPC;

/**
 * Enum for flConfig. The meanings of different bits.
 */
typedef enum{
	nACTIVATE = 0x001, nTURN = 0x002, nSOLID = 0x004,
	SCRIPT_SELECT = 0x400, UNK_800 = 0x800
}NPC_FLCFG;


/* Instances */
#pragma region Instances
#define sNPC_chaud 			((NPC*)0x02005F48)
#define sNPC_copybotneardog ((NPC*)0x02005BE8)
#define sNPC_ACDC_Boy		((NPC*)0x02005888)
#pragma endregion Instances

#pragma region Doc
/*
	
		s_02005BE8 # sNPC_copybotneardog
		s_02005F48 # chaud (ACDC), Subchip seller guy
		s_020062A8 # Another copybot
		s_02006458 # Enemy copybot, sigh
		s_02005C38 # seems to be a struct of its own? (0x50)
Other instances*/
/**
[Header]
	[Name] NPC
	[Size] 0x1B0 (Very likely)
	[TODO] Formatting. Still didnt settle on a good reporting format...
	[Description]
	// Overworld parameters and encapsulation of NPC objs?
Offset  Type  Name               
0x00    u8    invisCollSwitch    
		[0x0Z] <invisCollSwitch>
		// This seems to hold 4 states. All others are repeated. 00 through 04
		// covers all cases of INVISIBLE = TRUE/FALSE and COLLIDABLE = TRUE/FALSE!
0x01    u8    ?                  
		[0x0Z]
		// ??? Most values crash the game. May be tied to a function pointer calculation...
0x08    u8    contTrigger        
		[0x000Z] <convTrigger>
		// Z = 8: Trigger a certain conversation
		// Many other values just crash?
		end

0x09    u8    walkingFlag        
0x0A    u8    ?                  
0x0C    u16   volume             
		[0xAABB] <volume>
		// This specifies the width of the collision walls, in two components parallel and anti-parallel to
		// the streets in the game.
0x14    u8    animationSelect    
		[0X0Z] <facingDirection>
		// X not sure, but it is always identical or close to Z. It might be a flag.
		// Z determines direction of NPC based on 2<<n-1
0x15    u8    ROAnimationSel     
0x16    u8    palleteIndx        
		[0xZZ] <palleteIndx>
		// This seems like a pallete index
0x18    u16   ?                  
		[0x000Z]
		// Another conversation switch at Z...
0x1C    u8    convoSelect        
		[0x00ZZ] <convoSelect>
		// Changes conversation of copybot!!
0x24    u32   x                  
		[u32] <x>
0x28    u32   y                  
		[u32] <y>
0x2C    u32   z                  
		[u32] <z>
0x3C    u16   NPCSelect          
		[u32] <NPCSelect>
		// Changes sprite! some are neat, some are weird.
0x50    u16   ?                  
		[0x000Z]
		// For any Z, a certain conversation is triggered
		// Value constantly written to unless PET is open, for example
		// <0800385C> breaks whenever you talk to a character hmm..
0x60    u32   flConfig           
		[u32] <flConfig>
		// Flags! 0xUUUUU_0bXcUU_UUUs_osta
		// a(0x001): !activate. 1 = interaction w/ NPC is disabled.
		// t(0x002): !turn. 1 = disabled. NPC won't turn when you interact.
		// s(0x004): !solid. 1 = Can walk through NPC.
		// o(0x008): orientation. 0 = Facing direction parallel to Lan's old house. 1 = perpendicular
		// s(0x010): also solid. No other effects observed.
		// c(0x400): conversation select of some sort. 
		// X(0x800): If c, This enters a weird state where game
		// pauses for a while until a conversation is reached...
		// Unknown. Dangerous.
		

0x94    u32   *pScript           
*/
#pragma endregion Doc

#pragma region Accesses
/*
	name=NPC, size=0x1B0
	0809F554::0809F55C u32(0x50), 0800461E::08004640 u8(0x00), 0800461E::08004658 u8(0x01), 
	0809FAA8::0809FAAC u8(0x08), 0809FB1A::0809FB1C u8(0x18), 080A0114::080A0116 u8(0x19), 
	0809FB1A::0809FB2E u8(0x09), 0809FC14::0809FC18 u8(0x0A), 0809FD10::0809FD12 u32(0x60), 
	080A0B1C::080A0B22 u32(0x54), 0809FD10::0809FD22 u32(0x30), 0809FD10::0809FD24 u32(0x24), 
	0809FD10::0809FD26 u32(0x34), 0809FD10::0809FD28 u32(0x28), 0809FD10::0809FD2A u32(0x38), 
	0809FD10::0809FD2C u32(0x2C), 0809FD10::0809FD2E u16(0x20), 0809FD10::0809FD32 u16(0x20), 
	?::0809FD52 u32(0x40), ?::0809FD54 u32(0x30), ?::0809FD58 u32(0x30), 
	?::0809FD5A u32(0x44), ?::0809FD5C u32(0x34), ?::0809FD60 u32(0x34), 
	?::0809FD62 u32(0x60), ?::080316FA u8(-1), ?::080316FE u8(-1), 
	?::0803171A u8(-1), ?::0803171E u8(-1), ?::0809FD76 u32(0x2C), 
	?::0809FD78 u32(0x38), 080A0A94::080A0A96 u32(0x60), 080A0A94::080A0AA0 u32(0x30), 
	080A0A94::080A0AA4 u8(-1), 080A0A94::080A0AAA u32(0x34), 080A0A94::080A0AAE u8(-1), 
	080A0A94::080A0AB4 u32(0x38), 080A0A94::080A0AB8 u8(-1), 080A0A94::080A0AD0 u32(0x54), 
	080A0130::080A0132 u8(0x1F), 080A0130::080A0138 u32(0x5C), 0809FB1A::0809FB38 u32(0x60), 
	?::08002F5C u8(0x02), ?::08002F64 u8(0x13), ?::08002F6E u8(0x13), 
	?::08002F72 u8(0x16), ?::08002F7A u8(0x16), 0809FB1A::0809FB46 u16(0x3C), 
	0809FB1A::0809FB48 u16(0x3E), 0809FB1A::0809FB80 u8(0x14), 0809FB1A::0809FB82 u8(0x15), 
	080026C4::080026C6 u8(0x02), 03006792::03006794 u8(0x01), 03006792::03006798 u8(0x01), 
	03006792::030067F8 u32(0x20), 03006792::030067FE u32(0x1C), 03006792::03006802 u32(0x18), 
	03006792::0300680E u8(0x05), 0809FB1A::0809FB94 u8(0x16), ?::08002D80 u8(0x02), 
	?::08002D88 u8(0x04), 0809FB1A::0809FB9A u32(0x68), 0809FB1A::0809FB9C u32(0x6C), 
	0809FB1A::0809FBA6 u8(0x0E), 0809FB1A::0809FBA8 u8(0x0F), 0809FB1A::0809FBAA u8(0x14), 
	0809FB1A::0809FBAC u8(0x15), 0809FB1A::0809FBAE u16(0x3C), 0809FB1A::0809FBB0 u16(0x3E), 
	0809FB1A::0809FBB2 u32(0x68), 0809FB1A::0809FBB4 u32(0x6C), 080A0A0A::080A0A0C u32(0x60), 
	080A0A0A::080A0A0E u8(0x00), 080A0A0A::080A0A22 u32(0x24), 080A0A0A::080A0A26 u8(-1), 
	080A0A0A::080A0A2C u32(0x28), 080A0A0A::080A0A30 u8(-1), 080A0A0A::080A0A36 u8(0x17), 
	080A0A0A::080A0A4E u32(0x2C), 080A0A0A::080A0A52 u8(-1), 080A0A0A::080A0A5C u16(0x0C), 
	080A0A0A::080A0A7E u32(0x50), 080A0A0A::080A0A80 u32(0x58), 0809FB1A::0809FBBA u32(0x64), 
	?::08002E14 u8(0x02), ?::08002E1E u8(0x15), ?::08002E26 u8(0x15), 
	0809FB1A::0809FBCC u32(0x60), 080A0114::080A011C u32(0x4C), 080A0114::080A012A u32(0x4C), 
	080A03A4::080A03A8 u8(0x09), 080A03A4::080A03AC u16(0x0A), 080A03A4::080A03B0 u16(0x20), 
	080A0A02::080A0A06 u8(0x19), 0809FC00::0809FC02 u16(0x20), 0809FC00::0809FC06 u16(0x20), 
	080A09FA::080A09FE u8(0x19), 03006792::0300679E u8(0x03), 03006792::030067C0 u32(0x1C), 
	03006792::030067EE u8(0x01), 0800467C::0800468C u8(0x00), 030061E8::030061EE u8(0x00), 
	030061E8::030061F6 u8(0x02), 0300631C::03006320 u8(0x03), 0300631C::03006336 u32(0x08), 
	0300631C::0300633E u32(0x00), 0300631C::03006346 u32(0x04), 0300631C::03006352 u16(0x0C), 
	0300631C::03006368 u16(0x0A), 0300631C::0300636A u32(0x08), 0300631C::03006376 u8(0x0E), 
	0300631C::03006384 u8(0x0F), 030061E8::0300621A u8(0x03), 030061E8::03006226 u8(0x13), 
	030061E8::03006234 u8(0x13), 030061E8::03006240 u32(0x20), 030061E8::03006246 u32(0x1C), 
	030061E8::0300624A u32(0x18), 030061E8::030062CC u8(0x03), 030061E8::030062FC u8(0x03), 
	030061E8::030062FE u32(0x28), 03006028::0300602A u8(0x02), 03006028::03006032 u8(0x03), 
	03006028::03006038 u8(0x03), 03006028::03006042 u32(0x24), 03006440::03006442 u8(0x03), 
	03006792::030067CE u32(0x1C), 03006792::030067D0 u32(0x18), 03006792::030067DA u32(0x20), 
	03006792::030067DE u8(0x01), 03006792::030067E2 u8(0x02), 0809FD10::0809FD36 u32(0x70), 
	0809FD10::0809FD38 u32(0x24), 0809FD10::0809FD3A u32(0x74), 0809FD10::0809FD3C u32(0x28), 
	0809FD10::0809FD3E u8(0x05), 0809FD10::0809FD42 u8(0x05), 0809FC3C::0809FC40 u8(0x0E), 
	0809FC3C::0809FC46 u32(0x24), 0809FC3C::0809FC50 u32(0x70), 0809FC3C::0809FC52 u32(0x28), 
	0809FC3C::0809FC5C u32(0x74), 0809FC3C::0809FC60 u8(0x04), 0809FC3C::0809FC70 u16(0x20), 
	0809FC3C::0809FC74 u8(0x0E), 0809FC3C::0809FC7A u8(0x04), 0809FC3C::0809FC84 u32(0x40), 
	0809FC3C::0809FC8E u32(0x44), 0809FC3C::0809FC92 u32(0x48), 0809FC3C::0809FC96 u8(0x0A), 
	0809FC3C::0809FC98 u32(0x40), 0809FC3C::0809FC9A u32(0x24), 0809FC3C::0809FC9E u32(0x30), 
	0809FC3C::0809FCA0 u32(0x44), 0809FC3C::0809FCA2 u32(0x28), 0809FC3C::0809FCA6 u32(0x34), 
	0809FC3C::0809FCA8 u32(0x48), 0809FC3C::0809FCAA u32(0x2C), 0809FC3C::0809FCAE u32(0x38), 
	03006730::03006732 u8(0x03), 03006730::0300675A u8(0x00), 03006730::0300675E u32(0x18), 
	03006730::03006764 u32(0x1C), 03006730::0300676E u32(0x20), 03006730::03006772 u8(0x01), 
	03006730::03006776 u8(0x02), 03006730::03006778 u32(0x20), 03006730::0300677E u32(0x1C), 
	03006730::03006782 u32(0x18), 03006730::0300678E u8(0x05), ?::080A0432 u8(0x14), 
	?::08002DA4 u8(0x02), ?::08002DAC u8(0x00), 080026A4::080026A6 u8(0x02), 
	080A0776::080A077C u8(-1), 080A0776::080A0784 u8(0x0E), 080A0776::080A0788 u8(-1), 
	080A0776::080A078A u8(0x04), 080A0776::080A078E u8(-1), 080A0776::080A0790 u8(0x05), 
	080A0776::080A0794 u8(0x09), 080A0776::080A0798 u16(0x0A), 03006028::03006052 u32(0x1C), 
	03006028::03006056 u32(0x18), 03006028::03006062 u16(0x08), 03006028::0300606E u32(0x24), 
	03006028::03006090 u16(0x08), 03006028::03006096 u32(0x24), 03006028::0300609E u32(0x24), 
	03006028::030060A8 u16(0x08), 03006028::030060BE u8(0x15), 03006028::030060CA u8(0x03), 
	03006108::0300610A u32(0x1C), 03006108::03006110 u32(0x18), 03006108::03006114 u8(0x04), 
	03006108::03006116 u8(0x05), 03006108::0300611E u16(0x06), 03006028::030060D6 u8(0x15), 
	03006028::030060E0 u8(0x15), ?::03006460 u32(0x30), ?::03006466 u32(0x20), 
	?::0300646C u32(0x1C), ?::03006470 u32(0x18), ?::03006478 u32(0x28), 
	?::0300647C u32(0x2C), ?::03006482 u32(0x28), ?::03006484 u8(0x16), 
	?::03006498 u8(0x16), ?::0300649A u8(0x03), ?::030064BC u32(0x28), 
	?::030064C0 u32(0x28), ?::03006564 u8(0x03), ?::030064C6 u32(0x10), 
	?::030064C8 u8(0x16), ?::030065A6 u8(0x13), ?::030065C4 u8(0x13), 
	?::030064DE u8(-1), ?::03006500 u8(-1), ?::03006514 u16(0x14), 
	?::03006528 u16(0x08), ?::0300653E u8(-1), ?::03006584 u32(0x28), 
	080037F4::08003862 u32(0x00), 080037F4::08003866 u32(0x00), 080037F4::08003836 u32(0x00), 
	080037F4::0800383A u32(0x00), 0809F554::0809F564 u32(0x60), 0809ECE0::0809ECF0 u8(0x17), 
	0809ECE0::0809ECF8 u8(0x18), 080A0AE0::080A0AE2 u8(0x09), 080A0AE0::080A0AE4 u8(0x1D), 
	080A0AE0::080A0AE6 u8(0x0A), 080A0AE0::080A0AE8 u8(0x1E), 080A0AE0::080A0AEC u8(0x08), 
	080A0AE0::080A0AF0 u8(0x09), 080A0AE0::080A0AF2 u16(0x0A), 0809ED00::0809ED04 u8(0x0A), 
	080A0012::080A0016 u8(0x09), 080A003C::080A0040 u8(0x0A), 080A0058::080A005A u32(0x60), 
	080A0058::080A006A u32(0x28), 080A0058::080A0070 u32(0x24), 080A0058::080A008C u32(0x60), 
	080A0058::080A00DC u8(0x1C), 080A0058::080A00E4 u8(0x0A), 080A0012::080A0026 u32(0x60), 
	080A00F4::080A010C u8(0x07), 080A0AF6::080A0AFA u8(0x08), 080A0AF6::080A0AFC u8(0x1D), 
	080A0AF6::080A0AFE u8(0x09), 080A0AF6::080A0B00 u8(0x1E), 080A0AF6::080A0B02 u8(0x0A), 
	080A0AF6::080A0B04 u32(0x60), 080A0AF6::080A0B0C u8(0x14), 080A0AF6::080A0B18 u8(0x18), 

*/
#pragma endregion Accesses

/*
s_02035280 <sNoname>:
	Description
		// This seems to be a structure responsible for gui properties in battles
	0x00 [0xZZZZ]
		// Weird effect when it comes to HP bars
	0x48 [0xPPPPPPPP] <pStatusSettings>
		// Seems to be an active pointer to Megamans status settings or something?
*/
#endif /* NPC_H */