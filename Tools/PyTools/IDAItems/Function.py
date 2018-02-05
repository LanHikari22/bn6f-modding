#
# @Author Lan
# This module abstracts operations on Functions and CFunctions in IDAPython.
# It allows easy modification of propreties related to functions, and the
# abiility to save all modifications easily.
#

import idautils
import idaapi
import idc


def isFunction(ea):
    return idc.get_func_flags(ea) != -1

class InvalidFunctionException(Exception):
    def __init__(self, s):
        super(Exception, self).__init__(s)
        pass

class Function:
    func = None  # func_t
    func_ea = None  # ea_t

    def __init__(self, func_ea):
        """
        :raises: InvalidFunctionException if func_ea does not live within a function, or the function is not defined.
        :param func_ea: long: Effective Address of function to manipulate
        """
        # If the current address is a function process it
        if idc.get_func_flags(func_ea) != -1:

            self.func = idaapi.get_func(func_ea)
            self.func_ea = self.func.startEA
        else:
            raise (InvalidFunctionException("Address %08x does not live within a function" % func_ea))

    # Name -------------------------------------------------------------------------------------------------------------

    def getName(self):
        return idaapi.get_func_name(self.func_ea)

    def setName(self, funcName):
        """
        Same as in Head. Kept for reference.
        :param funcName:  (str) name of the function
        """
        idc.MakeName(self.func_ea, funcName)

    # Prototype --------------------------------------------------------------------------------------------------------

    def getPrototype(self):
        """
        :return: (str) representing the return type
        """
        # return idc.get_type(self.func_ea) Only works if type is defined with 'y' in disassembly
        cfunc = idaapi.decompile(self.func)
        retType = idaapi.tinfo_t()
        cfunc.get_func_type(retType)
        return str(retType)

    def getFuncPtrCMacro(self):
        """
        Will return the Prototype of the function in the format:
        #define <funcName> ((<retType> (*) (<params>)) (<funcAddr>+1))
        Example:
        #define sound_play ((void (*)(int a1, int a2, int a3))(0x080005CC+1))
        this DOES assume that the function is THUMB.
        TODO: Support ARM Functions too!
        :return: (str) Function pointer in a CMacro definition.
        """
        prototype = self.getPrototype()
        retType = prototype[0:prototype.index('(')]
        params = prototype[prototype.index('(') : prototype.index(')')+1]
        funcAddr = '0x%08X' % self.func_ea
        output = '#define ' + self.getName() + ' ((' + retType + ' (*) ' + params + ') (' + funcAddr + ' +1))'
        return output


    def ongoing_getParameters(self):
        """
        :return: A list of tuples of (typeName, paramName)
                 int a2 would give ('int, 'a2')
        """


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
        TODO: Sometimes the comment is repeatable (created through decomp) or not (created through disass).
        What to return???? Why not whichever works?
        """
        cmt = idc.get_func_cmt(self.func_ea, 1)
        if not cmt: cmt = idc.get_func_cmt(self.func_ea, 0)
        return cmt

    def setComment(self, cmt):
        """
        TODO: repeatable or not???
        :param cmt: Comment to be set as a function comment
        :return:
        """
        idaapi.set_func_cmt(self.func, cmt, 1)

    # Boundaries -------------------------------------------------------------------------------------------------------

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
    print(func.getComment())
    # crefs, drefs = func.getXRefsFrom()
    # printRefs(crefs, drefs)


if __name__ == '__main__':
    RunTesting()
