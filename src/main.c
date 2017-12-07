/**
* This is the project's entrypoint module. The code executes once every frame.
* Here, extra logic will be defined so that other modules may execute under different conditions.
* TODO one linking issue is that the reference to a statically defined function here cannot be obtained.
* That's fine though, considering they would always be called with BL. But you may Fix.
* @file main.c
*/
#include <vanilla/MMBN6.h>
#include <vanilla/structs/NPC.h>
#include <inttypes.h>

/**
* Calls an arbitrary function pointer to code in THUMB mode.
* This converts to THUMB to make the call, then converts back to ARM
* once done.
* The magic assembly is:
*	push {r3}
*	mov r3, r15
*	add r3, #0x4
* 	bx r3
* 
* R3 is reserved for long jump. In case it is needed, other macros r4CallThumb through r7Callthumb
*/
#define callThumb(funcAddress) ({\
	void (*f)() = (void *)(funcAddress + 1); \
	f(); \
	asm(".byte 0x08, 0xB4, 0x7B, 0x46, 0x04, 0x33, 0x18, 0x47"); \
	asm("pop {r3}"); \
})
#define callThumb_r4(funcAddress) ({\
	int register r asm("r4") = funcAddress + 1; \
	asm("push {lr}"); \
	asm("mov lr, pc"); \
	asm("bx r4"); \
	asm(".byte 0x10, 0xB4, 0x7C, 0x46, 0x04, 0x34, 0x20, 0x47"); \
	asm("pop {r4}"); \
	asm("pop {r4}"); \
	asm("mov lr, r4"); \
})
#define callThumb_r5(funcAddress) ({\
	int register r asm("r5") = funcAddress + 1; \
	asm("push {lr}"); \
	asm("mov lr, pc"); \
	asm("bx r5"); \
	asm(".byte 0x20, 0xB4, 0x7D, 0x46, 0x04, 0x35, 0x28, 0x47"); \
	asm("pop {r5}"); \
	asm("pop {r5}"); \
	asm("mov lr, r5"); \
})
#define callThumb_r6(funcAddress) ({\
	int register r asm("r6") = funcAddress + 1; \
	asm("push {lr}"); \
	asm("mov lr, pc"); \
	asm("bx r6"); \
	asm(".byte 0x40, 0xB4, 0x7E, 0x46, 0x04, 0x36, 0x30, 0x47"); \
	asm("pop {r6}"); \
	asm("pop {r6}"); \
	asm("mov lr, r6"); \
})
#define callThumb_r7(funcAddress) ({\
	int register r asm("r7") = funcAddress + 1; \
	asm("push {lr}"); \
	asm("mov lr, pc"); \
	asm("bx r7"); \
	asm(".byte 0x80, 0xB4, 0x7F, 0x46, 0x04, 0x37, 0x38, 0x47"); \
	asm("pop {r7}"); \
	asm("pop {r7}"); \
	asm("mov lr, r7"); \
})

#define NULL ((void *)0)
typedef char bool;
#define true 1
#define false 0

NPC *npc;
uint32_t *p;
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
	p = (uint32_t *)0x02050000;
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

/**
* TODO: modify linker so it can create these. Once that is done,
* main will be changed to be called... intecept_someAddress. That is because main is really just an interceptor function.
* The intercepting logic has just been hardwired.
*/
void intercept_08040000();

void RPress() // 0x0890018c
{
	// int register r5 asm("r5") = npc;
	// int register r2 asm("r2") = *((uint8_t*)0x02050050);
	int register r5 asm("r5") = 0x02005888;
	// callThumb(fpRunChatbox);

	int register r1 asm("r0") = ((NPC*)r5)->convoSelect;
	callThumb(0x803FD3C);
}