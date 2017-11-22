#ifndef S_02009CD0_H
#define S_02009CD0_H
#pragma region Docs
/*
s_02009CD0 <sNoname>:
	Description
		So far, I can just tell it seems to control various things in
		the textbox.
	Length
		Unknown
	0x00 [0xZZ] <showFlag>
		.# enable bit for textbox? Only Hides textbox when in-chat.
	0x01 [0xZZ] <scriptID?>
		.#
	0x10 [0xZZ]
		.# determines textbox width and content state
	0x18 [0xYYXX] <textCoord>
		.# coord of text body
	0x1A [0xYYXX] <csrCoord>
		.# coord of text cursor
	0x1C [0xPPPPYYXX]
		.# textbox gfx pointer? (0x081E0C00)
	0x22 [0xKKKK] <keyState_onChip>
		.# keyState (only active on-chat)
	0x24 [0xKKKK]
		.# KeyState? (Unexplored behavior)
	0x2C [0xPPPPPPPP] <pCurrScript>. 
		.# changing causes mouth animations.
	0x30-0x38 [0xPPPPPPPP]
		.# 0-1: pointers
		.# 2:   magic: 0x0200B2B0
	0x9C [0xZZ] <RelScriptID?>
		.# more likely to be a scriptID than 0x01!
		.# doesnt change while interacting with obj!
	0x1f8 [0xPPPPPPPP] <pGfx>
		.# (?)
	
	0x3C
*/
#pragma endregion Docs

#endif /* S_02009CD0_H */