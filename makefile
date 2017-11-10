# nope... SHELL = /bin/sh 
SRCDIR = ../src
BIN = C:/devkitPro/devkitARM/bin
CC = $(BIN)/arm-none-eabi-gcc
LD = $(BIN)/arm-none-eabi-ld
YACC = bison -y
CDEBUG = -g
COMPLIANCE_FLAGS = -Wall
CFLAGS = $(COMPLIANCE_FLAGS) $(CDEBUG) -I. -I$(SRCDIR)
LDFLAGS = -g
LIBS = 

#################################################################################################
# List your sources here.  The sources are all of the .c files that are part of the project.
SOURCES = main.c
#################################################################################################

#################################################################################################
# list the name of your output program here. (i.e. myfirstprogram
EXECUTABLE = hello
#################################################################################################

#################################################################################################
# Memory map (.mmp) configuratio file specifying text segment and data segment(s) for injection
MMP = ROM_Memory_Map.mmp
#################################################################################################

#################################################################################################
# list The ROM to build your program into. This file should be specified in this folder.
ROM = mmbn6ge.gba
# This is the backup living somewhere else. This is restored back when cleaning.
BACKUP_ROM = ../mmbn6ge.gba
#################################################################################################

#################################################################################################
# A temporary object file that is generated to as the sum of compiled object files to be injected
COMBINED_OBJ = output.o
#################################################################################################
# Create the names of the object files (each .c file becomes a .o file)
OBJS = $(patsubst %.c, %.o, $(SOURCES))

# include $(SOURCES:.c=.d) # TODO gives error

# This handles compiling and ROMLinking
rom:
	$(CC) $(COMPLIANCE_FLAGS) -c $(LDFLAGS) $(SRCDIR)/$(SOURCES) $(LIBS)
	$(LD) -r -o $(COMBINED_OBJ) $(OBJS)
	java -jar ROM_LINKER.jar $(ROM) $(COMBINED_OBJ) $(MMP)
	
all : $(OBJS) $(EXECUTABLE)

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

