/**
* This is the project's entrypoint module. The code executes once every frame.
* Here, extra logic will be defined so that other modules may execute under different conditions.
* TODO one linking issue is that the reference to a statically defined function here cannot be obtained.
* That's fine though, considering they would always be called with BL. But you may Fix.
* @file main.c
*/
#include "../include/main.h"
#include "../include/MMBN6.h"
#include "../Structs/NPC.h"
#include "../Constants/keys.h"
#include "../Constants/Mugshots.h"
#include <main.h>
#include <inttypes.h>
#include <TextGenerator.h>
#include <DebugConsole.h>

NPC *npc;
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
	if (sChief->joystick->keyPress != Key_DEFAULT)
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
	dc_init((u32*)0x02050010, (dc_ROM*)0x089A0000);

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
	// Put all modules that require frame updating here
	dc_onUpdate(0x089A0000);

	static int ctr = 0;
	if (ctr % 60 == 0)
		sBtlEnemyA->HP++;
	ctr++;
}

/**
* Handle logic to be done when a key is pressed. This executes whenever the keystate changes
*/
void onKeyPress()
{
	if (sChief->joystick->keyPress == (Key_DEFAULT | Key_R))
	{
		// Launch debugging console
		dc_startConsole(&p[0x10>>2], (dc_ROM*)0x089A0000);

	}
}

/**
 * Executes if 0x089A0000 is set to 0x02. This is handled by the DebugConsole.c Module
 * Can also be triggered to execute using the cheatcode "SELECT SELECT SELECT R"
 */
void RPress(){
	// dc_printChat((u16*)0x02500050, mugshot_shuko, "How can I help you?"); // sets zennies to 0
	// subsystem_launch_reqBBS(0x00);
	// Sound_playBG(mo_ACDC_town);

	r5 = sBtlEnemyA;
	// object_add_hp(50); // doesn't add HP for some reason??
	// object_break_panel(3, 3); // it woooorks!
	Save_803F79E();
}
