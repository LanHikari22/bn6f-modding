/**
 * mmbn6_globalvariables.asm
 * Author: Lan
 * Date created: 7/22/2017
 * Description
 * This is a headerfile to keep track of all global variables used by different scripts.
 * Include this in all scripts using global variables.
 * All variables are defined with this format: varname_FileID except for the allocN special variables.
*/
#ifndef MMBN6_GLOBALVARIABLES_ASM
#define MMBN6_GLOBALVARIABLES_ASM
.thumb

/* allocN is the memory address allocatable from by File with id [N] */
.equ alloc0,					 	0x02022000

/** KeyPressExecution.asm												[0]**/
/* Used to execute trigger code upon key press */
.equ isPressed_0,                	alloc0 + 0x00
/* A trigger flag to activate sub_continous */
.equ continuous_on_0,            	alloc0 + 0x01
/* Flag used to know whether the buttons have been pressed for 
the first time */ 
.equ cont_isPressed_0,           	alloc0 + 0x02
/* Every press counts for 1 count. 2 counts activates the function */
.equ cont_activationCounter_0,   	alloc0 + 0x03
/* --- */
.equ alloc1,					 	alloc0 + 0x04


/** CheatcodeACE_api.asm												[1]**/
/* Buffer used to store cheatcode sequence. Length = 3 */
.equ buffer_1, 						alloc1 + 0x00
/* This is the most current open space ready to be allocated. */
.equ next_var_1, 					alloc1 + 0x03
/* --- */
.equ alloc2,						alloc1 + 0x04

/** Someotherfile.asm													[2]**/

#endif
