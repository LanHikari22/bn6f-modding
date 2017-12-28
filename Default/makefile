SRCDIR = ../src/
SYSLIBDIR = C:/devkitPro/devkitARM/arm-none-eabi/lib/
INC = ../include/

# bin utils
BIN = C:/devkitPro/devkitARM/bin
CC = $(BIN)/arm-none-eabi-gcc
LD = $(BIN)/arm-none-eabi-ld
OBJCOPY = $(BIN)/arm-none-eabi-objcopy

COMPLIANCE_FLAGS = -Wall -Wno-unknown-pragmas
CDEBUG = 
CFLAGS = $(COMPLIANCE_FLAGS) $(CDEBUG) -I. -I$(SRCDIR) # TODO: not used? in rom at least
LDFLAGS = -L

# Add system libraries and custom libraries to include here
LIB_LINK_FLAG = -l
SYS_LIBS = c
ABS_SYS_LIBS = $(addprefix $(LIB_LINK_FLAG), $(SYS_LIBS))
LIBS = $(ABS_SYS_LIBS)

#################################################################################################
# List your sources here.  The sources are all of the .c files that are part of the project.
SOURCES = main.c beep.c TextGenerator.c
SYSTEM_SOURCES = libc.a
ABS_SOURCES = $(addprefix $(SRCDIR), $(SOURCES))
#################################################################################################

#################################################################################################
# list The ROM to build your program into. This file should be specified in this folder.
ROM = mmbn6ge.gba
# This is generated and is linked with the linker script to mod ROM
PURE_ROM = ../mmbn6ge.gba
#################################################################################################

#################################################################################################
# A temporary object file that is generated to as the sum of compiled object files to be injected
COMBINED_OBJ = output.o
#################################################################################################
# Create the names of the object files (each .c file becomes a .o file)
OBJS = $(patsubst %.c, %.o, $(SOURCES))

# include $(SOURCES:.c=.d) # TODO gives error

PURE_OBJCOPY_FLAGS = -O elf32-littlearm -B arm --rename-section .data=.rom --set-section-flags .rom="r,c,a"

# This handles compiling and linking into ROM.
build:
	$(OBJCOPY) -I binary $(PURE_OBJCOPY_FLAGS) $(PURE_ROM) pure.o
	$(CC) $(COMPLIANCE_FLAGS) -c $(ABS_SOURCES) -I$(INC)
	$(LD) -T romlink.ld -o $(COMBINED_OBJ) $(OBJS) pure.o
	$(OBJCOPY) --set-section-flags .rom="r,c,a" output.o
	$(OBJCOPY) -O binary output.o $(ROM)
	
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
	rm -f *d
	rm -f $(EXECUTABLE)
	cp $(BACKUP_ROM) $(ROM)

