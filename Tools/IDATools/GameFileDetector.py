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
from Command import c


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
        if len(name) >= len(moduleName) and name[0:len(moduleName)] == moduleName:
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

def dispModuleFileChunks(moduleName, onlyRange=True, showNames=False):
    """
    Prints the content of getModuleFileChunks. Each Chunk can be seen as a File (or parts of) a File.
    :param moduleName: The name of the module to analyze
    :param onlyRange: Will show [ <firstaddr> ..<n>.. <lastaddr> ]. The first and last addresses, and how many in between.
    :param showNames: Will show the subroutine names (Default shows effective addresses instead)
    """
    fileChunks = getModuleFileChunks(moduleName)

    print('numFiles= %d' % len(fileChunks))
    s = ''
    for names in fileChunks:
        s += '[ '
        if onlyRange:
            if showNames: s += names[0][1] + ' '
            else: s += '%08X ' % (names[0][0])

            if len(names) > 2: s += '..%2d.. ' % (len(names) - 2)

            if len(names) > 1:
                if showNames: s += names[-1][1] + ' '
                else: s += '%08X ' % (names[-1][0])

        else:
            for name_ea, name in names:
                if showNames: s += name + ' '
                else: s += '%08X ' % (name_ea)
        s += ']\n'

    return len(s) > 0 and s[:-1] or s


def moduleFiles(cmd, *args, **kwargs):
    """
    This is to be executed through the run module
    :param cmd: Not used. There because python! (Sorry)
    :param args: (moduleName, suppress=True, onlyRange=True, showNames=False)
    :param kwargs: Not used
    :return: Files detected within the module
    """
    moduleName = args[0]
    suppress = len(args) > 1 and args[1] or True
    onlyRange = len(args) > 2 and args[2] or True
    showNames = len(args) > 3 and args[3] or False

    if not suppress: print("Scanning files in Module '%s'..." % moduleName)
    output = dispModuleFileChunks(moduleName, onlyRange=onlyRange, showNames=showNames)
    if not suppress: print('Scanning Complete!')
    return output


if __name__ == '__main__':
    moduleName = 'main'
    suppressed=False
    onlyRange=True
    showNames=False
    print(moduleFiles(None, moduleName, suppressed, onlyRange, showNames))
