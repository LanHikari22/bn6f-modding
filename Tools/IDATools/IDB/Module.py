##
# @Author Lan
# This represents the concept of modulized functions/data. A set of functions may be related, or were belonging to
# A single file or set of files when compiled together.
# This encapsulates all Names that begin with <ModuleName> and count them as belonging to the same module.
##
import idaapi
import idautils
import idc_bc695

idaapi.require('BinarySearcher')
idaapi.require('Definitions.Architecture')
idaapi.require('GameItems.GameFile')
idaapi.require('IDAItems.Function')

from BinarySearcher import BinarySearcher
from Definitions.Architecture import ROM_SEG
from IDAItems.GameFile import GameFile
from IDAItems import Function


class Module:

    def __init__(self, moduleName):
        """
        Creates a module with the name moduleName. This could be exported from the database, or it could be a new
        module to include in the database!
        :param moduleName:  The name of the module
        """
        self.name = moduleName
        self.files = self.getModuleFiles()


    def getModuleFileChunks(self):
        """
        When performing context analysis, many functions all over the place could be associated with a module.
        Say, anything that only seems to have to do with the Battle engine, maybe called as 'Battle_08040000' or
        'Battle_Start', 'Battle)CheckPlayerStatus', 'Battle_IncreaseHP', etc. They are named that, simply because they
        in some sense were thought to have something to do with 'Battle'.
        They have to be named '<moduleName>_'... to count as part of the module.

        This function identifies a list of lists of Names starting with moduleName, each list would reperesent a collection
        of names that identify as one chunk. If they are cut by other defined names, other chunks are appended.
        :return: (list(list(long, str)) All Module-defined Names, seperated out in chunks such that each chunk represents a
                 valid GameFile.
        """
        namesLists = []
        listCsr = 0

        foundFirstName = False
        foundLastName = False
        # First get all names within the module
        for name_ea, name in idautils.Names():
            if len(name) >= len(self.name)+1 and name[0:len(self.name)+1] == self.name + '_': # starts with '<moduleName>_'
                print name # TODO: debug
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

    def getModuleFiles(self):
        """
        :return: list(GameFile) list of files of this modules
        """
        namesLists = self.getModuleFileChunks()
        files = []
        for names in namesLists: # each name is a tuple (name_ea, name)
            files.append(GameFile(names[0][0], names[-1][0]))
        return files

    def getModuleFunctions(self):
        """
        This traverses all segments, and all defined modules to retrieve all functions with that module name.
        :return: a list of Functions that are in this module, saved in the database.
        """
        output = []
        for seg_ea in idautils.Segments():
            for func_ea in idautils.Functions(idc_bc695.SegStart(seg_ea), idc_bc695.SegEnd(seg_ea)):
                func = Function.Function(func_ea)
                # if the function starts with '<moduleName>'...
                if len(func.getName())>len(self.name) and func.getName()[0:len(self.name)]==self.name :
                    output.append(func)
        return output

    def getVersionSegregatedModuleFuncs(self, otherVersionBinPath):
        """
        This not only searches for function modules, but recognizes functions that are:
        1) Version Dependent functions
        2) Shared by both versions
        3) Functions unique ONLY to this version

        Please note that this has an inherent limitation of only being able to search ROM.
        This means that some 'unique' functions might just exist in RAM, or IRAM, or any non-ROM segments.

        TODO: [1] Implemented [1] Tested

        :return: A tuple of the three lists of functions mentioned above: (VersionDependent, Shared, Unique)
        """
        searcher = BinarySearcher(otherVersionBinPath)

        moduleFunctions = self.getModuleFunctions()

        # Search for each function in the other binary!
        matchedFunctions = [] # list of tuples of function in this version, and its match in the other.
        UniqueFunctions = [] # Unique to this function.
        for func in moduleFunctions:
            func_ea = searcher.find_function(func.func_ea)
            if func_ea >= 0:
                matchedFunctions.append((func, ROM_SEG + func_ea)) # found func_ea's are file-relative
            else: # Those are functions unique to THIS version!
                UniqueFunctions.append(func)
        # Those are all of the matches, Find both the VERSION and SHARED Functions!
        SharedFunctions = [] # Same location in both versions
        VersionFunctions = [] # Different locations, but present in both. This is matchedFunctions - SharedFunctions
        for func, otherVersion_func_ea in matchedFunctions:
            if func.func_ea == otherVersion_func_ea: # SHARED!
                SharedFunctions.append(func)
            else: # VERSION DEPENDENT!
                VersionFunctions.append( (func, otherVersion_func_ea) )

        # Close the searcher! good job, searcher-san!
        searcher.closeFiles()

        return VersionFunctions, SharedFunctions, UniqueFunctions


if __name__ == '__main__':
    pass