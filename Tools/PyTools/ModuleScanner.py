##
# @Author Lan
# This module iterates through a region, or from a function startpoint, and
# checks both the xrefs to it, and the xrefs from it.
# If the function name is sub_<...>:
#   if all of the functions it calls have names like: <moduleName>_<...>
#   or if all of the functions that call it have names like: <moduleName>_<...>
# Then the curr function's name is modified from sub_<...> to <moduleName>_<...>
# If the function name doesn't start with sub_, then it is just front appended to:
# <ModuleName>_<NotSub>_<...>
##

from Function import *

class ModuleScanner:

    func_ea = None
    def __init__(self, func_ea):
        self.func_ea = func_ea

    def scanFunction(func_ea):
        func = Function(func_ea)

        """
        Performs module checking on one function only. No iteration.
        If all of its xrefs from, or all of its xrefs to conform to one module,
        its name is changed.
        """
