/**
 * mmbn6_globalvariables.asm
 * Author: Lan
 * Date created: 7/22/2017
 * Description
 * This is a headerfile to keep track of all global variables used by different scripts.
 * Include this in all scripts using global variables.
 * All variables are defined with this format: varname_FileID except for the allocN special variables. (Except for constants)
 * Do align with 4. A variable must have a byte size of a multiple of 4 bytes.
 * if a constant that is depended on is defined, a pad must also be defined and added to depended allocations.
 * The pad's length must be a multiple of 4, and must account for all space requirements brought upon by the constant.
*/
#ifndef MMBN6_GLOBALVARIABLES_ASM
#define MMBN6_GLOBALVARIABLES_ASM
.thumb

/* allocN is the memory address allocatable from by File with id [N] */
.equ alloc0,					 	0x02025000

/** KeyPressExecution.asm														[0]**/
/* CONST - tracked event pointers by onEvent and onState.
   The masks determine what to check against.
   onState_activationState is the state that onState executes on */
.equ onEvent_pEvent,				0x02005F48 + 0x08 // sNPC_chaud.convTrigger
.equ onEvent_mask,					0xFF
.equ onState_pEvent,				0x02025000
.equ onState_mask,					0xFFFFFFFF
.equ onState_activationState,		0xCEEEEEED
/* Used to execute trigger code upon key press */
.equ testVar_0,	                	alloc0 + 0x00
/* A trigger flag to activate onActive */
.equ onActive_enabled_0,            alloc0 + 0x04
/* Every press counts for 1 count. 2 counts will toggle onActive_enabled_0 */
.equ activationCounter_0,   		alloc0 + 0x08
/* Determines whether this is the first time this code is executed.
   Its value will change immediately after to (most likely) indicate it did. */
.equ onStartExecuted_0,				alloc0 + 0x0C
/* This flag controls whether onTrigger and onActive can be activated with 
   their desginated simple shorcuts.*/
.equ shortcutsEnabled_0,			alloc0 + 0x10
/* Variables that record the state of a RAM value to determine when it changes.*/
.equ onEvent_watcher_0,				alloc0 + 0x14	
.equ onState_watcher_0,				alloc0 + 0x18
/* --- */
.equ alloc1,					 	alloc0 + 0x1C


/** CheatcodeACE_api.asm														[1]**/
/* CONST - Specifies length of cheatcode sequences. Max = 255*/
.equ cc_cheatLength,				4
/* CONST - Number of cheatcodes present.*/
.equ cc_nCheatcodes,				5
/* Some consts, like cc_cheatLength are depended on dynamically.
In such cases, a pad must be inserted. to other memory allocations.*/
.equ pad0_1, 2*(cc_cheatLength) + 2*(cc_cheatLength) % 4
/* Buffer used to store cheatcode seqence. Length=pad0_1 */
.equ buffer_1, 						alloc1 + 0x00
/* Cursor to keep track of location on buffer_1*/
.equ bufferCsr_1,					alloc1 + 0x00 + pad0_1
/* Last key that was recognized as pressed. Should be updated a lot.*/
.equ savedKeystate_1,				alloc1 + 0x04 + pad0_1
/* cheatcodes -- patterns to be checked against. Length=cc_nCheatcodes*pad0_1 */
.equ cheatcodes_1,					alloc1 + 0x08 + pad0_1
/* --- */
.equ alloc2,						alloc1 + 0x08 + cc_nCheatcodes*pad0_1


/** Someotherfile.asm															[2]**/



#endif
