#include "TextGenerator.h"

/**
 * This should be called everytime pCurrScript changes. It updates global variables pActiveScript_2.
 * if pActiveScript_2 == 0, there is no active script at the moment. This is toggled upon the 
 * [side effects]
 * pCurrScript
*/
void tg_handleScriptEvent();

/**
 * A hacky... hack, for now, that tries to only modify the megaman that talks in none gamebreaking scenarios.
 * This should only be called when pCurrScript changes, and when it's only at the start of the script.
 * such as the Levibus.
 * [params]
 * r1_pScript
 * [side effects]
 * pCurrScript
*/
void tg_handleMegamanScript(void* pScript);

/**
 * Determines if given r1_pScript is at its start.
 * This is done by checking by checking if it's currently at
 * the command msgOpen (0xE8 0x00).
 * [params]
 * r1_pScript
 * [return]
 * r0_atScriptStart (false: 0, true: 1)
*/
bool tg_atScriptStart(char* pScript){
	return pScript[0] == 0xE8 && pScript[1] == 0x00;
}

/**
 * Converts a r1_pText to gametext. Generates gametext at specified r2_pGameText
 * [params]
 * r2_pText, r3_pGameText
 * [side effects]
 * [return]
*/
char* tg_toGameText(char* pText, char* pGameText){
	int i = 0;
	while(pText[i] != '\0'){
		char gameChar = tg_toGameChar(pText[i]);
		pGameText[i] = gameChar;
		i++;
	}
	return pGameText;
}

/**
 * 
 * [params]
 * r1_asciiChar
 * [return]
 * r0_gameChar
*/
char tg_toGameChar(char asciiChar){
	return pAsciiGameText[(unsigned int)asciiChar];
}