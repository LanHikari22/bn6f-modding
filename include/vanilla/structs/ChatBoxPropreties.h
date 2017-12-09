#ifndef S_02009CD0_H
#define S_02009CD0_H

#include "../../inttypes.h"

/**
 * This is responsible for GUI propreties of the chatbox as well as script running.
 */
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

#pragma region Docs
/*
s_02009CD0 <ChatBoxPropreties>:
	Description
		So far, I can just tell it seems to control various things in
		the textbox as a GUI element.
	Size
		Hypothesis: 0x98 (0x02009D68 - 0x02009CD0) (TODO: update! 0x100?)
	Offset	Type	Name
	0x00	bool	visible
		- if 0, not visible, otherwise chatbox is visible when
		initiated
		.# enable bit for textbox? Only Hides textbox when in-chat.
	0x01	u8		scriptID?
	0x02	u8		currLine
		- This changes whenever the text reaches a new line!
	0x03	u8		?
	0x04	u8		?
		- Might be currLine of cursor?
	0x05	u8		?
		- =0xFF: Cannot leave chatbox
		- values other than 0x00 just make character spam animate until interacted to?
		And when pressing a button, the character stops and the chatbox no longer is responsive
	0x07	u8		mugshotPalleteSel
		- Seems to select the magshot pallete
	0x08	u8		typingSpeed
		- Mugshot animation speed is not affected
	0x09	u8		typingPauseTimer
		- It seems like the mugshot animation may be synced to this by code, but also not.
		- The text freezes until it counts to 0. Then everything continues as normal. 
		- In normal operation, this is set to 1, so it counts down to 0 again immediately before reset to 1 again
	0x0A	u8		?
	0x0B	u8		?
	0x0C	u8/u16	?
	0x10	u8		?
		[0xZZ]
		.# determines textbox width and content state
	0x18	u16		textCoord
		[0xYYXX] <textCoord>
		.# coord of text body
	0x1A	u16		csrCoord
		[0xYYXX] <csrCoord>
		.# coord of text cursor
	0x1C	u32		?
		[0xPPPPYYXX]
		.# textbox gfx pointer? (0x081E0C00)
	0x22	u16		keyState_onChip
		[0xKKKK] <keyState_onChip>
		.# keyState (only active on-chat)
	0x24	u16		?
		[0xKKKK]
		.# KeyState? (Unexplored behavior)
	0x2C	void	*pCurrScript
		[0xPPPPPPPP] <pCurrScript>.
		.# changing causes mouth animations.
	Other	?		?
		v OMG this legacy documentation lmao! this won't fit my doc formatting
		0x30-0x38 [0xPPPPPPPP]
		.# 0-1: pointers
		.# 2:   magic: 0x0200B2B0
	0x9C	u8		RelScriptId
		[0xZZ] <RelScriptID?>
		.# more likely to be a scriptID than 0x01!
		.# doesnt change while interacting with obj!
	--
	0x1f8	void	*pGfx 
		[0xPPPPPPPP] <pGfx>
		.# (?)
	0x3C
Old Docs*/

/*
	[Header]
			[Name] ChatBoxPropreties
			[Size] 0x98
			[Offset] 0x02009CD0
			[Description]
	Offset  Type  Name                 
	0x00    u8    visible              
			bool.
			- if 0, not visible, otherwise chatbox is visible when
			initiated
			.# enable bit for textbox? Only Hides textbox when in-chat.
	0x01    u8    scriptID             
	0x02    u8    currLine             
			- This changes whenever the text reaches a new line!
	0x03    u8    ?                    
	0x04    u8    chatPageState
		
		Seems to indicate when the script is done by transitioning from 0 to 1 
		After a set amount of time, it transitions to 2.
		When a choice is present, the transition to 2 does not occur at all. It stays at 0x01, until the

	0x05    u8    ?                    
			- =0xFF: Cannot leave chatbox
			- values other than 0x00 just make character spam animate until interacted to?
			And when pressing a button, the character stops and the chatbox no longer is responsive
			This can however cause some chats with characters to behave abnormally
	0x07    u8    mugshotPalleteSel    
			- Seems to select the magshot pallete
	0x08    u8    typingSpeed          
			- Mugshot animation speed is not affected
	0x09    u8    nCharacterTyped
			bool
			If 0, it indicates a character was just printed to the screen     
			Its end state after everything has been typed, is 0 however.
			If 1, this indicates that a character is about to be TYPED.
	0x0A    u8    ?                    
	0x0B    u8    ?
		Set to -1 everytime a page loads for some reason                    
	0x0C    u8    chatbox_y
		I THINK THIS AND 0D ARE WRONG. THESE ARE 1C AND 1D, AND ALSO LIKELY ON REVERSE
		Vertical coordinate of the chatbox (not the text, or the mugshot, literally the box)
		0x00 is at the top of the screen, and it grows downwards                    
	0x0D    u8    chatbox_x
		Horizontal coordinate of the chatbox (not the text, or the mugshot, literally the box)
		0x00 is at the natural positon, it transforms to the right  
	0x0E    u8	  ?

	0x0F    u8    amount_of_box_appeared
		at 0x00, only a little of the box is visible, as it increases, more of the box loads
		until it loads completely at 0x08                 
	0x10    u8    chatboxOpenState
			Determines how open the chatbox is. The values are used for the chatbox full opening
			states and closing. The width of the chatbox varies in each state, and the mugshot appears
			when the chatbox is in state 3. At high values, random graphics appear.                    
			[0xZZ]
			.# determines textbox width and content state
	0x11    u8    bxoff_11
		((void (*)(void))*(&0x803FF04 + chatbox->unk_11))();
		This structure pointers appears to contain very important information about the chatbox's
		initiaton                    
	0x12    u8    ?                    
	0x13    u8    choiceCursorPos
		Position of coicecursor, depends on what is selected in a choice
		Changing this is valid and it changes the cursor position accordingly                    
	0x14    u8    ?                    
	0x15    u8    ?                    
	0x16    u8    ?                    
	0x17    u8    ?                    
	0x18    u8    textCoord            
			[0xYYXX] <textCoord>
			.# coord of text body
	0x19    u8    ?                    
	0x1A    u8    csrCoord             
			[0xYYXX] <csrCoord>
			.# coord of text cursor
	0x1B    u8    ?                    
	0x1C    u8    ?                    
			[0xPPPPYYXX]
			.# textbox gfx pointer? (0x081E0C00)
	0x1D    u8    ?                    
	0x1E    u8    ?                    
	0x1F    u8    ?                    
	0x22    u16   keyState      
	0x24    u16   keyPress                    
		joystick->keyPress
		Stays at its default state, but changes when a key is pressed
		for a brief moment
	0x26    u16   keysFlags
		chatbox->loc_26 = joystick->IQR
		Obtained from the Joystick module
		Those are flags for which joystick
		keys are pressed.
		                    
	0x2C    u8   *pScriptCursor          
		Advances everytime a character is processed from pCurrScript
		starts at pCurrScript
			0x9C	u8		RelScriptId
			[0xZZ] <RelScriptID?>
			.# more likely to be a scriptID than 0x01!
			.# doesnt change while interacting with obj!
			.# (?)
	0x30    u16   *pScriptArray              
	0x34    u8   *pCurrScript                    
	0x38    u32   ?                    
	0x3D    u8    ?                    
	0x3E    u16   flags_3E
		When not in a choice menu, and the page chat finished typing
		Default - 0x0421 (Game code always maintains this)
			Full open chat window, no mugshot
		The following is ORR'd with Default:
		0x0002 - mugshotActive
		0x0004 - ?
		0x0008 - ?
		0x000F - pallete rainbow active in loc_40?
		0x0100 - hideChatbox
		0x04
	0x40    u32   mugshot_color_filter
		hypothesis: [0x0000RRYY]
		The last four bytes are responsible for the filtering.  
		It's more complicated logically, in the sense green and yellow alternate between even/odd YY, or some
		other logic.
		RR also alternates with blue.               
	0x44    u32   ?                    
	0x4C    u32   ?                    
	0x50    u32   ?                    
	0x54    u32   ?                    
	0x58    u32   ?                    
	0x64    u16   ?                    
	0x68    u16   ?                    
	0x6A    u16   ?                    
	0x6C    u16   ?                    
	0x6E    u16   ?                    
	0x70    u32   ?                    
	0x74    u32   ?                    
	0x78    u32   ?                    
	0x7C    u32   ?                    
	0x80    u8    ?
		temp = *(uint32_t*)&chatbox->unk_80;
      	chatbox->unk_12 = temp--;                    
	0x84    u32   ?                    
	0x88    u32   ?                    
	0x90    u32   ?                    
	0x94    u8    ?                    


Docs: ChatBoxPropreties*/
#pragma endregion Docs

#pragma region Accesses

/*
	03006F88 030070B0 0803FE88 0803FE96? 0803FF24 
	08040030 08040128 080401F0 08040318 08040358 
	080407EC 08040800 080408A4 080408EA? 08040900? 
	0804090C? 08040918 08040B0E 08040B60 08040E6C 
	08040EB0? 08040EC8 08040F44 08041012 08041034? 
	0804108A? 08041098? 080410B0? 080410CC 08041108 
	08041218 0804125C 0804127E? 0804129C 0804135C? 
	080413D4? 0804147C 080414C4? 08041B74 08041BA8 
	08041CC4 08041F84 080420F8 08042810? (jmptable) 0804288E? 
	080428BA? 080428CA? 0804290C 08042960 080429A8 
	08045F30 08139F4C 
Function Accesses */

/*
	name=ChatBoxPropreties, size=0x98
	0803FE88::0803FE8E u8(0x00), 080407EC::080407F4 u8(0x00), 08040358::0804035E u32(0x4C), 
	08040358::08040360 u32(0x50), 08040358::08040362 u32(0x54), 08040358::08040364 u32(0x58), 
	08040358::08040374 u32(0x4C), 08040358::08040376 u32(0x50), 08040358::08040378 u32(0x54), 
	08040358::0804037A u32(0x58), 08040358::0804037C u32(0x30), 08040358::0804037E u8(0x01), 
	08040358::0804038A u32(0x2C), 08040358::0804038C u32(0x34), 08040358::08040390 u8(0x00), 
	08040358::08040394 u8(0x08), 08040358::08040398 u32(0x38), 08040358::0804039C u8(0x0C), 
	08040358::080403A0 u32(0x74), 08040358::080403A2 u8(0x11), 08040358::080403A6 u32(0x78), 
	08040358::080403B6 u8(0x1D), 08040358::080403BA u8(0x1E), 08040358::080403BE u8(0x1F), 
	08040358::080403C2 u8(0x1A), 08040358::080403C6 u8(0x1B), 08040358::080403CA u8(0x18), 
	08040358::080403CE u8(0x19), 08040358::080403D4 u32(0x84), 08040358::080403DA u32(0x88), 
	08045F30::08045F34 u32(0x70), 08045F30::08045F36 u8(0x0F), 08045F30::08045F38 u8(0x0E), 
	08045F30::08045F3A u32(0x7C), 080408EA?::080408F6 u16(0x3E), 080408EA?::080408FA u16(0x3E), 
	08040358::08040410 u8(0x18), 08040358::08040416 u8(0x94+0x00), 08040358::0804041C u32(0x90), 
	0803FE96?::0803FEAA u16(0x22), 0803FE96?::0803FEAE u16(0x26), 0803FE96?::0803FEB2 u16(0x24), 
	0804090C?::0804090E u16(0x3E), 0803FE96?::0803FEC6 u32(0x78), 0803FE96?::0803FECE u32(0x78), 
	0803FE96?::0803FEDA u8(0x11), 0803FE96?::0803FEDE u8(0x11), 0803FF24::0803FF28 u8(0x11), 
	0803FF24::0803FF2A u32(0x2C), 0803FF24::0803FF34 u8(0x09), 08041012::0804101A u8(0x10), 
	08040900?::08040902 u16(0x3E), 08040900?::08040906 u16(0x3E), 08041012::08041026 u8(0x0C), 
	08041012::0804102E u8(0x0C), 0803FF24::0803FFA4 u32(0x2C), 08040318::08040322 u8(0x10), 
	08040318::0804032C u8(0x1C), 08040318::0804032E u8(0x1D), 08040318::08040332 u8(0x1E), 
	08040318::08040334 u8(0x1F), 0803FF24::0803FFC6 u8(0x10), 08041034?::08041034 u8(0x10), 
	08041034?::0804103A u8(0x10), 08041034?::0804103E u8(0x10), 08041034?::08041048 u8(0x0C), 
	0803FF24::0803FF58 u8(0x09), 0803FF24::0803FF5E u8(0x08), 0803FF24::0803FF60 u8(0x09), 
	0803FF24::0803FF6C u16(0x68), 0803FF24::0803FF76 u32(0x7C), 03006F88::03006FB0 u32(0x70), 
	03006F88::03006FB4 u32(0x70), 03006F88::03006FBC u32(0x7C), 0803FF24::0803FFA2 u8(0x09), 
	0803FF24::0803FFCC u8(0x0F), 0803FF24::0803FFD0 u8(0x3D), 0803FF24::0803FFE2 u8(0x0F), 
	0803FF24::0803FFE4 u8(0x02), 080401F0::08040202 u8(0x18), 080401F0::08040206 u8(0x19), 
	08040128::0804012C u16(0x22), 08040128::08040134 u16(0x26), 08040128::0804013A u8(0x08), 
	08040EC8::08040ED8 u8(0x03), 08040EC8::08040EDA u8(0x04), 08040EC8::08040EE6 u16(0x0C), 
	08040EC8::08040EEA u8(0x04), 030070B0::030071E2 u8(0x3D), 08040800::0804080C u8(0x03), 
	08040800::08040814 u8(0x17), 08040800::0804082E u8(0x1A), 08040800::08040830 u8(0x1B), 
	08040800::08040836 u8(0x17), 08040800::08040844 u8(0x17), 08040EC8::08040EEE u16(0x0C), 
	08040EC8::08040EF6 u16(0x0C), 08040EC8::08040EFC u8(0x04), 08040EC8::08040F08 u16(0x26), 
	08040EC8::08040F0E u16(0x22), 08040EC8::08040F2A u8(0x04), 08040EC8::08040F2C u16(0x0C), 
	08040EC8::08040F30 u32(0x74), 08040128::08040144 u8(0x11), 08040030::08040034 u8(0x11), 
	08040030::08040036 u32(0x74), 08040030::0804003C u8(0x3D), 08040030::0804003E u8(0x0F), 
	08040030::08040040 u8(0x02), 08040030::08040042 u32(0x2C), 08041BA8::08041BB0 u8(0x08), 
	08041BA8::08041BCE u32(0x34), 08041BA8::08041BD2 u8(0x04), 08041BA8::08041BD4 u32(0x64), 
	08041BA8::08041BD6 u8(0x12), 08041BA8::08041BD8 u8(0x02), 08041BA8::08041BDA u8(0x17), 
	08041BA8::08041BDE u8(0x3D), 08041BA8::08041BE2 u32(0x80), 08041BA8::08041BE6 u32(0x78), 
	08041BA8::08041BEA u8(0x11), 08041BA8::08041BEC u32(0x74), 08041BA8::08041BEE u8(0x08), 
	08041BA8::08041BF0 u8(0x18), 08041BA8::08041BF6 u8(0x94+0x00), 08040030::0804008C u32(0x2C), 
	08040030::0804008E u16(0x3E), 08040030::08040094 u32(0x74), 08040030::0804009C u8(0x11), 
	08040030::080400C6 u8(0x10), 08040030::080400CC u8(0x02), 08040030::080400D4 u8(0x0F), 
	08040030::080400D6 u8(0x02), 08040030::080400F0 u8(0x11), 08040030::08040068 u32(0x7C), 
	08041108::0804110A u8(0x0F), 08041108::0804110E u8(0x0F), 08041108::08041112 u32(0x70), 
	08041108::08041128 u32(0x7C), 08040030::080400DE u8(0x02), 08040E6C::08040E6E u8(0x05), 
	0804108A?::0804108A u8(0x0C), 08041098?::08041098 u8(0x10), 08041098?::0804109E u8(0x10), 
	08041098?::080410A6 u8(0x10), 08041098?::080410AA u8(0x0C), 080410B0?::080410B2 u8(0x0C), 
	08040EB0?::08040EB8 u8(0x00), 08040EB0?::08040EBA u8(0x04), 080408A4::080408A6 u8(0x01), 
	080408A4::080408A8 u32(0x30), 080408A4::080408B0 u32(0x2C), 080408A4::080408B2 u32(0x34), 
	080408A4::080408B8 u8(0x04), 080408A4::080408BA u32(0x64), 080408A4::080408BC u8(0x12), 
	080408A4::080408BE u8(0x02), 080408A4::080408C0 u8(0x17), 080408A4::080408C4 u8(0x3D), 
	080408A4::080408C8 u32(0x80), 080408A4::080408CC u8(0x11), 080408A4::080408CE u32(0x74), 
	080408A4::080408D0 u8(0x08), 080408A4::080408D2 u8(0x18), 080408A4::080408D8 u8(0x94+0x00), 
	08041CC4::08041CF6 u32(0x40), 08041CC4::08041D0E u8(0x07), 08041CC4::08041D30 u8(0x14), 
	08041CC4::08041D32 u8(0x0A), 08041CC4::08041D3A u8(0x0B), 08040B0E::08040B32 u8(0x0A), 
	08040B0E::08040B3C u32(0x90), 08040B0E::08040B4C u32(0x84), 08040B0E::08040B52 u32(0x88), 
	08040B60::08040B72 u8(0x10), 08040B60::08040B78 u32(0x40), 08040B60::08040B84 u32(0x40), 
	08040B60::08040BB6 u32(0x40), 08040B60::08040BBA u8(0x07), 08040EC8::08040F16 u16(0x0C), 
	08040EC8::08040F1E u16(0x0C), 08040B60::08040BA2 u32(0x40), 08041F84::08041F86 u8(0x05), 
	08041F84::08041F8A u8(0x05), 08041F84::08041FF6 u16(0x64+0x00), 08041F84::0804200C u16(0x64+0x00), 
	08041F84::08042010 u16(0x64+0x00), 08041F84::08042012 u32(0x2C), 08041F84::08042016 u32(0x44), 
	08041F84::0804201A u8(0x05), 08040E6C::08040E80 u8(0x05), 0804290C::0804293E u8(0x18), 
	0804290C::08042942 u8(0x18), 0804290C::0804294A u8(0x94+0x00), 0804290C::08042952 u32(0x7C), 
	0804290C::08042956 u32(0x7C), 08041218::08041222 u16(0x0C), 08041218::08041226 u32(0x80), 
	08041218::08041242 u32(0x70), 08041218::08041248 u32(0x80), 08041218::0804124A u8(0x12), 
	08041218::0804124E u8(0x13), 08041218::08041252 u8(0x0F), 0804125C::0804126A u32(0x70), 
	0804125C::0804126E u32(0x70), 0804125C::08041270 u32(0x7C), 0804125C::08041276 u32(0x7C), 
	0804129C::080412A4 u8(0x13), 0804129C::080412B6 u8(0x04), 0804129C::080412BC u16(0x24), 
	0804129C::080412F2 u8(0x13), 0804129C::080412F6 u8(0x04), 0804129C::08041308 u8(0x04), 
	0804129C::0804131E u8(0x04), 0804129C::080412FC u16(0x0C), 0804129C::08041304 u16(0x0C), 
	0804129C::08041336 u8(0x13), 0804129C::08041344 u32(0x70), 0804129C::0804134A u8(0x0F), 
	0804129C::0804134C u8(0x0F), 08040918::0804091A u8(0x16), 08040918::08040932 u8(0x94+0x00), 
	08040918::08040934 u32(0x70), 08040918::0804093A u8(0x0F), 08040918::08040940 u8(0x19), 
	08040918::0804094A u8(0x16), 08040918::0804095A u8(0x16), 0804129C::08041356 u8(0x0F), 
	0804129C::080412D6 u16(0x24), 0804129C::080412DE u8(0x13), 0804129C::080412E0 u8(0x13), 
	0804129C::08041328 u16(0x26), 0804129C::080412E8 u16(0x0C), 0804129C::080412EC u16(0x6C), 
	0804135C?::08041368 u16(0x6E), 0804135C?::0804137A u8(0x13), 0804135C?::08041380 u8(0x13), 
	0804135C?::08041384 u8(0x80), 0804135C?::08041394 u8(0x13), 0804135C?::080413C4 u8(0x04), 
	0804135C?::080413C8 u32(0x78), 0803FF24::0803FFDA u8(0x02), 0804147C::08041490 u8(0x11), 
	0804147C::080414A2 u8(0x04), 0804147C::080414B0 u16(0x0C), 0804147C::080414B4 u8(0x04), 
	0804147C::080414B6 u16(0x0C), 0804147C::080414BE u16(0x0C), 080414C4?::080414CC u8(0x04), 
	08040F44::08040F8A u8(0x1A), 08040F44::08040F8C u8(0x1B), 080410CC::080410D6 u8(0x10), 
	08041B74::08041B78 u8(0x08), 0804127E?::08041280 u32(0x70), 0804127E?::08041284 u32(0x70), 
	0804127E?::08041286 u32(0x7C), 0804127E?::0804128C u32(0x7C), 080413D4?::080413F0 u32(0x80), 
	080413D4?::080413F2 u8(0x12), 080413D4?::080413F6 u8(0x13), 080413D4?::08041408 u16(0x6A), 
	080413D4?::08041410 u8(0x04), 080413D4?::08041414 u16(0x0C), 080413D4?::0804141C u8(0x13), 
	080413D4?::0804142A u8(0x0F), 080413D4?::0804142C u8(0x0F), 080413D4?::08041436 u8(0x0F), 
	0804135C?::08041392 u8(0x13), 0804135C?::080413B0 u32(0x64), 0804135C?::080413B4 u32(0x74), 
	0804135C?::080413B6 u32(0x2C), 0804135C?::080413B8 u32(0x34), 0803FE96?::0803FEB8 u16(0x22), 
	0803FE96?::0803FEBA u16(0x26), 0803FE96?::0803FEBC u16(0x24), 08042960::0804298E u8(0x18), 
	08042960::08042996 u8(0x94+0x00), 08042960::0804299A u32(0x7C), 08042960::0804299E u32(0x7C), 
	0804288E?::08042892 u8(0x18), 0804288E?::08042896 u8(0x1A), 0804288E?::0804289A u8(0x19), 
	0804288E?::080428A4 u8(0x1B), 0804288E?::080428A6 u8(0x18), 0804288E?::080428AC u8(0x94+0x00), 
	080428BA?::080428BE u8(0x1A), 080428BA?::080428C2 u8(0x1B), 08042810?::08042840 u8(0x15), 
	08042810?::08042848 u8(0x1C), 08042810?::0804284C u8(0x1E), 08042810?::08042854 u8(0x1A), 
	08042810?::08042858 u8(0x1D), 08042810?::0804285C u8(0x1F), 08042810?::08042864 u8(0x1B), 
	080428CA?::080428D0 u32(0x84), 080428CA?::080428D6 u32(0x88), 080429A8::080429C6 u8(0x18), 
	080429A8::080429CE u8(0x94+0x00), 080429A8::080429D6 u32(0x7C), 080429A8::080429DA u32(0x7C), 
	0804129C::0804131A u8(0x13), 08139F4C::08139F98 u32(0x4C), 08139F4C::08139FB0 u32(0x50), 
	08139F4C::08139FC6 u32(0x54), 080420F8::080420FA u8(0x05), 080420F8::080420FE u8(0x05), 
	080420F8::0804210C u32(0x4C), 080420F8::0804212E u32(0x2C), 080420F8::08042132 u32(0x44), 
	080420F8::08042136 u8(0x05), 

Accesses */

#pragma endregion Accesses


#endif /* S_02009CD0_H */