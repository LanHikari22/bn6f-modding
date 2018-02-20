##
# @Author Lan
# This module is to be used by the Exporter to generate the files dependencies.x and dependencies.s
# dependencies are function namees called by the exported region, or accessible to the exported region within its pool,
# but are not part of the region. They have to be defined for the disassembly to be functional.
# Technically, data accesses are also dependencies, but (for now, todo: fix this) dependencies are only functions.
##
import idc


class NoDependencyException(Exception):
    def __init__(self):
        super(NoDependencyException, self).__init__()


class Dependency:
    def __init__(self, ea):
        """
                If the passed instruction is a branch, (but now BX), this extracts the Name being branched to.
                If the passed disasm is a DCD to a NAME, this extracts the name
                Otherwise a NoDependencyException is raised.
                :param ea: Effective address to check the disasm of
                :raises NoDependencyException: when the ea passed has no dependencies
                """
        disasm = idc.GetDisasm(ea)
        if disasm.startswith('B') and not disasm.startswith('BX'):
            self.name = disasm[disasm.index(' '):].lstrip()
        elif disasm.startswith('DCD'):
            operand = disasm[disasm.index(' '):].lstrip()  # DCD <operand>
            if operand[-2:] == '+1': operand = operand[:-2]  # Remove the '+1' in function DCDs
            operandEA_str = "%08X" % idc.get_name_ea(0, operand)  # invalid names would give 'FFFFFFFF'
            if operandEA_str != 'FFFFFFFF': self.name = operand
            else: raise NoDependencyException()
        else:
            raise NoDependencyException()
        self.ea = idc.get_name_ea(0,self.name)
        self.name = idc.get_name(self.ea) # this filters out silly comments in the name

    def getLabelDefinition(self):
        """
        This is to be put in the definitions.s file
        :return: a definition of the label so that it can be BL'd into and stuff
        """
        return '.section .d__%s, "ax"\n%s:' % (self.name, self.name)

    def getLdScript(self):
        return '. = 0x%08X;\n.d__%s : {*.o(.d__%s)}' % (self.ea, self.name, self.name)