SRCDIR = ../src/
SYS_LIB_DIR1 = C:/devkitPro/devkitARM/arm-none-eabi/lib/
SYS_LIB_DIR2 = C:/devkitPro/devkitARM/lib/gcc/arm-none-eabi/7.1.0/
INC = ../include/

# bin utils
BIN = C:/devkitPro/devkitARM/bin
CC = $(BIN)/arm-none-eabi-gcc
LD = $(BIN)/arm-none-eabi-ld
OBJCOPY = $(BIN)/arm-none-eabi-objcopy

# build flags
COMPLIANCE_FLAGS = -fomit-frame-pointer -ffast-math -fno-toplevel-reorder -nostdinc # -O2 makes main not first
WFLAGS = -Wall -Wno-unkown-pragmas
ARCH   = -mcpu=arm7tdmi -mabi=aapcs -mthumb -mthumb-interwork
CDEBUG = -g
CFLAGS = $(ARCH) $(COMPLIANCE_FLAGS) $(CDEBUG) -I. -I$(SRCDIR)
LDFLAGS = -g -T romlink.ld -Map output.map
LD_LINK = -static -L $(SYS_LIB_DIR1) -L $(SYS_LIB_DIR2) $(LIBS)
PURE_OBJCOPY_FLAGS = -O elf32-littlearm -B arm --rename-section .data=.rom --set-section-flags .rom="r,c,a"

# Add system libraries and custom libraries to include here
LIB_LINK_FLAG = -l
SYS_LIBS = c gcc
LIBS = $(addprefix $(LIB_LINK_FLAG), $(SYS_LIBS))

# project files for compilation
CFILES	:=	$(foreach dir,$(SRCDIR),$(notdir $(wildcard $(SRCDIR)/*.c)))
SFILES	:=	$(foreach dir,$(SRCDIR),$(notdir $(wildcard $(SRCDIR)/*.S))) \
			$(foreach dir,$(SRCDIR),$(notdir $(wildcard $(SRCDIR)/*.s)))
OFILES 	:=  $(patsubst %.c, %.o, $(CFILES)) $(patsubst %.s, %.o, $(SFILES))
SOURCES :=  $(addprefix $(SRCDIR), $(CFILES)) $(addprefix $(SRCDIR), $(SFILES))

# BINFILES	:=	$(foreach dir,$(DATA),$(notdir $(wildcard $(dir)/*.bin)))

#################################################################################################
# list The ROM to build your program into. This file should be specified in this folder.
ROM = mmbn6g.gba
# This is generated and is linked with the linker script to mod ROM
PURE_ROM = ../mmbn6g.gba
# A temporary object file that is generated to as the sum of compiled object files to be injected
COMBINED_OBJ = output.o
#################################################################################################
# Create the names of the object files (each .c file becomes a .o file)

# include $(SOURCES:.c=.d) # TODO gives error

# This handles compiling and linking into ROM.
build:
	$(CC) $(CFLAGS) -c $(SOURCES) -I$(INC)
	$(LD) $(LDFLAGS) -o $(COMBINED_OBJ) $(OFILES) pure.o $(LD_LINK)
	$(OBJCOPY) --set-section-flags .rom="r,c,a" output.o
	$(OBJCOPY) -O binary output.o $(ROM)
	

init:
	$(OBJCOPY) -I binary $(PURE_OBJCOPY_FLAGS) $(PURE_ROM) pure.o
	
$(EXECUTABLE) : $(OBJS)
	$(CC) $(COMPLIANCE_FLAGS) -o $(EXECUTABLE) $(LDFLAGS) $(OBJS) $(LIBS)
	
	
%.o : %.c #Defines how to translate a single c file into an object file.
	echo compiling $<
	echo $(CC) $(CFLAGS) -c $<
	$(CC) $(CFLAGS) -E $< > $<.preout
	$(CC) $(CFLAGS) -S $<
	$(CC) $(CFLAGS) -c $<
	echo done compiling $<

%.d : %.c #Defines how to generate the dependencies for the given files. -M gcc option generates dependencies.
	@set -e; rm -f $@; \
	$(CC) $(COMPLIANCE_FLAGS ) -M $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

clean : # Delete any and all artifacts from the build. The only thing which is kept is the source rm -f *.o
	rm -f *.preout
	rm -f *.s
	rm -f *.S
	rm -f *.o
	rm -f *.d
	rm -f *.map