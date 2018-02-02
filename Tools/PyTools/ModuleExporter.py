##
# @Author Lan
# This module is responsible for exporting 'modules' from the IDA Database into header files.
# For Scripts, Each module is exported into its own .h file, with C Macros defining the location of functions of the
# module so that they are accessible to C/asm injections through the linker.
#
# [Configuration]
# It is probably necessary to configure genScriptFile_HeaderStart and genScriptFile_HeaderEnd correctly.
# They include necessary headers to all script files, such as inttypes.h, for example.
#
# [Caveats]
# - One issue, is that the BinarySearcher introduces noise into its search. Seme functions are too small, they occur
# at different random places in binaries. It becomes almost impossible pinpointing them. This could reflect here.
# This wouldn't cause too much of an issue, but could introduce inaccuracies sometimes.
# - This doesn't necessarily CATCH everything. Sometimes, the functions themselves are modified in content between
# versions, making them not detectable using this method in the other version.
# - IDA is weird sometimes and introduces outright illegal keywords like _spoils<R1, R2> etc. TODO deal with this!
##

import os

from GameItems import Module


class VersionInputException(Exception):
    def __init__(self, str):
        super(str)

class ScriptExportElement:
    def __init__(self, func, otherFunc_ea=None):
        """
        This takes a function and creates a C function and converts it to a C Macro Function pointer,
        and comments.
        Simple print, or use __str__() to get the output of the conversion.
        :param func: (Function.Function) the function to be converted
        :param otherFunc_ea: If not None, this address replaces the original from func in the macro!
        """
        try:
            self.macro = func.getFuncPtrCMacro()
            if otherFunc_ea:
                self.macro = self.macro.replace('0x%08X' % func.func_ea, '0x%08X' % otherFunc_ea)
                self.macro = self.macro.replace('%07X' % func.func_ea, '%07X' % otherFunc_ea) # in case of names containing their own func_ea
            self.cmt = func.getComment()
        except Exception:
            print("Couldn't decompile: 0x%08X (I think) Sorry about that." % func.getName())

    def __str__(self):
        if self.cmt:
            output = '/**\n' + self.cmt + '\n*/\n' + self.macro
        else:
            output = self.macro
        return output

class ModuleExporter:

    def __init__(self, scriptsDir, versionDir=None, otherVersionDir=None, ROMPath=None, otherVersionBinPath=None):
        """

        :param scriptsDir: Directory to update/export Function modules to
        :param versionDir: If the game is split into multiple versions, then this specifies the sub directory relative
                            to scriptDir where module code unique to that version is placed!
        :param otherVersionBinPath: If versionDir != None, then this shouldn't be too. The other version must be
                                    specified so that it is compared against.
        """
        self.scriptsDir = scriptsDir
        self.versionDir = versionDir
        self.otherVersionDir = otherVersionDir
        self.ROMPath = ROMPath
        self.otherVersionBinPath = otherVersionBinPath
        if not ((self.versionDir and self.otherVersionDir and self.ROMPath and self.otherVersionBinPath )
                 or (not self.versionDir and not self.otherVersionDir and not self.ROMPath and not self.otherVersionBinPath)):
            raise VersionInputException("For 2 versions mode: relative directories for each and " +
                                        "paths to the curr version and other version binaries must be passed")

    def exportScripts(self, moduleName):
        """
        Exports all functions that begin with '<moduleName>_' to a file called moduleName.h in the scriptsDir.
        If the file exists already, it is overwritten.
        :param moduleName: (str) Name of the module to export the functions from.
        :return: None
        """

        # Retrieve the module from the database
        module = Module.Module(moduleName)

        if self.versionDir:

            # Retrieve list of functions to write for: This version, and the shared version
            funcs_version, funcs_shared, funcs_unique = module.getVersionSegregatedModuleFuncs(self.ROMPath, self.otherVersionBinPath)

            # Write version dependent files
            if funcs_unique:
                # Open this version file
                scriptFile_this = open(self.scriptsDir + self.versionDir + moduleName + '.h', 'w')
                # Generate the header file
                # self.versionDir[-1] simply removes the \ at the end of the relative path to get the version name >.<
                scriptFile_this.write(self.genScriptFile_HeaderStart(moduleName, version=self.versionDir[:-1]) + '\n\n')
                # Write function pointer macros UNIQUE to the primary version first...
                for func in funcs_unique:
                    scriptFile_this.write(str(ScriptExportElement(func)) + '\n')
                if funcs_unique: scriptFile_this.write('\n')
                # Write VERSION DEPENDENT  function pointer macros
                if funcs_version:
                    for func, otherVersion_func_ea in funcs_version:
                        scriptFile_this.write(str(ScriptExportElement(func)) + '\n')
                # Whew, done! Write the ends of the headers
                scriptFile_this.write('\n\n' + self.genScriptFile_HeaderEnd(moduleName, version=self.versionDir[:-1]))
                # Bye bye!
                scriptFile_this.close()

            # Not only this version is present? write the other also!
            if funcs_version:
                # Open the other version file
                scriptFile_other = open(self.scriptsDir + self.otherVersionDir + moduleName + '.h', 'w')
                # Generate the header file
                # self.otherVersionDir[-1] simply removes the \ at the end of the relative path to get the version name >.<
                scriptFile_other.write(self.genScriptFile_HeaderStart(moduleName, version=self.otherVersionDir[:-1]) + '\n\n')
                # Write VERSION DEPENDENT  function pointer macros
                if funcs_version:
                    for func, otherVersion_func_ea in funcs_version:
                        scriptFile_other.write(str(ScriptExportElement(func, otherFunc_ea=otherVersion_func_ea)) + '\n')
                # Whew, done! Write the ends of the headers
                scriptFile_other.write('\n\n' + self.genScriptFile_HeaderEnd(moduleName, version=self.otherVersionDir[:-1]))
                # Bye bye!
                scriptFile_other.close()

            # Write the shared file now
            if funcs_shared:
                scriptFile_shared = open(self.scriptsDir + moduleName + '.h', 'w')
                # Generate the file
                scriptFile_shared.write(self.genScriptFile_HeaderStart(moduleName) + '\n\n')
                for func in funcs_shared:
                    scriptFile_shared.write(str(ScriptExportElement(func)) + '\n')
                scriptFile_shared.write('\n\n' + self.genScriptFile_HeaderEnd(moduleName))
                # Bye bye!
                scriptFile_shared.close()

        else: # One version case? No problem!
            # Find the file in the scriptDir
            scriptFile = open(self.scriptsDir + moduleName + '.h', 'w')
            # Generate the file
            scriptFile.write(self.genScriptFile_HeaderStart(moduleName) + '\n\n')
            for func in module.getModuleFunctions():
                scriptFile.write(str(ScriptExportElement(func)) + '\n')
            scriptFile.write('\n\n' + self.genScriptFile_HeaderEnd(moduleName))
            # Bye bye!
            scriptFile.close()

    def updateScripts(self, moduleName):
        """
        Exports all functions that begin with '<moduleName>_' to a file called moduleName.h in the scriptsDir.
        If the file exists already, its contents are only updated with the exported contents.
        :param moduleName: (str) Name of the module to export the functions from.
        :return: None
        """
        raise Exception('Feature not implemented. Sorry!')

    @staticmethod
    def genScriptFile_HeaderStart(moduleName, version=None):
        """
        This defines the string to be written at the start of a module script header file.
        This includes inttype.h into the script file so that it could process types.
        Version is an optional parameter, if it is specified, it is included in the header guard.
        :param moduleName: (str) the module name
        :param version: (str) Optional. Included in header guard.
        :return: (str) the string to write at the start of a script module header file (ex. Battle.h)
        """
        if version:
            headerLabel = 'SCRIPT_%s_%s_H' % (version.upper(), moduleName.upper())
            includesLevel = '../../'
        else:
            headerLabel = 'SCRIPT_%s_H' % (moduleName.upper())
            includesLevel = '../'
        output =  "#ifndef %s\n#define %s" % (headerLabel, headerLabel) + \
               "\n\n#include \"%sinclude/inttypes.h\"" % includesLevel + \
                 "\n#include \"%sConstants/_Constants.h\"" % includesLevel + \
                 "\n#include \"%sStructs/_Structs.h\"" % includesLevel + \
                 "\n#include \"%sinclude/IDADefinitions.h\"" % includesLevel
        return output

    @staticmethod
    def genScriptFile_HeaderEnd(moduleName, version=None):
        """
        This defines the string to be written at the start of a module script header file.
        Version is an optional parameter, if it is specified, it is included in the header guard comment
        :param moduleName: (str) the module name
        :return: (str) the strin to be written at the end of a script module header file (ex. Battle.h)
        """
        if version:
            headerLabel = 'SCRIPT_%s_%s_H' % (version.upper(), moduleName.upper())
        else:
            headerLabel = 'SCRIPT_%s_H' % (moduleName.upper())
        output = '#endif // %s' % (headerLabel)
        return output

def deleteOldModules(scriptsDir, versionDir, otherVersionDir):
    """
    Deletes all of the files in the Scripts directory and version subdirectories, except for "Misc.h"
    :param scriptsDir: (str) directory to export scripts to
    :param versionDir: (str) relative subdirectory of scriptsDir for the primary version (analyzed by this IDA DB)
    :param otherVersionDir: (str) relative subdirectory of scriptsDir for the other version
    :return: None
    """
    # delete all of the files except for  Misc.h
    print('Deleting old Modules...')
    for folder in [scriptsDir, scriptsDir + versionDir, scriptsDir + otherVersionDir]:
        for file in os.listdir(folder):
            file_path = os.path.join(folder, file)
            try:
                if os.path.isfile(file_path) and 'Misc.h' not in str(file_path):
                    print("Deleting Module '%s'..." % file)
                    os.unlink(file_path)
                    # elif os.path.isdir(file_path): shutil.rmtree(file_path)
            except Exception as e:
                print(e)

def generate_ScriptsFile(scriptsDir, versionDir, otherVersionDir):
    """
    Generates the '_Scripts.h' file that basically includes all exported modules!
    :param scriptsDir: (str) directory to export scripts to
    :param versionDir: (str) relative subdirectory of scriptsDir for the primary version (analyzed by this IDA DB)
    :param otherVersionDir: (str) relative subdirectory of scriptsDir for the other version
    :return: None
    """
    # Now update _Scripts.h to include all modules
    _ScriptsFile = open(scriptsDir + '_Scripts.h', 'w')
    _ScriptsFile.write('#ifndef SCRIPTS__SCRIPTS_H\n#define SCRIPTS__SCRIPTS_H\n\n#include "../include/inttypes.h"\n')

    # Include shared files first
    print("Generating '_Scripts.h'...")
    for file in os.listdir(scriptsDir):
        if '_Scripts.h' not in file and os.path.isfile(scriptsDir + file):
            _ScriptsFile.write('#include "%s"\n' % file)
    # Include files from first version
    _ScriptsFile.write('\n\n#ifdef %s\n\n' % versionDir[:-1].upper())
    for file in os.listdir(scriptsDir + versionDir):
        _ScriptsFile.write('#include "%s"\n' % (versionDir[:-1] + '/' + file))
    _ScriptsFile.write('\n\n#endif // %s\n\n' % versionDir[:-1].upper())
    # Include files from second version
    _ScriptsFile.write('#ifdef %s\n\n' % otherVersionDir[:-1].upper())
    for file in os.listdir(scriptsDir + otherVersionDir):
        _ScriptsFile.write('#include "%s"\n' % (otherVersionDir[:-1] + '/' + file))
    _ScriptsFile.write('\n\n#endif // %s\n\n' % otherVersionDir[:-1].upper())

    _ScriptsFile.write('#endif // SCRIPTS__SCRIPTS_H')

    # Bye bye!
    _ScriptsFile.close()


def exportModules(mods, scriptsDir, versionDir, otherVersionDir, ROMPath, otherVersionBinPath):
    """
    exports all specified modules from IDA into the specified scriptsDir and version subdirectories
    and updates the '_Scripts.h' file to include all of the new module files!
    If the 'subs' module is included, it is assumed to be a full refresh, and old modules are deleted.

    :param mods: (list(str)) List of modules to be exported (should be everything, s
    :param scriptsDir: (str) directory to export scripts to
    :param versionDir: (str) relative subdirectory of scriptsDir for the primary version (analyzed by this IDA DB)
    :param otherVersionDir: (str) relative subdirectory of scriptsDir for the other version
    :param ROMPath: (str) Path to a ROM with content identical to the one analyzed by this IDA DB
    :param otherVersionBinPath: (str) Path to the ROM of the other version
    :return: None
    """
    import time

    # if subs is included, perform a full refresh
    if 'sub' in mods:
        deleteOldModules(scriptsDir, versionDir, otherVersionDir)

    print('Exporting Modules...')
    stopwatch = time.time()
    for mod in mods:
        print("Exporting Module '%s'..." % mod)
        exporter = ModuleExporter(scriptsDir, versionDir, otherVersionDir, ROMPath, otherVersionBinPath)
        exporter.exportScripts(mod)

    # Generate new '_Scripts.h' file to link all of the exported modules together!
    generate_ScriptsFile(scriptsDir, versionDir, otherVersionDir)

    stopwatch = time.time() - stopwatch
    print("Exporting Complete! It took %d s" % int(stopwatch))

if __name__ == '__main__':
    mods = ['main', 'Battle', 'BattleMenu', 'Chatbox', 'Load', 'Memory', 'MenuControl', 'NCP',
            'reqBBS', 'Save', 'Startscreen', 'subsystem', 'Bios', 'NPC', 'object', 'Sound', 'sprite', 'libc',
            'engine', 'check', 'render', 'cb', 'uncomp']
    # mods.append('sub')
    mods.append('invalid_modules_dont_generate_junk!')

    scriptsDir = 'C:\\Users\\alzakariyamq\Documents\\Game Modding\\mods\\MMBN6\\Scripts\\'
    versionDir = 'Falzar\\'; otherVersionDir = 'Gregar\\'
    ROMPath = 'C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\mmbn6f.gba'
    otherVersionBinPath = 'C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\mmbn6g.gba'

    # deleteOldModules(scriptsDir, versionDir, otherVersionDir)
    exportModules(mods, scriptsDir, versionDir, otherVersionDir, ROMPath, otherVersionBinPath)

