# MMBN6-Romhacking
This is for reverse engineering MMBN6, disassembling it, and documenting all of its functions. 
as well as create a C SDK framework for hacking it
This uses linker script to link absolutely all data, assembly files, and C files into the ROM. 

# Goals
- Reverse engineer, document, disassemble, and write SDKs for different engines/features of the game
- Current Reversing goal: 
  Storyline hacking. 
  Be able to create a Scene, be able to create a side mission through a request BBS.

# Note
- This is a pure system that takes in a completely unmodified ROM, and outputs a modded ROM.
- Note that having DevkitARM is necessary, since its binaries are used.

# Usage
- Specify the locations of both the input pure ROM and the output modded ROM in the makefile
- Run "make init" to create an object version of the ROM, this is needed for linking. It may only be needed once, but "make clean" will delete it
- Run "make build" to build the project and the pure ROM object together into the output ROM!

# Contributions
Any and all contributions, suggestions, and anything are welcome! (Please!)
