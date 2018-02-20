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
        self.disasm = self._convertComments(self.disasm)

        self.size = idc.get_item_size(ea)


    def _convertCode(self, ea, disasm):
        """
        Instructions that end with 'S' like 'MOVS' are macro instructions for dealing with immediates >255
        Such instructions are demacroized into their INST, LSL  format. <INST>s -> INST, LSL
        :param ea: (long) addr of disasm
        :param disasm: (str) disasm to transform
        :return: (str) converted disasm
        """
        flags = idc.GetFlags(ea)
        output = disasm # Default case, no modifications
        if idc.isCode(flags):
            instName = disasm[:disasm.index(' ')]
            if instName[-1] == 'S':
                # remove the 'S'
                output = instName[:-1] + output[len(instName):]
                # if imm is present, a shift may be present, in case it wasn't disabled in ARM-specific settings
                if '#' in output:
                    destReg = output[len(instName)+1:output.index(',')]
                    immStr = output[output.index('#'):]
                    base = '0x' in immStr and 16 or 10
                    charAfterImm = ';' in immStr and ';' or ' ' # could be a comment, or a space (or nothing)
                    imm = charAfterImm in immStr and int(immStr[1:immStr.index(charAfterImm)], base) or int(immStr[1:], base)
                    if imm > 255:
                        # determine how many shifts are needed, and the value to be shifted
                        numShifts = 1
                        n = imm/2
                        while n > 255:
                            numShifts += 1
                            n /= 2
                        output = instName[:-1] + output[len(instName):output.index('#')] + '#0x%X' % n + \
                                 '\nLSL    %s, %s, #%d' % (destReg, destReg, numShifts)
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

    def _convertComments(self, disasm):
        return disasm.replace(';', ' //', disasm.count(';'))
        pass