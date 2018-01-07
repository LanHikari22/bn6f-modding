#include <TextGenerator.h>
#include <scriptCommands.h>
#include <str.h>

/**
 * Prints a message using the chatbox!
 */
void tg_chatPrint(const char* str, uint8_t mugshot){	
	// setup script
	sc_script *script = tg_setupScriptList((uint16_t*)0x02050040);
	sc_mugshot(script, 0x00, mugshot); // F5
 	sc_msgbox (script, 0x00, 0, 0); // E8
	sc_text(script, str);
	sc_buttonhalt(script, 0x00); // E7
	sc_end(script); // E6

	// invoke engine
 	tg_invoke_script_engine((uint16_t*)0x02050040);
}

void tg_invoke_script_engine(uint16_t *scriptList){
	chatbox_run_script(scriptList, 0x00 /* halfword offset to start from in script */);
}

void tg_startBattle(u16 index){
	// setup script
	sc_script *script = tg_setupScriptList((uint16_t*)0x02050040);
	sc_special(script, 0x03, index); // FB
	sc_end(script); // E6

	// invoke engine
 	tg_invoke_script_engine((uint16_t*)0x02050040);
}

void tg_createScriptList(uint16_t *scriptList, char* str, uint8_t mugshot){

}

sc_script* tg_setupScriptList(uint16_t *scriptList){
	scriptList[0] = 0x0008;
	sc_script *pScript = (sc_script*)(scriptList + 2);
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
void tg_toGameText(const char* pText, char* pGameText){
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