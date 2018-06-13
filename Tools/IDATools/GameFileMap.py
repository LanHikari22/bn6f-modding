# @Author Lan
# This module displays the list of all registered game files, as well as their ranges
# It displays this in a form that gives a senste to how much of the ROM was file-defined.
# Any file displayed here in essence is disassemblable, so this also gives a summary of the disassembly progress

import idaapi

from Definitions.Architecture import ROM_SEG
from Definitions.GameDefinitions import GAME_MODULES
from Definitions.GameDefinitions import ROM_SIZE
from Definitions.Paths import PROJ_PATH
from IDAItems.Module import Module

idaapi.require('GameItems.Module')
idaapi.require('GameItems.GameFile')


def getSortedGameFiles():
    """
    :return: a list of game files found from all registered modules sorted by start_ea
    """
    gamefiles = []
    for mod in GAME_MODULES:
        m = Module(mod)
        files = m.getModuleFiles()
        for file in files:
            # make sure to filter all files below ROM. they aren't really files
            if file.start_ea >= ROM_SEG:
                gamefiles.append( (m.name, file) )

    # now sort them based on start_ea
    return sorted(gamefiles, key=lambda x: x[1].start_ea)




def getMapFileRow(file, filename=None):
    """
    Based on the game file given, this generates a row in the map table
    consisting of start_ea, end_ea, and the name.
    In case the file doesn't have a name, the default is file_<start_ea>
    :param file: (GameFile) file to generate table row of
    :param filename: (str) name of file in case the name isn't encapsulated in the file itself
    :return: (str) A table row representing the range and file name
    """
    if filename:
        name = filename
    elif file.hasName():
        name = file.getName()
    else:
        name = 'file_%07X' % file.start_ea
    return "%07X %07X %07X %s\n" % (file.start_ea, file.end_ea, file.end_ea - file.start_ea, name)

def getMapPadRow(prevFile=None, nextFile=None):
    """
    Given two game files, this will find the range of no files between them.
    If the two files are contiguous, '' is returned.
    If prevFile is none, then this computes the range from ROM_SEG to currFile.start_ea
    if currFile is none, it cmomputes from prevFile.end_ea to the end of the ROM.
    if both are none, it just generates the range of the whole ROM.
    :param prevFile: (GameFile) the last file whose range was shown
    :param nextFile: (GameFile) the next file whose range will be shown
    :return: The pad range in the format "'07X %07X -'
    """
    start_ea = prevFile.end_ea if (prevFile) else ROM_SEG
    end_ea = nextFile.start_ea if (nextFile) else ROM_SEG + ROM_SIZE
    if end_ea - start_ea == 0:
        return ''
    else:
        return '%07X %07X %07X -\n' % (start_ea, end_ea, end_ea - start_ea)

def generateMap():
    """
    Retrieves all registered files, then generates a table with a Start and End columns, and a File column
    representing the Ranges and the filename.
    :return:
    """
    map = ''
    gamefiles = getSortedGameFiles()
    map += '%s %s %s Name\n' % ('Start'.ljust(7), 'End'.ljust(7), 'Size'.ljust(7))
    map += getMapPadRow(nextFile=gamefiles[0][1]) # gamefiles[0] = (name0, gamefile0)
    for i in range(len(gamefiles)):
        name, file = gamefiles[i]
        map += getMapFileRow(file, name)
        if i < len(gamefiles)-1:
            map += getMapPadRow(prevFile=file, nextFile=gamefiles[i+1][1])
    map += getMapPadRow(prevFile=gamefiles[-1][1])
    return map

if __name__ == '__main__':
    f = open(PROJ_PATH + 'FILE_MAP', 'w')
    f.write(generateMap())
    f.close()