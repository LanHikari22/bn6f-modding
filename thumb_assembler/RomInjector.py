import sys
import os
import io


def binLen(file):
    """Returns the number of bytes in a seekable binary file"""
    file.read()
    len = file.tell()
    file.seek(0)
    return len


##
# This program copies the binary contents from the file pointed by binaryPath
# to the gba ROM at the specified injection offset.
# Expected Args: gbaROMPath binaryPath injectionOffset
# Example: "C:\MMBN6.gba" "C:\S Subroutine.bin" 090036
##
if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Invalid arguments.\nExpected Args: gbaROMPath binaryPath injectionOffset\nExiting...")
        exit(1)
    # Loading  Data
    rom = open(sys.argv[1], "r+b")
    injection = open(sys.argv[2], "rb")
    injectionOffset = int(sys.argv[3], 16)
    # Injecting
    rom.seek(injectionOffset)
    bytesWritten = rom.write(injection.read())
    print("Injected successfully! Wrote %i bytes to offset 0x%x!" % (bytesWritten, injectionOffset))

    # Lengths of files
    #romLen = binLen(rom)
    #injectionLen = binLen(injection)
    # Reporting File sizes
    #print("rom.size: %f MB" % (romLen/1E6))
    #print("injection.size: %i bytes" % injectionLen)

    # Closing files
    rom.close()
    injection.close()