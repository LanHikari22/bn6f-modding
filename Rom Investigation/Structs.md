s_020093B0 <sChiefStruct>:
	Description
		Table of other structs.
		Always accessible. Seems to be the toolkit to everything else.
	Length
		Unknown
	Other Instances
		Probably None
	
s_02009CD0 <sNoname>:
	Description
		So far, I can just tell it seems to control various things in
		the textbox.
	Length
		Unknown
	0x00 [0xZZ] <showFlag>
		# enable bit for textbox? Only Hides textbox when in-chat.
	0x10 [0xZZ]
		# determines textbox width and content state
	0x18 [0xYYXX] <textCoord>
		# coord of text body
	0x1A [0xYYXX] <csrCoord>
		# coord of text cursor
	0x1C [0xPPPPYYXX]
		# textbox gfx pointer? (0x081E0C00)
	0x22 [0xKKKK] <keyState_onChip>
		# keyState (only active on-chat)
	0x24 [0xKKKK]
		# KeyState? (Unexplored behavior)
	0x2C [0xPPPPPPPP] <pCurrScript>. 
		# changing causes mouth animations.
	0x30-0x38 [0xPPPPPPPP]
		# 0-1: pointers
		# 2:   magic: 0x0200B2B0
	0x1f8 [0xPPPPPPPP] <pGfx>
		# (?)
	
	0x3C

s_0203A9B0 <sBtlPlayer>:
	Description
		Holds some battle parameters such as HP of a battle obj
	Length
		0xD8 Bytes. End: 0x0203AB60
	Other Instances
		s_0203AA88 <sEnemyA>
		s_0203AB60 <sEnemyB>
		s_0203AC38 <sEnemyC>
	0x00 [0xXXYZ] <ctrl>
		# [0xXX00]: ID? changing This crashes the game.
		# 01: First enemy, 02: Second Enemy... it's like an... ID?
		# [0x00Y0]: Undetermined Functionality
		# [0x000Z]: Can make one enemy go invisible
	0x02
		# [0x00Z0]: Weird. Can crash game, or change enemy sprite
	0x08
		# [0xZZ00]: can make enemy use a chip?!
		# [0x000Z]: Freeze game or make enemy invisible
	0x10
		# Keeps alternating with sprites. modification makes sprite
		# weird.
	0x12 [0x0R0C] <attackCoord>
		# R, Row of attack. C, Column of attack.
	0x14
		# Seems to be like 0x12, maybe for another attack?
	0x16 [0x000Z]
		# Reverses direction of attack, or inverses it?
		#			Or nullifies it?
	0x24 [0xZZZZ] <HP>
		# 0203AAAC; HALF WORD
		# One Enemy's HP
	0x36 [0xXXXX] <x>
		# [0xZZZZ]: X-coordinant of enemy
	0x3A [0xYYYY] <y>
		# [0xZZZZ]: Y-coordinant of enemy
	0x3E [0xZZZZ] <z>
		# [0xZZZZ]: Controls depth or virus? makes it float...
	0x54 [0xPPPPPPPP]
		# A Pointer
		# Has something to do with side effects to enemy AND player
		# Might be a function pointer to status effects.
	0x58 [0xPPPPPPPP]
		# A Pointer
		# Changing this crashes the game.
	0x90 [0xZZZZ]
		# Keeps changing. Seems to have something to do
		# with the sprite.
	0x92 [0xZZZZ]
		# Doesn't change much, modification causes sprite glitches
	0x94 [0x00ZZ] <pallete>
		# Pallet of enemy! Not Pure RGB, Different color modes
		# like stronger versions of said enemy/virus!!
	0xA0 [0xZZZZ]
		# Does some weird coordinant/sprite shift?
	0xA2 [0xZZZZ]
		# Also does weird sprite shift. Too creepy.
	0xA6 [0x00Z0] <facingDirection>
		#Where the enemy is facing! You can mirror the enemy!
		# Ultimately, It seems the value is mod 4, since there are only
		# 4 Directions the enemy can face.

s_020384F0 <sBtlPlayerStatus>:
	Description
		This structure was being updated constantly alongside
		the battle structures via calling sub_0800E2D8
	Length 
		0x34 bytes
	Other Instances
		s_02038524 <sEnemyAStatus>
	0x02 [0x00Z0]
		# Insta kill if hit!
	0x0C [0xZZ00]
		# Counter hit clock! Not 0? It seems you get a crit hit!
	0x10 [0x0Z00]
		# Triggering that seems to make us take a SUPER DUPER
		# damage, as if we're weak to the attack, and BOOM!
	0x24 [0xZZZZ] <invisClock>
		# Invincibility clock! Not 0? You're invincible!
	0x26 [0xZZZZ] ...
		# Clocks for various different effects!
	0x40 [0x000Z]
		# Auto Destruct
		
s_02005BE8 <sNPC_copybotneardog>
	TODO
		Formatting. Still didn't settle on a good reporting format...
	Description
		# Overworld parameters and encapsulation of NPC objs?
	Length
		0x1B0 bytes
	Other Instances (?)
		s_02005F48 # Subchip seller guy
		s_020062A8 # Another copybot
		s_02006458 # Enemy copybot, sigh
		s_02005C38 # seems to be a struct of its own? (0x50)
	0x00 [0x000Z]
		# Changing that made collision on NPC collapse!
		# Z = 3 seems to indicate that the NPC is active?
		# inactive NPCs can't be "talked to" through 0x08
	0x08 [0x000Z] <convTrigger>
		# Z = 8: Trigger a certain conversation
		# Many other values just crash?
	0x1C [0x00ZZ]
		# Changes conversation of copybot!!
	0x3C [0x00ZZ] <sprite>
		# Changes sprite! some are neat, some are weird.
	0x50 [0x000Z]
		# For any Z, a certain conversation is triggered
		# Value constantly written to unless PET is open, for example
		# <0800385C> breaks whenever you talk to a character hmm..

s_02035280 <sNoname>:
	TODO
		# Again, Formatting. See, I'm just copypasting this. I've been researching on my own before and all.
	Description
		This seems to be a structure responsible for gui properties in battles
	<fields> (Default: [0xZZZZ])
	0x00
		Weird effect when it comes to HP bars
	0x48
		[word]
		Seems to be an active pointer to Megaman's status settings or something?
		
s_02001B80 <sNoName>:
	Description
		TODO
	Length
		Unknown
	Other Instances
		Unknown
	0x00 [0xZZ]
		Deadly parameter. Many values cause gfx glitches and crash.
		Z=0x00 Causes all NPC objects to disappear.
	0x08 [0xZZ]
		This can change L chat to Dummy Text, or other predefined text.
		or it can crash the game.
	
		