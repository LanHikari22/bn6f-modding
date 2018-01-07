
#include <DebugConsole.h>
#include <main.h>
#include <str.h>
#include <scriptCommands.h>
#include <TextGenerator.h>
#include "../Constants/mugshots.h"
#include "../Constants/keys.h"


// Module State
u32 *writeLoc;
dc_ROM *ROM;
u8 RPressState;
Key dc_cheatSeq[4];
dc_seqCtr;


void dc_printEmptyShuko();

dc_Command dc_monitorKeySequence();

void dc_sweep1D(int (*fp)(int a1), int* loggingLoc, int start, int amount);
void dc_sweepPartial2D(int (*fp)(int a1, int a2), int* loggingLoc, int start, int amount, int c, int which);

void dc_printChat(u16 *scriptList, Mugshot mugshot, const char* str);
void dc_call(int Address, u32* RetAddress, int numParams, u32 params[]);


void dc_init(u32 *wl, dc_ROM *rl){
    writeLoc = wl;
    ROM = rl;
    RPressState = 0; // disabled state
    for (int i=0; i<4; i++)
        dc_cheatSeq[i] = 0;
    dc_seqCtr = 0;
}

void dc_onUpdate(dc_ROM *configMem){

    if (sChief->joystick->keyPress == Key_DEFAULT && RPressState >= 2) // Not OFF, or ON
        RPressState = !(RPressState - 2); // Return to previous state of OFF/ON and toggle

    if (configMem->command == dc_cmd_cheatsystem){
        dc_Command cmd = dc_monitorKeySequence();
        switch (cmd){
            case dc_cmd_init:           /* SEL SEL SEL START */
                onStart_executed = 0;
                break;
            case dc_cmd_toggleRPress:   /* SEL SEL SEL R */
                RPressState += 2; // needs to be toggled once the keypress goes cold
                
        }
        if (cmd != dc_cmd_NONE){
            for (int i = 0; i < 4; i++)
                dc_cheatSeq[i] = Key_None;
        }
    }

}

void dc_startConsole(u32 *writeLoc, dc_ROM *configMem){

    // Init command makes onStart() run to instantiate all state
    if (configMem->command == dc_cmd_init)
        onStart_executed = 0;
    
    if (configMem->command == dc_cmd_shuko)
        dc_printChat((u16*)writeLoc, mugshot_shuko, "How can I help you?");
    
    // Format: call <Address> <retAddress> <numParams> <params...>
    // if <retAddress> is 0, it is assumed that the function doesn't return a value in R0.
    if (configMem->command == dc_cmd_call)
        dc_call(configMem->params[0], (u32*)configMem->params[1], configMem->params[2], &configMem->params[3]);
    
    // Format: sweep1D <Address> <loggingAddress> <start> <amount>
    if (configMem->command == dc_cmd_sweep1D){
        int (*fp) (int) = (int (*)(int))configMem->params[3];
        dc_sweep1D(fp, configMem->params[4], configMem->params[5], configMem->params[6]);
    }

    // Format: SweepPartial2D <Address> <loggingAddress> <start> <amount> <c> <which>
    if (configMem->command == dc_cmd_sweepPartial2D){
        int (*fp) (int, int) = (int (*)(int, int))configMem->params[3];
        dc_sweepPartial2D(fp, configMem->params[4], configMem->params[5], configMem->params[6], 
        configMem->params[7], configMem->params[8]);
    }

    // Formar: jumptable <TableAddress> <WordOffset> <retAddress> <numParams> <params...>
    if (configMem->command == dc_cmd_jumptable){
        dc_call(((u32*)configMem->params[0])[configMem->params[1]], configMem->params[2], 
        configMem->params[3], &configMem->params[4]);
    }

    if (configMem->command == dc_cmd_toggleRPress 
        || RPressState == 1) {
        RPress();
    }
}

/**
 * if retAddress is NULL, it is assumed that the function doesn't return a value in R0.
 */
void dc_call(int Address, u32* RetAddress, int numParams, u32 params[]){
    switch(numParams){
        case 0:
        {
            int (*fp) () = (int (*) ())Address;
            if (RetAddress) *RetAddress = fp();
            else fp();
        }
        break;
        case 1:
        {
            int (*fp) (int a1) = (int (*) (int a1))Address;
            if (RetAddress) *RetAddress = fp(params[0]);
            else fp(params[0]);
        }
        break;
        case 2:
        {
            int (*fp) (int a1, int a2) = (int (*) (int a1, int a2))Address;
            if (RetAddress) *RetAddress = fp(params[0], params[1]);
            else fp(params[0], params[1]);
        }
        break;
        case 3:
        {
            int (*fp) (int a1, int a2, int a3) = (int (*) (int a1, int a2, int a3))Address;
            if (RetAddress) *RetAddress = fp(params[0], params[1], params[2]);
            else fp(params[0], params[1], params[2]);
        }
        break;
    }
}

void dc_printChat(u16 *scriptList, Mugshot mugshot, const char* str){
    // setup script
	sc_script *script = tg_setupScriptList(scriptList);
	sc_mugshot(script, 0x00, mugshot); // F5
 	sc_msgbox (script, 0x00, 0, 0); // E8
	sc_text(script, str);
	sc_buttonhalt(script, 0x00); // E7
	sc_end(script); // E6

	// invoke engine
 	tg_invoke_script_engine(scriptList);
}

void dc_printEmptyShuko(){
        dc_printChat((u16*)writeLoc, mugshot_shuko, "                      \n                      \n                      ");
}

void dc_sweep1D(int (*fp)(int a1), int* loggingLoc, int start, int amount){
	
	for (int i = start; i < start + amount; i++){
		loggingLoc[i - start] = fp(i); 
	}
}

void dc_sweepPartial2D(int (*fp)(int a1, int a2), int* loggingLoc, int start, int amount, int c, int which){
	for (int i = start; i < start + amount; i++){
		if (which == 1) loggingLoc[i - start] = fp(c, i);
		if (which == 2) loggingLoc[i - start] = fp(i, c);
	}
}

dc_Command dc_monitorKeySequence(){
    Key curr = sChief->joystick->keyPress;
    curr &= ~(Key_DEFAULT);
    
    if (curr != Key_None){
        dc_cheatSeq[dc_seqCtr] = curr;
        dc_seqCtr = (dc_seqCtr + 1) % 4;
    }

    Key initCheat[4]         = {Key_SELECT, Key_SELECT, Key_SELECT, Key_START};
    Key RPressToggleCheat[4] = {Key_SELECT, Key_SELECT, Key_SELECT, Key_R};

    bool_t initMatch;
    bool_t RPressToggleMatch;
    for (int i = 0; i<4; i++){
        initMatch = true;
        RPressToggleMatch = true;
        for (int j = 0; j<4; j++){
            initMatch &= dc_cheatSeq[(j+i) % 4] == initCheat[j];
            RPressToggleMatch &= dc_cheatSeq[(j+i) % 4] == RPressToggleCheat[j];
            if (!initMatch && !RPressToggleMatch) break;
        }
            if (initMatch) return dc_cmd_init;
            if (RPressToggleMatch) return dc_cmd_toggleRPress;
    }
    return dc_cmd_NONE; 
}