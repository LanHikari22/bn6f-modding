#include <TextGenerator.h>
#include <inttypes.h>

void memcpy(void *dest, void *src, int size){
    for(int i = 0; i<size; i++){
        ((uint8_t*)dest)[i] = ((uint8_t*)src)[i];
    }
}

int strlen(char* s){
    char c = s[0];
    int i;
    for (i = 0; ;i++){
        if(c == '\0')
            break;
        c = s[i];
    }
    return i;
}

/**
 * Prints a message using the chatbox!
 */
void tg_chatPrint(char* str, uint8_t mugshot){	

	tg_createScriptList((uint16_t*)0x02050040, str, mugshot);
	int register r0 asm("r0") = 0x02050040;
	int register r1 asm("r1") = 0x00; // halfword offset to start from in script
	int register r5 asm("r5") = sChief->chatbox;
	callThumb(chatbox_run_script);
}


void tg_createScriptList(uint16_t *scriptList, char* str, uint8_t mugshot){
	char gameText[255];
    tg_toGameText(str, gameText);
    scriptList[0] = 0x0002;
	uint8_t entryCtrl[5] = {0xF5, 0x00, mugshot, 0xE8};
	uint8_t closureCtrl[4] = {0xE7, 0x00, 0xE6, 0xF0};
	uint8_t *script = scriptList + 1;
	memcpy(script, entryCtrl, 5);
    memcpy(script + 5, gameText, strlen(str));
	memcpy(script + 5 + strlen(str), closureCtrl, 4);
}


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
void tg_toGameText(char* pText, char* pGameText){
	int i = 0;
	while(pText[i] != '\0'){
		char gameChar = tg_toGameChar(pText[i]);
		pGameText[i] = gameChar;
		i++;
	}
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