##
# @Author Lan
# This module is responsible for exporting 'modules' from the IDA Database into header files.
# For Scripts, Each module is exported into its own .h file, with C Macros defining the location of functions of the
# module so that they are accessible to C/asm injections through the linker.
#
# [Configuration]
# It is probably necessary to configure genScriptFile_HeaderStart and genScriptFile_HeaderEnd correctly.
# They include necessary headers to all script files, such as inttypes.h, for example.
##

import Function
import Module


class ScriptExportElement:
    def __init__(self, func):
        """
        This takes a function and creates a C function and converts it to a C Macro Function pointer,
        and comments.
        Simple print, or use __str__() to get the output of the conversion.
        :param func: (Function.Function) the function to be converted
        """
        self.macro = func.getFuncPtrCMacro()
        self.cmt = func.getComment()

    def __str__(self):
        if self.cmt:
            output = '/**\n' + self.cmt + '\n*/\n' + self.macro
        else:
            output = self.macro
        return output


class ModuleExporter:

    def __init__(self, scriptsDir):
        """

        :param scriptsDir: Directory to update/export Function modules to
        """
        self.scriptsDir = scriptsDir

    def exportScripts(self, moduleName):
        """
        Exports all functions that begin with '<moduleName>_' to a file called moduleName.h in the scriptsDir.
        If the file exists already, it is overwritten.
        :param moduleName: (str) Name of the module to export the functions from.
        :return: None
        """
        # Find the file in the scriptDir
        scriptFile = open(self.scriptsDir + moduleName + '.h', 'w')
        # Retrieve the module from the database
        module = Module.Module(moduleName)
        # Generate the file
        scriptFile.write(self.genScriptFile_HeaderStart(moduleName) + '\n\n')
        for func in module.getModuleFunctions():
            scriptFile.write(str(ScriptExportElement(func)) + '\n')
        scriptFile.write('\n\n' + self.genScriptFile_HeaderEnd(moduleName))

    def updateScripts(self, moduleName):
        """
        Exports all functions that begin with '<moduleName>_' to a file called moduleName.h in the scriptsDir.
        If the file exists already, its contents are only updated with the exported contents.
        :param moduleName: (str) Name of the module to export the functions from.
        :return: None
        """
        pass

    @staticmethod
    def genScriptFile_HeaderStart(moduleName):
        """
        This defines the string to be written at the start of a module script header file.
        This includes inttype.h into the script file so that it could process types.
        :param moduleName: (str) the module name
        :return: (str) the string to write at the start of a script module header file (ex. Battle.h)
        """
        return "#ifndef SCRIPT_%s_H\n#define SCRIPT_%s_H" % (moduleName.upper(), moduleName.upper()) + \
               "\n\n#include \"../include/inttypes.h\"" + \
                 "\n#include \"../include/IDADefinitions.h\""

    @staticmethod
    def genScriptFile_HeaderEnd(moduleName):
        """
        This defines the string to be written at the start of a module script header file.
        :param moduleName: (str) the module name
        :return: (str) the strin to be written at the end of a script module header file (ex. Battle.h)
        """
        return "#endif // SCRIPT_%s_H" % (moduleName.upper())

if __name__ == '__main__':
    exporter = ModuleExporter(scriptsDir='C:\\Users\\alzakariyamq\\Desktop\\Analysis\\')
    exporter.exportScripts('Battle')