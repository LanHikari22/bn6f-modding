#ifndef SCRIPT_MEMORY_H
#define SCRIPT_MEMORY_H

#include "../include/inttypes.h"

#define init_memblock_to_byte ((void (*)(u8 *memblock, int size, char initByte))(0x08000964+1))

#endif // SCRIPT_MEMORY_H