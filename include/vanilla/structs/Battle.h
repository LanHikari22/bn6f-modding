#ifndef BATTLE_H
#define BAALE_H
#include <inttypes.h>

/* Battle Structure, and variations of it in memory ********************/
/**
* Description: Holds some battle parameters such as battle of a battle
* object.
* Length: 0xD8 bytes
*/
typedef struct{
	uint16_t ctrl;				// loc=0x00
		uint8_t pad1202 [0x12 - 0x02];
	uint16_t attackCoord;		// loc=0x12
		uint8_t pad2414 [0x24 - 0x14];
	uint16_t HP;				// loc=0x24
		uint8_t pad3626 [0x36 - 0x26];
	uint16_t x;					// loc=0x36
		uint8_t pad3A38 [0x3A - 0x38];
	uint16_t y;					// loc=0x3A
		uint8_t pad3E3C [0x3E - 0x3C];
	uint16_t z;					// loc=0x3E
		uint8_t pad943F [0x94 - 0x40]; 
	uint16_t pallete;			// loc=0x94
		uint8_t padA696 [0xA6 - 0x96];
	uint16_t facingDirection;	// loc=0xA6
		uint8_t padD8A8 [0xD8 - 0xA8];
	// size=0xD8	
}Battle;


#define sBtlEnemyA 	((Battle*)0x0203AA88)
#define sBtlEnemyB 	((Battle*)0x0203AB60)
#define sBtlEnemyC 	((Battle*)0x0203AC38)
#define sBtlPlayer 	((Battle*)0x0203A9B0)

#pragma region Docs
/*
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
		.# [0xXX00]: ID? changing This crashes the game.
		.# 01: First enemy, 02: Second Enemy... its like an... ID?
		.# [0x00Y0]: Undetermined Functionality
		.# [0x000Z]: Can make one enemy go invisible
	0x02
		.# [0x00Z0]: Weird. Can crash game, or change enemy sprite
	0x08
		.# [0xZZ00]: can make enemy use a chip?!
		.# [0x000Z]: Freeze game or make enemy invisible
	0x10
		.# Keeps alternating with sprites. modification makes sprite
		.# weird.
	0x12 [0x0R0C] <attackCoord>
		.# R, Row of attack. C, Column of attack.
	0x14
		.# Seems to be like 0x12, maybe for another attack?
	0x16 [0x000Z]
		.# Reverses direction of attack, or inverses it?
		.#			Or nullifies it?
	0x24 [0xZZZZ] <HP>
		.# 0203AAAC; HALF WORD
		.# One Enemys HP
	0x36 [0xXXXX] <x>
		.# [0xZZZZ]: X-coordinant of enemy
	0x3A [0xYYYY] <y>
		.# [0xZZZZ]: Y-coordinant of enemy
	0x3E [0xZZZZ] <z>
		.# [0xZZZZ]: Controls depth or virus? makes it float...
	0x54 [0xPPPPPPPP]
		.# A Pointer
		.# Has something to do with side effects to enemy AND player
		.# Might be a function pointer to status effects.
	0x58 [0xPPPPPPPP]
		.# A Pointer
		.# Changing this crashes the game.
	0x90 [0xZZZZ]
		.# Keeps changing. Seems to have something to do
		.# with the sprite.
	0x92 [0xZZZZ]
		.# Doesnt change much, modification causes sprite glitches
	0x94 [0x00ZZ] <pallete>
		.# Pallet of enemy! Not Pure RGB, Different color modes
		.# like stronger versions of said enemy/virus!!
	0xA0 [0xZZZZ]
		.# Does some weird coordinant/sprite shift?
	0xA2 [0xZZZZ]
		.# Also does weird sprite shift. Too creepy.
	0xA6 [0x00Z0] <facingDirection>
		.#Where the enemy is facing! You can mirror the enemy!
		.# Ultimately, It seems the value is mod 4, since there are only
		.# 4 Directions the enemy can face.
*/
#pragma endregion

#pragma region sBtlPlayerStatus	
/*
s_020384F0 <sBtlPlayerStatus>:
	Description
		This structure was being updated constantly alongside
		the battle structures via calling sub_0800E2D8
	Length 
		0x34 bytes
	Other Instances
		s_02038524 <sEnemyAStatus>
	0x02 [0x00Z0]
		.# Insta kill if hit!
	0x0C [0xZZ00]
		.# Counter hit clock! Not 0? It seems you get a crit hit!
	0x10 [0x0Z00]
		.# Triggering that seems to make us take a SUPER DUPER
		.# damage, as if we're weak to the attack, and BOOM!
	0x24 [0xZZZZ] <invisClock>
		.# Invincibility clock! Not 0? You're invincible!
	0x26 [0xZZZZ] ...
		.# Clocks for various different effects!
	0x40 [0x000Z]
		.# Auto Destruct
*/		
#pragma endregion sBtlPlayerStatus	

#endif /* BATTLE_H */