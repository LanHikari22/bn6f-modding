#include <TextGenerator.h>
#include <scriptCommands.h>

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
	p[0x60>>2] = (u32)str;
	tg_createScriptList((uint16_t*)0x02050040, str, mugshot);
	int register r0 asm("r0") = 0x02050040;
	int register r1 asm("r1") = 0x00; // halfword offset to start from in script
	int register r5 asm("r5") = sChief->chatbox;
	r5 = r5 + 0*(r0 + r1); // a damn hacky way of removing warnings
	((void (*)())(chatbox_run_script+1))();
}

void tg_startBattle(u16 index){
	uint8_t *scriptList = (uint16_t*)0x02050040;
    scriptList[0] = 0x0002;
	uint8_t entryCtrl[5] = {0xF5, 0x00, 0x00, 0xE8};
	uint8_t battleScript[4] = {0xFB, 0x03, (index & 0xFF) >> 8, index & 0xFF};
	uint8_t closureCtrl[4] = {0xE7, 0x00, 0xE6, 0xF0};
	uint8_t *script = scriptList + 1;
	memcpy(script, entryCtrl, 5);
    memcpy(script + 6, battleScript, 4);
	memcpy(script + 6 + 5, closureCtrl, 4);
	int register r0 asm("r0") = 0x02050040;
	int register r1 asm("r1") = 0x00; // halfword offset to start from in script
	int register r5 asm("r5") = sChief->chatbox;
	// r5 = r5 + 0*(r0 + r1); // a damn hacky way of removing warnings
	((void (*)())(chatbox_run_script+1))();
}

void tg_createScriptList(uint16_t *scriptList, char* str, uint8_t mugshot){
	sc_script *script = tg_setupScriptList(scriptList);
	// uint8_t entryCtrl[5] = {0xF5, 0x00, mugshot, 0xE8, 0x00};
	sc_mugshot(script, 0x00, mugshot); // F5
 	sc_msgbox (script, 0x00, NULL, NULL); // E8
	sc_text(script, str);
	// uint8_t closureCtrl[4] = {0xE7, 0x00, 0xE6, 0xF0};
	sc_buttonhalt(script, 0x00); // E7
	sc_end(script); // E6
	sc_jump(script, NULL, NULL); // F0
}

sc_script* tg_setupScriptList(uint16_t *scriptList){
	scriptList[0] = 0x0008;
	sc_script *pScript = scriptList + 2;
	sc_init_script(pScript);
	return pScript;
}

/**
 * Determines if given r1_pScript is at its start.
 * This is done by checking by checking if it's currently at
 * the command msgOpen (0xE8 0x00).
 * [params]
 * r1_pScript
 * [return]
 * r0_atScriptStart (false: 0, true: 1)
*/
bool_t tg_atScriptStart(char* pScript){
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
 * converts ASCII text to gameText
*/
char tg_toGameChar(char asciiChar){
	return tg_ascii2GameText[asciiChar];
}