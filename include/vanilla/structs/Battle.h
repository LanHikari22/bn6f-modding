#ifndef BATTLE_H
#define BATTLE_H
#include "../../inttypes.h"

/**
 * Structure obtained from sub_080182B4
 */
typedef struct {
	// size=0x3
}s_080182C4

typedef struct {
	uint8_t naviVirusIndicator;        // loc=0x0
	uint8_t AI_index;                  // loc=0x1
	uint8_t unk_02;                    // loc=0x2
	uint8_t unk_03;                    // loc=0x3
		uint8_t pad_04[0x05];             
	uint8_t unk_09;                    // loc=0x9
		uint8_t pad_0A[0x02];             
	uint8_t unk_0C;                    // loc=0xC
		uint8_t pad_0D[0x01];             
	uint8_t unk_0E;                    // loc=0xE
		uint8_t pad_0F[0x03];             
	uint8_t unk_12;                    // loc=0x12
		uint8_t pad_13[0x03];             
	uint8_t level;                     // loc=0x16
	uint8_t level2;                    // loc=0x17
		uint8_t pad_18[0x01];             
	uint8_t unk_19;                    // loc=0x19
	uint8_t unk_1A;                    // loc=0x1A
	uint8_t unk_1B;                    // loc=0x1B
		uint8_t pad_1C[0x01];             
	uint8_t unk_1D;                    // loc=0x1D
	uint8_t unk_1E;                    // loc=0x1E
		uint8_t pad_1F[0x01];             
	uint16_t totalDamageReceived;      // loc=0x20
	uint16_t keysHeld;                 // loc=0x22
	uint16_t keysDown;                 // loc=0x24
	uint16_t keysUp;                   // loc=0x26
	uint16_t prevKeysHeld;             // loc=0x28
		uint8_t pad_2A[0x08];             
	uint16_t unk_32;                   // loc=0x32
	uint16_t isAngry;                  // loc=0x34
	uint16_t unk_36;                   // loc=0x36
	uint16_t unk_38;                   // loc=0x38
		uint8_t pad_3A[0x02];             
	uint16_t unk_3C;                   // loc=0x3C
		uint8_t pad_3E[0x02];             
	uint32_t unk_40;                   // loc=0x40
	uint32_t unk_44;                   // loc=0x44
	uint32_t unk_48;                   // loc=0x48
		uint8_t pad_4C[0x08];             
	uint32_t unk_54;                   // loc=0x54
		uint8_t pad_58[0x08];             
	uint32_t unk_60;                   // loc=0x60
		uint8_t pad_64[0x04];             
	uint32_t unk_68;                   // loc=0x68
		uint8_t pad_6C[0x08];             
	uint32_t unk_74;                   // loc=0x74
	uint32_t unk_78;                   // loc=0x78
	uint32_t unk_7C;                   // loc=0x7C
	uint8_t AI_state[0x20];            // loc=0x80 size=0x20
	uint8_t attackVarRegion[0x50];     // loc=0xA0 size=0x50
		uint8_t pad_F0[0x10];             
	// size=0x100
}AI;

typedef struct {
	uint8_t enable;                         // loc=0x0
	uint8_t collisionRegion;                // loc=0x1
	uint8_t primaryElement;                 // loc=0x2
	uint8_t unk_03;                         // loc=0x3
	uint8_t alliance;                       // loc=0x4
	uint8_t flip;                           // loc=0x5
	uint8_t unk_06;                         // loc=0x6
	uint8_t staminaDmg_counterDisabler;     // loc=0x7
	uint8_t poisonPanelTimer;               // loc=0x8
		uint8_t pad_09[0x01];                  
	uint8_t panelX;                         // loc=0xA
	uint8_t panelY;                         // loc=0xB
	uint8_t direction;                      // loc=0xC
	uint8_t counterTimer;                   // loc=0xD
	uint8_t hitModifierBase;                // loc=0xE
	uint8_t hitModifierFinal;               // loc=0xF
	uint8_t statusEffectBase;               // loc=0x10
	uint8_t statusEffectFinal;              // loc=0x11
	uint16_t bugs;                          // loc=0x12
		uint8_t pad_14[0x04];                  
	uint8_t secondaryElementWeakness;       // loc=0x18
	uint8_t secondaryElement;               // loc=0x19
		uint8_t pad_1A[0x02];                  
	uint16_t unk_1C;                        // loc=0x1C
	uint16_t unk_1E;                        // loc=0x1E
	uint16_t unk_20;                        // loc=0x20
	uint16_t unk_22;                        // loc=0x22
	uint16_t unk_24;                        // loc=0x24
	uint16_t unk_26;                        // loc=0x26
	uint16_t unk_28;                        // loc=0x28
	uint16_t unk_2A;                        // loc=0x2A
	uint16_t unk_2C;                        // loc=0x2C
	uint16_t selfDamage;                    // loc=0x2E
	uint32_t selfCollisionTypeFlags;        // loc=0x30
	uint32_t targetCollisionTypeFlags;      // loc=0x34
	uint32_t *parentObject;                 // loc=0x38
	uint32_t objectFlags;                   // loc=0x3C
	uint32_t objectFlags2;                  // loc=0x40
	uint32_t collisionIndexBit;             // loc=0x44
	uint32_t unk_48;                        // loc=0x48
	uint32_t unk_4C;                        // loc=0x4C
		uint8_t pad_50[0x04];                  
	uint32_t unk_54;                        // loc=0x54
		uint8_t pad_58[0x08];                  
	uint32_t unk_60;                        // loc=0x60
	uint32_t unk_64;                        // loc=0x64
	uint32_t unk_68;                        // loc=0x68
	uint32_t unk_6C;                        // loc=0x6C
	uint32_t collisionFlags;                // loc=0x70
	uint8_t factorialIndicator;             // loc=0x74
	uint8_t damageMultiplier;               // loc=0x75
	uint8_t damageElements;                 // loc=0x76
	uint8_t unk_77;                         // loc=0x77
	uint16_t unk_78;                        // loc=0x78
		uint8_t pad_7A[0x02];                  
	uint32_t unk_7C;                        // loc=0x7C
	uint16_t finalDamage;                   // loc=0x80
	uint16_t panelDamage1;                  // loc=0x82
	uint16_t panelDamage2;                  // loc=0x84
	uint16_t panelDamage3;                  // loc=0x86
	uint16_t panelDamage4;                  // loc=0x88
	uint16_t panelDamage5;                  // loc=0x8A
	uint16_t panelDamage6;                  // loc=0x8C
	uint16_t unk_8E;                        // loc=0x8E
	uint16_t unk_90;                        // loc=0x90
	uint16_t unk_92;                        // loc=0x92
	uint16_t unk_94;                        // loc=0x94
		uint8_t pad_96[0x0A];                  
	uint32_t unk_A0;                        // loc=0xA0
	uint8_t inflictedBugs;                  // loc=0xA4
		uint8_t pad_A5[0x03];                  
	// size=0xA8
}CollisionData;

/* Battle Structure, and variations of it in memory ********************/
/**
* Description: Holds some battle parameters such as battle of a battle
* object.
* Length: 0xD8 bytes
*/
typedef struct {
	uint8_t objFlags;                        // loc=0x0
	uint8_t objIndex;                        // loc=0x1
	uint8_t objTypeSpriteOff;                // loc=0x2
	uint8_t objMemIndex;                     // loc=0x3
	uint32_t objParams;                      // loc=0x4
	uint8_t currState;                       // loc=0x8
	uint8_t currAction;                      // loc=0x9
	uint8_t currPhase;                       // loc=0xA
	uint8_t phaseInitialized;                // loc=0xB
		uint8_t pad_0C[0x01];                   
	uint8_t unk_0D;                          // loc=0xD
	uint8_t Element;                         // loc=0xE
	uint8_t unk_0F;                          // loc=0xF
	uint8_t currAnimation;                   // loc=0x10
	uint8_t currAnimationCpy;                // loc=0x11
	uint8_t panelX;                          // loc=0x12
	uint8_t panelY;                          // loc=0x13
	uint8_t futurePanelX;                    // loc=0x14
	uint8_t futurePanelY;                    // loc=0x15
	uint8_t Alliance;                        // loc=0x16
	uint8_t directionFlip;                   // loc=0x17
	uint8_t preventAnimation;                // loc=0x18
	uint8_t unk_19;                          // loc=0x19
	uint8_t chipsHeld;                       // loc=0x1A
		uint8_t pad_1B[0x01];                   
	uint8_t unk_1C;                          // loc=0x1C
	uint8_t unk_1D;                          // loc=0x1D
		uint8_t pad_1E[0x01];                   
	uint8_t unk_1F;                          // loc=0x1F
	uint16_t Timer;                          // loc=0x20
	uint16_t Timer2;                         // loc=0x22
	uint16_t HP;                             // loc=0x24
	uint16_t maxHP;                          // loc=0x26
	uint16_t nameID;                         // loc=0x28
	uint16_t chip;                           // loc=0x2A
	uint16_t damage;                         // loc=0x2C
	uint16_t staminaDmg_counterDisabler;     // loc=0x2E
	uint16_t unk_30;                         // loc=0x30
	uint16_t unk_32;                         // loc=0x32
	uint32_t x;                              // loc=0x34
	uint32_t y;                              // loc=0x38
	uint32_t z;                              // loc=0x3C
	uint32_t vx;                             // loc=0x40
	uint32_t vy;                             // loc=0x44
	uint32_t vz;                             // loc=0x48
	uint32_t *parent;                        // loc=0x4C
	uint32_t *childobject2;                  // loc=0x50
	CollisionData *collisionData;                  // loc=0x54
	AI *ai;                             // loc=0x58
	uint32_t unk_5C;                         // loc=0x5C
	uint8_t extraVars[0x2C];                 // loc=0x60 size=0x2C
	// size=0x8C
	uint32_t y;                              // loc=0x38
	uint32_t z;                              // loc=0x3C
	uint32_t vx;                             // loc=0x40
	uint32_t vy;                             // loc=0x44
	uint32_t vz;                             // loc=0x48
	uint32_t *parent;                        // loc=0x4C
	uint32_t *childobject2;                  // loc=0x50
	CollisionData *collisionData;                  // loc=0x54
	AI *ai;                             // loc=0x58
	uint32_t unk_5C;                         // loc=0x5C
	uint8_t extraVars[0x2C];                 // loc=0x60 size=0x2C
	// size=0x8C
}Battle;


#define sBtlEnemyA 	((Battle*)0x0203AA88)
#define sBtlEnemyB 	((Battle*)0x0203AB60)
#define sBtlEnemyC 	((Battle*)0x0203AC38)
#define sBtlPlayer 	((Battle*)0x0203A9B0)

#pragma region Docs

/*
	[Header]
		[Name] AI
		[Size] 0x100
		[Description]
	Offset  Type  Name 
	0x00    u8    naviVirusIndicator
		0x00 - Virus
		0x01 - Navi
		0x02 - Player
	0x01    u8    AI_index    
	0x02    u8    ?    
	0x03    u8    ?    
	0x09    u8    ?    
	0x0C    u8    ?    
	0x0E    u8    ?
		FF?    
	0x12    u8    ?    
	0x16    u8    level
		Version/Level    
	0x17    u8    level2
		Also Version/Level?? TODO: investigate off 0x16 and 0x17    
	0x19    u8    ?    
	0x1A    u8    ?    
	0x1B    u8    ?    
	0x1D    u8    ?    
	0x1E    u8    ?    
	0x20    u16   totalDamageReceived    
	0x22    u16   keysHeld
	0x24    u16   keysDown
	0x26    u16   keysUp
	0x28    u16   prevKeysHeld
	0x32    u16   ?    
	0x34    u16   isAngry
		anger bool    
	0x36    u16   ?    
	0x38    u16   ?    
	0x3C    u16   ?    
	0x40    u32   ?    
	0x44    u32   ?    
	0x48    u32   ?    
	0x54    u32   ?    
	0x60    u32   ?    
	0x68    u32   ?    
	0x74    u32   ?    
	0x78    u32   ?    
	0x7C    u32   ?    
	0x80    u8    AI_state[0x20]
		[Size] 0x20
		Start of AI state (0x20 bytes)    
		0x82    u8    ?    
		0x84    u8    ?    
		0x85    u8    ?    
		0x86    u8    ?    
		0x87    u8    ?    
	0xA0    u8    attackVarRegion[0x50]
		[Size] 0x50
		start of attack variable region (0x50 bytes)    
		0xA1    u8    ?    
		0xA2    u8    ?    
		0xA3    u8    ?    
		0xA8    u16   ?    
		0xAA    u16   ?    
		0xAC    u8    ?    
		0xAD    u8    ?    
		0xAE    u8    ?    
		0xAF    u8    ?    
		0xB0    u16   ?    
		0xB2    u16   ?    
		0xB6    u8    ?    
		0xB7    u8    ?    
		0xB8    u16   ?    
		0xBA    u8    ?    
		0xBB    u8    ?    
		0xBC    u8    ?    
		0xBD    u8    ?    
		0xBE    u16   ?    
		0xC8    u32   ?    
		0xCC    u32   ?    
		0xD0    u32   ?    
		0xD4    u32   ?    
		0xD8    u32   ?    
		0xDC    u32   ?    

AI*/

/*
	[Header]
	[Name] CollisionData
	[Size] 0xA8
	[Description]
	Offset  Type  Name 
	0x00    u8    enable
		Enabled/Disabled?
	0x01    u8    collisionRegion
	0x02    u8    primaryElement    
	0x03    u8    ?    
	0x04    u8    alliance    
	0x05    u8    flip    
	0x06    u8    ?    
	0x07    u8    staminaDmg_counterDisabler    
	0x08    u8    poisonPanelTimer    
	0x0A    u8    panelX    
	0x0B    u8    panelY    
	0x0C    u8    direction    
	0x0D    u8    counterTimer    
	0x0E    u8    hitModifierBase    
	0x0F    u8    hitModifierFinal    
	0x10    u8    statusEffectBase    
	0x11    u8    statusEffectFinal    
	0x12    u16   bugs
		TODO: Is the whole u16 on bugs?    
	0x18    u8    secondaryElementWeakness    
	0x19    u8    secondaryElement    
	0x1C    u16   ?    
	0x1E    u16   ?    
	0x20    u16   ?    
	0x22    u16   ?    
	0x24    u16   ?    
	0x26    u16   ?    
	0x28    u16   ?    
	0x2A    u16   ?    
	0x2C    u16   ?    
	0x2E    u16   selfDamage    
	0x30    u32   selfCollisionTypeFlags    
	0x34    u32   targetCollisionTypeFlags    
	0x38    u32   *parentObject    
	0x3C    u32   objectFlags
		0x00000001 Guard
		0x00000008 invulnerable
		0x00000010 airshoe
		0x00000020 floatshoe
		0x00000040 currently moving
		0x00000800 paralyzed
		0x00004000 immobilized
		0x00010000 frozen
		0x00020000 superarmor
		0x00040000 undershirt
		0x00080000 currently moving
		0x02000000 affected by ice
		0x08000000 unaffected by poison
	0x40    u32   objectFlags2
	0x44    u32   collisionIndexBit
		TODO: [Investigate] Bit? This is a u32 though.
	0x48    u32   ?    
	0x4C    u32   ?    
	0x54    u32   ?    
	0x60    u32   ?    
	0x64    u32   ?    
	0x68    u32   ?    
	0x6C    u32   ?    
	0x70    u32   collisionFlags
		flags from a collision(bits from Collision Type list)    
	0x74    u8    factorialIndicator
		!! indicator. Oops, a joke in names p:
	0x75    u8    damageMultiplier
	0x76    u8    damageElements
	0x77    u8    ?
	0x78    u16   ?    
	0x7C    u32   ?    
	0x80    u16   finalDamage    
	0x82    u16   panelDamage1
	0x84    u16   panelDamage2
	0x86    u16   panelDamage3
	0x88    u16   panelDamage4
	0x8A    u16   panelDamage5
	0x8C    u16   panelDamage6
		used for poison
	0x8E    u16   ?    
	0x90    u16   ?    
	0x92    u16   ?    
	0x94    u16   ?    
	0xA0    u32   ?    
	0xA4    u8    inflictedBugs    
CollisionData*/

/*
	[Header]
		[Name] Battle
		[Size] 0x8C
		[Description]
		Objects can have collision data and AI data
		x, y, z, vx, vy, vz are 16.16 fixed point integers. 
		upper 16 bits are the integer portion, lower are the decimal region
		x,y and z are also relative to the center of the battlefield
	Offset  Type             Name                          
	0x00    u8               objFlags                      
				0x01 active
				0x02 visable
				0x04 updates during pause
				0x08 Hide/Dont update sprite
				0x10 updates during timestop	
	0x01    u8               objIndex                      
	0x02    u8               objTypeSpriteOff              
				object type/sprite offset
				0x0F Object type
				0xF0 relative sprite data offset (from start of object)
	0x03    u8               objMemIndex                   
				object memory index
	0x04    u32              objParams                     
				[0x00000011] object parameters 1
				[0x00002200] object parameters 2
				[0x00330000] object parameters 3
				[0x44000000] object parameters 4
	0x08    u8               currState                     
				current state, usually
				0 - Initialize
				4 - Update
				8 - Destroy
	0x09    u8               currAction                    
				current "attack"/action (typically)
	0x0A    u8               currPhase                     
				current phase of "attack"/action (typically)
	0x0B    u8               phaseInitialized              
				bool. indicates if current phase is initialized (typically)
	0x0D    u8               ?                             
	0x0E    u8               Element                       
	0x0F    u8               ?                             
	0x10    u8               currAnimation                 
	0x11    u8               currAnimationCpy              
				current animation(copy)
	0x12    u8               panelX                        
	0x13    u8               panelY                        
	0x14    u8               futurePanelX                  
	0x15    u8               futurePanelY                  
	0x16    u8               Alliance                      
				0 = friend, 1 = enemy
	0x17    u8               directionFlip                 
	0x18    u8               preventAnimation              
	0x19    u8               ?                             
	0x1A    u8               chipsHeld                     
	0x1C    u8               ?                             
	0x1D    u8               ?                             
	0x1F    u8               ?                             
	0x20    u16              Timer                         
				(typically) lol
	0x22    u16              Timer2                        
				also typically
	0x24    u16              HP                            
	0x26    u16              maxHP                         
	0x28    u16              nameID                        
	0x2A    u16              chip                          
	0x2C    u16              damage                        
				0x8000 - double damage
				0x4000 - paralyze
				0x2000 - Uninstall
				0x1000 - KillerCross Skull hit
				0x0800 - nothing
				0x07FF - damage
	0x2E    u16              staminaDmg_counterDisabler    
	0x30    u16              ?                             
	0x32    u16              ?                             
	0x34    u32              x                             
	0x38    u32              y                             
	0x3C    u32              z                             
	0x40    u32              vx                            
				X Velocity
	0x44    u32              vy                            
				Y Velocity
	0x48    u32              vz                            
				Z Velocity
	0x4C    u32              *parent                       
				Can either be pointer to parent or childobject1
	0x50    u32              *childobject2                 
	0x54    CollisionData    *collisionData                
	0x58    AI               *ai                           
	0x5C    u32              ?                             
	0x60    u8               extraVars[0x2C]               
				[Size] 0x2C
				(0x60 - 0x8C)
				0x60 - 0x7C - free space for object specific variables (type 4)
				0x60 - 0x8C - free space for object specific variables (type 3)
				0x60 - 0x8C - free space for object specific variables (type 1)
Battle*/

/*        
	0x00	u16		ctrl
		[0xXXYZ]
		.# [0xXX00]: ID? changing This crashes the game.
		.# 01: First enemy, 02: Second Enemy... its like an... ID?
		.# [0x00Y0]: Undetermined Functionality
		.# [0x000Z]: Can make one enemy go invisible
	0x02	u16		?
		.# [0x00Z0]: Weird. Can crash game, or change enemy sprite
	0x08	u16		?
		.# [0xZZ00]: can make enemy use a chip?!
		.# [0x000Z]: Freeze game or make enemy invisible
	0x10	u16		?
		.# Keeps alternating with sprites. modification makes sprite
		.# weird.
	0x12	u16		attackCoord
		[0x0R0C]
		.# R, Row of attack. C, Column of attack.
	0x14	u16		?
		.# Seems to be like 0x12, maybe for another attack?
	0x16 	u16		?
		[0x000Z]
		.# Reverses direction of attack, or inverses it?
		.#			Or nullifies it?
	0x24 	u16		HP
		[0xZZZZ]
		.# 0203AAAC; HALF WORD
		.# One Enemys HP
	0x36 	u16		x
		[0xXXXX] <x>
		.# [0xZZZZ]: X-coordinant of enemy
	0x3A	u16		y 
		[0xYYYY] <y>
		.# [0xZZZZ]: Y-coordinant of enemy
	0x3E	u16		z 
		[0xZZZZ] <z>
		.# [0xZZZZ]: Controls depth or virus? makes it float...
	0x54	ptr		? 
		[0xPPPPPPPP]
		.# A Pointer
		.# Has something to do with side effects to enemy AND player
		.# Might be a function pointer to status effects.
	0x58	ptr		? 
		[0xPPPPPPPP]
		.# A Pointer
		.# Changing this crashes the game.
	0x90	u16		? 
		[0xZZZZ]
		.# Keeps changing. Seems to have something to do
		.# with the sprite.
	0x92	u16		? 
		[0xZZZZ]
		.# Doesnt change much, modification causes sprite glitches
	0x94	u16		pallete 
		[0x00ZZ] <pallete>
		.# Pallet of enemy! Not Pure RGB, Different color modes
		.# like stronger versions of said enemy/virus!!
	0xA0	u16		? 
		[0xZZZZ]
		.# Does some weird coordinant/sprite shift?
	0xA2	u16		? 
		[0xZZZZ]
		.# Also does weird sprite shift. Too creepy.
	0xA6 	u16		facingDirection
Deprecated docs*/
/*
s_0203A9B0 <sBtlPlayer>:		
	Offset	Type	Name

		[0x00Z0] <facingDirection>
		.#Where the enemy is facing! You can mirror the enemy!
		.# Ultimately, It seems the value is mod 4, since there are only
		.# 4 Directions the enemy can face.
*/
#pragma endregion

#pragma region Accesses

/*
	name=AI, size=0x100
	0800ECD6?::0800ED0A u32(0x7C), 080076A0::080076F0 u8(0x02), 08007778::08007794 u8(0x02), 
	080076A0::0800771C u8(0x16), 080076A0::0800771E u8(0x17), 080076A0::08007722 u8(0x00), 
	080076A0::08007726 u8(0x01), 080076A0::08007730 u8(0x03), 080076A0::0800775E u32(0x54), 
	080076A0::08007766 u8(0x0E), 080B9A5C::080B9A62 u8(0x00), 0800F420::0800F424 u8(0x00), 
	0800F420::0800F42A u8(0x01), 0800F334?::0800F336 u8(0x00), 0800F334?::0800F338 u8(0x16), 
	0800F334?::0800F33A u8(0x03), 0800F318?::0800F31E u32(0x78), 0800F2C6::0800F2D6 u8(0x00), 
	08016F56::08017088 u8(0x0C), 0800FDC0::0800FDD6 u8(0x00), 080F367C::080F3680 u8(0x01), 
	0801032C?::0801032E u32(0x48), 0800FFFE?::08010000 u32(0x44), 08014498::080144A4 u16(0x36), 
	080143E4::080143E8 u16(0x34), 08016380::08016384 u8(0x02), 080F367C::080F36B2 u8(0x19), 
	0801A36A::0801A37C u16(0x38), 08010230::08010266 u8(0x09), 080FCD04::080FCD10 u8(0x80+0x00), 
	0800FE36?::0800FE38 u8(0x16), 080FCD34::080FCD3E u8(0x80+0x00), 080FCE5C::080FCE5E u8(0x80+0x04), 
	080FCE5C::080FCE64 u8(0x80+0x04), 080FCE5C::080FCE68 u8(0x80+0x04), 080FCE5C::080FCE6A u8(0x80+0x07), 
	080FCE5C::080FCEBE u8(0x80+0x07), 080FCE5C::080FCEC2 u8(0x80+0x07), 080FD174::080FD178 u32(0xA0+0x28), 
	080FD174::080FD17E u16(0xA0+0x18), 08011698::080116A4 u16(0xA0+0x00), 08011698::080116A6 u8(0xA0+0x1C), 
	0801011A::08010122 u8(0xA0+0x1D), 0801011A::08010124 u16(0xA0+0x1E), 080E29A2?::080E29A4 u32(0x40), 
	080FD39C::080FD3A0 u8(0xA0+0x00), 080FD3BC::080FD3D0 u32(0xA0+0x28), 080FD3BC::080FD3EE u16(0xA0+0x10), 
	080FD3BC::080FD3F2 u16(0xA0+0x00), 080FD414::080FD416 u16(0xA0+0x10), 080FD414::080FD41A u16(0xA0+0x10), 
	080FD414::080FD438 u16(0xA0+0x10), 080FD414::080FD43C u16(0xA0+0x00), 080FD440::080FD442 u8(0xA0+0x01), 
	080FD440::080FD448 u16(0xA0+0x10), 080FD440::080FD44C u16(0xA0+0x10), 080FD440::080FD462 u16(0xA0+0x18), 
	080FD440::080FD464 u16(0xA0+0x10), 080FD440::080FD468 u8(0xA0+0x01), 080FD440::080FD46C u16(0xA0+0x10), 
	080FD440::080FD470 u16(0xA0+0x10), 0801171C::08011726 u8(0xA0+0x1B), 0801171C::08011728 u8(0xA0+0x1C), 
	0801171C::0801175A u16(0xA0+0x00), 080FCE5C::080FCED0 u8(0x80+0x07), 080FCE5C::080FCED4 u8(0x80+0x07), 
	080FCE5C::080FCE74 u8(0x80+0x04), 080FCE5C::080FCE76 u8(0x80+0x05), 080FCE5C::080FCE7C u8(0x80+0x05), 
	080FCE5C::080FCE80 u8(0x80+0x05), 080FCE5C::080FCE82 u8(0x80+0x06), 080FCE5C::080FCE94 u8(0x80+0x06), 
	080FCE5C::080FCE98 u8(0x80+0x06), 080FD188::080FD18E u8(0xA0+0x03), 080FD188::080FD192 u8(0xA0+0x02), 
	0800FE12?::0800FE14 u8(0x16), 080FD2BA::080FD2E4 u32(0xA0+0x08), 080FD188::080FD19C u32(0xA0+0x28), 
	080FD188::080FD1A2 u16(0xA0+0x18), 080FD188::080FD1A8 u8(0xA0+0x0C), 080FD188::080FD1AE u32(0xA0+0x30), 
	080FD188::080FD1BA u32(0xA0+0x2C), 080FD47A::080FD47E u8(0xA0+0x00), 080FD4A4::080FD4B8 u32(0xA0+0x2C), 
	080FD4A4::080FD4BA u32(0xA0+0x28), 080FD4A4::080FD4D8 u16(0xA0+0x10), 080FD4A4::080FD4DC u8(0xA0+0x1A), 
	080FD4A4::080FD4E0 u16(0xA0+0x00), 080FD504::080FD506 u16(0xA0+0x10), 080FD504::080FD50A u16(0xA0+0x10), 
	080FD504::080FD528 u16(0xA0+0x10), 080FD504::080FD52C u16(0xA0+0x00), 080FD530::080FD532 u16(0xA0+0x10), 
	080FD530::080FD536 u16(0xA0+0x10), 080FD530::080FD54A u16(0xA0+0x00), 080FD54E::080FD550 u8(0xA0+0x01), 
	080FD54E::080FD558 u8(0xA0+0x01), 080FD54E::080FD55E u8(0xA0+0x0C), 080FD54E::080FD560 u16(0xA0+0x10), 
	080FD54E::080FD564 u16(0xA0+0x12), 080FD54E::080FD568 u16(0xA0+0x12), 080FD54E::080FD56C u16(0xA0+0x12), 
	080FD54E::080FD584 u16(0xA0+0x10), 080FD54E::080FD588 u16(0xA0+0x10), 080FD54E::080FD58E u16(0xA0+0x00), 
	080FD592::080FD594 u8(0xA0+0x01), 080FD592::080FD59C u8(0xA0+0x01), 080FD592::080FD5A2 u32(0xA0+0x30), 
	0800E9DC::0800E9E0 u8(0x00), 080FD592::080FD5B6 u16(0xA0+0x10), 080FD592::080FD5BA u16(0xA0+0x10), 
	080FD592::080FD5BE u16(0xA0+0x10), 080FE168::080FE16E u8(0xA0+0x02), 080FE168::080FE172 u32(0xA0+0x08), 
	08010548::0801054E u16(0x20), 08010548::0801055A u16(0x20), 080FCFCA::080FD006 u8(0xA0+0x16), 
	080FCFCA::080FD008 u8(0xA0+0x17), 0801A2B0::0801A2C6 u16(0x3C), 0801031C?::0801031E u32(0x48), 
	0801031C?::08010322 u32(0x48), 08012EA8::08012EAE u8(0x1D), 08012EA8::08012EB0 u8(0x1B), 
	08012EA8::08012EB2 u8(0x1E), 0800FFEE?::0800FFF0 u32(0x44), 0800FFEE?::0800FFF4 u32(0x44), 
	08011450::08011454 u8(0x00), 08011450::08011456 u8(0x01), 080174FE::0801756E u32(0x68), 
	080FCE5C::080FCEB6 u8(0x80+0x07), 080FD1C4::080FD1CE u8(0xA0+0x03), 080FD1C4::080FD1D2 u8(0xA0+0x02), 
	080FD1C4::080FD1DC u32(0xA0+0x28), 080FD1C4::080FD1E2 u16(0xA0+0x18), 080FD1C4::080FD1E8 u8(0xA0+0x0C), 
	080FD1C4::080FD1EE u8(0xA0+0x0D), 080FD1C4::080FD1F4 u32(0xA0+0x30), 080FD1C4::080FD1FA u32(0xA0+0x34), 
	080FD1C4::080FD206 u32(0xA0+0x2C), 080FD62A::080FD62E u8(0xA0+0x00), 080FD660::080FD674 u32(0xA0+0x2C), 
	080FD660::080FD676 u32(0xA0+0x28), 080FD660::080FD694 u16(0xA0+0x10), 080FD660::080FD698 u8(0xA0+0x1A), 
	080FD660::080FD69C u16(0xA0+0x00), 080FD6C0::080FD6C2 u16(0xA0+0x10), 080FD6C0::080FD6C6 u16(0xA0+0x10), 
	080FD6C0::080FD6E4 u16(0xA0+0x10), 080FD6C0::080FD6E8 u16(0xA0+0x00), 080FD6EC::080FD6EE u16(0xA0+0x10), 
	080FD6EC::080FD6F2 u16(0xA0+0x10), 080FD6EC::080FD706 u16(0xA0+0x00), 080FD70A::080FD70C u8(0xA0+0x01), 
	080FD70A::080FD714 u8(0xA0+0x01), 080FD70A::080FD71C u8(0xA0+0x0D), 080FD70A::080FD71E u16(0xA0+0x10), 
	080FD70A::080FD720 u32(0xA0+0x34), 080FD70A::080FD722 u8(0xA0+0x0D), 080FD70A::080FD732 u32(0xA0+0x38), 
	080FD70A::080FD736 u32(0xA0+0x34), 080FD70A::080FD73E u16(0xA0+0x10), 080FD70A::080FD742 u16(0xA0+0x10), 
	0801171C::08011740 u8(0x1A), 080FD70A::080FD750 u32(0xA0+0x38), 080FCE5C::080FCEA2 u8(0x80+0x06), 
	080FD210::080FD216 u8(0xA0+0x03), 080FD210::080FD21A u8(0xA0+0x02), 080FD210::080FD224 u32(0xA0+0x28), 
	080FD210::080FD22A u16(0xA0+0x18), 080FD210::080FD230 u8(0xA0+0x0C), 080FD210::080FD236 u32(0xA0+0x30), 
	080FD210::080FD242 u32(0xA0+0x2C), 080FD922::080FD926 u8(0xA0+0x00), 080FD950::080FD95E u32(0xA0+0x2C), 
	080FD950::080FD960 u32(0xA0+0x28), 080FD950::080FD96A u8(0xA0+0x16), 080FD950::080FD96C u8(0xA0+0x17), 
	080FD950::080FD98A u16(0xA0+0x10), 080FD950::080FD98E u8(0xA0+0x1A), 080FD950::080FD992 u16(0xA0+0x00), 
	080FD9AC::080FD9AE u16(0xA0+0x10), 080FD9AC::080FD9B2 u16(0xA0+0x10), 080FD9AC::080FD9BA u8(0xA0+0x16), 
	080FD9AC::080FD9BC u8(0xA0+0x17), 080FD9AC::080FD9CC u16(0xA0+0x10), 080FD9AC::080FD9D0 u16(0xA0+0x00), 
	080FD9D4::080FD9D6 u16(0xA0+0x10), 080FD9D4::080FD9DA u16(0xA0+0x10), 080FD9D4::080FD9E0 u16(0xA0+0x00), 
	080FD9E4::080FD9E6 u8(0xA0+0x01), 080FD9E4::080FD9EE u8(0xA0+0x01), 080FD9E4::080FD9F4 u8(0xA0+0x0C), 
	080FD9E4::080FD9F6 u16(0xA0+0x10), 080FD9E4::080FD9FA u16(0xA0+0x12), 080FD9E4::080FD9FE u16(0xA0+0x12), 
	080FD9E4::080FDA02 u16(0xA0+0x12), 080FD9E4::080FDA1A u16(0xA0+0x10), 080FD9E4::080FDA1E u16(0xA0+0x10), 
	080FD9E4::080FDA24 u16(0xA0+0x00), 080FDA28::080FDA2A u8(0xA0+0x01), 080FDA28::080FDA32 u8(0xA0+0x01), 
	080FDA28::080FDA38 u32(0xA0+0x30), 080FDA28::080FDA4C u16(0xA0+0x10), 080FDA28::080FDA50 u16(0xA0+0x10), 
	080FDA28::080FDA54 u16(0xA0+0x10), 080FDA28::080FDA60 u16(0xA0+0x00), 080FDA9A::080FDA9C u8(0xA0+0x01), 
	080FDA9A::080FDAA4 u8(0xA0+0x01), 080FDA9A::080FDAA6 u16(0xA0+0x18), 080FDA9A::080FDAA8 u16(0xA0+0x10), 
	080FDA9A::080FDAAC u16(0xA0+0x10), 080FDA9A::080FDAB0 u16(0xA0+0x10), 080FDA9A::080FDAB6 u16(0xA0+0x00), 
	080FDABA::080FDABC u8(0xA0+0x01), 080FDABA::080FDAC4 u8(0xA0+0x01), 080FDABA::080FDACA u32(0xA0+0x30), 
	080FDABA::080FDAFC u16(0xA0+0x10), 080FDABA::080FDB00 u16(0xA0+0x10), 080FDABA::080FDB04 u16(0xA0+0x10), 
	080FCE5C::080FCEAC u8(0x80+0x05), 080FD24C::080FD252 u8(0xA0+0x03), 080FD24C::080FD256 u8(0xA0+0x02), 
	080FD24C::080FD260 u32(0xA0+0x28), 080FD24C::080FD266 u16(0xA0+0x18), 080FD24C::080FD26C u8(0xA0+0x0C), 
	080FD24C::080FD272 u32(0xA0+0x30), 080FDB0E::080FDB12 u8(0xA0+0x00), 080FDB38::080FDB4C u32(0xA0+0x28), 
	080FDB38::080FDB6A u16(0xA0+0x10), 080FDB38::080FDB6E u8(0xA0+0x1A), 080FDB38::080FDB72 u16(0xA0+0x00), 
	080FDB94::080FDB96 u16(0xA0+0x10), 080FDB94::080FDB9A u16(0xA0+0x10), 080FDB94::080FDBB8 u16(0xA0+0x10), 
	080FDB94::080FDBBC u16(0xA0+0x00), 080FDBC0::080FDBC2 u16(0xA0+0x10), 080FDBC0::080FDBC6 u16(0xA0+0x10), 
	080FDBC0::080FDBDA u16(0xA0+0x00), 080FDBDE::080FDBE0 u8(0xA0+0x01), 080FDBDE::080FDBE8 u8(0xA0+0x01), 
	080FDBDE::080FDBEE u8(0xA0+0x0C), 080FDBDE::080FDBF0 u16(0xA0+0x10), 080FDBDE::080FDBF4 u16(0xA0+0x12), 
	080FDBDE::080FDBF8 u16(0xA0+0x12), 080FDBDE::080FDBFC u16(0xA0+0x12), 080FDBDE::080FDC18 u16(0xA0+0x10), 
	080FDBDE::080FDC1C u16(0xA0+0x10), 080FDBDE::080FDC22 u16(0xA0+0x00), 080FDC26::080FDC28 u8(0xA0+0x01), 
	080FDC26::080FDC30 u8(0xA0+0x01), 080FDC26::080FDC36 u32(0xA0+0x30), 080FDC26::080FDC4A u16(0xA0+0x10), 
	080FDC26::080FDC4E u16(0xA0+0x10), 080FDC26::080FDC52 u16(0xA0+0x10), 080FDC26::080FDC62 u16(0xA0+0x00), 
	080FDCCA::080FDCCC u8(0xA0+0x01), 080FDCCA::080FDCD4 u8(0xA0+0x01), 080FDCCA::080FDCD6 u16(0xA0+0x18), 
	080FDCCA::080FDCD8 u16(0xA0+0x10), 080FDCCA::080FDCDC u16(0xA0+0x10), 080FDCCA::080FDCE0 u16(0xA0+0x10), 
	080FDCCA::080FDCE4 u32(0xA0+0x30), 080FD592::080FD5CA u16(0xA0+0x00), 080FD604::080FD606 u8(0xA0+0x01), 
	080FD604::080FD60E u8(0xA0+0x01), 080FD604::080FD610 u16(0xA0+0x18), 080FD604::080FD612 u16(0xA0+0x10), 
	080FD604::080FD616 u16(0xA0+0x10), 080FD604::080FD61A u16(0xA0+0x10), 080FD604::080FD61E u32(0xA0+0x30), 
	080178D4::080178E6 u32(0x68), 080FD70A::080FD75E u16(0xA0+0x00), 080FD70A::080FD760 u32(0xA0+0x38), 
	080FD76C::080FD76E u8(0xA0+0x01), 080FD76C::080FD776 u8(0xA0+0x01), 080FD76C::080FD780 u32(0xA0+0x3C), 
	080FE184::080FE18C u32(0xA0+0x2C), 080FD76C::080FD78A u8(0xA0+0x16), 080FD76C::080FD78C u8(0xA0+0x17), 
	080FE1A6::080FE1AC u8(0xA0+0x16), 080FE1A6::080FE1B6 u8(0xA0+0x16), 080FE1A6::080FE1C4 u8(0xA0+0x16), 
	080FE1A6::080FE1D8 u16(0xA0+0x10), 080FE1A6::080FE1DE u8(0xA0+0x17), 080FE1A6::080FE1F4 u16(0xA0+0x10), 
	080FD76C::080FD7C0 u32(0xA0+0x3C), 080FD76C::080FD7E6 u16(0xA0+0x10), 080FD76C::080FD7EA u16(0xA0+0x10), 
	080FCE5C::080FCEE6 u8(0x80+0x00), 080FCE5C::080FCEEA u32(0x80+0x04), 080FCE5C::080FCEEE u16(0x80+0x02), 
	080FCEF2::080FCF14 u8(0x80+0x05), 080FCEF2::080FCF1A u8(0x80+0x05), 080FCEF2::080FCF1E u8(0x80+0x05), 
	080FCEF2::080FCF84 u8(0x80+0x05), 080FCEF2::080FCF88 u8(0x80+0x05), 080FCEF2::080FCF30 u8(0x80+0x05), 
	080FCEF2::080FCF32 u8(0x80+0x06), 080FCEF2::080FCF42 u8(0x80+0x06), 080FCEF2::080FCF46 u8(0x80+0x06), 
	080FCEF2::080FCF48 u8(0x80+0x02), 080FCEF2::080FCF4E u8(0x80+0x02), 080FD76C::080FD7F0 u16(0xA0+0x00), 
	080FD7FA::080FD7FC u8(0xA0+0x01), 080FD7FA::080FD804 u8(0xA0+0x01), 080FD7FA::080FD806 u8(0xA0+0x0C), 
	080FD7FA::080FD808 u16(0xA0+0x10), 080FD7FA::080FD80C u16(0xA0+0x12), 080FD7FA::080FD80E u32(0xA0+0x3C), 
	080FD7FA::080FD81A u16(0xA0+0x12), 080FD7FA::080FD81E u16(0xA0+0x12), 080FD7FA::080FD836 u16(0xA0+0x10), 
	080FD7FA::080FD83A u16(0xA0+0x10), 080FD7FA::080FD840 u16(0xA0+0x00), 080FD844::080FD846 u8(0xA0+0x01), 
	080FD844::080FD84E u8(0xA0+0x01), 080FD844::080FD854 u32(0xA0+0x30), 080FD844::080FD868 u16(0xA0+0x10), 
	080FD844::080FD86C u16(0xA0+0x10), 080FD844::080FD870 u16(0xA0+0x10), 080FD844::080FD87C u16(0xA0+0x00), 
	080FD8B6::080FD8B8 u8(0xA0+0x01), 080FD8B6::080FD8C0 u8(0xA0+0x01), 080FD8B6::080FD8C2 u16(0xA0+0x18), 
	080FD8B6::080FD8C4 u16(0xA0+0x10), 080FD8B6::080FD8C8 u16(0xA0+0x10), 080FD8B6::080FD8CC u16(0xA0+0x10), 
	080FD8B6::080FD8D2 u16(0xA0+0x00), 080FD8D6::080FD8D8 u8(0xA0+0x01), 080FD8D6::080FD8E0 u8(0xA0+0x01), 
	080FD8D6::080FD8E6 u32(0xA0+0x30), 080FD8D6::080FD910 u16(0xA0+0x10), 080FD8D6::080FD914 u16(0xA0+0x10), 
	080FD8D6::080FD918 u16(0xA0+0x10), 080FCEF2::080FCF62 u8(0x80+0x06), 080FCEF2::080FCEFC u8(0x80+0x04), 
	080FCEF2::080FCF0E u8(0x80+0x04), 080FCEF2::080FCF12 u8(0x80+0x04), 080FCEF2::080FCF72 u8(0x80+0x04), 
	080FD27C::080FD282 u8(0xA0+0x03), 080FD27C::080FD286 u8(0xA0+0x02), 080FD27C::080FD292 u16(0xA0+0x18), 
	080FD27C::080FD298 u8(0xA0+0x0C), 080FD27C::080FD29E u8(0xA0+0x0D), 080FD27C::080FD2A4 u32(0xA0+0x30), 
	080FD27C::080FD2B0 u32(0xA0+0x2C), 080FDCF0::080FDCF4 u8(0xA0+0x00), 080FDD20::080FDD22 u8(0xA0+0x01), 
	080FDD20::080FDD2A u8(0xA0+0x01), 080FDD20::080FDD52 u16(0xA0+0x10), 080FDD20::080FDD56 u16(0xA0+0x10), 
	080FDD20::080FDD5A u16(0xA0+0x10), 080FE22C::080FE22E u32(0xA0+0x2C), 080FDD20::080FDD66 u8(0xA0+0x16), 
	080FDD20::080FDD68 u8(0xA0+0x17), 080FDD20::080FDD6C u16(0xA0+0x00), 080FDD76::080FDD78 u8(0xA0+0x01), 
	080FDD76::080FDD80 u8(0xA0+0x01), 080FDD76::080FDD82 u8(0xA0+0x0C), 080FDD76::080FDD84 u16(0xA0+0x10), 
	080FDD76::080FDD88 u16(0xA0+0x12), 080FDD76::080FDD8C u16(0xA0+0x12), 080FDD76::080FDD90 u16(0xA0+0x12), 
	080FDD76::080FDD96 u8(0xA0+0x16), 080FDD76::080FDD98 u8(0xA0+0x17), 080FDD76::080FDDA2 u16(0xA0+0x10), 
	080FDD76::080FDDA6 u16(0xA0+0x10), 080FDD76::080FDDCE u32(0xA0+0x08), 080FDD76::080FDDE0 u8(0xA0+0x0E), 
	080FDD76::080FDDE4 u16(0xA0+0x00), 080FDDE8::080FDDEA u8(0xA0+0x01), 080FDDE8::080FDDF2 u8(0xA0+0x01), 
	080FDDE8::080FDDF8 u32(0xA0+0x30), 080FDDE8::080FDE00 u16(0xA0+0x10), 080FDDE8::080FDE04 u16(0xA0+0x10), 
	080FDDE8::080FDE08 u16(0xA0+0x10), 080FDDE8::080FDE1C u8(0xA0+0x0E), 080FDDE8::080FDE26 u8(0xA0+0x0F), 
	080FDDE8::080FDE30 u8(0xA0+0x0E), 080FDDE8::080FDE42 u8(0xA0+0x16), 080FDDE8::080FDE44 u8(0xA0+0x17), 
	080FDDE8::080FDE14 u16(0xA0+0x00), 080FDE8C::080FDE8E u8(0xA0+0x01), 080FDE8C::080FDE96 u8(0xA0+0x01), 
	080FE2FA::080FE2FC u8(0xA0+0x0F), 080FDE8C::080FDEA0 u32(0xA0+0x30), 080FE25E::080FE264 u8(0xA0+0x0E), 
	080FE25E::080FE282 u8(0xA0+0x0E), 080FE25E::080FE28A u16(0xA0+0x10), 080FDE8C::080FDEBC u32(0xA0+0x34), 
	080FDE8C::080FDEBE u8(0xA0+0x0E), 080FDE8C::080FDF00 u16(0xA0+0x10), 080FDE8C::080FDF04 u16(0xA0+0x10), 
	080FDE8C::080FDF08 u32(0xA0+0x34), 080FDE8C::080FDF12 u8(0xA0+0x0E), 080FDE8C::080FDF16 u8(0xA0+0x0E), 
	080FDE8C::080FDF18 u8(0xA0+0x0D), 080FDE8C::080FDF20 u16(0xA0+0x00), 080FDE8C::080FDF26 u16(0xA0+0x00), 
	080FDF2A::080FDF2C u8(0xA0+0x01), 080FDF2A::080FDF34 u8(0xA0+0x01), 080FDF2A::080FDF36 u16(0xA0+0x18), 
	080FDF2A::080FDF38 u16(0xA0+0x10), 080FDF2A::080FDF3C u16(0xA0+0x10), 080FDF2A::080FDF40 u16(0xA0+0x10), 
	0801A7EC?::0801A7F8 u32(0x60), 08017122::0801713A u32(0x68), 080E2DAA::080E2DC0 u32(0x74+0x00), 
	080E2D4C::080E2D54 u32(0x74+0x00), 08017122::0801717E u32(0x74), 0800A0FE?::0800A106 u8(0x02), 
	08016C4E::08016C66 u8(0x0E), 08016C4E::08016C76 u8(0x02), 0810A8F8::0810A8FC u8(0x16), 
	0810A8F8::0810A900 u8(0x17), 0810A29C::0810A34A u8(0x01), 0801B9BC::0801B9C4 u8(0x02), 
	0810A29C::0810A36C u16(0x3C), 0801026A::08010280 u8(0x12), 0801026A::0801029C u8(0x09), 
	0810B306::0810B310 u8(0x80+0x00), 0810B334::0810B358 u16(0xA0+0x10), 0810B334::0810B35E u32(0xA0+0x30), 
	0810AFEC::0810AFEE u16(0xA0+0x10), 0810AFEC::0810AFF2 u16(0xA0+0x10), 0810AFEC::0810AFF6 u32(0xA0+0x30), 
	0810B334::0810B398 u8(0x80+0x00), 0810B334::0810B39C u16(0x80+0x02), 0810B3B0::0810B3B2 u8(0x80+0x02), 
	0810B3B0::0810B3BA u32(0xA0+0x28), 0810B3B0::0810B3BC u8(0x16), 0810B3B0::0810B3C2 u16(0xA0+0x18), 
	0810B3B0::0810B3CC u8(0x80+0x02), 0810B016::0810B01A u8(0xA0+0x00), 0810B038::0810B04C u32(0xA0+0x2C), 
	0810B038::0810B04E u32(0xA0+0x28), 0810B038::0810B07A u16(0xA0+0x10), 0810B038::0810B07E u16(0xA0+0x00), 
	0810B0A0::0810B0A2 u16(0xA0+0x10), 0810B0A0::0810B0A6 u16(0xA0+0x10), 0810B0A0::0810B0C0 u16(0xA0+0x10), 
	0810B0A0::0810B0C4 u16(0xA0+0x00), 0810B0C8::0810B0CA u16(0xA0+0x10), 0810B0C8::0810B0CE u16(0xA0+0x10), 
	0810B0C8::0810B0E0 u16(0xA0+0x18), 0810B0C8::0810B0E2 u16(0xA0+0x10), 0810B0C8::0810B0E6 u16(0xA0+0x00), 
	0810B0EA::0810B0EC u16(0xA0+0x10), 0810B0EA::0810B0F0 u16(0xA0+0x10), 0810B0EA::0810B0FA u8(0xA0+0x1A), 
	0810B3B0::0810B3D0 u8(0xA0+0x1A), 0810B3B0::0810B3E2 u8(0x80+0x00), 0810B3B0::0810B3E6 u16(0x80+0x02), 
	0810B334::0810B3A2 u8(0x80+0x00), 0810B334::0810B3A6 u16(0x80+0x02), 0810B456::0810B4B6 u8(0x16), 
	0810B456::0810B4BC u8(0xA0+0x0C), 0810B456::0810B4C4 u32(0xA0+0x08), 0810B456::0810B4CA u32(0xA0+0x30), 
	0810B456::0810B4D4 u8(0x80+0x00), 0810B456::0810B4D8 u16(0x80+0x02), 0810B102::0810B106 u8(0xA0+0x00), 
	0810B11C::0810B11E u8(0xA0+0x01), 0810B11C::0810B126 u8(0xA0+0x01), 0810B11C::0810B13A u16(0xA0+0x10), 
	0810B11C::0810B13C u16(0xA0+0x10), 0810B11C::0810B168 u16(0xA0+0x10), 0810B11C::0810B16C u16(0xA0+0x10), 
	0810B11C::0810B15A u8(0xA0+0x0C), 0810B11C::0810B15C u32(0xA0+0x08), 0810B11C::0810B164 u32(0xA0+0x30), 
	0810B11C::0810B176 u16(0xA0+0x00), 0810B17A::0810B17C u8(0xA0+0x01), 0810B17A::0810B184 u8(0xA0+0x01), 
	0810B17A::0810B188 u16(0xA0+0x10), 0810B17A::0810B18A u16(0xA0+0x10), 0810B17A::0810B18E u16(0xA0+0x10), 
	0810B17A::0810B1A0 u32(0xA0+0x30), 0810B334::0810B340 u8(0x16), 0810B1AA::0810B1AE u8(0xA0+0x00), 
	0810B1C8::0810B1CA u8(0xA0+0x01), 0810B1C8::0810B1D2 u8(0xA0+0x01), 0810B1C8::0810B1DA u16(0xA0+0x10), 
	0810B1C8::0810B1DC u16(0xA0+0x10), 0810B1C8::0810B1E0 u16(0xA0+0x10), 0810B1C8::0810B1F0 u16(0xA0+0x00), 
	0810B1F4::0810B206 u16(0xA0+0x10), 0810B1F4::0810B210 u16(0xA0+0x00), 0810B214::0810B216 u16(0xA0+0x10), 
	0810B214::0810B21A u16(0xA0+0x10), 0801664E::08016690 u32(0x74), 0800A86E::0800A880 u8(0x0E), 
	0810DA5E::0810DA68 u8(0x80+0x00), 0810DA84::0810DA86 u8(0x16), 0810DA84::0810DA8C u16(0xA0+0x10), 
	0810DA84::0810DA96 u8(0x80+0x00), 0810AAEA::0810AAEE u16(0xA0+0x10), 0810AAEA::0810AAF2 u16(0xA0+0x10), 
	0810DAA6::0810DAB6 u32(0xA0+0x28), 0810DAA6::0810DAC4 u8(0x16), 0810DAA6::0810DACC u32(0xA0+0x30), 
	0810DAA6::0810DAD6 u8(0x80+0x00), 0810D854::0810D858 u8(0xA0+0x00), 0810D874::0810D88C u32(0xA0+0x2C), 
	0810D874::0810D88E u32(0xA0+0x28), 0810D874::0810D898 u8(0xA0+0x16), 0810D874::0810D89A u8(0xA0+0x17), 
	0810D874::0810D8AC u8(0xA0+0x16), 0810D874::0810D8AE u8(0xA0+0x17), 0810D874::0810D8CC u8(0xA0+0x16), 
	0810D874::0810D8D0 u8(0xA0+0x17), 0810D874::0810D8DA u16(0xA0+0x00), 0810D874::0810D908 u8(0xA0+0x16), 
	0810D874::0810D910 u32(0xA0+0x30), 0810D874::0810D912 u16(0xA0+0x10), 0810D874::0810D916 u16(0xA0+0x12), 
	0810D934::0810D94A u32(0xA0+0x3C), 0810D934::0810D95E u16(0xA0+0x10), 0810D934::0810D960 u16(0xA0+0x12), 
	0810D934::0810D96E u16(0xA0+0x10), 0810D934::0810D972 u16(0xA0+0x10), 0810D934::0810D9A0 u8(0xA0+0x1A), 
	0810DAE6::0810DAFC u8(0x16), 0810DAE6::0810DB02 u16(0xA0+0x08), 0810DAE6::0810DB06 u16(0xA0+0x0A), 
	0810D778::0810D77C u8(0xA0+0x00), 0810D79C::0810D79E u8(0xA0+0x01), 0810D79C::0810D7AC u8(0xA0+0x01), 
	0810D79C::0810D7E0 u16(0xA0+0x00), 0810D7E4::0810D812 u32(0xA0+0x08), 0810D7E4::0810D81A u16(0xA0+0x00), 
	0810D81E::0810D830 u16(0xA0+0x00), 0810DAE6::0810DB24 u8(0x16), 0810DAE6::0810DB2C u16(0xA0+0x10), 
	0810DAE6::0810DB36 u8(0x80+0x00), 080F3E70::080F3E7C u8(0x80+0x00), 080F3E94::080F3E96 u8(0x80+0x04), 
	080F3E94::080F3EFA u32(0xA0+0x28), 080F3E94::080F3F00 u16(0xA0+0x18), 080F3E94::080F3F0C u32(0xA0+0x2C), 
	080F41FC::080F4200 u8(0xA0+0x00), 080F421C::080F4230 u32(0xA0+0x2C), 080F421C::080F4232 u32(0xA0+0x28), 
	080F421C::080F4250 u16(0xA0+0x10), 080F421C::080F4254 u16(0xA0+0x00), 080F427C::080F427E u16(0xA0+0x10), 
	080F427C::080F4282 u16(0xA0+0x10), 080F427C::080F42A0 u16(0xA0+0x10), 080F427C::080F42A4 u16(0xA0+0x00), 
	080F42A8::080F42AA u8(0xA0+0x01), 080F42A8::080F42B0 u16(0xA0+0x10), 080F42A8::080F42B4 u16(0xA0+0x10), 
	080F42A8::080F42CA u16(0xA0+0x18), 080F42A8::080F42CC u16(0xA0+0x10), 080F42A8::080F42D0 u8(0xA0+0x01), 
	080F3E94::080F3EF2 u8(0x80+0x04), 080F3E94::080F3EF6 u8(0x80+0x04), 080F42A8::080F42D4 u16(0xA0+0x10), 
	080F42A8::080F42D8 u16(0xA0+0x10), 080F3E94::080F3E9C u8(0x80+0x05), 080F3E94::080F3E9E u8(0xA0+0x0C), 
	080F3E94::080F3EA4 u8(0xA0+0x03), 080F3E94::080F3EA8 u8(0xA0+0x02), 080F4104::080F412E u32(0xA0+0x08), 
	080F3E94::080F3EB4 u16(0xA0+0x18), 080F3E94::080F3EB8 u32(0xA0+0x28), 080F3E94::080F3EBE u32(0xA0+0x30), 
	080F3E94::080F3ECE u8(0x80+0x05), 080F3E94::080F3ED4 u8(0x80+0x05), 080F3E94::080F3EE2 u8(0x80+0x00), 
	080F42E2::080F42E6 u8(0xA0+0x00), 080F430C::080F4320 u32(0xA0+0x28), 080F430C::080F433E u16(0xA0+0x10), 
	080F430C::080F4342 u8(0xA0+0x1A), 080F430C::080F4346 u16(0xA0+0x00), 080F4368::080F436A u16(0xA0+0x10), 
	080F4368::080F436E u16(0xA0+0x10), 080F4368::080F438C u16(0xA0+0x10), 080F4368::080F4390 u16(0xA0+0x00), 
	080F4394::080F4396 u16(0xA0+0x10), 080F4394::080F439A u16(0xA0+0x10), 080F4394::080F43B2 u16(0xA0+0x00), 
	080F43B6::080F43B8 u8(0xA0+0x01), 080F43B6::080F43C0 u8(0xA0+0x01), 080F43B6::080F43C8 u16(0xA0+0x10), 
	080F43B6::080F43CC u16(0xA0+0x10), 080F43B6::080F43D0 u16(0xA0+0x10), 080F43B6::080F43D6 u16(0xA0+0x00), 
	080F43DA::080F43DC u8(0xA0+0x01), 080F43DA::080F43E4 u8(0xA0+0x01), 080F43DA::080F43F2 u16(0xA0+0x10), 
	080F43DA::080F43F6 u16(0xA0+0x10), 080F43DA::080F43FA u16(0xA0+0x10), 080F43DA::080F4402 u32(0xA0+0x30), 
	080F43DA::080F4404 u8(0xA0+0x03), 080F43DA::080F440E u8(0xA0+0x0C), 080F43DA::080F4410 u32(0xA0+0x08), 
	080F4B54::080F4B84 u8(0xA0+0x02), 080F43DA::080F4418 u16(0xA0+0x00), 080F442C::080F442E u8(0xA0+0x01), 
	080F442C::080F4436 u8(0xA0+0x01), 080F442C::080F4438 u16(0xA0+0x18), 080F442C::080F443A u16(0xA0+0x10), 
	080F442C::080F443E u16(0xA0+0x10), 080F442C::080F4442 u16(0xA0+0x10), 080F3F16::080F3F5E u8(0xA0+0x03), 
	080F3F16::080F3F64 u8(0xA0+0x0C), 080F3F16::080F3F6A u8(0xA0+0x0D), 080F3F16::080F3F6E u8(0xA0+0x02), 
	080F3F16::080F3F7A u16(0xA0+0x18), 080F3F16::080F3F7E u32(0xA0+0x28), 080F3F16::080F3F8A u32(0xA0+0x2C), 
	080F3F16::080F3F90 u32(0xA0+0x30), 080F3F16::080F3F9A u8(0x80+0x04), 080F3F16::080F3F9E u8(0x80+0x00), 
	080F4750::080F4754 u8(0xA0+0x00), 080F4788::080F478C u8(0xA0+0x0E), 080F4788::080F4790 u8(0xA0+0x16), 
	080F4788::080F4792 u8(0xA0+0x17), 080F4788::080F4796 u16(0xA0+0x00), 080F479A::080F479C u8(0xA0+0x0E), 
	080F479A::080F47A0 u8(0xA0+0x0E), 080F479A::080F47B4 u32(0xA0+0x2C), 080F479A::080F47B6 u8(0xA0+0x0E), 
	080F479A::080F47B8 u32(0xA0+0x28), 080F479A::080F47D6 u16(0xA0+0x10), 080F479A::080F47DA u16(0xA0+0x00), 
	080F479A::080F47DC u8(0xA0+0x0E), 080F4814::080F4816 u16(0xA0+0x10), 080F4814::080F481A u16(0xA0+0x10), 
	080F3E94::080F3EDC u8(0x80+0x04), 080F4814::080F4838 u16(0xA0+0x10), 080F4814::080F483C u16(0xA0+0x00), 
	080F4840::080F4842 u16(0xA0+0x10), 080F4840::080F4846 u16(0xA0+0x10), 080F4840::080F485C u8(0xA0+0x0E), 
	080F4840::080F486A u16(0xA0+0x00), 080F486E::080F4870 u8(0xA0+0x01), 080F486E::080F4878 u8(0xA0+0x01), 
	080F486E::080F4880 u16(0xA0+0x10), 080F486E::080F4884 u16(0xA0+0x12), 080F486E::080F4894 u16(0xA0+0x12), 
	080F486E::080F4898 u16(0xA0+0x12), 080F486E::080F4888 u16(0xA0+0x10), 080F486E::080F488C u16(0xA0+0x10), 
	080F486E::080F4892 u16(0xA0+0x00), 080F48A4::080F48A6 u8(0xA0+0x01), 080F48A4::080F48AE u8(0xA0+0x01), 
	080F48A4::080F48BC u16(0xA0+0x10), 080F48A4::080F48FC u16(0xA0+0x12), 080F48A4::080F4900 u16(0xA0+0x12), 
	080F48A4::080F48C0 u16(0xA0+0x10), 080F48A4::080F48C4 u16(0xA0+0x10), 080F48A4::080F48DE u8(0xA0+0x02), 
	080F48A4::080F48E0 u8(0xA0+0x0D), 080F48A4::080F48E4 u8(0xA0+0x03), 080F48A4::080F48E8 u32(0xA0+0x08), 
	080F48A4::080F48EA u32(0xA0+0x30), 080F48A4::080F48FA u16(0xA0+0x00), 080F4950::080F4952 u8(0xA0+0x01), 
	080F4950::080F4958 u32(0xA0+0x30), 080F4950::080F4966 u8(0xA0+0x0D), 080F4950::080F4968 u16(0xA0+0x10), 
	080F4950::080F496A u32(0xA0+0x30), 080F4950::080F4978 u8(0xA0+0x01), 080F4950::080F497C u16(0xA0+0x10), 
	080F4950::080F4980 u16(0xA0+0x10), 080F4950::080F4984 u32(0xA0+0x30), 080F4950::080F4990 u8(0xA0+0x0C), 
	080F4950::080F4994 u8(0xA0+0x0C), 080F4950::080F499C u16(0xA0+0x00), 080F479A::080F47E2 u32(0xA0+0x30), 
	080F4840::080F4864 u16(0xA0+0x00), 080F490C::080F490E u8(0xA0+0x01), 080F490C::080F4916 u8(0xA0+0x01), 
	080F490C::080F491E u16(0xA0+0x10), 080F490C::080F4940 u16(0xA0+0x12), 080F490C::080F4944 u16(0xA0+0x12), 
	080F490C::080F4922 u16(0xA0+0x10), 080F490C::080F4926 u16(0xA0+0x10), 080F490C::080F493E u16(0xA0+0x00), 
	080F4950::080F49A2 u16(0xA0+0x00), 080F49A6::080F49A8 u8(0xA0+0x01), 080F49A6::080F49B0 u8(0xA0+0x01), 
	080F49A6::080F49B6 u16(0xA0+0x18), 080F49A6::080F49B8 u16(0xA0+0x10), 080F49A6::080F49BC u16(0xA0+0x10), 
	080F49A6::080F49C0 u16(0xA0+0x10), 0801445C?::0801445E u16(0x32), 08014490?::08014492 u16(0x36), 
	080175B8::08017618 u32(0x68), 080175B8::0801762A u16(0x24), 080F6C50::080F6C5C u8(0x80+0x00), 
	080F6C74::080F6C7E u8(0x80+0x04), 080F6C74::080F6CDC u8(0x80+0x04), 080F6C74::080F6CE0 u8(0x80+0x04), 
	080F6C74::080F6CE6 u8(0xA0+0x03), 080F6C74::080F6CEA u32(0xA0+0x28), 080F6C74::080F6CF0 u16(0xA0+0x18), 
	080F6C74::080F6CFC u32(0xA0+0x2C), 080F6EAC::080F6EB0 u8(0xA0+0x00), 080F6ECC::080F6EE0 u32(0xA0+0x2C), 
	080F6ECC::080F6EE2 u32(0xA0+0x28), 080F6ECC::080F6F00 u16(0xA0+0x10), 080F6ECC::080F6F04 u16(0xA0+0x00), 
	080F6F28::080F6F2A u16(0xA0+0x10), 080F6F28::080F6F2E u16(0xA0+0x10), 080F6F28::080F6F4C u16(0xA0+0x10), 
	080F6F28::080F6F50 u16(0xA0+0x00), 080F6F54::080F6F56 u8(0xA0+0x01), 080F6F54::080F6F5C u16(0xA0+0x10), 
	080F6F54::080F6F60 u16(0xA0+0x10), 080F6F54::080F6F76 u16(0xA0+0x18), 080F6F54::080F6F78 u16(0xA0+0x10), 
	080F6F54::080F6F7C u8(0xA0+0x01), 080F6F54::080F6F80 u16(0xA0+0x10), 080F6F54::080F6F84 u16(0xA0+0x10), 
	080F6D42::080F6D76 u8(0xA0+0x16), 080F6D42::080F6D78 u8(0xA0+0x17), 080F6C74::080F6C86 u8(0x80+0x04), 
	080F6C74::080F6C94 u8(0x80+0x05), 080F6C74::080F6C9A u8(0x80+0x05), 080F6C74::080F6C9E u8(0x80+0x05), 
	080F6C74::080F6CA4 u8(0xA0+0x03), 080F6C74::080F6CA8 u8(0xA0+0x02), 080F6DFC::080F6E26 u32(0xA0+0x08), 
	080F6C74::080F6CB2 u32(0xA0+0x28), 080F6C74::080F6CB8 u16(0xA0+0x18), 080F6C74::080F6CC4 u32(0xA0+0x2C), 
	080F6C74::080F6CCE u8(0x80+0x00), 080F6F8E::080F6F92 u8(0xA0+0x00), 080F6FB8::080F6FCC u32(0xA0+0x2C), 
	080F6FB8::080F6FCE u32(0xA0+0x28), 080F6FB8::080F6FFA u8(0xA0+0x1A), 080F6D10::080F6D12 u8(0xA0+0x1A), 
	080F6D10::080F6D1A u8(0x80+0x05), 080F6DC8::080F6DCE u8(0xA0+0x03), 080F6DC8::080F6DD2 u8(0xA0+0x02), 
	080F6DC8::080F6DDC u32(0xA0+0x28), 080F6DC8::080F6DE0 u32(0xA0+0x30), 080F6DC8::080F6DE6 u32(0xA0+0x34), 
	080F6DC8::080F6DF2 u32(0xA0+0x2C), 080F6D10::080F6D22 u8(0x80+0x00), 080F70FA::080F70FE u8(0xA0+0x00), 
	080F7140::080F7154 u32(0xA0+0x28), 080F7140::080F7172 u16(0xA0+0x10), 080F7140::080F7176 u16(0xA0+0x00), 
	080F7198::080F719A u16(0xA0+0x10), 080F7198::080F719E u16(0xA0+0x10), 080F7198::080F71BC u16(0xA0+0x10), 
	080F7198::080F71C0 u16(0xA0+0x00), 080F71C4::080F71C6 u16(0xA0+0x10), 080F71C4::080F71CA u16(0xA0+0x10), 
	080F71C4::080F71E2 u16(0xA0+0x00), 080F71E6::080F71E8 u8(0xA0+0x01), 080F71E6::080F71F0 u8(0xA0+0x01), 
	080F71E6::080F71F4 u16(0xA0+0x10), 080F71E6::080F71F8 u16(0xA0+0x10), 080F71E6::080F71FC u16(0xA0+0x10), 
	080F71E6::080F7202 u16(0xA0+0x00), 080F7206::080F7208 u8(0xA0+0x01), 080F7206::080F7210 u8(0xA0+0x01), 
	080F7614::080F7622 u8(0xA0+0x02), 080F7614::080F7624 u8(0xA0+0x03), 080F7614::080F7626 u32(0xA0+0x34), 
	080F7206::080F7222 u32(0xA0+0x34), 080F7206::080F7234 u8(0xA0+0x0E), 080F7206::080F7236 u8(0xA0+0x0F), 
	080F7206::080F723E u16(0xA0+0x00), 080F724E::080F7250 u8(0xA0+0x01), 080F724E::080F7258 u8(0xA0+0x01), 
	080F724E::080F725C u16(0xA0+0x10), 080F724E::080F7260 u16(0xA0+0x10), 080F724E::080F7264 u16(0xA0+0x10), 
	080F724E::080F7274 u8(0xA0+0x0E), 080F724E::080F7276 u32(0xA0+0x30), 080F724E::080F7280 u8(0xA0+0x16), 
	080F724E::080F7282 u8(0xA0+0x17), 080F724E::080F72A0 u16(0xA0+0x10), 080F724E::080F72A4 u16(0xA0+0x00), 
	080F72C0::080F72C2 u16(0xA0+0x10), 080F72C0::080F72C6 u16(0xA0+0x10), 080F72C0::080F72CE u8(0xA0+0x16), 
	080F72C0::080F72D0 u8(0xA0+0x17), 080F72C0::080F72E0 u16(0xA0+0x10), 080F72C0::080F72E4 u16(0xA0+0x00), 
	080F72E8::080F72EA u16(0xA0+0x10), 080F72E8::080F72EE u16(0xA0+0x10), 080F72E8::080F72F8 u16(0xA0+0x00), 
	080F731C::080F731E u8(0xA0+0x01), 080F731C::080F7326 u8(0xA0+0x01), 080F731C::080F732E u16(0xA0+0x10), 
	080F7638::080F7646 u8(0xA0+0x0F), 080F7638::080F7666 u8(0xA0+0x02), 080F7638::080F7668 u8(0xA0+0x0F), 
	080F7638::080F766C u16(0xA0+0x10), 080F7638::080F7672 u32(0xA0+0x08), 080F731C::080F733C u16(0xA0+0x10), 
	080F731C::080F7340 u16(0xA0+0x10), 080F731C::080F7344 u8(0xA0+0x0F), 080F731C::080F734C u16(0xA0+0x00), 
	080F7356::080F7358 u8(0xA0+0x01), 080F7356::080F7360 u8(0xA0+0x01), 080F7356::080F7368 u16(0xA0+0x10), 
	080F7356::080F736C u16(0xA0+0x10), 080F7356::080F7370 u16(0xA0+0x10), 080F7356::080F7376 u16(0xA0+0x00), 
	080F737A::080F737C u8(0xA0+0x01), 080F737A::080F7384 u8(0xA0+0x01), 080F737A::080F73B6 u16(0xA0+0x10), 
	080F737A::080F73BA u16(0xA0+0x10), 080F737A::080F73BE u16(0xA0+0x10), 080F737A::080F73C4 u16(0xA0+0x00), 
	080F73C8::080F73CA u8(0xA0+0x01), 080F73C8::080F73D2 u8(0xA0+0x01), 080F73C8::080F73DA u16(0xA0+0x10), 
	080F73C8::080F73DE u16(0xA0+0x10), 080F73C8::080F73E2 u16(0xA0+0x10), 080F7206::080F7244 u16(0xA0+0x00), 
	080F72FC::080F72FE u8(0xA0+0x01), 080F72FC::080F7306 u8(0xA0+0x01), 080F72FC::080F730A u16(0xA0+0x10), 
	080F72FC::080F730E u16(0xA0+0x10), 080F72FC::080F7312 u16(0xA0+0x10), 080F72FC::080F7318 u16(0xA0+0x00), 
	080F731C::080F7352 u16(0xA0+0x00), 080F6FB8::080F6FEC u16(0xA0+0x10), 080F6FB8::080F6FF0 u8(0xA0+0x1A), 
	080F6FB8::080F6FF4 u16(0xA0+0x00), 080F7018::080F701A u16(0xA0+0x10), 080F7018::080F701E u16(0xA0+0x10), 
	080F7018::080F703C u16(0xA0+0x10), 080F7018::080F7040 u16(0xA0+0x00), 080F7044::080F7046 u16(0xA0+0x10), 
	080F7044::080F704A u16(0xA0+0x10), 080F7044::080F7062 u16(0xA0+0x00), 080F7066::080F7068 u8(0xA0+0x01), 
	080F7066::080F7070 u8(0xA0+0x01), 080F7066::080F707C u8(0xA0+0x03), 080F7066::080F7082 u16(0xA0+0x10), 
	080F7066::080F7086 u16(0xA0+0x10), 080F7066::080F708A u16(0xA0+0x10), 080F7066::080F7090 u16(0xA0+0x00), 
	080F709C::080F709E u8(0xA0+0x01), 080F709C::080F70A6 u8(0xA0+0x01), 080F709C::080F70B4 u16(0xA0+0x10), 
	080F709C::080F70B8 u16(0xA0+0x10), 080F709C::080F70BC u16(0xA0+0x10), 080F7552::080F7562 u8(0xA0+0x02), 
	080F7552::080F7568 u32(0xA0+0x08), 080F709C::080F70C8 u16(0xA0+0x00), 080F70D6::080F70D8 u8(0xA0+0x01), 
	080F70D6::080F70E0 u8(0xA0+0x01), 080F70D6::080F70E2 u16(0xA0+0x18), 080F70D6::080F70E4 u16(0xA0+0x10), 
	080F70D6::080F70E8 u16(0xA0+0x10), 080F70D6::080F70EC u16(0xA0+0x10), 08110764::08110768 u8(0x80+0x00), 
	0811077C::0811077E u8(0x16), 0811077C::08110790 u8(0xA0+0x0C), 0811077C::081107A4 u8(0xA0+0x0D), 
	0811077C::081107AA u16(0xA0+0x0E), 0811077C::081107B0 u16(0xA0+0x08), 0811077C::081107B4 u16(0xA0+0x0A), 
	0811077C::081107BC u32(0xA0+0x30), 0811077C::081107C2 u32(0xA0+0x34), 0811077C::081107C6 u32(0xA0+0x38), 
	0811077C::081107D2 u32(0xA0+0x3C), 0811077C::081107D6 u16(0xA0+0x18), 0811077C::081107EC u32(0xA0+0x28), 
	0811061C::08110620 u8(0xA0+0x00), 08110640::08110642 u8(0xA0+0x01), 08110640::0811064A u8(0xA0+0x01), 
	08110640::08110668 u16(0xA0+0x00), 0811066C::0811066E u8(0xA0+0x0E), 0811066C::08110670 u16(0xA0+0x10), 
	0811066C::08110674 u16(0xA0+0x00), 0811066C::08110684 u32(0xA0+0x34), 0811066C::08110690 u32(0xA0+0x3C), 
	0811066C::08110692 u32(0xA0+0x30), 0811066C::08110694 u8(0xA0+0x0D), 0811066C::08110696 u32(0xA0+0x38), 
	0811066C::0811069C u32(0xA0+0x08), 0811066C::0811069E u32(0xA0+0x28), 081106A6::081106A8 u16(0xA0+0x10), 
	081106A6::081106AC u16(0xA0+0x10), 

Accesses: AI*/

/*
	080076A0 08007778 0800A0FE? 0800A86E 0800E9DC 
	0800ECD6? 0800F2C6 0800F318? 0800F334? 0800F420 
	0800FDC0 0800FE12? 0800FE36? 0800FFEE? 0800FFFE? 
	0801011A 08010230 0801026A 0801031C? 0801032C? 
	08010548 08011450 08011698 0801171C 08012EA8 
	080143E4 0801445C? 08014490? 08014498 08016380 
	0801664E 08016C4E 08016F56 08017122 080174FE 
	080175B8 080178D4 0801A2B0 0801A36A 0801A7EC? 
	0801B9BC 080B9A5C 080E29A2? 080E2D4C 080E2DAA 
	080F367C 080F3E70 080F3E94 080F3F16 080F4104 
	080F41FC 080F421C 080F427C 080F42A8 080F42E2 
	080F430C 080F4368 080F4394 080F43B6 080F43DA 
	080F442C 080F4750 080F4788 080F479A 080F4814 
	080F4840 080F486E 080F48A4 080F490C 080F4950 
	080F49A6 080F4B54 080F6C50 080F6C74 080F6D10 
	080F6D42 080F6DC8 080F6DFC 080F6EAC 080F6ECC 
	080F6F28 080F6F54 080F6F8E 080F6FB8 080F7018 
	080F7044 080F7066 080F709C 080F70D6 080F70FA 
	080F7140 080F7198 080F71C4 080F71E6 080F7206 
	080F724E 080F72C0 080F72E8 080F72FC 080F731C 
	080F7356 080F737A 080F73C8 080F7552 080F7614 
	080F7638 080FCD04 080FCD34 080FCE5C 080FCEF2 
	080FCFCA 080FD174 080FD188 080FD1C4 080FD210 
	080FD24C 080FD27C 080FD2BA 080FD39C 080FD3BC 
	080FD414 080FD440 080FD47A 080FD4A4 080FD504 
	080FD530 080FD54E 080FD592 080FD604 080FD62A 
	080FD660 080FD6C0 080FD6EC 080FD70A 080FD76C 
	080FD7FA 080FD844 080FD8B6 080FD8D6 080FD922 
	080FD950 080FD9AC 080FD9D4 080FD9E4 080FDA28 
	080FDA9A 080FDABA 080FDB0E 080FDB38 080FDB94 
	080FDBC0 080FDBDE 080FDC26 080FDCCA 080FDCF0 
	080FDD20 080FDD76 080FDDE8 080FDE8C 080FDF2A 
	080FE168 080FE184 080FE1A6 080FE22C 080FE25E 
	080FE2FA 0810A29C 0810A8F8 0810AAEA 0810AFEC 
	0810B016 0810B038 0810B0A0 0810B0C8 0810B0EA 
	0810B102 0810B11C 0810B17A 0810B1AA 0810B1C8 
	0810B1F4 0810B214 0810B306 0810B334 0810B3B0 
	0810B456 0810D778 0810D79C 0810D7E4 0810D81E 
	0810D854 0810D874 0810D934 0810DA5E 0810DA84 
	0810DAA6 0810DAE6 0811061C 08110640 0811066C 
	081106A6 08110764 0811077C 
Functions: AI*/

/*
	name=CollisionData, size=0xA8
	0801986C::08019884 u32(0x44), 080198AE?::080198C8 u8(0x00), 08019FB4::08019FB8 u32(0x38), 
	08019FB4::08019FBA u8(0x0E), 08019FB4::08019FC2 u8(0x02), 08019FB4::08019FC8 u8(0x19), 
	08019FB4::08019FCC u16(0x04), 08019FB4::08019FD2 u16(0x0A), 08019FB4::08019FD6 u8(0x01), 
	08019FB4::08019FDA u8(0x07), 08019FB4::08019FDE u16(0x2E), 08019FB4::08019FE8 u32(0x30), 
	08019FB4::0801A004 u32(0x34), 08019F44::08019F48 u16(0x2E), 08019F44::08019F50 u16(0x2E), 
	08019F9E?::08019FA0 u8(0x18), 0801A42E::0801A434 u8(0x74), 0801A4A6::0801A4AC u8(0xA4), 
	0801A45C::0801A460 u32(0x70), 0801A506::0801A50C u8(0x75), 0801BA12::0801BA16 u16(0x80), 
	0801BA12::0801BA6A u16(0x8C), 0801A200::0801A20E u16(0x90), 0801A200::0801A24E u16(0x8E), 
	0801A166?::0801A168 u32(0x3C), 0801A180?::0801A182 u32(0x40), 08010162::08010166 u16(0x26), 
	0801A15C?::0801A15E u32(0x3C), 0801A15C?::0801A162 u32(0x3C), 0801A176?::0801A178 u32(0x40), 
	0801A176?::0801A17C u32(0x40), 0801A018::0801A01C u32(0x70), 0801A018::0801A01E u32(0x54), 
	0801A018::0801A022 u32(0x54), 0801A018::0801A02E u8(0x0F), 0801A018::0801A030 u8(0x03), 
	0801A018::0801A032 u32(0x54), 0801A018::0801A036 u8(0x11), 03007778::03007780 u8(0x01), 
	03007778::0300778E u8(0x04), 03007778::03007790 u8(0x05), 03007778::030077A4 u8(0x0A), 
	03007778::030077AC u8(0x0B), 0300785E?::0300786E u32(0x44), 03007970?::0300798C u32(0x30), 
	0801C168::0801C1A2 u8(0x08), 0300754C::03007552 u8(0x01), 0300754C::03007560 u8(0x04), 
	0300754C::03007562 u8(0x05), 0300754C::03007576 u8(0x0A), 0300754C::0300757E u8(0x0B), 
	03007876?::0300788A u32(0x44), 03007704::03007722 u32(0x30), 0801A80C?::0801A80E u8(0x06), 
	0801A186::0801A196 u8(0x01), 0801A186::0801A19C u8(0x0A), 0801A186::0801A19E u8(0x0B), 
	0801A1CE?::0801A1D0 u8(0x08), 0801A36A::0801A394 u8(0x0A), 0801A36A::0801A396 u8(0x0B), 
	0802CFF8::0802CFFE u8(0x76), 0801A6E8::0801A6EE u8(0xA4), 0801A720::0801A726 u8(0xA4), 
	08013AE4::08013AEC u8(0xA4), 0801AEB0::0801AEB2 u8(0x0F), 0800EB26::0800EB2A u32(0x70), 
	0801A554::0801A558 u8(0x11), 0801A2CC::0801A2D0 u32(0x70), 0801A308::0801A31A u16(0x92), 
	0800E3DE::0800E404 u16(0x82+0x00), 0800E3DE::0800E40A u16(0x82+0x00), 0800E3DE::0800E41C u16(0x80+0x00), 
	0801A420?::0801A422 u8(0x0D), 08010198::0801019C u16(0x26), 0801A648::0801A652 u16(0x24), 
	0800EB9E::0800EBA8 u32(0x70), 0801A5EE::0801A5FC u16(0x24), 0801A5EE::0801A616 u16(0x24), 
	0800E730::0800E744 u16(0x1C), 0800E730::0800E748 u16(0x1C), 0800E730::0800E75A u16(0x1C), 
	0800E730::0800E7AE u16(0x2A), 0800E730::0800E7B2 u16(0x2A), 0800E730::0800E7BE u16(0x2A), 
	0800E730::0800E820 u16(0x2C), 0800E730::0800E824 u16(0x2C), 0800E730::0800E830 u16(0x2C), 
	0800E730::0800E832 u32(0x60), 0800E730::0800E894 u16(0x1E), 0800E730::0800E898 u16(0x1E), 
	0800E730::0800E8AA u16(0x1E), 0800E730::0800E8AC u32(0x48), 0800E730::0800E8E2 u16(0x22), 
	0800E730::0800E8E6 u16(0x22), 0800E730::0800E8F2 u16(0x22), 0800E730::0800E908 u16(0x20), 
	0800E730::0800E90C u16(0x20), 0800E730::0800E918 u16(0x20), 0800E730::0800E91C u32(0x4C), 
	0800E730::0800E942 u16(0x28), 0800E730::0800E946 u16(0x28), 0800E730::0800E952 u16(0x28), 
	0801A152?::0801A154 u32(0x3C), 0801A152?::0801A158 u32(0x3C), 0801A04C::0801A050 u8(0x0A), 
	0801A04C::0801A052 u8(0x0B), 0801A04C::0801A056 u8(0x0A), 0801A04C::0801A05A u8(0x0B), 
	0801A04C::0801A062 u8(0x0C), 0801A3AC?::0801A3C0 u8(0x0A), 0801A3AC?::0801A3C2 u8(0x0B), 
	030075F8::03007620 u32(0x44), 030075F8::0300762A u32(0x68), 030075F8::03007630 u32(0x68), 
	0300764C::03007650 u32(0x30), 0300764C::0300764E u32(0x34), 030075F8::0300761E u32(0x68), 
	08017AB4::08017B7E u16(0x80), 030075F8::03007628 u32(0x68), 030075F8::0300762C u32(0x44), 
	03007214::03007230 u32(0x30), 0300723A?::0300723A u32(0x3C), 0300732C?::03007332 u32(0x44), 
	0300732C?::0300733A u32(0x30), 0300732C?::03007344 u8(0x19), 0300732C?::0300734E u8(0x10), 
	0300732C?::0300735A u8(0x07), 0300732C?::030073B2 u8(0x0E), 0300732C?::030073BC u16(0x12), 
	0300732C?::030073CC u8(0x02), 0300732C?::030073D6 u8(0x19), 0300732C?::030073F6 u16(0x2E), 
	0300732C?::030073F8 u8(0x02), 03007668::03007676 u8(0x02), 0300732C?::03007422 u32(0x64), 
	0300768E::030076A4 u32(0x30), 030076AE?::030076AE u32(0x3C), 030076C0?::030076C0 u32(0x30), 
	030076D2?::030076D4 u32(0x30), 030076D2?::030076DA u8(0x19), 030076D2?::030076E4 u8(0x02), 
	030076D2?::030076EA u16(0x2E), 03007214::0300721A u32(0x3C), 03007214::0300721C u32(0x30), 
	030072C4?::030072F6 u8(0x03), 030072C4?::030072FA u8(0x03), 030072C4?::03007300 u32(0x70), 
	030072C4?::03007304 u32(0x70), 0300768E::0300769A u32(0x3C), 030076AE?::030076B0 u32(0x30), 
	030076C0?::030076C2 u32(0x3C), 030076D2?::030076D2 u32(0x6C), 030076D2?::030076D8 u32(0x6C), 
	030076D2?::030076DE u8(0x77), 030076D2?::030076E2 u8(0x77), 030076D2?::030076EC u16(0x94), 
	030076D2?::030076F0 u16(0x94), 03007668::0300766C u8(0x0B), 03007668::0300766E u8(0x0A), 
	030076D2?::030076FC u16(0x94), 030076D2?::03007700 u16(0x94), 0800E9DC::0800E9F6 u8(0x0D), 
	0801A420?::0801A42A u8(0x0D), 03007308?::03007308 u32(0x30), 0300731A?::0300731A u32(0x30), 
	0300732C?::03007334 u32(0x7C), 0300732C?::03007338 u32(0x7C), 0300732C?::0300733C u32(0x70), 
	0300732C?::03007340 u32(0x70), 0300732C?::03007348 u8(0x76), 0300732C?::0300734C u8(0x76), 
	0300745C::0300745E u8(0x02), 0300732C?::0300735C u8(0x0D), 0300732C?::03007382 u8(0x0D), 
	0300732C?::03007394 u16(0x90), 0300732C?::03007398 u16(0x90), 0300732C?::030073A0 u16(0x8E), 
	0300732C?::030073A4 u16(0x8E), 0300732C?::030073B4 u8(0x0F), 0300732C?::030073B8 u8(0x0F), 
	0300732C?::030073CA u8(0x02), 0300732C?::030073D4 u8(0x18), 0300732C?::030073E2 u8(0x75), 
	030074B6::030074BA u32(0x3C), 0300749E::030074A2 u32(0x3C), 0300732C?::030073F4 u8(0x74), 
	0300732C?::0300740C u16(0x82), 0300732C?::03007410 u16(0x82), 0300732C?::0300741C u16(0x82), 
	0300732C?::03007420 u16(0x82), 0300732C?::03007426 u32(0xA0), 0300732C?::0300742A u32(0xA0), 
	0801A16C?::0801A16E u32(0x40), 0801A16C?::0801A172 u32(0x40), 0801A29A::0801A2AC u16(0x2A), 
	0801A2B0::0801A2C2 u16(0x2C), 0801A284::0801A296 u16(0x1C), 0801A082::0801A086 u8(0x0E), 
	0801A082::0801A08A u16(0x2E), 0801A082::0801A094 u32(0x30), 0801A082::0801A09E u32(0x34), 
	0801A07C?::0801A07E u8(0x01), 080FCFCA::080FCFF4 u16(0x2E), 080FCFCA::080FCFF8 u8(0x07), 
	080101C4::080101CA u16(0x26), 0800E498::0800E4A2 u8(0x0C), 0800E548::0800E552 u8(0x0F), 
	0801A5EE::0801A60E u16(0x24), 0801A5EE::0801A61E u16(0x24), 08016934::08016956 u16(0x24), 
	0801A648::0801A658 u32(0x70), 0300732C?::03007370 u32(0x70), 0300732C?::03007374 u32(0x70), 
	0300732C?::0300738E u16(0x90), 0800EB26::0800EB32 u8(0x11), 0800EB26::0800EB3E u8(0x11), 
	0801A554::0801A574 u16(0x1C), 0801A45C::0801A48C u8(0x0D), 0800E730::0800E780 u16(0x1E), 
	0800E730::0800E782 u16(0x2A), 0800E730::0800E784 u16(0x2C), 08016CA4::08016CC8 u8(0x0D), 
	0300732C?::03007400 u16(0x78), 0300732C?::03007404 u16(0x78), 0801A074?::0801A078 u8(0x01), 
	0801A5E2?::0801A5E6 u32(0x48), 0801A5E2?::0801A5EA u32(0x4C), 0801A7EC?::0801A7FE u8(0x06), 
	080198CE?::080198D4 u8(0x00), 080198CE?::080198D6 u32(0x44), 

Accesses: CollisionData*/

/*
	03007214 0300723A? 030072C4? 03007308? 0300731A? 
	0300732C? 0300745C 0300749E 030074B6 0300754C 
	030075F8 0300764C 03007668 0300768E 030076AE? 
	030076C0? 030076D2? 03007704 03007778 0300785E? 
	03007876? 03007970? 0800E3DE 0800E498 0800E548 
	0800E730 0800E9DC 0800EB26 0800EB9E 08010162 
	08010198 080101C4 08013AE4 08016934 08016CA4 
	08017AB4 0801986C 080198AE? 080198CE? 08019F44 
	08019F9E? 08019FB4 0801A018 0801A04C 0801A074? 
	0801A07C? 0801A082 0801A152? 0801A15C? 0801A166? 
	0801A16C? 0801A176? 0801A180? 0801A186 0801A1CE? 
	0801A200 0801A284 0801A29A 0801A2B0 0801A2CC 
	0801A308 0801A36A 0801A3AC? 0801A420? 0801A42E 
	0801A45C 0801A4A6 0801A506 0801A554 0801A5E2? 
	0801A5EE 0801A648 0801A6E8 0801A720 0801A7EC? 
	0801A80C? 0801AEB0 0801BA12 0801C168 0802CFF8 
	080FCFCA 
Functions: CollisionData*/

/*
	name=Battle, size=0xD8
	08003490::080034BC u8(0x02), 08003490::080034BE u8(0x03), 08003278::080032B8 u8(0x00), 
	08003278::080032BE u8(0x01), 08003278::080032C0 u32(0x34), 08003278::080032C2 u32(0x38), 
	08003278::080032C4 u32(0x3C), 08003278::080032C6 u32(0x04), 080076A0::080076DC u8(0x16), 
	080076A0::080076E2 u32(0x58), 080076A0::080076F2 u8(0x05), 08007778::0800777A u8(0x16), 
	08007778::08007792 u32(0x58), 08007778::0800779A u8(0x16), 080076A0::08007708 u8(0x00), 
	080076A0::0800770E u8(0x00), 080076A0::08007712 u16(0x28), 080076A0::08007740 u16(0x24), 
	080076A0::08007742 u16(0x26), 080076A0::08007746 u8(0x0E), 080076A0::0800774A u16(0x2C), 
	080076A0::0800774E u16(0x2E), 080076A0::08007754 u8(0x12), 080076A0::08007756 u8(0x13), 
	080076A0::08007758 u8(0x14), 080076A0::0800775A u8(0x15), 080076A0::08007762 u16(0x2A), 
	080077D2::080077D4 u16(0x28), 080077D2::080077D6 u16(0x16), 080AC0FC::080AC118 u16(0x28), 
	080031AC::080031CA u8(0x00), 080031AC::080031E8 u8(0x02), 080031AC::080031F4 u8(0x01), 
	080B9A5C::080B9A5E u32(0x58), 080F3658::080F365C u8(0x08), 0800F420::0800F422 u32(0x58), 
	08016F56::08016F5C u32(0x58), 08016F56::08016F5E u16(0x28), 080026E4::080026E6 u8(0x00), 
	080026E4::080026EC u8(0x00), 080026E4::080026EE u8(0x02), 08002722?::0800272E u32(0x90+0x18), 
	08002722?::08002732 u8(0x90+0x03), 08002722?::08002734 u8(0x90+0x00), 08002722?::08002736 u32(0x90+0x24), 
	08002722?::08002738 u8(0x90+0x04), 08002722?::0800273A u16(0x90+0x0A), 08002722?::0800273C u16(0x90+0x06), 
	08002722?::0800273E u32(0x90+0x2C), 08002722?::08002740 u16(0x90+0x10), 08002722?::08002742 u16(0x90+0x12), 
	08002722?::08002744 u8(0x90+0x14), 08002722?::08002746 u8(0x90+0x05), 08002722?::08002748 u32(0x90+0x30), 
	08002722?::0800274A u32(0x90+0x34), 08002722?::0800274E u32(0x90+0x28), 08002722?::08002752 u8(0x90+0x15), 
	08002722?::08002756 u16(0x90+0x16), 080026E4::0800271E u8(0x90+0x03), 08002E3C?::08002E3C u8(0x02), 
	08002E3C?::08002E44 u8(0x90+0x03), 08002E3C?::08002E4E u8(0x90+0x03), 08016F56::08016F82 u8(0x10), 
	08016F56::08016F86 u8(0x11), 08002DA4?::08002DA4 u8(0x02), 08002DA4?::08002DAC u8(0x90+0x00), 
	080026A4::080026A6 u8(0x02), 03006730::03006732 u8(0x90+0x03), 03006730::0300675A u8(0x90+0x00), 
	03006730::0300675E u32(0x90+0x18), 03006730::03006764 u32(0x90+0x1C), 03006730::0300676E u32(0x90+0x20), 
	03006730::03006772 u8(0x90+0x01), 03006730::03006776 u8(0x90+0x02), 03006730::03006778 u32(0x90+0x20), 
	03006730::0300677E u32(0x90+0x1C), 03006730::03006782 u32(0x90+0x18), 03006730::0300678E u8(0x90+0x05), 
	0800F334?::0800F334 u32(0x58), 08002D80?::08002D80 u8(0x02), 08002D80?::08002D88 u8(0x90+0x04), 
	0800E456?::0800E456 u8(0x16), 0800E456?::0800E458 u8(0x17), 08002F5A?::08002F5C u8(0x02), 
	08002F5A?::08002F64 u8(0x90+0x13), 08002F5A?::08002F6E u8(0x90+0x13), 08002F5A?::08002F72 u8(0x90+0x16), 
	08002F5A?::08002F7A u8(0x90+0x16), 08016F56::08016FA2 u8(0x0E), 08016F56::08016FA6 u8(0x0E), 
	080198AE?::080198CA u32(0x54), 08016F56::08016FCE u16(0x28), 08019FB4::08019FBC u8(0x0E), 
	08019FB4::08019FCA u16(0x16), 08019FB4::08019FD0 u16(0x12), 08019FB4::08019FD8 u16(0x2E), 
	08019FB4::08019FDC u16(0x2C), 08019FB4::08019FE0 u8(0x16), 08019FB4::08019FFC u8(0x16), 
	08019F9E?::08019F9E u32(0x54), 0801DB84::0801DB86 u8(0x16), 0801DB84::0801DBB8 u16(0x28), 
	0801DB84::0801DBBC u8(0x16), 0801DB84::0801DBBE u8(0x17), 08016F56::08017038 u8(0x16), 
	0800F318?::0800F318 u32(0x58), 08016F56::0801705E u8(0x17), 0800F2C6::0800F2D0 u32(0x58), 
	0801DBD4::0801DBF0 u16(0x28), 0801DBD4::0801DBF4 u8(0x16), 0801DBD4::0801DBF6 u8(0x17), 
	08010DD0::08010DD2 u16(0x28), 08016F56::08017068 u8(0x16), 08016F56::08017086 u32(0x58), 
	08016F56::08017090 u32(0x08), 0800372A?::0800372A u8(0x02), 0800FDC0::0800FDD0 u32(0x58), 
	08003E18::08003E2E u8(0x00), 08003E18::08003E60 u32(0x90+0x24), 030061E8::030061EE u8(0x00), 
	030061E8::030061F6 u8(0x02), 03006388?::03006394 u16(0x34+0x02), 03006388?::030063C4 u8(0x90+0x16), 
	03006388?::030063B8 u8(0x90+0x13), 03006388?::030063C0 u8(0x90+0x13), 03006388?::030063CE u16(0x90+0x0C), 
	03006388?::030063D2 u16(0x34+0x06), 03006388?::030063DE u16(0x90+0x0A), 03006388?::030063E2 u16(0x34+0x0A), 
	03006388?::030063EC u8(0x90+0x0E), 03006388?::030063EE u8(0x90+0x0F), 03006388?::030063F0 u8(0x90+0x03), 
	030061E8::0300621A u8(0x90+0x03), 030061E8::03006226 u8(0x90+0x13), 030061E8::03006234 u8(0x90+0x13), 
	030061E8::03006240 u32(0x90+0x20), 030061E8::03006246 u32(0x90+0x1C), 030061E8::0300624A u32(0x90+0x18), 
	030061E8::030062CC u8(0x90+0x03), 030061E8::030062FC u8(0x90+0x03), 030061E8::030062FE u32(0x90+0x28), 
	080F367C::080F367E u32(0x58), 08002DD8?::08002DD8 u8(0x02), 08002DD8?::08002DE0 u8(0x90+0x15), 
	08002DD8?::08002DE6 u8(0x90+0x15), 0801A9B8::0801A9BE u32(0x54), 0801AF44::0801AF4A u32(0x54), 
	0801AF44::0801AF4C u32(0x58), 0801AF44::0801AF56 u8(0x09), 0801A42E::0801A430 u32(0x54), 
	0801A4A6::0801A4A8 u32(0x54), 0801A45C::0801A45E u32(0x54), 0801A506::0801A508 u32(0x54), 
	0800E2D8::0800E2DA u16(0x24), 0800E2D8::0800E2E2 u16(0x24), 0801BA12::0801BA70 u16(0x24), 
	0801A200::0801A20A u32(0x54), 0801A200::0801A250 u8(0x16), 0801BADE::0801BAE2 u8(0x09), 
	0801A166?::0801A166 u32(0x54), 0801A180?::0801A180 u32(0x54), 0801032C?::0801032C u32(0x58), 
	0801AF44::0801AFE6 u8(0x18), 0800FFFE?::0800FFFE u32(0x58), 0801AF44::0801B0BE u8(0x0D), 
	0801AF44::0801B0EA u8(0x1F), 0800E730::0800E73A u32(0x54), 08010162::08010164 u32(0x54), 
	0801A15C?::0801A15C u32(0x54), 08014326::08014328 u16(0x28), 08014498::080144A2 u32(0x58), 
	0802E1D8::0802E1DA u8(0x16), 08002EE8?::08002EE8 u8(0x02), 08002EE8?::08002EF2 u16(0x90+0x06), 
	0801A176?::0801A176 u32(0x54), 080143E4::080143E6 u32(0x58), 08013774::08013776 u8(0x16), 
	08016860::08016870 u8(0x09), 08016934::0801693C u8(0x00), 08016934::08016942 u8(0x00), 
	08016934::0801696A u8(0x16), 08016934::08016970 u8(0x16), 08016CA4::08016CB4 u8(0x16), 
	0801AF44::0801B180 u8(0x09), 0801B9E6::0801B9E8 u32(0x58), 0801B9E6::0801B9F2 u8(0x09), 
	08016380::08016382 u32(0x58), 08016396::0801639A u8(0x0A), 080163B4::080163B6 u8(0x0B), 
	080163B4::080163C2 u8(0x16), 080163B4::080163DE u8(0x0B), 08016410?::08016410 u8(0x00), 
	08016410?::08016416 u8(0x00), 080F367C::080F36B0 u32(0x58), 0801A018::0801A01A u32(0x54), 
	0801A018::0801A042 u32(0x54), 080163B4::080163FE u16(0x20), 080163B4::08016402 u16(0x22), 
	08002C7A?::08002C7E u8(0x02), 08002C7A?::08002C88 u8(0x90+0x11), 08002C7A?::08002C90 u8(0x90+0x11), 
	080163B4::0801640C u8(0x0A), 03006028::0300602A u8(0x02), 03006028::03006032 u8(0x90+0x03), 
	03006028::03006038 u8(0x90+0x03), 03006028::03006052 u32(0x90+0x1C), 03006028::03006056 u32(0x90+0x18), 
	03006028::03006062 u16(0x90+0x08), 03006028::0300606E u32(0x90+0x24), 03006028::03006090 u16(0x90+0x08), 
	03006028::03006096 u32(0x90+0x24), 03006028::0300609E u32(0x90+0x24), 03006028::030060A8 u16(0x90+0x08), 
	03006028::030060BE u8(0x90+0x15), 03006028::030060CA u8(0x90+0x03), 03006108::0300610A u32(0x90+0x1C), 
	03006108::03006110 u32(0x90+0x18), 03006108::03006114 u8(0x90+0x04), 03006108::03006116 u8(0x90+0x05), 
	03006108::0300611E u16(0x90+0x06), 03006028::030060D6 u8(0x90+0x15), 03006028::030060E0 u8(0x90+0x15), 
	03006440::03006442 u8(0x90+0x03), 03006452?::03006460 u32(0x90+0x30), 03006452?::03006466 u32(0x90+0x20), 
	03006452?::0300646C u32(0x90+0x1C), 03006452?::03006470 u32(0x90+0x18), 03006452?::03006478 u32(0x90+0x28), 
	03006452?::0300647C u32(0x90+0x2C), 03006452?::03006482 u32(0x90+0x28), 03006452?::03006484 u8(0x90+0x16), 
	03006452?::03006498 u8(0x90+0x16), 03006452?::0300649A u8(0x90+0x03), 03006452?::030064BC u32(0x90+0x28), 
	03006452?::030064C0 u32(0x90+0x28), 03006452?::030064C6 u32(0x90+0x10), 03006452?::030064C8 u8(0x90+0x16), 
	0300658A?::030065A6 u8(0x90+0x13), 0300658A?::030065C4 u8(0x90+0x13), 03006452?::030064DE u16(0x90+0x0C), 
	03006452?::03006500 u8(0x90+0x0F), 03006452?::03006514 u16(0x90+0x14), 03006452?::03006528 u16(0x90+0x08), 
	03006452?::0300653E u16(0x90+0x0A), 03006452?::03006564 u8(0x90+0x03), 03006452?::03006584 u32(0x90+0x28), 
	0801641A::0801641C u16(0x20), 0801641A::08016420 u16(0x20), 0801641A::08016426 u16(0x20), 
	0801641A::08016428 u16(0x22), 0801641A::0801642C u16(0x22), 08002EF6?::08002F0C u8(0x02), 
	08002EF6?::08002F14 u8(0x90+0x11), 08002EF6?::08002F18 u8(0x90+0x11), 0801641A::08016442 u8(0x00), 
	0801641A::08016448 u8(0x00), 08002CCE?::08002CCE u8(0x02), 08002CCE?::08002CD6 u8(0x90+0x11), 
	08002CCE?::08002CDC u8(0x90+0x11), 08002F2C?::08002F2C u8(0x02), 08002F2C?::08002F34 u8(0x90+0x11), 
	08002F2C?::08002F3A u8(0x90+0x11), 0801641A::0801645C u16(0x0A), 08016460::08016478 u8(0x16), 
	08016460::08016482 u16(0x28), 0801DC7C::0801DC98 u16(0x28), 0801DC7C::0801DCB2 u16(0x24), 
	08016460::08016498 u8(0x09), 08016460::0801649C u16(0x0A), 0801C168::0801C17A u16(0x24), 
	0801C168::0801C1A0 u32(0x54), 0800362C::08003634 u16(0x34+0x02), 0800362C::0800364A u16(0x34+0x06), 
	0800362C::08003656 u16(0x34+0x0A), 08017BC0::08017BC2 u32(0x58), 0800ED90::0800ED94 u16(0x28), 
	0800EDC6?::0800EDC6 u16(0x2A), 0800EDC6?::0800EDCC u8(0x1A), 0800A998::0800A9B8 u16(0x28), 
	080103BC::080103D2 u16(0x28), 0800EBD4::0800EBEC u16(0x28), 080E2A44::080E2A4E u8(0x12), 
	080E28A6::080E28F4 u16(0x28), 080E28A6::080E2910 u8(0x16), 080E28A6::080E2912 u8(0x17), 
	0300754C::03007550 u32(0x54), 0801A80C?::0801A80C u32(0x54), 0801A186::0801A194 u32(0x54), 
	0801A36A::0801A36C u32(0x54), 0801A36A::0801A37A u32(0x58), 08010230::0801023E u32(0x58), 
	08010230::08010240 u16(0x24), 0802CFF8::0802CFFA u32(0x54), 0802CEF4::0802CEF6 u32(0x54), 
	0802CEF4::0802CF32 u8(0x16), 0801A6B4::0801A6B6 u32(0x54), 0801A720::0801A722 u32(0x54), 
	08013AE4::08013AE8 u32(0x54), 0800EB26::0800EB28 u32(0x54), 0801A9B8::0801AA0E u16(0x28), 
	0801A554::0801A556 u32(0x54), 0801A2CC::0801A2CE u32(0x54), 0801A308::0801A30A u8(0x16), 
	0801A308::0801A316 u32(0x54), 0800E3DE::0800E3E0 u32(0x54), 0800E3DE::0800E3E2 u8(0x12), 
	0800E3DE::0800E3E4 u8(0x13), 0800E3DE::0800E3FC u32(0x54), 0802CE10?::0802CE12 u8(0x16), 
	0800E3DE::0800E418 u32(0x54), 0801A420?::0801A420 u32(0x54), 08010198::0801019A u32(0x54), 
	0801A648::0801A650 u32(0x54), 0800EB9E::0800EBA6 u32(0x54), 0801A5EE::0801A5FA u32(0x54), 
	08017888::080178AE u8(0x09), 08017888::080178B2 u16(0x0A), 0801BBAC::0801BBB4 u8(0x00), 
	0801BBAC::0801BBCE u32(0x54), 0801BBAC::0801BBD4 u8(0x18), 0801BBAC::0801BBDA u8(0x10), 
	0801BBAC::0801BBDC u8(0x11), 0801BBAC::0801BBEA u8(0x10), 0801BBAC::0801BBEC u8(0x11), 
	080026C4::080026C6 u8(0x02), 03006792::03006794 u8(0x90+0x01), 03006792::03006798 u8(0x90+0x01), 
	03006792::030067F8 u32(0x90+0x20), 03006792::030067FE u32(0x90+0x1C), 03006792::03006802 u32(0x90+0x18), 
	03006792::0300680E u8(0x90+0x05), 080FCD04::080FCD06 u32(0x58), 0800FE36?::0800FE36 u32(0x58), 
	08011698::0801169A u8(0x09), 08011698::0801169E u16(0x0A), 08011698::080116A0 u32(0x58), 
	0801011A::0801011C u32(0x58), 080E29A2?::080E29A2 u32(0x58), 080FCE5C::080FCEDA u16(0x26), 
	080FCE5C::080FCEDE u16(0x24), 03006792::0300679E u8(0x90+0x03), 03006792::030067C0 u32(0x90+0x1C), 
	03006792::030067EE u8(0x90+0x01), 080FD3BC::080FD3C4 u8(0x16), 080FDFE4::080FE010 u8(0x12), 
	080FDFE4::080FE012 u8(0x13), 080FDFE4::080FE046 u8(0x12), 080FDFE4::080FE048 u8(0x13), 
	080FDFE4::080FE050 u8(0x16), 080FD3BC::080FD3DA u8(0x14), 080FD3BC::080FD3DC u8(0x15), 
	0801BB1C::0801BB36 u8(0x00), 0801BB1C::0801BB3C u8(0x00), 0801A152?::0801A152 u32(0x54), 
	080FD3BC::080FD3EA u8(0x10), 03006792::030067CE u32(0x90+0x1C), 03006792::030067D0 u32(0x90+0x18), 
	03006792::030067DA u32(0x90+0x20), 03006792::030067DE u8(0x90+0x01), 03006792::030067E2 u8(0x90+0x02), 
	080FD414::080FD420 u8(0x10), 080FD414::080FD422 u8(0x14), 080FD414::080FD424 u8(0x15), 
	080FD414::080FD426 u8(0x12), 080FD414::080FD428 u8(0x13), 0800E29C::0800E29E u8(0x12), 
	0800E29C::0800E2A0 u8(0x13), 0800E29C::0800E2A6 u32(0x34), 0800E29C::0800E2A8 u32(0x38), 
	0801A04C::0801A04E u32(0x54), 0801A04C::0801A054 u8(0x12), 0801A04C::0801A058 u8(0x13), 
	0801A04C::0801A05C u8(0x16), 08017AB4::08017AB8 u16(0x28), 08017AB4::08017B64 u8(0x18), 
	08017AB4::08017B6A u16(0x36), 08017AB4::08017B6C u16(0x30), 08017AB4::08017B6E u16(0x3E), 
	08017AB4::08017B70 u16(0x32), 08017AB4::08017B74 u8(0x19), 08017AB4::08017B78 u8(0x18), 
	08017AB4::08017B7A u32(0x54), 08017AB4::08017B88 u8(0x19), 08017AB4::08017BAA u16(0x30), 
	08017AB4::08017BAC u16(0x36), 08017AB4::08017BAE u16(0x32), 08017AB4::08017BB0 u16(0x3E), 
	08003400::08003412 u32(0xC8+0x00), 08003400::08003418 u32(0xC8+0x04), 080031AC::080031BA u32(0xC8+0x04), 
	08003458::0800347C u32(0xC8+0x00), 08003458::0800347E u32(0xC8+0x04), 03006028::030060B8 u16(0x90+0x08), 
	03006028::030060BC u32(0x90+0x24), 08003400::08003414 u32(0xC8+0x04), 08003400::08003416 u32(0xC8+0x04), 
	0801A16C?::0801A16C u32(0x54), 08010548::0801054C u32(0x58), 0801BA12::0801BA22 u16(0x24), 
	0801BA12::0801BA44 u16(0x28), 08002DB0?::08002DB4 u8(0x02), 08002DB0?::08002DBC u8(0x90+0x15), 
	08002DB0?::08002DC4 u8(0x90+0x15), 08017AB4::08017B86 u8(0x19), 08017AB4::08017B90 u8(0x19), 
	08017AB4::08017B92 u16(0x30), 08017AB4::08017B96 u32(0x38), 08017AB4::08017B98 u16(0x32), 
	08003458::08003480 u32(0xC8+0x04), 0801BA92::0801BA96 u8(0x09), 0801BABE::0801BAC2 u8(0x09), 
	08016934::08016954 u32(0x54), 08016934::0801695C u8(0x00), 08016934::08016962 u8(0x00), 
	080174FE::08017500 u8(0x0B), 0801A082::0801A084 u32(0x54), 0801A082::0801A088 u16(0x2C), 
	0801A082::0801A08C u8(0x16), 0801A082::0801A096 u8(0x16), 0801A07C?::0801A07C u32(0x54), 
	080FCFCA::080FCFEA u32(0x2C), 080FCFCA::080FCFF2 u32(0x54), 080FCFCA::080FD002 u32(0x58), 
	080FCFCA::080FD00E u32(0x64), 0801A284::0801A294 u32(0x54), 0801A29A::0801A2AA u32(0x54), 
	0801A2B0::0801A2C0 u32(0x54), 0801A2B0::0801A2C4 u32(0x58), 0801A2B0::0801A2C8 u16(0x3E), 
	080101C4::080101C6 u32(0x54), 0801031C?::0801031C u32(0x58), 08012EA8::08012EAA u32(0x58), 
	0800FFEE?::0800FFEE u32(0x58), 080174FE::0801753C u8(0x14), 080174FE::0801753E u8(0x12), 
	080174FE::08017540 u8(0x15), 080174FE::08017542 u8(0x13), 080174FE::08017552 u32(0x3C), 
	080174FE::08017556 u8(0x10), 080174FE::0801755A u8(0x11), 08011450::08011452 u32(0x58), 
	08011450::08011462 u32(0x50), 080174FE::0801756A u32(0x4C), 080174FE::0801756C u32(0x58), 
	080174FE::08017570 u8(0x16), 080174FE::0801757C u16(0x20), 080174FE::08017580 u8(0x0B), 
	080174FE::08017582 u16(0x20), 080174FE::08017586 u16(0x20), 080174FE::08017598 u8(0x10), 
	080174FE::0801759C u8(0x09), 080174FE::080175A0 u16(0x0A), 080FD440::080FD452 u8(0x10), 
	08011714::08011718 u8(0x10), 0801171C::0801171E u32(0x58), 0801171C::08011756 u8(0x09), 
	0800FE12?::0800FE12 u32(0x58), 080FD2BA::080FD2DE u32(0x58), 080FD188::080FD1B0 u8(0x16), 
	080FD4A4::080FD4AC u8(0x16), 080FE098::080FE09C u8(0x16), 080FD4A4::080FD4C4 u8(0x14), 
	080FD4A4::080FD4C6 u8(0x15), 080FD4A4::080FD4D4 u8(0x10), 080FD504::080FD510 u8(0x10), 
	080FD504::080FD512 u8(0x14), 080FD504::080FD514 u8(0x15), 080FD504::080FD516 u8(0x12), 
	080FD504::080FD518 u8(0x13), 080FD54E::080FD55C u8(0x10), 0800E2CA?::0800E2CA u8(0x16), 
	0800E2CA?::0800E2CC u8(0x17), 080FD54E::080FD576 u8(0x12), 080FD54E::080FD57A u8(0x13), 
	080FD54E::080FD57E u16(0x16), 080FD592::080FD5A0 u8(0x10), 080BA6A0::080BA6B4 u16(0x12), 
	080BA6A0::080BA6B8 u16(0x16), 080BA6A0::080BA6C4 u32(0x64+0x00), 0800E9DC::0800E9DE u32(0x58), 
	0800E9DC::0800E9F4 u32(0x54), 080BA568::080BA588 u16(0x28), 080BA616::080BA640 u8(0x00), 
	08002EDC?::08002EDC u8(0x02), 08002EDC?::08002EE4 u16(0x90+0x06), 08002DC8?::08002DC8 u8(0x02), 
	08002DC8?::08002DD0 u8(0x90+0x15), 08002CE0?::08002CE0 u8(0x02), 08002CE0?::08002CE8 u8(0x90+0x11), 
	08002F7E?::08002F7E u8(0x02), 08002F7E?::08002F86 u8(0x90+0x16), 080BA616::080BA674 u32(0x64+0x00), 
	080FD592::080FD5D2 u8(0x12), 080FD592::080FD5D6 u8(0x13), 08003400::0800341A u32(0xC8+0x00), 
	080C6BDA::080C6BF2 u16(0x16), 080FD592::080FD5EC u8(0x12), 080FD592::080FD5F0 u8(0x13), 
	08003458::08003482 u32(0xC8+0x00), 080FE2C4::080FE2CC u32(0x64+0x00), 080FD1C4::080FD1C8 u32(0x60), 
	080FD1C4::080FD1FC u8(0x16), 080FD660::080FD668 u8(0x16), 080FD660::080FD680 u8(0x14), 
	080FD660::080FD682 u8(0x15), 080FD660::080FD690 u8(0x10), 080FD6C0::080FD6CC u8(0x10), 
	080FD6C0::080FD6CE u8(0x14), 080FD6C0::080FD6D0 u8(0x15), 080FD6C0::080FD6D2 u8(0x12), 
	080FD6C0::080FD6D4 u8(0x13), 080D3464::080D3478 u16(0x16), 080D3464::080D347C u16(0x12), 
	080E8DC8::080E8DDA u16(0x16), 080E8DF0::080E8DFC u16(0x36), 080E8DF0::080E8E02 u16(0x3A), 
	080E8DF0::080E8E06 u16(0x3E), 080E8D0E::080E8D26 u8(0x00), 08002D8C?::08002D8C u8(0x02), 
	08002D8C?::08002D94 u8(0x90+0x04), 08002F3E?::08002F3E u8(0x02), 08002F3E?::08002F46 u8(0x90+0x11), 
	080E8D0E::080E8D5A u8(0x17), 080E8D90::080E8D94 u8(0x09), 080D340A::080D3436 u8(0x60+0x00), 
	080FD210::080FD238 u8(0x16), 080FD950::080FD972 u8(0x12), 080FD950::080FD974 u8(0x13), 
	080FD950::080FD976 u8(0x14), 080FD950::080FD978 u8(0x15), 080FD950::080FD986 u8(0x10), 
	080FD9AC::080FD9B8 u8(0x10), 080FD9AC::080FD9BE u8(0x12), 080FD9AC::080FD9C0 u8(0x13), 
	080FD9E4::080FD9F2 u8(0x10), 080FD9E4::080FDA0C u8(0x12), 080FD9E4::080FDA10 u8(0x13), 
	080FD9E4::080FDA14 u16(0x16), 080FDA28::080FDA36 u8(0x10), 080FDA28::080FDA68 u8(0x12), 
	080FDA28::080FDA6C u8(0x13), 080FDA28::080FDA82 u8(0x12), 080FDA28::080FDA86 u8(0x13), 
	080FDABA::080FDAC8 u8(0x10), 080FDABA::080FDAD0 u8(0x12), 080FDABA::080FDAD2 u8(0x13), 
	080FDABA::080FDAD8 u8(0x14), 080FDABA::080FDADA u8(0x15), 080FDABA::080FDADC u8(0x12), 
	080FDABA::080FDADE u8(0x13), 080FD70A::080FD738 u32(0x60+0x00), 080FDB38::080FDB40 u8(0x16), 
	080FE106::080FE10C u8(0x16), 080FE106::080FE110 u8(0x16), 080FDB38::080FDB56 u8(0x14), 
	080FDB38::080FDB58 u8(0x15), 080FDB38::080FDB66 u8(0x10), 080FDB94::080FDBA0 u8(0x10), 
	080FDB94::080FDBA2 u8(0x14), 080FDB94::080FDBA4 u8(0x15), 080FDB94::080FDBA6 u8(0x12), 
	080FDB94::080FDBA8 u8(0x13), 080FDBDE::080FDBEC u8(0x10), 080FDBDE::080FDC0A u8(0x12), 
	080FDBDE::080FDC0E u8(0x13), 080FDBDE::080FDC12 u16(0x16), 080FDC26::080FDC34 u8(0x10), 
	080FDC26::080FDC6E u8(0x12), 080FDC26::080FDC72 u8(0x13), 080FDC26::080FDC8C u8(0x12), 
	080FDC26::080FDC90 u8(0x13), 080FDC26::080FDCB4 u8(0x12), 080FDC26::080FDCB8 u8(0x13), 
	080E1C00::080E1C12 u8(0x16), 080FD76C::080FD78E u8(0x12), 080FD76C::080FD790 u8(0x13), 
	080FD76C::080FD79A u8(0x12), 080FD76C::080FD79C u8(0x13), 080FD76C::080FD79E u8(0x14), 
	080FD76C::080FD7A0 u8(0x15), 080FE2D0::080FE2DA u8(0x10), 080E473A::080E4750 u8(0x16), 
	080FE1A6::080FE1AA u8(0x12), 080FE1A6::080FE1B4 u8(0x12), 080FE1A6::080FE1C0 u32(0x40), 
	080FE1A6::080FE1C2 u8(0x12), 080FE1A6::080FE1DC u8(0x13), 080FE1A6::080FE1FA u32(0x44), 
	080D647A::080D648E u32(0x09+0x00), 080D647A::080D6494 u16(0x16), 080FD76C::080FD7C2 u32(0x44), 
	080FD76C::080FD7C4 u32(0x38), 080FD76C::080FD7C8 u32(0x38), 080FD76C::080FD7CA u32(0x40), 
	080FD76C::080FD7CC u32(0x34), 080FD76C::080FD7D0 u32(0x34), 080FD76C::080FD7D2 u8(0x12), 
	0800E2AC::0800E2AE u32(0x34), 0800E2AC::0800E2B0 u32(0x38), 0800E2AC::0800E2B4 u32(0x3C), 
	0800E2AC::0800E2BA u8(0x12), 0800E2AC::0800E2BC u8(0x13), 080FD76C::080FD7DC u8(0x12), 
	080D64AA::080D64B0 u32(0x40), 080D64AA::080D64BE u8(0x12), 080D64AA::080D64C6 u32(0x44), 
	080D64AA::080D64D4 u8(0x13), 080D64DC::080D64E2 u32(0x09+0x00), 080FD7FA::080FD828 u8(0x12), 
	080FD7FA::080FD82C u8(0x13), 080FD7FA::080FD830 u16(0x16), 080FD844::080FD852 u8(0x10), 
	080FD844::080FD884 u8(0x12), 080FD844::080FD888 u8(0x13), 080FD844::080FD89E u8(0x12), 
	080FD844::080FD8A2 u8(0x13), 080FD8D6::080FD8E4 u8(0x10), 080FD8D6::080FD8EC u8(0x14), 
	080FD8D6::080FD8EE u8(0x15), 080FD8D6::080FD8F0 u8(0x12), 080FD8D6::080FD8F2 u8(0x13), 
	080FCFCA::080FD016 u32(0x64), 080FD11C::080FD120 u8(0x16), 080FD11C::080FD134 u8(0x16), 
	080FCEF2::080FCF8E u16(0x26), 080FCEF2::080FCF92 u16(0x24), 0801AEB0::0801AEF2 u8(0x0F), 
	0801AEB0::0801AEF4 u8(0x0F), 0801A45C::0801A47C u8(0x16), 0801A200::0801A21A u8(0x16), 
	0801445C?::0801445C u32(0x58), 08014490?::08014490 u32(0x58), 0801AF44::0801B064 u32(0x5C), 
	0801AF44::0801B06A u32(0x08), 0801AF44::0801B06C u32(0x5C), 0801AF44::0801B0A0 u8(0x09), 
	0801AF44::0801B0A4 u8(0x0A), 0801AF44::0801B0A6 u8(0x0D), 080178B6::080178BA u8(0x0D), 
	080178D4::080178E2 u32(0x4C), 080178D4::080178E4 u32(0x58), 080178D4::08017900 u8(0x10), 
	080178D4::08017904 u8(0x11), 080178D4::08017916 u16(0x14), 080178D4::08017918 u16(0x12), 
	080178D4::08017924 u16(0x3C), 080178D4::08017930 u8(0x14), 080178D4::08017932 u8(0x15), 
	080178D4::08017938 u8(0x16), 0800E468::0800E46C u8(0x0F), 0800E498::0800E4A0 u32(0x54), 
	0800E2C0?::0800E2C0 u8(0x16), 0800E548::0800E550 u32(0x54), 0800E468::0800E478 u8(0x12), 
	0800E468::0800E47C u8(0x13), 0800E5AC::0800E5C6 u8(0x16), 080178D4::08017946 u8(0x1C), 
	080178D4::08017948 u8(0x1D), 080178D4::0801794A u16(0x22), 080178D4::08017950 u8(0x12), 
	080178D4::08017954 u8(0x13), 080178D4::08017964 u8(0x1C), 080178D4::0801796A u32(0x40), 
	080178D4::0801796E u8(0x1D), 080178D4::08017974 u32(0x44), 080178D4::0801797A u8(0x14), 
	080178D4::0801797C u8(0x15), 080178D4::08017984 u8(0x0D), 0801AF44::0801B0B8 u8(0x09), 
	08017992::08017994 u8(0x14), 08017992::08017996 u8(0x15), 08017992::080179A0 u32(0x34), 
	08017992::080179A2 u32(0x40), 08017992::080179A6 u32(0x34), 08017992::080179B2 u32(0x38), 
	08017992::080179B4 u32(0x44), 08017992::080179B8 u32(0x38), 08017992::080179C2 u8(0x14), 
	08017992::080179C4 u8(0x15), 08017992::080179CA u8(0x14), 08017992::080179CC u8(0x15), 
	08017992::080179E8 u16(0x22), 08017992::080179EC u16(0x22), 08017992::080179F2 u8(0x1C), 
	08017992::080179F4 u8(0x14), 08017992::080179FA u8(0x1D), 08017992::080179FC u8(0x15), 
	08017992::08017A0E u8(0x14), 08017992::08017A10 u8(0x15), 08017A18?::08017A18 u16(0x14), 
	08017A18?::08017A1A u16(0x12), 08017A18?::08017A26 u16(0x20), 08017A18?::08017A2A u8(0x0D), 
	08017A38::08017A3A u16(0x20), 08017A38::08017A3E u16(0x20), 08017A38::08017A78 u8(0x1F), 
	08017A38::08017A7C u8(0x10), 08017A38::08017A80 u8(0x11), 08017A38::08017A88 u8(0x09), 
	08017A38::08017A8C u16(0x0A), 0800E730::0800E76C u32(0x5C), 0800E730::0800E778 u8(0x09), 
	0800E730::0800E77C u16(0x0A), 0800E730::0800E79C u32(0x5C), 0800E730::0800E7A8 u8(0x09), 
	0800E730::0800E7AC u16(0x0A), 08002ED0?::08002ED0 u8(0x02), 08002ED0?::08002ED8 u16(0x90+0x06), 
	080175B8::080175BA u8(0x0B), 080175B8::080175EA u8(0x14), 080175B8::080175EC u8(0x12), 
	080175B8::080175EE u8(0x15), 080175B8::080175F0 u8(0x13), 080175B8::08017600 u32(0x3C), 
	080175B8::08017604 u8(0x10), 080175B8::08017608 u8(0x11), 080175B8::08017614 u32(0x4C), 
	080175B8::08017616 u32(0x58), 080175B8::0801761A u8(0x16), 080175B8::08017626 u8(0x0B), 
	080175B8::08017628 u32(0x58), 03006108::03006130 u16(0x90+0x06), 080175B8::08017660 u8(0x10), 
	080175B8::08017664 u8(0x09), 080175B8::08017668 u16(0x0A), 080E87C6::080E87E8 u32(0x54), 
	0802D358::0802D36E u32(0x54), 080170C4::080170CE u8(0x0A), 0801A074?::0801A074 u32(0x54), 
	0801A5E2?::0801A5E2 u32(0x54), 080170E4::080170FC u8(0x1A), 080170E4::08017100 u16(0x2A), 
	0801A7EC?::0801A7F6 u32(0x58), 0801A7EC?::0801A7FA u32(0x54), 080170E4::0801710E u8(0x05), 
	0800A11C?::0800A11C u8(0x16), 080170E4::0801711E u16(0x0A), 080FCFB2::080FCFB8 u8(0x10), 
	08017122::08017124 u8(0x0B), 08017122::08017132 u8(0x18), 08017122::08017136 u32(0x4C), 
	08017122::08017138 u32(0x58), 08017122::0801713E u8(0x10), 08017122::08017142 u32(0x58), 
	08017122::08017162 u16(0x20), 08017122::08017166 u8(0x0B), 08017122::08017168 u16(0x20), 
	08017122::0801716C u16(0x20), 080FCFB2::080FCFBE u32(0x64), 080FCFB2::080FCFC6 u32(0x64), 
	080E2D68?::080E2D7A u32(0x34), 080E2D68?::080E2D7C u32(0x38), 080E2D68?::080E2D7E u32(0x3C), 
	0802CD80::0802CDD2 u8(0x16), 08017122::08017174 u8(0x14), 08017122::08017176 u8(0x15), 
	08017122::0801717C u32(0x58), 08011020::08011022 u16(0x28), 08017122::0801718E u8(0x00), 
	08017122::08017194 u8(0x00), 08017122::08017198 u32(0x08), 08016C4E::08016C50 u32(0x58), 
	08016C4E::08016C52 u8(0x0B), 0801BB78::0801BB7A u8(0x00), 08016C4E::08016C5C u32(0x54), 
	0800A0FE?::0800A104 u32(0x58), 0800A0FE?::0800A10C u8(0x16), 08016C4E::08016C74 u8(0x0B), 
	0800A7A6::0800A7B8 u16(0x28), 08003458::0800345C u8(0x00), 08003458::0800345E u8(0x02), 
	08003458::0800346A u8(0x03), 08002D52::08002D54 u8(0x02), 08002D5E::08002D60 u8(0x90+0x11), 

	name=Battle, size=0xD8
	08003490::080034BC u8(0x02), 08003490::080034BE u8(0x03), 08003278::080032B8 u8(0x00), 
	08003278::080032BE u8(0x01), 08003278::080032C0 u32(0x34), 08003278::080032C2 u32(0x38), 
	08003278::080032C4 u32(0x3C), 08003278::080032C6 u32(0x04), 080076A0::080076DC u8(0x16), 
	080076A0::080076E2 u32(0x58), 080076A0::080076F2 u8(0x05), 08007778::0800777A u8(0x16), 
	08007778::08007792 u32(0x58), 08007778::0800779A u8(0x16), 080076A0::08007708 u8(0x00), 
	080076A0::0800770E u8(0x00), 080076A0::08007712 u16(0x28), 080076A0::08007740 u16(0x24), 
	080076A0::08007742 u16(0x26), 080076A0::08007746 u8(0x0E), 080076A0::0800774A u16(0x2C), 
	080076A0::0800774E u16(0x2E), 080076A0::08007754 u8(0x12), 080076A0::08007756 u8(0x13), 
	080076A0::08007758 u8(0x14), 080076A0::0800775A u8(0x15), 080076A0::08007762 u16(0x2A), 
	080077D2::080077D4 u16(0x28), 080077D2::080077D6 u16(0x16), 080AC0FC::080AC118 u16(0x28), 
	080031AC::080031CA u8(0x00), 080031AC::080031E8 u8(0x02), 080031AC::080031F4 u8(0x01), 
	080B9A5C::080B9A5E u32(0x58), 080F3658::080F365C u8(0x08), 0800F420::0800F422 u32(0x58), 
	08016F56::08016F5C u32(0x58), 08016F56::08016F5E u16(0x28), 080026E4::080026E6 u8(0x00), 
	080026E4::080026EC u8(0x00), 080026E4::080026EE u8(0x02), 08002722?::0800272E u32(0x90+0x18), 
	08002722?::08002732 u8(0x90+0x03), 08002722?::08002734 u8(0x90+0x00), 08002722?::08002736 u32(0x90+0x24), 
	08002722?::08002738 u8(0x90+0x04), 08002722?::0800273A u16(0x90+0x0A), 08002722?::0800273C u16(0x90+0x06), 
	08002722?::0800273E u32(0x90+0x2C), 08002722?::08002740 u16(0x90+0x10), 08002722?::08002742 u16(0x90+0x12), 
	08002722?::08002744 u8(0x90+0x14), 08002722?::08002746 u8(0x90+0x05), 08002722?::08002748 u32(0x90+0x30), 
	08002722?::0800274A u32(0x90+0x34), 08002722?::0800274E u32(0x90+0x28), 08002722?::08002752 u8(0x90+0x15), 
	08002722?::08002756 u16(0x90+0x16), 080026E4::0800271E u8(0x90+0x03), 08002E3C?::08002E3C u8(0x02), 
	08002E3C?::08002E44 u8(0x90+0x03), 08002E3C?::08002E4E u8(0x90+0x03), 08016F56::08016F82 u8(0x10), 
	08016F56::08016F86 u8(0x11), 08002DA4?::08002DA4 u8(0x02), 08002DA4?::08002DAC u8(0x90+0x00), 
	080026A4::080026A6 u8(0x02), 03006730::03006732 u8(0x90+0x03), 03006730::0300675A u8(0x90+0x00), 
	03006730::0300675E u32(0x90+0x18), 03006730::03006764 u32(0x90+0x1C), 03006730::0300676E u32(0x90+0x20), 
	03006730::03006772 u8(0x90+0x01), 03006730::03006776 u8(0x90+0x02), 03006730::03006778 u32(0x90+0x20), 
	03006730::0300677E u32(0x90+0x1C), 03006730::03006782 u32(0x90+0x18), 03006730::0300678E u8(0x90+0x05), 
	0800F334?::0800F334 u32(0x58), 08002D80?::08002D80 u8(0x02), 08002D80?::08002D88 u8(0x90+0x04), 
	0800E456?::0800E456 u8(0x16), 0800E456?::0800E458 u8(0x17), 08002F5A?::08002F5C u8(0x02), 
	08002F5A?::08002F64 u8(0x90+0x13), 08002F5A?::08002F6E u8(0x90+0x13), 08002F5A?::08002F72 u8(0x90+0x16), 
	08002F5A?::08002F7A u8(0x90+0x16), 08016F56::08016FA2 u8(0x0E), 08016F56::08016FA6 u8(0x0E), 
	080198AE?::080198CA u32(0x54), 08016F56::08016FCE u16(0x28), 08019FB4::08019FBC u8(0x0E), 
	08019FB4::08019FCA u16(0x16), 08019FB4::08019FD0 u16(0x12), 08019FB4::08019FD8 u16(0x2E), 
	08019FB4::08019FDC u16(0x2C), 08019FB4::08019FE0 u8(0x16), 08019FB4::08019FFC u8(0x16), 
	08019F9E?::08019F9E u32(0x54), 0801DB84::0801DB86 u8(0x16), 0801DB84::0801DBB8 u16(0x28), 
	0801DB84::0801DBBC u8(0x16), 0801DB84::0801DBBE u8(0x17), 08016F56::08017038 u8(0x16), 
	0800F318?::0800F318 u32(0x58), 08016F56::0801705E u8(0x17), 0800F2C6::0800F2D0 u32(0x58), 
	0801DBD4::0801DBF0 u16(0x28), 0801DBD4::0801DBF4 u8(0x16), 0801DBD4::0801DBF6 u8(0x17), 
	08010DD0::08010DD2 u16(0x28), 08016F56::08017068 u8(0x16), 08016F56::08017086 u32(0x58), 
	08016F56::08017090 u32(0x08), 0800372A?::0800372A u8(0x02), 0800FDC0::0800FDD0 u32(0x58), 
	08003E18::08003E2E u8(0x00), 08003E18::08003E60 u32(0x90+0x24), 030061E8::030061EE u8(0x00), 
	030061E8::030061F6 u8(0x02), 03006388?::03006394 u16(0x34+0x02), 03006388?::030063C4 u8(0x90+0x16), 
	03006388?::030063B8 u8(0x90+0x13), 03006388?::030063C0 u8(0x90+0x13), 03006388?::030063CE u16(0x90+0x0C), 
	03006388?::030063D2 u16(0x34+0x06), 03006388?::030063DE u16(0x90+0x0A), 03006388?::030063E2 u16(0x34+0x0A), 
	03006388?::030063EC u8(0x90+0x0E), 03006388?::030063EE u8(0x90+0x0F), 03006388?::030063F0 u8(0x90+0x03), 
	030061E8::0300621A u8(0x90+0x03), 030061E8::03006226 u8(0x90+0x13), 030061E8::03006234 u8(0x90+0x13), 
	030061E8::03006240 u32(0x90+0x20), 030061E8::03006246 u32(0x90+0x1C), 030061E8::0300624A u32(0x90+0x18), 
	030061E8::030062CC u8(0x90+0x03), 030061E8::030062FC u8(0x90+0x03), 030061E8::030062FE u32(0x90+0x28), 
	080F367C::080F367E u32(0x58), 08002DD8?::08002DD8 u8(0x02), 08002DD8?::08002DE0 u8(0x90+0x15), 
	08002DD8?::08002DE6 u8(0x90+0x15), 0801A9B8::0801A9BE u32(0x54), 0801AF44::0801AF4A u32(0x54), 
	0801AF44::0801AF4C u32(0x58), 0801AF44::0801AF56 u8(0x09), 0801A42E::0801A430 u32(0x54), 
	0801A4A6::0801A4A8 u32(0x54), 0801A45C::0801A45E u32(0x54), 0801A506::0801A508 u32(0x54), 
	0800E2D8::0800E2DA u16(0x24), 0800E2D8::0800E2E2 u16(0x24), 0801BA12::0801BA70 u16(0x24), 
	0801A200::0801A20A u32(0x54), 0801A200::0801A250 u8(0x16), 0801BADE::0801BAE2 u8(0x09), 
	0801A166?::0801A166 u32(0x54), 0801A180?::0801A180 u32(0x54), 0801032C?::0801032C u32(0x58), 
	0801AF44::0801AFE6 u8(0x18), 0800FFFE?::0800FFFE u32(0x58), 0801AF44::0801B0BE u8(0x0D), 
	0801AF44::0801B0EA u8(0x1F), 0800E730::0800E73A u32(0x54), 08010162::08010164 u32(0x54), 
	0801A15C?::0801A15C u32(0x54), 08014326::08014328 u16(0x28), 08014498::080144A2 u32(0x58), 
	0802E1D8::0802E1DA u8(0x16), 08002EE8?::08002EE8 u8(0x02), 08002EE8?::08002EF2 u16(0x90+0x06), 
	0801A176?::0801A176 u32(0x54), 080143E4::080143E6 u32(0x58), 08013774::08013776 u8(0x16), 
	08016860::08016870 u8(0x09), 08016934::0801693C u8(0x00), 08016934::08016942 u8(0x00), 
	08016934::0801696A u8(0x16), 08016934::08016970 u8(0x16), 08016CA4::08016CB4 u8(0x16), 
	0801AF44::0801B180 u8(0x09), 0801B9E6::0801B9E8 u32(0x58), 0801B9E6::0801B9F2 u8(0x09), 
	08016380::08016382 u32(0x58), 08016396::0801639A u8(0x0A), 080163B4::080163B6 u8(0x0B), 
	080163B4::080163C2 u8(0x16), 080163B4::080163DE u8(0x0B), 08016410?::08016410 u8(0x00), 
	08016410?::08016416 u8(0x00), 080F367C::080F36B0 u32(0x58), 0801A018::0801A01A u32(0x54), 
	0801A018::0801A042 u32(0x54), 080163B4::080163FE u16(0x20), 080163B4::08016402 u16(0x22), 
	08002C7A?::08002C7E u8(0x02), 08002C7A?::08002C88 u8(0x90+0x11), 08002C7A?::08002C90 u8(0x90+0x11), 
	080163B4::0801640C u8(0x0A), 03006028::0300602A u8(0x02), 03006028::03006032 u8(0x90+0x03), 
	03006028::03006038 u8(0x90+0x03), 03006028::03006052 u32(0x90+0x1C), 03006028::03006056 u32(0x90+0x18), 
	03006028::03006062 u16(0x90+0x08), 03006028::0300606E u32(0x90+0x24), 03006028::03006090 u16(0x90+0x08), 
	03006028::03006096 u32(0x90+0x24), 03006028::0300609E u32(0x90+0x24), 03006028::030060A8 u16(0x90+0x08), 
	03006028::030060BE u8(0x90+0x15), 03006028::030060CA u8(0x90+0x03), 03006108::0300610A u32(0x90+0x1C), 
	03006108::03006110 u32(0x90+0x18), 03006108::03006114 u8(0x90+0x04), 03006108::03006116 u8(0x90+0x05), 
	03006108::0300611E u16(0x90+0x06), 03006028::030060D6 u8(0x90+0x15), 03006028::030060E0 u8(0x90+0x15), 
	03006440::03006442 u8(0x90+0x03), 03006452?::03006460 u32(0x90+0x30), 03006452?::03006466 u32(0x90+0x20), 
	03006452?::0300646C u32(0x90+0x1C), 03006452?::03006470 u32(0x90+0x18), 03006452?::03006478 u32(0x90+0x28), 
	03006452?::0300647C u32(0x90+0x2C), 03006452?::03006482 u32(0x90+0x28), 03006452?::03006484 u8(0x90+0x16), 
	03006452?::03006498 u8(0x90+0x16), 03006452?::0300649A u8(0x90+0x03), 03006452?::030064BC u32(0x90+0x28), 
	03006452?::030064C0 u32(0x90+0x28), 03006452?::030064C6 u32(0x90+0x10), 03006452?::030064C8 u8(0x90+0x16), 
	0300658A?::030065A6 u8(0x90+0x13), 0300658A?::030065C4 u8(0x90+0x13), 03006452?::030064DE u16(0x90+0x0C), 
	03006452?::03006500 u8(0x90+0x0F), 03006452?::03006514 u16(0x90+0x14), 03006452?::03006528 u16(0x90+0x08), 
	03006452?::0300653E u16(0x90+0x0A), 03006452?::03006564 u8(0x90+0x03), 03006452?::03006500 u8(0x90+0x0E), 
	03006452?::03006584 u32(0x90+0x28), 0801641A::0801641C u16(0x20), 0801641A::08016420 u16(0x20), 
	0801641A::08016426 u16(0x20), 0801641A::08016428 u16(0x22), 0801641A::0801642C u16(0x22), 
	08002EF6?::08002F0C u8(0x02), 08002EF6?::08002F14 u8(0x90+0x11), 08002EF6?::08002F18 u8(0x90+0x11), 
	0801641A::08016442 u8(0x00), 0801641A::08016448 u8(0x00), 08002CCE?::08002CCE u8(0x02), 
	08002CCE?::08002CD6 u8(0x90+0x11), 08002CCE?::08002CDC u8(0x90+0x11), 08002F2C?::08002F2C u8(0x02), 
	08002F2C?::08002F34 u8(0x90+0x11), 08002F2C?::08002F3A u8(0x90+0x11), 0801641A::0801645C u16(0x0A), 
	08016460::08016478 u8(0x16), 08016460::08016482 u16(0x28), 0801DC7C::0801DC98 u16(0x28), 
	0801DC7C::0801DCB2 u16(0x24), 08016460::08016498 u8(0x09), 08016460::0801649C u16(0x0A), 
	0801C168::0801C17A u16(0x24), 0801C168::0801C1A0 u32(0x54), 0800362C::08003634 u16(0x34+0x02), 
	0800362C::0800364A u16(0x34+0x06), 0800362C::08003656 u16(0x34+0x0A), 08017BC0::08017BC2 u32(0x58), 
	0800ED90::0800ED94 u16(0x28), 0800EDC6?::0800EDC6 u16(0x2A), 0800EDC6?::0800EDCC u8(0x1A), 
	0800A998::0800A9B8 u16(0x28), 080103BC::080103D2 u16(0x28), 0300754C::03007550 u32(0x54), 
	0801A80C?::0801A80C u32(0x54), 0801A186::0801A194 u32(0x54), 0801A36A::0801A36C u32(0x54), 
	0801A36A::0801A37A u32(0x58), 08010230::0801023E u32(0x58), 08010230::08010240 u16(0x24), 
	0802CFF8::0802CFFA u32(0x54), 0802CEF4::0802CEF6 u32(0x54), 0802CEF4::0802CF32 u8(0x16), 
	0801A6B4::0801A6B6 u32(0x54), 0801A720::0801A722 u32(0x54), 08013AE4::08013AE8 u32(0x54), 
	0800EB26::0800EB28 u32(0x54), 0801A9B8::0801AA0E u16(0x28), 0801A554::0801A556 u32(0x54), 
	0801A2CC::0801A2CE u32(0x54), 0801A308::0801A30A u8(0x16), 0801A308::0801A316 u32(0x54), 
	0800E3DE::0800E3E0 u32(0x54), 0800E3DE::0800E3E2 u8(0x12), 0800E3DE::0800E3E4 u8(0x13), 
	0800E3DE::0800E3FC u32(0x54), 0802CE10?::0802CE12 u8(0x16), 0800E3DE::0800E418 u32(0x54), 
	0801A420?::0801A420 u32(0x54), 08010198::0801019A u32(0x54), 0801A648::0801A650 u32(0x54), 
	0800EB9E::0800EBA6 u32(0x54), 0801A5EE::0801A5FA u32(0x54), 08017888::080178AE u8(0x09), 
	08017888::080178B2 u16(0x0A), 0801BBAC::0801BBB4 u8(0x00), 0801BBAC::0801BBCE u32(0x54), 
	0801BBAC::0801BBD4 u8(0x18), 0801BBAC::0801BBDA u8(0x10), 0801BBAC::0801BBDC u8(0x11), 
	0801BBAC::0801BBEA u8(0x10), 0801BBAC::0801BBEC u8(0x11), 080026C4::080026C6 u8(0x02), 
	03006792::03006794 u8(0x90+0x01), 03006792::03006798 u8(0x90+0x01), 03006792::030067F8 u32(0x90+0x20), 
	03006792::030067FE u32(0x90+0x1C), 03006792::03006802 u32(0x90+0x18), 03006792::0300680E u8(0x90+0x05), 
	080FCD04::080FCD06 u32(0x58), 0800FE36?::0800FE36 u32(0x58), 08011698::0801169A u8(0x09), 
	08011698::0801169E u16(0x0A), 08011698::080116A0 u32(0x58), 0801011A::0801011C u32(0x58), 
	080E29A2?::080E29A2 u32(0x58), 080FCE5C::080FCEDA u16(0x26), 080FCE5C::080FCEDE u16(0x24), 
	03006792::0300679E u8(0x90+0x03), 03006792::030067C0 u32(0x90+0x1C), 03006792::030067EE u8(0x90+0x01), 
	080FD3BC::080FD3C4 u8(0x16), 080FDFE4::080FE010 u8(0x12), 080FDFE4::080FE012 u8(0x13), 
	080FDFE4::080FE046 u8(0x12), 080FDFE4::080FE048 u8(0x13), 080FDFE4::080FE050 u8(0x16), 
	080FD3BC::080FD3DA u8(0x14), 080FD3BC::080FD3DC u8(0x15), 0801BB1C::0801BB36 u8(0x00), 
	0801BB1C::0801BB3C u8(0x00), 0801A152?::0801A152 u32(0x54), 080FD3BC::080FD3EA u8(0x10), 
	03006792::030067CE u32(0x90+0x1C), 03006792::030067D0 u32(0x90+0x18), 03006792::030067DA u32(0x90+0x20), 
	03006792::030067DE u8(0x90+0x01), 03006792::030067E2 u8(0x90+0x02), 080FD414::080FD420 u8(0x10), 
	080FD414::080FD422 u8(0x14), 080FD414::080FD424 u8(0x15), 080FD414::080FD426 u8(0x12), 
	080FD414::080FD428 u8(0x13), 0800E29C::0800E29E u8(0x12), 0800E29C::0800E2A0 u8(0x13), 
	0800E29C::0800E2A6 u32(0x34), 0800E29C::0800E2A8 u32(0x38), 0801A04C::0801A04E u32(0x54), 
	0801A04C::0801A054 u8(0x12), 0801A04C::0801A058 u8(0x13), 0801A04C::0801A05C u8(0x16), 
	080FD440::080FD452 u8(0x10), 08011714::08011718 u8(0x10), 0801171C::0801171E u32(0x58), 
	0801171C::08011756 u8(0x09), 0800FE12?::0800FE12 u32(0x58), 080FD2BA::080FD2DE u32(0x58), 
	080FD188::080FD1B0 u8(0x16), 080FD4A4::080FD4AC u8(0x16), 080FE098::080FE09C u8(0x16), 
	080FD4A4::080FD4C4 u8(0x14), 080FD4A4::080FD4C6 u8(0x15), 080FD4A4::080FD4D4 u8(0x10), 
	080FD504::080FD510 u8(0x10), 080FD504::080FD512 u8(0x14), 080FD504::080FD514 u8(0x15), 
	080FD504::080FD516 u8(0x12), 080FD504::080FD518 u8(0x13), 080FD54E::080FD55C u8(0x10), 
	0800E2CA?::0800E2CA u8(0x16), 0800E2CA?::0800E2CC u8(0x17), 080FD54E::080FD576 u8(0x12), 
	080FD54E::080FD57A u8(0x13), 080FD54E::080FD57E u16(0x16), 080FD592::080FD5A0 u8(0x10), 
	08003400::08003412 u32(0xC8+0x00), 08003400::08003418 u32(0xC8+0x04), 080BA6A0::080BA6B4 u16(0x12), 
	080BA6A0::080BA6B8 u16(0x16), 080BA6A0::080BA6C4 u32(0x64+0x00), 0800E9DC::0800E9DE u32(0x58), 
	0800E9DC::0800E9F4 u32(0x54), 080BA568::080BA588 u16(0x28), 080BA616::080BA640 u8(0x00), 
	08002EDC?::08002EDC u8(0x02), 08002EDC?::08002EE4 u16(0x90+0x06), 08002DC8?::08002DC8 u8(0x02), 
	08002DC8?::08002DD0 u8(0x90+0x15), 08002CE0?::08002CE0 u8(0x02), 08002CE0?::08002CE8 u8(0x90+0x11), 
	08002F7E?::08002F7E u8(0x02), 08002F7E?::08002F86 u8(0x90+0x16), 080BA616::080BA674 u32(0x64+0x00), 
	080031AC::080031BA u32(0xC8+0x04), 080FD592::080FD5D2 u8(0x12), 080FD592::080FD5D6 u8(0x13), 
	08003400::0800341A u32(0xC8+0x00), 080C6BDA::080C6BF2 u16(0x16), 080FD592::080FD5EC u8(0x12), 
	080FD592::080FD5F0 u8(0x13), 08003458::08003482 u32(0xC8+0x00), 080FE2C4::080FE2CC u32(0x64+0x00), 
	0800FFEE?::0800FFEE u32(0x58), 08012EA8::08012EAA u32(0x58), 080FD1C4::080FD1C8 u32(0x60), 
	080FD1C4::080FD1FC u8(0x16), 08003458::0800347C u32(0xC8+0x00), 08003458::0800347E u32(0xC8+0x04), 
	080FD660::080FD668 u8(0x16), 080FD660::080FD680 u8(0x14), 080FD660::080FD682 u8(0x15), 
	080FD660::080FD690 u8(0x10), 080FD6C0::080FD6CC u8(0x10), 080FD6C0::080FD6CE u8(0x14), 
	080FD6C0::080FD6D0 u8(0x15), 080FD6C0::080FD6D2 u8(0x12), 080FD6C0::080FD6D4 u8(0x13), 
	080D3464::080D3478 u16(0x16), 080D3464::080D347C u16(0x12), 080E8DC8::080E8DDA u16(0x16), 
	080E8DF0::080E8DFC u16(0x36), 080E8DF0::080E8E02 u16(0x3A), 080E8DF0::080E8E06 u16(0x3E), 
	080FD70A::080FD738 u32(0x60+0x00), 080E8D0E::080E8D26 u8(0x00), 08002D8C?::08002D8C u8(0x02), 
	08002D8C?::08002D94 u8(0x90+0x04), 08002F3E?::08002F3E u8(0x02), 08002F3E?::08002F46 u8(0x90+0x11), 
	080E8D0E::080E8D5A u8(0x17), 080E8D90::080E8D94 u8(0x09), 080D340A::080D3436 u8(0x60+0x00), 
	080E1C00::080E1C12 u8(0x16), 080FD76C::080FD78E u8(0x12), 080FD76C::080FD790 u8(0x13), 
	080FD76C::080FD79A u8(0x12), 080FD76C::080FD79C u8(0x13), 080FD76C::080FD79E u8(0x14), 
	080FD76C::080FD7A0 u8(0x15), 080FE2D0::080FE2DA u8(0x10), 080E473A::080E4750 u8(0x16), 
	080FE1A6::080FE1AA u8(0x12), 080FE1A6::080FE1B4 u8(0x12), 080FE1A6::080FE1C0 u32(0x40), 
	080FE1A6::080FE1C2 u8(0x12), 080FE1A6::080FE1DC u8(0x13), 080FE1A6::080FE1FA u32(0x44), 
	080D647A::080D648E u32(0x09+0x00), 080D647A::080D6494 u16(0x16), 080FD76C::080FD7C2 u32(0x44), 
	080FD76C::080FD7C4 u32(0x38), 080FD76C::080FD7C8 u32(0x38), 080FD76C::080FD7CA u32(0x40), 
	080FD76C::080FD7CC u32(0x34), 080FD76C::080FD7D0 u32(0x34), 080FD76C::080FD7D2 u8(0x12), 
	0800E2AC::0800E2AE u32(0x34), 0800E2AC::0800E2B0 u32(0x38), 0800E2AC::0800E2B4 u32(0x3C), 
	0800E2AC::0800E2BA u8(0x12), 0800E2AC::0800E2BC u8(0x13), 080FD76C::080FD7DC u8(0x12), 
	080D64AA::080D64B0 u32(0x40), 080D64AA::080D64BE u8(0x12), 080D64AA::080D64C6 u32(0x44), 
	080D64AA::080D64D4 u8(0x13), 080D64DC::080D64E2 u32(0x09+0x00), 080FD7FA::080FD828 u8(0x12), 
	080FD7FA::080FD82C u8(0x13), 080FD7FA::080FD830 u16(0x16), 080FD844::080FD852 u8(0x10), 
	080FD844::080FD884 u8(0x12), 080FD844::080FD888 u8(0x13), 080FD844::080FD89E u8(0x12), 
	080FD844::080FD8A2 u8(0x13), 080FD8D6::080FD8E4 u8(0x10), 080FD8D6::080FD8EC u8(0x14), 
	080FD8D6::080FD8EE u8(0x15), 080FD8D6::080FD8F0 u8(0x12), 080FD8D6::080FD8F2 u8(0x13), 
	08010548::0801054C u32(0x58), 0801BA12::0801BA22 u16(0x24), 0801BA12::0801BA44 u16(0x28), 
	08002DB0?::08002DB4 u8(0x02), 08002DB0?::08002DBC u8(0x90+0x15), 08002DB0?::08002DC4 u8(0x90+0x15), 
	080FD210::080FD238 u8(0x16), 080FD950::080FD972 u8(0x12), 080FD950::080FD974 u8(0x13), 
	080FD950::080FD976 u8(0x14), 080FD950::080FD978 u8(0x15), 080FD950::080FD986 u8(0x10), 
	080FD9AC::080FD9B8 u8(0x10), 080FD9AC::080FD9BE u8(0x12), 080FD9AC::080FD9C0 u8(0x13), 
	080FD9E4::080FD9F2 u8(0x10), 080FD9E4::080FDA0C u8(0x12), 080FD9E4::080FDA10 u8(0x13), 
	080FD9E4::080FDA14 u16(0x16), 080FDA28::080FDA36 u8(0x10), 080FDA28::080FDA68 u8(0x12), 
	080FDA28::080FDA6C u8(0x13), 080FDA28::080FDA82 u8(0x12), 080FDA28::080FDA86 u8(0x13), 
	080FDABA::080FDAC8 u8(0x10), 080FDABA::080FDAD0 u8(0x12), 080FDABA::080FDAD2 u8(0x13), 
	080FDABA::080FDAD8 u8(0x14), 080FDABA::080FDADA u8(0x15), 080FDABA::080FDADC u8(0x12), 
	080FDABA::080FDADE u8(0x13), 080FDB38::080FDB40 u8(0x16), 080FE106::080FE10C u8(0x16), 
	080FE106::080FE110 u8(0x16), 080FDB38::080FDB56 u8(0x14), 080FDB38::080FDB58 u8(0x15), 
	080FDB38::080FDB66 u8(0x10), 080FDB94::080FDBA0 u8(0x10), 080FDB94::080FDBA2 u8(0x14), 
	080FDB94::080FDBA4 u8(0x15), 080FDB94::080FDBA6 u8(0x12), 080FDB94::080FDBA8 u8(0x13), 
	080FDBDE::080FDBEC u8(0x10), 080FDBDE::080FDC0A u8(0x12), 080FDBDE::080FDC0E u8(0x13), 
	080FDBDE::080FDC12 u16(0x16), 080FDC26::080FDC34 u8(0x10), 080FDC26::080FDC6E u8(0x12), 
	080FDC26::080FDC72 u8(0x13), 080FDC26::080FDC8C u8(0x12), 080FDC26::080FDC90 u8(0x13), 
	080FDC26::080FDCB4 u8(0x12), 080FDC26::080FDCB8 u8(0x13), 08003458::08003480 u32(0xC8+0x04), 
	08017AB4::08017AB8 u16(0x28), 08017AB4::08017B64 u8(0x18), 08017AB4::08017B6A u16(0x36), 
	08017AB4::08017B6C u16(0x30), 08017AB4::08017B6E u16(0x3E), 08017AB4::08017B70 u16(0x32), 
	08017AB4::08017B74 u8(0x19), 08017AB4::08017B78 u8(0x18), 08017AB4::08017B7A u32(0x54), 
	08017AB4::08017B88 u8(0x19), 08017AB4::08017BAA u16(0x30), 08017AB4::08017BAC u16(0x36), 
	08017AB4::08017BAE u16(0x32), 08017AB4::08017BB0 u16(0x3E), 0801A16C?::0801A16C u32(0x54), 
	08017AB4::08017B86 u8(0x19), 08017AB4::08017B90 u8(0x19), 08017AB4::08017B92 u16(0x30), 
	08017AB4::08017B96 u32(0x38), 08017AB4::08017B98 u16(0x32), 03006028::030060B8 u16(0x90+0x08), 
	03006028::030060BC u32(0x90+0x24), 0801BA92::0801BA96 u8(0x09), 0801BABE::0801BAC2 u8(0x09), 
	08016934::08016954 u32(0x54), 08016934::0801695C u8(0x00), 08016934::08016962 u8(0x00), 
	080174FE::08017500 u8(0x0B), 0801A082::0801A084 u32(0x54), 0801A082::0801A088 u16(0x2C), 
	0801A082::0801A08C u8(0x16), 0801A082::0801A096 u8(0x16), 0801A07C?::0801A07C u32(0x54), 
	080FCFCA::080FCFEA u32(0x2C), 080FCFCA::080FCFF2 u32(0x54), 080FCFCA::080FD002 u32(0x58), 
	080FCFCA::080FD00E u32(0x64), 080FCFCA::080FD016 u32(0x64), 0801A284::0801A294 u32(0x54), 
	0801A29A::0801A2AA u32(0x54), 0801A2B0::0801A2C0 u32(0x54), 0801A2B0::0801A2C4 u32(0x58), 
	0801A2B0::0801A2C8 u16(0x3E), 080101C4::080101C6 u32(0x54), 0801031C?::0801031C u32(0x58), 
	080174FE::0801753C u8(0x14), 080174FE::0801753E u8(0x12), 080174FE::08017540 u8(0x15), 
	080174FE::08017542 u8(0x13), 080174FE::08017552 u32(0x3C), 080174FE::08017556 u8(0x10), 
	080174FE::0801755A u8(0x11), 08011450::08011452 u32(0x58), 08011450::08011462 u32(0x50), 
	080174FE::0801756A u32(0x4C), 080174FE::0801756C u32(0x58), 080174FE::08017570 u8(0x16), 
	080174FE::0801757C u16(0x20), 080174FE::08017580 u8(0x0B), 080174FE::08017582 u16(0x20), 
	080174FE::08017586 u16(0x20), 080174FE::08017598 u8(0x10), 080174FE::0801759C u8(0x09), 
	080174FE::080175A0 u16(0x0A), 08003400::08003414 u32(0xC8+0x04), 08003400::08003416 u32(0xC8+0x04), 
	080FD11C::080FD120 u8(0x16), 080FD11C::080FD134 u8(0x16), 080FCEF2::080FCF8E u16(0x26), 
	080FCEF2::080FCF92 u16(0x24), 0800A7A6::0800A7B8 u16(0x28), 08003458::0800345C u8(0x00), 
	08003458::0800345E u8(0x02), 08003458::0800346A u8(0x03), 08002D52::08002D54 u8(0x02), 
	08002D5E::08002D60 u8(0x90+0x11), 0800A86E::0800A87E u32(0x58), 

Accesses: Battle*/

/*
	03006028 03006108 030061E8 03006388? 03006440 
	03006452? 0300658A? 03006730 03006792 0300754C 
	080026A4 <applyAnimationChange> 080026C4 080026E4 08002722? 08002C7A? 
	08002CCE? 08002CE0? 08002D52 08002D5E 08002D80? 
	08002D8C? 08002DA4? 08002DB0? 08002DC8? 08002DD8? 
	08002E3C? 08002ED0? 08002EDC? 08002EE8? 08002EF6? 
	08002F2C? 08002F3E? 08002F5A? 08002F7E? 080031AC 
	08003278 08003400 08003458 08003490 0800362C 
	0800372A? 08003E18 080076A0 08007778 080077D2 
	0800A0FE? 0800A11C? 0800A7A6 0800A998 0800E29C 
	0800E2AC 0800E2C0? 0800E2CA? 0800E2D8 0800E3DE 
	0800E456? 0800E468 0800E498 0800E548 0800E5AC 
	0800E730 0800E9DC 0800EB26 0800EB9E 0800EBD4 
	0800ED90 0800EDC6? 0800F2C6 0800F318? 0800F334? 
	0800F420 0800FDC0 0800FE12? 0800FE36? 0800FFEE? 
	0800FFFE? 0801011A 08010162 08010198 080101C4 
	08010230 0801031C? 0801032C? 080103BC 08010548 
	08010DD0 08011020 08011450 08011698 08011714 
	0801171C 08012EA8 08013774 08013AE4 08014326 
	080143E4 0801445C? 08014490? 08014498 08016380 
	08016396 080163B4 08016410? 0801641A 08016460 
	08016860 08016934 08016C4E 08016CA4 08016F56 
	080170C4 080170E4 08017122 080174FE 080175B8 
	08017888 080178B6 080178D4 08017992 08017A18? 
	08017A38 08017AB4 08017BC0 080198AE? 08019F9E? 
	08019FB4 0801A018 0801A04C 0801A074? 0801A07C? 
	0801A082 0801A152? 0801A15C? 0801A166? 0801A16C? 
	0801A176? 0801A180? 0801A186 0801A200 0801A284 
	0801A29A 0801A2B0 0801A2CC 0801A308 0801A36A 
	0801A420? 0801A42E 0801A45C 0801A4A6 0801A506 
	0801A554 0801A5E2? 0801A5EE 0801A648 0801A6B4 
	0801A720 0801A7EC? 0801A80C? 0801A9B8 0801AEB0 
	0801AF44 0801B9E6 0801BA12 0801BA92 0801BABE 
	0801BADE 0801BB1C 0801BB78 0801BBAC 0801C168 
	0801DB84 0801DBD4 0801DC7C 0802CD80 0802CE10? 
	0802CEF4 0802CFF8 0802D358 0802E1D8 080AC0FC 
	080B9A5C 080BA568 080BA616 080BA6A0 080C6BDA 
	080D340A 080D3464 080D647A 080D64AA 080D64DC 
	080E1C00 080E28A6 080E29A2? 080E2A44 080E2D68? 
	080E473A 080E87C6 080E8D0E 080E8D90 080E8DC8 
	080E8DF0 080F3658 080F367C 080FCD04 080FCE5C 
	080FCEF2 080FCFB2 080FCFCA 080FD11C 080FD188 
	080FD1C4 080FD210 080FD2BA 080FD3BC 080FD414 
	080FD440 080FD4A4 080FD504 080FD54E 080FD592 
	080FD660 080FD6C0 080FD70A 080FD76C 080FD7FA 
	080FD844 080FD8D6 080FD950 080FD9AC 080FD9E4 
	080FDA28 080FDABA 080FDB38 080FDB94 080FDBDE 
	080FDC26 080FDFE4 080FE098 080FE106 080FE1A6 
	080FE2C4 080FE2D0 
Functions: Battle*/
#pragma endregion Accesses

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