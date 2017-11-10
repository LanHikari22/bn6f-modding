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


uint32_t* p;
int onStart_executed;
int savedKeyState;
int counter; // TODO: actually breaks project AND other variables unless initialized???? Doesn't work as static either. Linker error.
// Actually, it also breaks if it's accessed a lot??? Putting it in many places in main BREAKS variables, but putting in a place that doesn't execute much doesnt???
// onStart() breaks it for example...



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
}

/**
* This is called once per frame. Approximately once every 60th of a second.
*/
void onUpdate(){
	if(counter % 60 == 0)
		sBtlEnemyA->HP++;
	counter++;
	p[0] = counter;
	p[1] = &counter;
	p[3] = &p;
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
	//callThumb(0x08040358); // Brings text into life!
	
	
	// register int r0 asm("r0") = 0xFFFFFFFF;
	// register int r1 asm("r1") = 0xFFFFFFFF;
	// register int r2 asm("r2") = 0xFFFFFFFF;
	// register int r3 asm("r3") = 0xFFFFFFFF;
	// register int r4 asm("r4") = 0xFFFFFFFF;
	// register int r6 asm("r6") = 0xFFFFFFFF;
	// register int r7 asm("r7") = 0xFFFFFFFF;
	// register int r8 asm("r8") = 0xFFFFFFFF;
	// register int r9 asm("r9") = 0xFFFFFFFF;
	// 	register int r5 asm("r5") = sNPC_chaud;
    // 
	// //r5 = 0x00000101;
	// callThumb(fpRunChatbox); // THIS ACTUALLY STARTS A MESSAGE BOX LEGIT
	// p[0] = r0;
	// p[1] = r1;
	// p[2] = r2;
	// p[3] = r3;
	// p[4] = r4;
	// p[5] = r5;
	// p[6] = r6;
	// p[7] = r7;
	// p[8] = r8;
	// p[9] = r9;
	// 
	// ((uint32_t*)0x08A00000)[0] = 0xDEADFEED;
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