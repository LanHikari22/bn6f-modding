##
# @Author Lan
# This represents one assembly line. Could be code, could be data, could be a label, but it's easily written to a file.
##
import idc


class AsmLine:
    def __init__(self, ea):
        self.ea = ea
        self.name = idc.Name(ea)
        self.disasm = self._convertCode(ea, idc.GetDisasm(ea))
        self.disasm = self._convertData(self.disasm)
        self.size = idc.get_item_size(ea)


    def _convertCode(self, ea, disasm):
        """
        This is purely assembler-specific. It will convert the disassembly from the form found in IDA, to the form
        used by whatever compiler/assembler is using the s files.
        :param ea: (long) addr of disasm
        :param disasm: (str) disasm to transform
        :return: (str) converted disasm
        """
        flags = idc.GetFlags(ea)
        output = disasm # Default case, no modifications
        if idc.isCode(flags):
            # Remove all 'S's (in ADDS, MOVS, etc) because they're not supported in thumb2
            instName = disasm[:disasm.index(' ')]
            if instName[-1] == 'S':
                output = instName[:-1] + ' ' + disasm[len(instName):]
        return output

    def __str__(self):
        """
        :return: (str) The disassembly, but in a disassembler-compatible manner!
        """
        name = self.name and self.name + ':\n' or ''
        return name + '\t' + self.disasm

    def _convertData(self, disasm):
        if disasm.startswith('DCD'):
            disasm = '.word ' + disasm[disasm.index(' '):].lstrip()
        if disasm.startswith('DCB'):
            disasm = '.byte ' + disasm[disasm.index(' '):].lstrip()

        return disasm
        pass