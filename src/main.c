/**
* This is the project's entrypoint module. The code executes once every frame.
* Here, extra logic will be defined so that other modules may execute under different conditions.
* TODO one linking issue is that the reference to a statically defined function here cannot be obtained.
* That's fine though, considering they would always be called with BL. But you may Fix.
* @file main.c
*/
#include "MMBN6.h"
#include "inttypes.h"
#include "beep.h"
#include "TextGenerator.h"


#define NULL ((void*) 0)
typedef char bool;
#define true 1
#define false 0

NPC *npc;
uint32_t* p;
int onStart_executed;
int savedKeyState;
int counter;


// A random pattern that will only be written into the global during onStart
#define ONSTART_EXECUTED 0xDEADFEED

void callThumb(uint32_t funcAddress);
void callThumb_r(uint32_t funcAddress, int r1, int r2);
void onStart();
void onKeyPress();
void onUpdate();
void RPress();


int main(){
	// handle onStart()
	if(onStart_executed != ONSTART_EXECUTED){
		onStart();
	}
	// handle onUpdate()
	onUpdate();
	
	// handle onKeyPress()
	if(*pKeyState != KeyIDLE){
		onKeyPress();
	}	
	return 0;
}	

/**
* This executes only once, it is used for module initialization.
*/
void onStart(){
	onStart_executed = ONSTART_EXECUTED;
	/* Put initialization logic here ******/
	// p is just somewhere full of zeros i like to debug values in.
	p = (uint32_t*)0x02050000;
	counter = 0;
	npc = (NPC*)0x02050010;
	p[0] = (uint32_t)npc;
	
}




/**
* This is called once per frame. Approximately once every 60th of a second.
*/
void onUpdate(){
	if(counter % 60 == 0)
		sBtlEnemyA->HP++;
	counter++;
}

/**
* Handle logic to be done when a key is pressed. This executes whenever the keystate changes
*/
void onKeyPress(){
	if(*pKeyState == KeyR){
		RPress();
	}
}

/**
* TODO: modify linker so it can create these. Once that is done,
* main will be changed to be called... intecept_someAddress. That is because main is really just an interceptor function.
* The intercepting logic has just been hardwired.
*/
void intercept_08040000();

void RPress(){
	int register r5 asm("r5") = npc;
	int register r0 asm("r0") = 0xF
	int regist
	callThumb(0x080A00F4);
	// callThumb(fpRunChatbox);
}

/**
* Calls an arbitrary function pointer to code in THUMB mode.
* This converts to THUMB to make the call, then converts back to ARM
* once done.
*/
void callThumb(uint32_t funcAddress){
    void (*f)() = (void*)(funcAddress+1); // convert to THUMB mode
    f();
	// bx to next instruction and convert THUMB to ARM mode:
	/*	push {r3}
		mov r3, pc
		add r3, #0x4
		bx r3 */
    asm(".byte 0x08, 0xB4, 0x7B, 0x46, 0x04, 0x33, 0x18, 0x47");
    asm("pop {r3}"); // this was used in the magical THUMB asm above!
}
	
/**
* This is a register optimized callThumb function. The operator may specify what registers to use
* in order to perform the bx call...
*/
void callThumb_r(uint32_t funcAddress, int r1, int r2){
	// TODO: implement callThumb_r
	
}