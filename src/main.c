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
	if (*pKeyState != KeyIDLE)
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
	if (counter % 60 == 0)
		sBtlEnemyA->HP++;
	counter++;
}

/**
* Handle logic to be done when a key is pressed. This executes whenever the keystate changes
*/
void onKeyPress()
{
	if (*pKeyState == KeyR)
	{
		RPress();
	}
}

void RPress(){
	tg_chatPrint("Hello, World!!", 0x38);
}


/**
* TODO: modify linker so it can create these. Once that is done,
* main will be changed to be called... intecept_someAddress. That is because main is really just an interceptor function.
* The intercepting logic has just been hardwired.
*/
void intercept_08040000();

 