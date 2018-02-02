import idaapi
import idc

class Head:
    pass

    # Name -------------------------------------------------------------------------------------------------------------

    def ongoing_getName(self):
        return idaapi.get_func_name(self.func_ea)

    def setName(self, name):
        idc.MakeName(self.head_ea, name)

    # Xrefs ------------------------------------------------------------------------------------------------------------

    def ongoing_getXRefsTo(self):
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

    def ongoing_getComment(self):
        """
        TODO: Sometimes the comment is repeatable (created through decomp) or not (created through disass).
        What to return???? Why not whichever works?
        """
        cmt = idc.get_func_cmt(self.func_ea, 1)
        if not cmt: cmt = idc.get_func_cmt(self.func_ea, 0)
        return cmt

    def ongoing_setComment(self, cmt):
        """
        TODO: repeatable or not???
        :param cmt: Comment to be set as a function comment
        :return:
        """
        idaapi.set_func_cmt(self.func, cmt, 1)
