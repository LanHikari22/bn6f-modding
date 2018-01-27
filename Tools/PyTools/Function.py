#
# @Author Lan
# This module abstracts operations on Functions and CFunctions in IDAPython.
# It allows easy modification of propreties related to functions, and the
# abiility to save all modifications easily.
#

import idautils
import idaapi
import idc


class InvalidFunctionException(Exception):
    def __init__(self, str):
        super(self, str)
        pass


class Function:
    func = None  # func_t
    func_ea = None  # ea_t

    def __init__(self, func_ea):
        """
        :raises: InvalidFunctionException if func_ea does not live within a function, or the function is not defined.
        :param func_ea: long: Effective Address of function to manipulate
        """
        # If the current address is function process it
        if idc.get_func_flags(func_ea) != -1:

            self.func = idaapi.get_func(func_ea)
            self.func_ea = self.func.startEA
        else:
            raise (InvalidFunctionException("Address %08x does not live within a function" % func_ea))

    # Name ----------------------------------------------------------------------------------------------------

    def getName(self):
        return idaapi.get_func_name(self.func_ea)

    def setName(self, funcName):
        idc.MakeName(self.func_ea, funcName)

    # Xrefs ------------------------------------------------------------------------------------------------------------

    def getXRefsTo(self):
        """
        Computes a list of the names of the xrefs to the function.
        This includes all functions that call this, but also data xrefs.
        @returns a tuple of two lists: crefs and drefs
        """
        crefs = []
        drefs = []
        # If the current address is function process it
        if idc.get_func_flags(self.func_ea) != -1:
            # Find all code references to func
            ref = idc.get_first_cref_to(self.func_ea)
            while ref != idaapi.BADADDR:
                # name = get_func_name(ref)
                # if not name: name = "ROM:%08X" % ref
                crefs.append(ref)
                ref = idaapi.get_next_cref_to(self.func_ea, ref)
            # Find all data references to func
            for ref in idautils.DataRefsTo(self.func_ea):
                drefs.append(ref)
            for ref in idautils.DataRefsTo(self.func_ea + 1):
                drefs.append(ref)

            return (crefs, drefs)

    def ongoing_getXRefsFrom(self):
        crefs = []
        drefs = []
        normalFlow = True
        for ref in idautils.CodeRefsFrom(self.func_ea, normalFlow):  # XrefsFrom
            # print xref.type, XrefTypeName(xref.type), 'from', hex(xref.frm), 'to', hex(xref.to)
            crefs.append(ref)
        for ref in idautils.CodeRefsFrom(self.func_ea, not normalFlow):  # XrefsFrom
            # print xref.type, XrefTypeName(xref.type), 'from', hex(xref.frm), 'to', hex(xref.to)
            crefs.append(ref)
            # for xref in XrefsFrom(self.func_ea, 0):
            # if xref.type == fl_CN or xref.type == fl_CF:
            # Message("%s calls %s from %x\n" % (fname,  Name(xref.to), i))
            # else:
            # Warning("No function found at location %x" % here())
            # crefs.append(xref.to)

        for ref in idautils.DataRefsFrom(self.func_ea):
            drefs.append(ref)
        for ref in idautils.DataRefsFrom(self.func_ea + 1):
            drefs.append(ref)
        return crefs, drefs

    # Comments ---------------------------------------------------------------------------------------------------------

    def getComment(self):
        """
        TODO: For some reason, there is this weird weird glitch where if you
        manually set a function comment through the decompiler, it isn't recognized
        here?? At least if you don't do it on a disassembly level first...
        """
        return idaapi.get_func_cmt(self.func.func, 0)

    def setComment(self, cmt):
        idaapi.set_func_cmt(self.func.func, cmt, 0)

    def getSize(self):
        """
        :return:  Returns the size of the Function in bytes: EndEA - StartEA
        """
        return self.func.end_ea - self.func.start_ea

    def getBoundaries(self):
        """
        :return: Tuple of Start address and end address of function
        """
        return self.func.start_ea, self.func.end_ea


def printRefs(crefs, drefs):
    s = ''
    s += '['
    for ref in crefs:
        s += str(hex(ref)) + ', '
    s = (len(s) > 8) and s[0:-2] + '] ' or s + '] '
    len1 = len(s)

    s += '['
    for ref in drefs:
        s += str(hex(ref)) + ', '
    s = (len(s) - len1 > 8) and s[0:-2] + '] ' or s + '] '

    print(s)


def RunTesting():
    func = Function(idc.here())
    print(func.setName("Strawberry_sub"))

    # crefs, drefs = func.getXRefsFrom()
    # printRefs(crefs, drefs)


if __name__ == '__main__':
    RunTesting()
