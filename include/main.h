#ifndef MAIN_H
#define MAIN_H

#include "MMBN6.h"
#include "structs/Toolkit/Toolkit.h"
#include "structs/Battle.h"
#include "constants/EWRAM.h"

register void *r5 asm("r5");

extern SWI_LZ77UnCompReadNormalWrite8bit(void *compressedData, void *dest);

int onStart_executed;

void RPress();

/* All supported System code is here */
// #include <string.h>

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

uint32_t *p;

#endif // MAIN_H
