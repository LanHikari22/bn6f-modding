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

from IDAItems.Function import Function
from IDAItems.Function import InvalidFunctionException
from Definitions import Architecture
from SlinkyEngine.AsmLine import AsmLine
from SlinkyEngine.Dependency import Dependency, NoDependencyException


class Extractor:

    def __init__(self):
        pass

    def extractFunction(self, func_ea):
        """
        Extracts and converts the assembly content of a function. Function.getSize() is utilized to detect the function's
        pool, if any. The function is iterated through to obtain each assembly line, which is converted appropriately based
        on the assembler used. Dependencies are Names that are not defined within the confined space of the function.
        :param func_ea: (long) The effective address of the function
        :return: (tuple(list(AsmLine), list(str)) Both the assembly lines of the function, and all of the Names of its
        dependencies.
        """
        # This is needed to obtain the size of the function (+pool)
        func = Function(func_ea)
        # Iterate through all heads from start to end
        asmLines = []
        sizeCounter = 0 # This will be incremented based on each head, to ensure all items were accounted for
        dependencies = [] # all B/BL's and DCDs involved
        for head in idautils.Heads(func_ea, func_ea + func.getSize(withPool=True)):
            asmLine = AsmLine(head)
            sizeCounter += asmLine.size
            asmLines.append(asmLine)
            try:
                dependency = Dependency(head)
                dependencies.append(dependency)
            except NoDependencyException: pass
        if sizeCounter != func.getSize(withPool=True):
            raise Exception('Extracted items do not sum to the size of the function %08X' % func_ea)
        # Remove any dependencies self-contained within the function, like a label within the function.
        dependencies = self.filterResolvedDependencies(dependencies, asmLines)
        return (asmLines, dependencies)

    def extractFile(self, gamefile):
        asmLines = []
        sizeCounter = 0 # This will be incremented based on each head, to ensure all items were accounted for
        dependencies = [] # all B/BL's and DCDs involved
        for head in idautils.Heads(gamefile.start_ea, gamefile.start_ea + gamefile.getSize(withPool=True)):
            asmLine = AsmLine(head)
            sizeCounter += asmLine.size
            asmLines.append(asmLine)
            try:
                dependency = Dependency(head)
                dependencies.append(dependency)
            except NoDependencyException: pass
        if sizeCounter != gamefile.getSize(withPool=True):
            raise Exception('Extracted items do not sum to the size of the file %08X' % func_ea)
        print(hex(sizeCounter))
        # Remove any dependencies self-contained within the function, like a label within the function.
        dependencies = self.filterResolvedDependencies(dependencies, asmLines)
        return (asmLines, dependencies)

    def exportRange(self, startEA, size):
        asmLines = []
        sizeCounter = 0 # This will be incremented based on each head, to ensure all items were accounted for
        dependencies = [] # all B/BL's and DCDs involved
        for head in idautils.Heads(startEA, startEA + size):
            asmLine = AsmLine(head)
            sizeCounter += asmLine.size
            asmLines.append(asmLine)
            try:
                dependency = Dependency(head)
                dependencies.append(dependency)
            except NoDependencyException: pass
        if sizeCounter != size:
            raise Exception('Extracted items do not sum to the size of the range @ %08X' % startEA)
        print(hex(sizeCounter))
        # Remove any dependencies self-contained within the function, like a label within the function.
        dependencies = self.filterResolvedDependencies(dependencies, asmLines)
        return (asmLines, dependencies)


    def filterResolvedDependencies(self, dependencies, asmLines):
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
