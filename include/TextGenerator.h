#ifndef TEXT_GENERATOR_H
#define TEXT_GENERATOR_H

#include <inttypes.h>
#include <main.h>

// This is an array stored in the ROM specifying a conversion between ASCII and game text
#define pAsciiGameText ((unsigned char*)0x08800000)

void memcpy(void *dest, void *src, int size);

int strlen(char* s);

/**
 * Prints a message using the chatbox!
 * @param str       ASCII string to print in GameText
 * @param mugshot   mugshot to be used in the chatbox
 */
void tg_chatPrint(char* str, uint8_t mugshot);

/**
 * Returns a Script list that links to its script components.
 * currScript = script + (script + 2 * offset)[0]
 * 
 * @param scriptList	This array should contain enough space for 9 + strlen(str)
 * @param str   		ASCII text to convert to game text and print
 * @param mugshot       Mugshot of the chatbox
 */
void tg_createScriptList(uint16_t *scriptList, char* str, uint8_t mugshot);

/**
 * Determines if given r1_pScript is at its start.
 * This is done by checking by checking if it's currently at
 * the command msgOpen (0xE8 0x00).
 * [params]
 * r1_pScript
 * [return]
 * r0_atScriptStart (false: 0, true: 1)
*/
extern bool tg_atScriptStart(char* pScript);

/**
 * Converts a r1_pText to gametext. Generates gametext at specified r2_pGameText
 * [params]
 * r2_pText, r3_pGameText
 * [side effects]
 * [return]
*/
extern void tg_toGameText(char* pText, char* pGameText);

/**
 * 
 * [params]
 * r1_asciiChar
 * [return]
 * r0_gameChar
*/
extern char tg_toGameChar(char asciiChar);

#endif // TEXT_GENERATOR_H