##
# @Author Lan
# This module Runs heuristics to identify function files. There is no filesystem in the GBA Architecture, meaning that
# there's no surefire way to determining file borders. But this code hopes to at least identify a collection of
# functions that seem to suggest they're in the same file.
# Manual renaming is necessary. This will assume that your guesses are correct and identify extra functions you have
# not renamed to be part of the file, part of the file.
# Heuristics:
# - Identify Helper functions, and collections of helper functions that are close to each other.
#   If (1) all references to a function come from already file-identified functions,
#      (2) The path between
#      (3) and the path between all references
#      (3) and
#   and the identified function form a valid file, then it belongs to that file.
##
import idautils

from GameItems.Module import Module


class GameFileDetector:
    pass

def getModuleFileChunks(moduleName):
    """
    When performing context analysis, many functions all over the place could be associated with a module.
    Say, anything that only seems to have to do with the Battle engine, maybe called as 'Battle_08040000' or
    'BattleStart', 'BattleCheckPlayerStatus', 'Battle_IncreaseHP', etc. They are named that, simply because they
    in some sense were thought to have something to do with 'Battle'.

    This function identifies a list of lists of Names starting with moduleName, each list would reperesent a collection
    of names that identify as one chunk. If they are cut by other defined names, other chunks are appended.
    :param moduleName: (str) the name of the module
    :return: (list(list(long, str)) All Module-defined Names, seperated out in chunks such that each chunk represents a
             valid GameFile.
    """
    namesLists = []
    listCsr = 0

    foundFirstName = False
    foundLastName = False
    # First get all names within the module
    for name_ea, name in idautils.Names():
        if len(name) > len(moduleName) and name[0:len(moduleName)] == moduleName:
            if foundFirstName and foundLastName:
                listCsr += 1
                # Repeat the process for the next field...
                foundFirstName = False
                foundLastName = False
            if not foundFirstName:
                namesLists.append([])
                foundFirstName = True
            namesLists[listCsr].append((name_ea, name))

        # we have entered the filename field, yet it was not detected in Names...
        elif foundFirstName and not foundLastName:
            foundLastName = True

    return namesLists

def dispModuleFileChunks(moduleName):
    """
    Prints the content of getModuleFileChunks. Each Chunk can be seen as a File (or parts of) a File.
    :param moduleName: The name of the module to analyze
    """
    fileChunks = getModuleFileChunks('Chatbox')

    print('numFiles= %d' % len(fileChunks))
    for names in fileChunks:
        s = '[ '
        for name_ea, name in names:
            s += '%08X ' % (name_ea)
        s += ']'
        print(s)

if __name__ == '__main__':
    dispModuleFileChunks('Chatbox')
    mod = Module('Chatbox')
    for func in mod.getModuleFunctions():
        print(func.getName())
