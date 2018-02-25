##
# @Author Lan
# This represents one assembly line. Could be code, could be data, could be a label, but it's easily written to a file.
##
import idc
import re
import ida_funcs

# import wingdbstub
# wingdbstub.Ensure()
import idaapi
idaapi.require('IDAItems.Function')

from IDAItems import Function

class AsmLine:
    def __init__(self, ea):
        self.ea = ea
        self.name = idc.Name(ea)
        self.size = idc.get_item_size(ea)

        self.hasLabel = False
        self.isFunctionStart = False
        self.withinFunction = idc.get_func_flags(ea) != -1
        if self.name:
            self.hasLabel = True
            try:
                self.isFunctionStart = Function.Function(self.ea).func_ea == ea
            except Function.InvalidFunctionException:
                pass

        flags = idc.GetFlags(ea)
        if idc.isCode(flags):
            self.disasm = self._convertCode(ea, idc.GetDisasm(ea))
        if idc.isData(flags):
            self.disasm = self.getDataDisasm(ea)
            self.disasm = self._convertData(self.disasm)
        self.disasm = self._convertComments(self.disasm)


    def _convertCode(self, ea, disasm):
        """
        Just removing 'S' from instructions like MOVS.
        :param ea: (long) addr of disasm
        :param disasm: (str) disasm to transform
        :return: (str) converted disasm
        """
        flags = idc.GetFlags(ea)
        output = disasm # Default case, no modifications
        if idc.isCode(flags):
            # some instructions take no operands, like NOP
            instName = disasm[:disasm.index(' ')] if ' ' in disasm else disasm
            if instName[-1] == 'S':
                # remove the 'S': 'MOVS ...' -> 'MOV  ...'
                output = instName[:-1] + ' ' +  output[len(instName):]
        return output

    def __str__(self):
        """
        :return: (str) The disassembly, but in a disassembler-compatible manner!
        """
        name = self.name and self.name + ':\n' or ''
        return name + '\t' + self.disasm

    def _convertData(self, disasm):
        """
        Simply replaces occurrances of DCD/DCB with what is compatible with the assembler
        :param disasm: disassembly to convert
        :return: converted disassembly
        """

        while 'DCD' in disasm: disasm = disasm.replace('DCD', '.word')
        while 'DCB' in disasm: disasm = disasm.replace('DCB', '.byte')

        return disasm

    def _convertComments(self, disasm):
        return disasm.replace(';', ' //', disasm.count(';'))
        pass

    def getDataDisasm(self, ea):
        """
        You cannot get array data using getdisasm. The disassembly has to be extracted differently.
        :param ea: the effective address of the item to get the disassembly of
        :return: the disasssembly of the data item
        """
        # First, do the easy cases that just work with GetDisasm
        flags = idc.GetFlags(ea)
        if idc.is_data(flags) and (idc.is_byte(flags) and idc.get_item_size(ea) == 1
                                   or idc.is_word(flags) and idc.get_item_size(ea) == 2
                                   or idc.is_dword(flags) and idc.get_item_size(ea) == 4):
            return idc.GetDisasm(ea) # very simple, this works.
        else: # The weird case... an array. I don't know why it's weird. IDA doesn't like it!
            # It is assumed this is an array, but the type is unknown. Imply type based on disasm of first line!
            firstLineSplitDisasm = list(filter(None, re.split('[ ,]', idc.GetDisasm(ea))))
            dataType = firstLineSplitDisasm[0]
            elemsPerLine = len(firstLineSplitDisasm) - 1 # don't include type, ex: DCB 0, 4, 5, 0x02, 0

            # Grab all of the bytes in the array
            bytes = []
            for char in idc.get_bytes(ea, idc.get_item_size(ea)):
                bytes.append(ord(char))

            # You can treat the data as bytes always, but I don't want to ruin the representation.
            if self.isFunctionPointer(firstLineSplitDisasm):
                return self.getFuncPtrArrayDisasm(bytes, elemsPerLine)

            bytesPerElem = dataType == 'DCB' and 1 \
                       or dataType == 'DCW' and 2 \
                       or dataType == 'DCD' and 4 \
                       or 1 # if type unknown, just show it as a an array of bytes

            # create new array with correct type
            arr = self.combineBytes(bytes, bytesPerElem)

            # generate disassembly for array
            disasm = firstLineSplitDisasm[0] + ' '
            newLineCounter = 0
            for elem in arr:
                if disasm[-1] == '\n': disasm += '\t%s' % (firstLineSplitDisasm[0] + ' ')
                disasm += '0x%X, ' % elem
                newLineCounter += 1
                if newLineCounter % elemsPerLine == 0:
                    disasm = (disasm[len(disasm)-2:] == ', ' and disasm[:-2] or disasm) + '\n'
            disasm = (disasm[len(disasm) - 2:] == ', ' and disasm[:-2] or disasm)
            return disasm


    def isFunctionPointer(self, firstLineSplitDisasm):
        """
        Identifies the construct 'DCD <funcName>' as a function pointer entry!
        The function Name is checked in the database for confirmation!
        This actually extend to none-identified functions, because it only checks if the location is valid code.
        :param firstLineSplitDisasm: list of space and comma split operands in the instruction. ['DCD', 'sub_DEADBEEF+1']
        :return:
        """
        return len(firstLineSplitDisasm) >= 2 and firstLineSplitDisasm[0] == 'DCD' \
            and idc.isCode(idc.GetFlags(idc.get_name_ea(0,firstLineSplitDisasm[1])))

    def getFuncPtrArrayDisasm(self, bytes, elemsPerLine, thumbMode=True):
        subpad = '+1' if thumbMode else ''
        func_eas = self.combineBytes(bytes, 4)
        newLineCounter = 0
        disasm = 'DCD '
        for func_ea in func_eas:
            if disasm[-1] == '\n': disasm += '\tDCD '
            disasm += '%s, ' % (idc.get_name(func_ea) + subpad)
            newLineCounter += 1
            if newLineCounter % elemsPerLine == 0:
                disasm = (disasm[len(disasm) - 2:] == ', ' and disasm[:-2] or disasm) + '\n'
            disasm = (disasm[len(disasm) - 2:] == ', ' and disasm[:-2] or disasm)
        return disasm

    def combineBytes(self, bytes, newDataSize):
        """
        Converts an array of bytes into an array of halfwords, or an array of words, or whatever the new data size is.
        Note that the passed b
        :raises ValueError: if list of bytes is not a multiple of newDataSize
        :param bytes: (list(int)) list of bytes. Length must be a multiple of newDataSize
        :param newDataSize: (iut) number of bytes in each element
        :return: an array of each element
        """
        if len(bytes) % newDataSize != 0: raise ValueError('bytes is not a multiple of newDataSize')
        # generate new list
        output = []
        i = 0
        while i + newDataSize-1 < len(bytes):
            n = 0
            for j in range(newDataSize-1, -1, -1):
                n |= bytes[i + j] << 8*j
            output.append(n)
            i += newDataSize
        return output

if __name__ == '__main__':
    line = AsmLine(0x0802F8AC)
    print(line.disasm)