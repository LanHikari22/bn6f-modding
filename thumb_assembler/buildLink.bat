@echo off
REM ^ the @ makes the echo off not appear, and that's awesome! no need for a cls :D

REM this is for use with the GBA thumb compiler only.
set rom="..\..\..\..\..\Roms\GBA\MMBN\MMBN6\mmbn6g - SCode.gba"
set asm="..\KeyPressExecution.asm"
set injectionOffset=090000

pushd "%~dp0"
call thumb %asm% output.bin
py RomInjector.py %rom% "output.bin" %injectionOffset%
popd

< nul set /p =Press any key to continue!
pause > nul