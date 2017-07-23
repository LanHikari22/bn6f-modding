/**
 * mmbn6_globalvariables.asm
 * Author: Lan
 * Date created: 7/22/2017
 * Description
 * This is a headerfile to keep track of all global variables used by different scripts.
 * Include this in all scripts using global variables.
 * All variables are defined with this format: varname_FileID except for the allocN special variables.
 * Do align with 4. A variable must have a byte size of a multiple of 4 bytes.
*/
#ifndef MMBN6_GLOBALVARIABLES_ASM
#define MMBN6_GLOBALVARIABLES_ASM
.thumb

/* allocN is the memory address allocatable from by File with id [N] */
.equ alloc0,					 	0x02022000

/** KeyPressExecution.asm												[0]**/
/* Used to execute trigger code upon key press */
.equ testVar_0,	                	alloc0 + 0x00
/* A trigger flag to activate onActive */
.equ onActive_enabled_0,            alloc0 + 0x04
/* Every press counts for 1 count. 2 counts will toggle
   onActive_enabled_0 */
.equ activationCounter_0,   		alloc0 + 0x08
/* --- */
.equ alloc1,					 	alloc0 + 0x0C


/** CheatcodeACE_api.asm												[1]**/
/* Buffer used to store cheatcode sequence. Length=3H */
.equ buffer_1, 						alloc1 + 0x00
/* Last key that was recognized as pressed. Should be updated a lot.*/
.equ savedKeystate_1,				alloc1 + 0x08
/* --- */
.equ alloc2,						alloc1 + 0x0C

/** Someotherfile.asm													[2]**/

#endif
