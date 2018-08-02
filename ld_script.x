OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)

SECTIONS
{
    /* linking file sections from rom.s into place */
    . = 0x08000000;
    .r__start : {*.o(.r__start)}

    /* Linking main.c as well as RAM variables*/
    . = 0x08900000;
    .text : {main.o(.text) *(.text)}
    .rodata : {*(.rodata) . = ALIGN(4);}
    . = 0x02500000;
    .data : {*(.data) . = ALIGN(4);}
    .bss : {*(.bss) . = ALIGN(4);}



}
