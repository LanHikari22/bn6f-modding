#
# @Author Lan
# This module abstracts operations on Functions and CFunctions in IDAPython.
# It allows easy modification of propreties related to functions, and the
# abiility to save all modifications easily.
#

from idaapi import *

class Function:

    func = None    # func_t
    func_ea = None # ea_t

    def __init__(self, func_ea):
        # If the current address is function process it
        if get_func_flags(func_ea) != -1:
            self.func = get_func(func_ea)
            self.func_ea = self.func.startEA
        else:
            raise(Exception("Address %08x does not live within a function" % func_ea))

    def getName(self):
        return idaapi.get_func_name(func_ea)

    def getXRefsTo(self):
        """
        Computes a list of the names of the xrefs to the function.
        This includes all functions that call this, but also data xrefs.
        @returns a tuple of two lists: crefs and drefs
        """
        crefs = []
        drefs = []
        # If the current address is function process it
        if get_func_flags(self.func_ea) != -1:
            # Find all code references to func
            ref = get_first_cref_to(self.func_ea)
            while ref != BADADDR:
                # name = get_func_name(ref)
                # if not name: name = "ROM:%08X" % ref
                crefs.append(ref)
                ref = get_next_cref_to(self.func_ea, ref)
            # Find all data references to func
            for ref in DataRefsTo(self.func_ea):
                drefs.append(ref)
            for ref in DataRefsTo(self.func_ea+1):
                drefs.append(ref)

            return (crefs, drefs)

    def getXRefsFrom(self):
        crefs = []
        drefs = []
        normalFlow = True
        for ref in CodeRefsFrom(self.func_ea, normalFlow): # XrefsFrom
            # print xref.type, XrefTypeName(xref.type), 'from', hex(xref.frm), 'to', hex(xref.to)
            crefs.append(ref)
        for ref in CodeRefsFrom(self.func_ea, not normalFlow): # XrefsFrom
            # print xref.type, XrefTypeName(xref.type), 'from', hex(xref.frm), 'to', hex(xref.to)
            crefs.append(ref)
        for ref in DataRefsFrom(self.func_ea):
            drefs.append(ref)
        for ref in DataRefsFrom(self.func_ea+1):
            drefs.append(ref)
        return (crefs, drefs)


    def getComment(self):
        return get_func_cmt(func.func, 0)
        """
        TODO: For some reason, there is this weird weird glitch where if you
        manually set a function comment through the decompiler, it isn't recognized
        here?? At least if you don't do it on a disassembly level first...
        """
    def setComment(self, cmt):
        set_func_cmt(func.func, cmt, 0)

def printRefs(crefs, drefs):
    s = ''
    s += '['
    for ref in crefs:
        s += str(hex(ref)) + ', '
    s = (len(s) > 8) and s[0:-2] +  '] ' or s + '] '
    len1 = len(s)

    s += '['
    for ref in drefs:
        s += str(hex(ref)) + ', '
    s = (len(s) - len1 > 8) and s[0:-2] +  '] ' or s + '] '

    print(s)


def RunTesting():
    func = Function(here())
    crefs, drefs = func.getXRefsFrom()
    printRefs(crefs, drefs)

if __name__ == '__main__':
    RunTesting()
