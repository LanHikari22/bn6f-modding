##
# @Author Lan
# This represents the concept of modulized functions/data. A set of functions may be related, or were belonging to
# A single file or set of files when compiled together. That is one example of a Module. This 'Module' module will
# define operations to be done on a whole module!
##
import idautils
import idc_bc695

from BinarySearcher import BinarySearcher
from Definitions.Architecture import ROM_SEG
from IDAItems import Function


class Module:

    def __init__(self, moduleName):
        """
        Creates a module with the name moduleName. This could be exported from the database, or it could be a new
        module to include in the database!
        :param moduleName:  The name of the module
        """
        self.name = moduleName

    def getModuleFunctions(self):
        """
        This traverses all segments, and all defined modules to retrieve all functions with that module name.
        :return: a list of Functions that are in this module, saved in the database.
        """
        output = []
        for seg_ea in idautils.Segments():
            for func_ea in idautils.Functions(idc_bc695.SegStart(seg_ea), idc_bc695.SegEnd(seg_ea)):
                func = Function.Function(func_ea)
                # if the function starts with '<moduleName>_'...
                if len(func.getName())>len(self.name)+1 and func.getName()[0:len(self.name)+1]==(self.name + '_'):
                    output.append(func)
        return output

    def getVersionSegregatedModuleFuncs(self, ROMPath, otherVersionBinPath):
        """
        This not only searches for function modules, but recognizes functions that are:
        1) Version Dependent functions
        2) Shared by both versions
        3) Functions unique ONLY to this version

        Please note that this has an inherent limitation of only being able to search ROM.
        This means that some 'unique' functions might just exist in RAM, or IRAM, or any non-ROM segments.

        TODO: [O] Implemented [X] Tested

        :return: A tuple of the three lists of functions mentioned above: (VersionDependent, Shared, Unique)
        """
        searcher = BinarySearcher(ROMPath, otherVersionBinPath, ROM_SEG)

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



