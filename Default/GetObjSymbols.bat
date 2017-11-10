echo off
REM start of the program: The java proram expects echo to be off (and is the first line in the file).
REM Arguments: %1= Object file path, %2= Table to retrieve

SET PATH=%PATH%;C:\devkitPro\devkitARM\bin

IF "%2"=="SYMBOL_TABLE"     GOTO SYMBOL_TABLE
IF "%2"=="RELOCATION_TABLE" GOTO RELOCATION_TABLE
IF "%2"=="SECTION_HEADERS"  GOTO SECTION_HEADERS
GOTO INVALID_ARGS

:SYMBOL_TABLE
    arm-none-eabi-readelf --syms %1
    GOTO END
:RELOCATION_TABLE
    arm-none-eabi-readelf --relocs %1
    GOTO END
:SECTION_HEADERS
    arm-none-eabi-readelf --section-headers %1
    GOTO END

:INVALID_ARGS
echo Invalid arguments passed to command.

:END