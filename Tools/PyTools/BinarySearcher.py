##
# @File BinarySearcher.py
# @Author Lan
# The purpose of this module is to use IDA database capabilities to search for things in binaries (ROMS, Dumps, etc).
# TODO: First feature to be implemented is searching for whether a function in the database exists in the binary.
##

import idautils
import idc_bc695
import Function
import os

# Constants
INSTRUCTION_WIDTH = 2 # The number of bytes an instruction takes is needed for the search algorithm
INVALID_FUNCTION = -1
RANGE_OUT_OF_ROM = -2



class BinarySearcher:

    def __init__(self, ROM, bin, ROM_start_addr):
        """
        :param ROM:  str: Path to the ROM to be opened as a file. This should be identical to the ROM analyzed by IDA
        :param bin:  str: Path to the binary to be searched
        :param ROM_start_addr: Reference address within the database. This is used to address things in the DB, and ROM.
        """
        self.ROM = open(ROM, 'rb')
        binFile = open(bin, 'rb')
        self.binSize = os.path.getsize(bin)
        self.ROM_start_addr = ROM_start_addr
        self.binData = binFile.read()
        binFile.close()

    def _get_func_data(self, func):
        """
        Returns bytes for the function
        :param func: Function.Function: Function to get data of
        :return: a byte string representing the function
        """
        start_ea, end_ea = func.getBoundaries()
        self.ROM.seek(start_ea - self.ROM_start_addr)
        data = self.ROM.read(func.getSize())
        # output = []
        # for b in data:
        #     output.append(int(ord(b)))
        # return output
        return data

    def find_function(self, func_ea):
        """
        This searches the binary for an occurrance of the hex data of this function. The hex data to be searched for
        is found in the Analysis ROM.
        :param func_ea:  long: The effective address of the function to search
        :return:  Address of occurrance of function in binary if found, or None.
                 (Error Cases)
                 - If func_ea is not found to be within a function, INVALID_FUNCTION is returned. (See constants)
                 - if func_ea < the ROM's starting addr, RANGE_OUT_OF_ROM is returned. (See constants)
        """

        # All functions to be found have to actually be within the ROM region
        if func_ea < self.ROM_start_addr: return RANGE_OUT_OF_ROM
        try:
            func = Function.Function(func_ea)
            start_ea, end_ea = func.getBoundaries()
            funcData = self._get_func_data(func)
            # Search Binary for the data
            try:
                output = self.binData.index(funcData)
            except ValueError:
                output = None
            return output
        except Function.InvalidFunctionException:
            return INVALID_FUNCTION

    def scan_for_known_functions(self):
        """
        This will scan the binary using ALL defined functions in the ROM SEGMENT in the IDA Database agaisnt the binary.
        Dictionary for each match:
        Key         Description
        Name        The name of the function in the IDA Database
        ROM_Addr    The ROM Address. This is absolute to the architecture in question, and the seg addr is added to it
        Bin_Addr    The Address in the binary file. This is relative to the binary file.
        :return: A list of Dictionaries according to the definition above, or an empty list if no matches.
        """
        output = []
        for func_ea in idautils.Functions(idc_bc695.SegStart(self.ROM_start_addr), idc_bc695.SegEnd(self.ROM_start_addr)):
            binEA = self.find_function(func_ea)
            if binEA:
                matchDict = {}
                matchDict['Name'] = idc_bc695.GetFunctionName(func_ea)
                matchDict['ROM_Addr'] = func_ea
                matchDict['Bin_Addr'] = binEA
                output.append(matchDict)
        return output


if __name__ == '__main__':
    ROM = 'C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\Build\\mmbn6f.gba'
    bin = ROM
    searcher = BinarySearcher(ROM, bin, 0x08000000)
    import time
    stopwatch = time.time()
    # Diagnosed code here...
    matchedFunctions = searcher.scan_for_known_functions()
    stopwatch = time.time() - stopwatch
    print("This operation took %d s" % int(stopwatch))
    for x in matchedFunctions: print (x["Name"])
    # print(hex(0x08000000 + searcher.find_function(0x803EFCC))) # returns 0x803efcc
