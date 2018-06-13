##
# @Author Lan
# This module is responsible for retrieving the original assembly content anywhere in the ROM. It processes and
# returns all content in terms of AsmLines. All necessary conversions are also made to the assembly lines, so that
# they can be valid to write immediately. Dependencies found in extracted files/functions/modules are also retrieved.
#
# DEPENDENCY NOTE: This module is very architecture dependent. Logic involved is specific to the ARM architecture
# Specifically, Cortex-M4 ARM7. Dependencies are obtained by checking for B and BL instructions.
##
import idautils
import idc

# import wingdbstub
# wingdbstub.Ensure()
import idaapi
idaapi.require('IDAItems.Function')
idaapi.require('Definitions')
idaapi.require('SlinkyEngine.AsmLine')
idaapi.require('SlinkyEngine.Dependency')

from IDAItems.Function import Function
from IDAItems.Function import InvalidFunctionException
from Definitions import Architecture
from SlinkyEngine.AsmLine import AsmLine
from SlinkyEngine.Dependency import Dependency, NoDependencyException


class SizeIntegrityViolation(Exception):
    def __init__(self, str):
        super(Exception, self).__init__(str)


class Extractor:

    def __init__(self):
        pass

    def extractRange(self, startEA, endEA):
        """
        Extracts all assembly lines within the range [startEA, endEA)
        The range is iterated through to obtain each assembly line, which is converted appropriately based
        on the assembler used.
        It also detects all dependencies to be resolved.
        The returned Dependencies are Names that are not defined within the confined space of the range.
        :param startEA: (long) Starting address
        :param endEA: (long) End address, not included
        :return: Assembly lines and all dependencies found
        """
        asmLines = [] # Assembly lines to be extracted
        sizeCounter = 0 # This will be incremented based on each head, to ensure all items were accounted for
        dependencies = [] # all B/BL's and DCDs involved

        # Extract all items within the range
        for head in idautils.Heads(startEA, endEA):
            # ensure item size integrity as you walk items (if not ensured, full of holes asm files can ruin the ROM)
            if sizeCounter != (head - startEA):
                print('[debug] %X, size= %X, sizeCounter= %X' % (head, head - startEA, sizeCounter))
                raise SizeIntegrityViolation('Size mismatch detected at the item before %08X' % head)
            # extract the item and account for its size
            asmLine = AsmLine(head)
            sizeCounter += asmLine.size
            asmLines.append(asmLine)
            # If the item contains a dependency, (ex: BL someFunction), the dependency must be accounted for.
            try:
                dependency = Dependency(head)
                dependencies.append(dependency)
            except NoDependencyException: pass

        # Size integrity check for the last item: This can be hit because of bad ranges.
        if sizeCounter != (endEA - startEA):
            # This is likely to mean that the range specified did not enclose entirely on all items
            # Remove the last item, and warn the user
            asmLines = asmLines[:-1]
            print('WARNING: Last asm lie not extracted. '
                  'Likely because the specified range did not enclose it completely.')
            print('size= %X, sizeCounter= %X' % (endEA - startEA, sizeCounter))
            # in the event that the last asmLine contained a dependency, it isn't removed, but it is harmless.

        # Remove any dependencies self-contained within the function, like a label within the function.
        dependencies = self.filterResolvedDependencies(dependencies, asmLines)
        return (asmLines, dependencies)

    def extractFunction(self, func_ea):
        """
        Extracts and converts the assembly content of a function. Function.getSize() is utilized to detect the function's
        pool, if any.
        :param func_ea: (long) The effective address of the function
        :return: (tuple(list(AsmLine), list(str)) Both the assembly lines of the function, and all of the Names of its
        dependencies.
        """
        # This is needed to obtain the size of the function (+pool)
        func = Function(func_ea)
        return self.extractRange(func_ea, func_ea + func.getSize(withPool=True))

    def extractFile(self, gamefile):
        """
        Extracts and converts assembly content of a game file.
        :param gamefile: (GameFile) A defined range as a file, either manually or through heuristics
        :return: (tuple(list(AsmLine), list(str)) Both the assembly lines of the file, and all of the Names of its
        dependencies.
        """
        return self.extractRange(gamefile.start_ea, gamefile.start_ea + gamefile.getSize(withPool=True))

    @staticmethod
    def filterResolvedDependencies(dependencies, asmLines):
        """
        if a dependency is in the names present in asmLines, it is filtered out.
        :param dependencies: List of names being branched to
        :param asmLines: List of Names of labels actually found in the disassembly
        :return: the dependencies, filtered to include only names not found in asmLines
        """
        output = []
        resolvedNames = []
        for asmLine in asmLines:
            name = asmLine.name
            if name: resolvedNames.append(name)
        for dependency in dependencies:
            if dependency.name not in resolvedNames: output.append(dependency)
        return output

if __name__ == '__main__':
    extractor = Extractor()
    # asmLines, dependencies = extractor.extractFunction(0x081382AC)
    asmLines, dependencies = extractor.exportRange(0x0802F8A6, 0x0802F8D8-0x0802F8A6)
    for line in asmLines:
        print(str(line))
