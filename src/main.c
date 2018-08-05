/**
* This is the project's entrypoint module. The code executes once every frame.
* Here, extra logic will be defined so that other modules may execute under different conditions.
* @file main.c
*/
#include "main.h"
#include "MMBN6.h"
#include "structs/NPC.h"
#include "constants/keys.h"
#include "constants/Mugshots.h"
#include "structs/inttypes.h"
#include "TextGenerator.h"
#include "DebugConsole.h"

NPC *npc;
int savedKeyState;
int counter;

// A random pattern that will only be written into the global during onStart
#define ONSTART_EXECUTED 0xDEADFEED

void onStart();
void onKeyPress();
void onUpdate();
void RPress();

int cMain()
{
	// handle onStart()
	if (onStart_executed != ONSTART_EXECUTED)
	{
		onStart();
	}

	// handle onUpdate()
	onUpdate();

	// handle onKeyPress()
	if (toolkit->joystick->keyPress != Key_DEFAULT)
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
	if (toolkit->joystick->keyPress == (Key_DEFAULT | Key_R))
	{
		RPress();
		// Launch debugging console
		dc_startConsole(&p[0x10>>2], (dc_ROM*)0x089A0000);

	}
}

/**
 * Executes if 0x089A0000 is set to 0x02. This is handled by the DebugConsole.c Module
 * Can also be triggered to execute using the cheatcode "SELECT SELECT SELECT R"
 */
void RPress(){
	// sets zennies to 0
	// TODO: this is not an indicator of how many characters go per line.
	// This isn't mono-space, but it's a good lower limit.
	// dc_printChat((u16*)0x02500050, mugshot_shuko,
  // "0123456789012345678901\n0123456789012345678901\n012345678901234567890");
	extern void sub_813C030();
	dc_printChat((u16*)0x02500050, mugshot_shuko, "Debugger Shuko, at your\nservice!");
	// subsystem_launch_reqBBS(0x00);
	// Sound_playBG(mo_ACDC_town);

	// r5 = sBtlEnemyA;
	// object_add_hp(50); // doesn't add HP for some reason??
	// object_break_panel(3, 3); // it woooorks!



	//
	// SWI_LZ77UnCompReadNormalWrite8bit(0x0809836B, 0x02050010);

}
