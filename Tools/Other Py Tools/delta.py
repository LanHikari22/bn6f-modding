from idautils import *
from idaapi import *
from ida_hexrays import *

def main():
    global x
    ea = 0x800068AL
    # get curr function
    func = idaapi.get_func(ea)
    cfunc = decompile(func)
    #
    lv = cfunc.get_lvars()
    cti = cfunc.treeitems

    x = cti
    print(x)

    # Find the r10 variable...
    r10 = getFuncLVarByRegNum(cfunc, 10)
    r10.name = "PLS"
    r10.cmt = "PLEAAAASE"

    tl = idaapi.treeloc_t()
    tl.ea = r10.defea
    tl.itp = idaapi.ITP_EMPTY
    cfunc.set_user_cmt(tl, "Please...")
    cfunc.save_user_cmts()


    # r10_info = lvar_saved_info_t()
    # r10_info.ll = r10
    # r10_info.name = "sChief"
    # r10_info.size = 4
    # lvinf = lvar_uservec_t

    # print(r10.name)

    # x.set_user_name()

    # tl = idaapi.treeloc_t()
    # tl.ea = r10.defea
    # tl.itp = idaapi.ITP_SEMI
    # cfunc.set_user_cmt(tl, "PLEASE")
    # cfunc.save_user_cmts()


    # Pls save everything, whatever it is
    cfunc.save_user_labels()
    cfunc.save_user_cmts()
    cfunc.save_user_numforms()
    cfunc.save_user_iflags()
    cfunc.save_user_unions()

    # modify_user_lvars(ea, lv)
    # print(x.name)

def getLVarRegNum(lv):
    """
    Returns the variable's register number.
    I don't know why it involves such a weird formula
    """
    return lv.get_regnum()/4 - 2
def getFuncLVarByRegNum(cfunc, regNum):
    """
    Returns the first encountered local variable using
    the specified regNum in the specified function, or None
    """
    lvs = cfunc.get_lvars()
    output = None
    i = 0
    while i < lvs.size():
        lv = lvs.at(i)
        if getLVarRegNum(lv) == regNum:
            output = lv
            break
        i += 1
    return output
def getFuncLVarByName(cfunc, lvName):
    """
    Returns lvar_t given a Cfunc (decompiled func), and an lvar Name
    """
    lvs = cfunc.get_lvars()

    output = None
    i = 0
    while i < lvs.size():
        lv = lvs.at(i)
        if lv.name and lv.name == lvName:
            output = lv
            break
        i += 1
    return output

def setCurrFuncName(funcName):
    func = get_func(here())


def modifyUserDefinedLVar(func_ea, oldVarName, newVarName):
    """
    This variable must be user modified in order for it to be
    renamable. Otherwise, it won't be detected.
    """
    lvinf = lvar_uservec_t()
    if restore_user_lvar_settings(lvinf, func_ea):
            for lv in lvinf.lvvec:
                if lv.name and lv.name == oldVarName:
                    lv.name = newVarName
                print "changed Lvar name at %x" % (lv.ll.defea, )
            save_user_lvar_settings(func_ea, lvinf)




def enumerateCrossReferences():
    """
    This finds all functions called by the function provided at
    the cursor.
    """
    # from idaapi import *
    func = get_func(here())
    if not func is None:
        fname = Name(func.startEA)
        items = FuncItems(func.startEA)
        for i in items:
            for xref in XrefsFrom(i, 0):
                if xref.type == fl_CN or xref.type == fl_CF:
                    Message("%s calls %s from %x\n" % (fname,  Name(xref.to), i))
                else:
                    Warning("No function found at location %x" % here())

def getKnownFunctions():
    """
    Returns all functions that don't begin with 'sub_' in the currSegment
    """
    # Segment's starting address
    ea = ScreenEA()

    output = {}
    for function_ea in Functions(SegStart(ea), SegEnd(ea)):
        if "sub" not in GetFunctionName(function_ea):
            output[function_ea] = GetFunctionName(function_ea)
    return output

def walkInstructions():
    # for each segment
    for seg_ea in Segments():
        # for each of the defined elements
        for head in Heads(seg_ea, SegEnd(seg_ea)):
            # If it's a instruction
            if isCode(GetFlags(head)):
                # Get the Disasm and print it
                disasm = GetDisasm(head)
                print(disasm)

def searchFunctionCalls():
    #     from idautils import *
    seg_ea = SegByName("ROM") # Doesn't work, for some reason?
    seg_ea = 0x08000000

    # For each instruction
    for addr in Heads(seg_ea, SegEnd(seg_ea)):
        # Get disassembly
        disasmStr = GetDisasm(addr)

        if disasmStr.startswith("BL"):
            # Print if it is a function call
            print("0x%08X [%s]" % (addr, disasmStr))

def getCurrCFunc():
    """
    Returns an object representing the C function at the current screen ea,
    if available.
    """
    # import idaapi
    f = idaapi.get_func(get_screen_ea())
    if f is None:
        raise(Exception("This isn't a function..."))
        return None

    cfunc = decompile(f)
    if f is None:
        raise(Exception("Can't decompile this function..."))
        return None

    return cfunc

def displayUserDefinedLocalVariableInformation():
    # get entry_ea
    cfunc = getCurrCFunc()
    entry_ea = cfunc.entry_ea

    # get the local variables, and display information
    lvinf = idaapi.lvar_uservec_t()
    if idaapi.restore_user_lvar_settings(lvinf, entry_ea):
        print "------- User defined local variable information\n"
        for lv in lvinf.lvvec:
            print "Lvar defined at %x" % (lv.ll.defea, )

            if len(str(lv.name)):
                print " Name: %s" % (str(lv.name), )

            if len(str(lv.type)):
                print " Type: %s" % (str(lv.type), )

            if len(str(lv.cmt)):
                print " Comment: %s" % (str(lv.cmt), )

    return

def defineChiefStructInFunction(funcAddr):
    """
    If an r10 variable is detected, it's given the type "ChiefStruct*"
    and its name is changes to "sChief"
    """


if __name__ == "__main__":
    main()
    # displayUserDefinedLocalVariableInformation()
    # cfunc = getCurrCFunc()
    # print(type(cfunc))
    # var = cfunc.get_lvars().find(0);
    # print(type(var))
