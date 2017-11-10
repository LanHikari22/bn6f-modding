echo off
REM start of the program: The java proram expects echo to be off (and is the first line in the file).
REM Arguments: %1= ROM path, %2= File to inject, %3= Injection offset

py RomInjector.py %1 %2 %3