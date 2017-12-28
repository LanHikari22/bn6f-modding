OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)

SECTIONS
{
    . = 0x08000000;
    .rom (COPY): {KEEP(*.o(.rom))}
    . = 0x08900000;
    .text : {main.o(.text) *(.text)}
    .rodata : {*(.rodata) . = ALIGN(4);}
    . = 0x02500000;
    .data : {*(.data) . = ALIGN(4);}
    .bss : {*(.bss) . = ALIGN(4);}

    /* things that require specialized linking */
    . = 0x08090000;
    .mainHook : {*.o(.mainHook)}
    . = 0x08000402;
    .intercept_08000402 : {*.o(.intercept_08000402)}

}