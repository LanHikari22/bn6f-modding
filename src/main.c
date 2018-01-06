/**
* This is the project's entrypoint module. The code executes once every frame.
* Here, extra logic will be defined so that other modules may execute under different conditions.
* TODO one linking issue is that the reference to a statically defined function here cannot be obtained.
* That's fine though, considering they would always be called with BL. But you may Fix.
* @file main.c
*/
#include <main.h>
#include <vanilla/MMBN6.h>
#include <vanilla/structs/NPC.h>
#include <inttypes.h>
#include <TextGenerator.h>

NPC *npc;
int onStart_executed;
int savedKeyState;
int counter;

// A random pattern that will only be written into the global during onStart
#define ONSTART_EXECUTED 0xDEADFEED

void onStart();
void onKeyPress();
void onUpdate();
void RPress();

int main()
{
	// handle onStart()
	if (onStart_executed != ONSTART_EXECUTED)
	{
		onStart();
	}

	// handle onUpdate()
	onUpdate();

	// handle onKeyPress()
	if (sChief->joystick->keyPress != KeyIDLE)
	{
		onKeyPress();
	}
	return 0;
}

/**
* This executes only once, it is used for module initialization.
*/
void onStart()
{
	onStart_executed = ONSTART_EXECUTED;
	/* Put initialization logic here ******/
	// p is just somewhere full of zeros i like to debug values in.
	p = (uint32_t*)0x02050000;
	counter = 0;
	npc = (NPC *)0x02050010;
	p[0] = (uint32_t)npc;
}

/**
* This is called once per frame. Approximately once every 60th of a second.
*/
void onUpdate()
{
	static ctr = 0;
	if (ctr % 60 == 0)
		sBtlEnemyA->HP++;
	ctr++;
}

/**
* Handle logic to be done when a key is pressed. This executes whenever the keystate changes
*/
void onKeyPress()
{
	if (sChief->joystick->keyPress == KeyR)
	{
		RPress();
	}
}

void sweep1D(int (*fp)(int a1), int* loggingLoc, int start, int amount);
void sweepPartial2D(int (*fp)(int a1, int a2), int* loggingLoc, int start, int amount, int c, int which);

void RPress(){
	u32 *c = (u8*)0x089A0000;
	// tg_chatPrint("Happy new year!", 0x01);
	// sBtlEnemyA->HP -= 10;
	// tg_startBattle((uint16_t)p[0x80>>2]);

	// int register r5 asm("r5") = 0x02005780;
	// testfunc();
	// p[0x10>>2] = testfunc(c[0]);
	p[0x10>>2] = testfunc(c[0], c[1]);
	sweepPartial2D(testfunc, &c[0], 0, 0xFF, 0x23, 1);


	// Call function from jump table
	// void (*fp) () = ( (void (*) ()) chatbox_jt3[c[0]] );
	// fp();

	// Sweep Tests
	// sweep1D(testfunc, &p[0x10>>2], c[0], c[1]);
	// sweepPartial2D(testfunc, &p[0x10>>2], c[0], c[1], c[2], c[3])

}

void sweep1D(int (*fp)(int a1), int* loggingLoc, int start, int amount){
	
	for (int i = start; i < start + amount; i++){
		loggingLoc[i - start] = fp(i); 
	}
}

void sweepPartial2D(int (*fp)(int a1, int a2), int* loggingLoc, int start, int amount, int c, int which){
	for (int i = start; i < start + amount; i++){
		if (which == 1) loggingLoc[i - start] = fp(c, i);
		if (which == 2) loggingLoc[i - start] = fp(i, c);
	}
}