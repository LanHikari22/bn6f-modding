##
# @Author Lan
# This represents the concept of modulized functions/data. A set of functions may be related, or were belonging to
# A single file or set of files when compiled together. That is one example of a Module. This 'Module' module will
# define operations to be done on a whole module!
##
import idautils
import idc_bc695

import Function


class Module:

    def __init__(self, moduleName):
        """
        Creates a module with the name moduleName. This could be exported from the database, or it could be a new
        module to include in the database!
        :param moduleName:  The name of the module
        """
        self.name = moduleName

    def getModuleFunctions(self):
        """
        This traverses all segments, and all defined modules to retrieve all functions with that module name.
        :return: a list of Functions that are in this module, saved in the database.
        """
        output = []
        for seg_ea in idautils.Segments():
            for func_ea in idautils.Functions(idc_bc695.SegStart(seg_ea), idc_bc695.SegEnd(seg_ea)):
                func = Function.Function(func_ea)
                # if the function starts with '<moduleName>_'...
                if len(func.getName())>len(self.name)+1 and func.getName()[0:len(self.name)+1]==(self.name + '_'):
                    output.append(func)
        return output