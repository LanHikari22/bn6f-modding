#
# @Author Lan
# This module abstracts operations on Functions and CFunctions in IDAPython.
# It allows easy modification of propreties related to functions, and the
# abiility to save all modifications easily.
#

def isFunction(ea):
    raise(NotImplemented())
    # return idc.get_func_flags(ea) != -1

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
        raise(NotImplemented())
        # If the current address is a function process it
        # if idc.get_func_flags(func_ea) != -1:

            # self.func = idaapi.get_func(func_ea)
            # self.func_ea = self.func.startEA
        # else:
        #     raise (InvalidFunctionException("Address %08x does not live within a function" % func_ea))

    # Name -------------------------------------------------------------------------------------------------------------

    def getName(self):
        raise(NotImplemented())
        # return idaapi.get_func_name(self.func_ea)

    def setName(self, funcName):
        """
        Same as in Head. Kept for reference.
        :param funcName:  (str) name of the function
        """
        raise(NotImplemented())
        idc.MakeName(self.func_ea, funcName)

    # Prototype --------------------------------------------------------------------------------------------------------

    def getPrototype(self):
        """
        :return: (str) representing the return type
        """
        raise(NotImplemented())

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
        raise(NotImplemented())

    def ongoing_getParameters(self):
        """
        :return: A list of tuples of (typeName, paramName)
                 int a2 would give ('int, 'a2')
        """
        raise(NotImplemented())

    def getXRefsTo(self):
        """
        Computes a list of the names of the xrefs to the function.
        This includes all functions that call this, but also data xrefs.
        @returns a tuple of two lists: crefs and drefs
        """
        raise(NotImplemented())

    def ongoing_getXRefsFrom(self):
        raise(NotImplemented())

    def enumerateCrossReferences(self):
        """
        This finds all functions called by the function provided at
        the cursor.
        """
        raise(NotImplemented)

    def getComment(self):
        """
        TODO: Sometimes the comment is repeatable (created through decomp) or not (created through disass).
        What to return???? Why not whichever works?
        """
        raise(NotImplemented())

    def setComment(self, cmt):
        """
        TODO: repeatable or not???
        :param cmt: Comment to be set as a function comment
        :return:
        """
        raise(NotImplemented())

    # Boundaries -------------------------------------------------------------------------------------------------------

    def getSize(self, withPool=False):
        """
        Computes the size of the function the first time this is called, and caches that computation for later
        :param withPool: (bool) somewhat of a heuristic. Computes the pool size as simply the amount of bytes since
                         the function's code portion finished (endEA) until a new code head is detected
        :return:  Returns the size of the Function in bytes: EndEA - StartEA (if no pool selected, otherwise + pool)
        """
        raise(NotImplemented())
        if not withPool: return self.func.end_ea - self.func.start_ea
        try:
            return self._size
        except AttributeError:
            head = self.func.end_ea
            # while not idc.isCode(idc.GetFlags(head)):
            #     head += idc.get_item_size(head)
            self._size = head - self.func.start_ea
            return self._size

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


if __name__ == "__main__":
        print("beep")