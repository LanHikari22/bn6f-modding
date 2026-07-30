#include "use_flags.pp"

OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)

MEMORY
{
    ewram_region (w!x) : ORIGIN = 0x02000000, LENGTH = 0x40000
    iwram_region (w!x) : ORIGIN = 0x03000000, LENGTH = 0x8000
    vram_region (w!x) : ORIGIN = 0x06000000, LENGTH = 0x18000
#ifdef USE_MOD
    rom_region (rx) : ORIGIN = 0x08000000, LENGTH = 0x1000000
#else
    rom_region (rx) : ORIGIN = 0x08000000, LENGTH = 0x0800000
#endif
}

SECTIONS
{
    INCLUDE "constants.ld"

    ewram_2000000 (NOLOAD) :
    ALIGN(4)
    {
        ewram.o(ewram_2000000);
    } >ewram_region

    OVERLAY . :
    {
        ewram_battle { ewram.o(ewram_battle); }
        ewram_2034000 { ewram.o(ewram_2034000); }
    } >ewram_region

    iwram (NOLOAD) :
    ALIGN(4)
    {
        iwram.o(.data);
    } >iwram_region

    vram_6000000 (NOLOAD) :
    ALIGN(4)
    {
        vram.o(vram_6000000);
    } >vram_region
    
    /* start of ROM */

    .text :
    {
        rom.o(.text);
    } >rom_region

    iwram_text :
    {
        iwram.o(.text);
    } >iwram_region AT>rom_region
    
    .data :
    ALIGN(4)
    {
        data.o(.data);
    } >rom_region

#ifdef USE_MOD
    .modding_text :
    {
        modding.o(.text);
    } >rom_region
#endif

    .fill :
    {
        FILL(0xff);
        . = ORIGIN(rom_region) + LENGTH(rom_region) - 1;
        BYTE(0xff);
    } >rom_region
}
