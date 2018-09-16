# binary tools used in build
# (the arm-none-eabi toolchain should be in the path)
MAKE = make
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
SHA1SUM = sha1sum
PY = py

# libraries
SYS_LIB_DIR1 = C:/devkitPro/devkitARM/arm-none-eabi/lib/
SYS_LIB_DIR2 = C:/devkitPro/devkitARM/lib/gcc/arm-none-eabi/7.1.0/

# Add system libraries and custom libraries to include here
LIB_LINK_FLAG = -l
SYS_LIBS = c gcc
LIBS = $(addprefix $(LIB_LINK_FLAG), $(SYS_LIBS))


# project paths
ASMDIR = asm
SRCDIR = src
BIN = bin
CONST = constants
STRUCTS = structs
INC = inc
INCLUDE = include

# project files
CFILES = $(wildcard $(SRCDIR)/*.c)
SFILES = $(ASMDIR)/_rom.s
OFILES = $(addprefix $(OBJ),$(notdir $(SFILES:.s=.o))) $(addprefix $(OBJ),$(notdir $(CFILES:.c=.o)))
ROM = bn6f

# build flags
COMPLIANCE_FLAGS = -O0 -g3 -I$(INC) -I$(INCLUDE) -I.
WFLAGS =
ARCH = -march=armv4t -mtune=arm7tdmi -mabi=aapcs -mthumb -mthumb-interwork
CDEBUG =
CFLAGS = $(ARCH) $(WFLAGS) $(COMPLIANCE_FLAGS) $(CDEBUG)
ASFLAGS =
LDFLAGS = -g -Map $(ROM).map
LIB = -static -L $(SYS_LIB_DIR1) -L $(SYS_LIB_DIR2) $(LIBS)

all:

rom: $(ROM)
	@# TODO: this tab is needed or ROM is executed weirdly?? oops!

$(ROM):
	$(CC) $(CFLAGS) -c $(SFILES) $(CFILES)
	$(LD) $(LDFLAGS) -o $(ROM).elf -T ld_script.x $(OFILES) $(LIB)
	$(OBJCOPY) -O binary $(ROM).elf $(ROM).gba

checksum:
	$(SHA1SUM) -b $(ROM).gba
	@echo "0676ecd4d58a976af3346caebb44b9b6489ad099 *Expected"


fdiff:
	$(PY) tools/fdiff.py _$(ROM).gba $(ROM).gba -s2

tail: $(ROM)
	@# Create tail.bin using the tail location in current elf then compile again
	$(PY) tools/gen_obj_tail.py $(ROM).elf _$(ROM).gba bin/tail.bin 'tail'
	@echo "Updated tail.bin!"

clean:
	rm -f *.preout
	rm -f *.o
	rm -f *.out
	rm -f *.d
	rm -f *.map
	rm -f *.elf

# Rule for how to translate a single c file into an object file.
%.o : %.c
	echo compiling $<
	echo $(CC) $(CFLAGS) -c $<
	$(CC) $(CFLAGS) -E $< > $<.preout
	$(CC) $(CFLAGS) -S $<
	$(CC) $(CFLAGS) -c $<
	echo done compiling $<

# Rule for how to generate the dependencies for the given files.
# -M gcc option generates dependencies.
%.d : %.c
	@set -e; rm -f $@; \
	$(CC) $(COMPLIANCE_FLAGS ) -M $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
