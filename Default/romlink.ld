OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)

SECTIONS
{
    . = 0x08000000;
    .rom (COPY): {KEEP(*.o(.rom))}
    . = 0x08900000;
    .text : {*(.text)}
    .rodata : {*(.rodata) . = ALIGN(4);}
}