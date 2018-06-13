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
import time

import idaapi

from IDAItems import Module

idaapi.require('Definitions.Paths')
from Definitions.Paths import ROM_PATH, IDATOOLS_PATH, OTHER_VERSION_BIN_PATH, OTHER_VERSION_DIR, VERSION_DIR, \
    DEFS_DIR

idaapi.require('Definitions.GameDefinitions')
from Definitions.GameDefinitions import GAME_MODULES

idaapi.require('ModuleDefExport.DefFileWriter')
from ModuleDefExport.DefFileWriter import ScriptFileWriter

idaapi.require('IDAItems.Module')


class VersionInputException(Exception):
    def __init__(self, str):
        super(str)

class ModuleDefExporter:

    # The folder name, and its symbol appearing in the header guards
    FOLDER_NAME = 'Definitions'
    FOLDER_HEADER = 'DEF'

    def __init__(self, scriptsDir, versionDir=None, otherVersionDir=None, otherVersionBinPath=None):
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
        self.ROMPath = ROM_PATH
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
            funcs_version, funcs_shared, funcs_unique = module.getVersionSegregatedModuleFuncs(self.otherVersionBinPath)

            # Write version dependent files
            if funcs_unique:
                # Write this version's script file...
                scriptFile_this = ScriptFileWriter(self.scriptsDir + self.versionDir, moduleName,
                                                '%s_%s_%s_H' % (ModuleDefExporter.FOLDER_HEADER,
                                                                self.versionDir[:-1].upper(), moduleName.upper()))

                # insert important includes in every script file header
                self.insertIncludes(scriptFile_this, version=self.versionDir[:-1])

                # Write function pointer macros UNIQUE to the primary version first...
                if funcs_unique: scriptFile_this.insertSegmentComment('VERSION UNIQUE')
                for func in funcs_unique:
                    scriptFile_this.insertFunction(func)

                # Write VERSION DEPENDENT  function pointer macros
                if funcs_version:
                    scriptFile_this.insertSegmentComment('VERSION DEPENDENT')
                    for func, otherVersion_func_ea in funcs_version:
                        scriptFile_this.insertFunction(func)

                # write the constructed header file
                scriptFile_this.write()

            # Not only this version is present? write the other also!
            if funcs_version:
                # Write the other version script file...
                scriptFile_other = ScriptFileWriter(self.scriptsDir + self.otherVersionDir, moduleName,
                                                '%s_%s_%s_H' % (ModuleDefExporter.FOLDER_HEADER,
                                                                self.otherVersionDir[:-1].upper(), moduleName.upper()))

                # Make sure to include important includes
                self.insertIncludes(scriptFile_other, version=self.otherVersionDir[:-1])

                # Write VERSION DEPENDENT function pointer macros
                if funcs_version:
                    for func, otherVersion_func_ea in funcs_version:
                        scriptFile_other.insertFunction(func, otherFunc_ea=otherVersion_func_ea)

                # Write the file!
                scriptFile_other.write()

            # Write the shared file now
            if funcs_shared:
                # construct writer for the shared header script file
                scriptFile_shared = ScriptFileWriter(self.scriptsDir, moduleName,
                                                '%s_%s_H' % (ModuleDefExporter.FOLDER_HEADER, moduleName.upper()))

                # Make sure to include important includes
                self.insertIncludes(scriptFile_shared)

                for func in funcs_shared:
                    scriptFile_shared.insertFunction(func)

                # write shared file to file!
                scriptFile_shared.write()

        else: # One version case? No problem!
            # construct writer for the shared header script file
            scriptFile = ScriptFileWriter(self.scriptsDir, moduleName,
                                                 '%s_%s_H' % (ModuleDefExporter.FOLDER_HEADER, self.moduleName.upper()))

            # Make sure to include important includes
            self.insertIncludes(scriptFile)

            for func in module.getModuleFunctions():
                scriptFile.insertFunction(func)

            # write shared file to file!
            scriptFile.write()

    def generateScriptsFile(self):
        """
        Generates the '_ScriptDefs.h' file that basically includes all exported modules!
        :param scriptsDir: (str) directory to export scripts to
        :param versionDir: (str) relative subdirectory of scriptsDir for the primary version (analyzed by this IDA DB)
        :param otherVersionDir: (str) relative subdirectory of scriptsDir for the other version
        :return: None
        """
        # Now update _ScriptDefs.h to include all modules
        _ScriptsFile = open(self.scriptsDir + '_%s.h' % ModuleDefExporter.FOLDER_NAME, 'w')
        _ScriptsFile.write(
            '#ifndef %s__%s_H\n#define %s__%s_H\n\n#include "../include/inttypes.h"\n'
            % (ModuleDefExporter.FOLDER_HEADER, ModuleDefExporter.FOLDER_HEADER,
               ModuleDefExporter.FOLDER_HEADER, ModuleDefExporter.FOLDER_HEADER))

        # Include shared files first
        fileName = '_%s.h' % ModuleDefExporter.FOLDER_NAME
        print("Generating '%s'..." % fileName)
        for file in os.listdir(self.scriptsDir):
            if fileName  not in file and os.path.isfile(self.scriptsDir + file):
                _ScriptsFile.write('#include "%s"\n' % file)
        # Include files from first version
        _ScriptsFile.write('\n\n#ifdef %s\n\n' % self.versionDir[:-1].upper())
        for file in os.listdir(self.scriptsDir + self.versionDir):
            _ScriptsFile.write('#include "%s"\n' % (self.versionDir[:-1] + '/' + file))
        _ScriptsFile.write('\n\n#endif // %s\n\n' % self.versionDir[:-1].upper())
        # Include files from second version
        _ScriptsFile.write('#ifdef %s\n\n' % self.otherVersionDir[:-1].upper())
        for file in os.listdir(self.scriptsDir + self.otherVersionDir):
            _ScriptsFile.write('#include "%s"\n' % (self.otherVersionDir[:-1] + '/' + file))
        _ScriptsFile.write('\n\n#endif // %s\n\n' % self.otherVersionDir[:-1].upper())

        _ScriptsFile.write('#endif // %s__%s_H' % (ModuleDefExporter.FOLDER_HEADER, ModuleDefExporter.FOLDER_HEADER))

        # Bye bye!
        _ScriptsFile.close()

    def deleteOldModules(self):
        """
        Deletes all of the files in the Scripts directory and version subdirectories, except for "Misc.h"
        :param scriptsDir: (str) directory to export scripts to
        :param versionDir: (str) relative subdirectory of scriptsDir for the primary version (analyzed by this IDA DB)
        :param otherVersionDir: (str) relative subdirectory of scriptsDir for the other version
        :return: None
        """
        # delete all of the files except for  Misc.h
        print('Deleting old Modules...')
        for folder in [self.scriptsDir, self.scriptsDir + self.versionDir, self.scriptsDir + self.otherVersionDir]:
            for file in os.listdir(folder):
                file_path = os.path.join(folder, file)
                try:
                    if os.path.isfile(file_path) and 'Misc.h' not in str(file_path):
                        print("Deleting Module '%s'..." % file)
                        os.unlink(file_path)
                        # elif os.path.isdir(file_path): shutil.rmtree(file_path)
                except Exception as e:
                    print(e)

    @staticmethod
    def insertIncludes(scriptFileWriter, version=None):
        """
        inserts into the script file necessary headers that are project-defined.
        :param scriptFileWriter: (ScriptFileWriter) writer to insert into
        :param version: (str) Optional. Included in header guard.
        """
        if version:
            includesLevel = '../../'
        else:
            includesLevel = '../'
        # needed for u8, u16, s32, etc...
        scriptFileWriter.insertInclude('"%sinclude/inttypes.h"' % includesLevel)
        # can be used to provide a clean interface
        scriptFileWriter.insertInclude('"%sConstants/_Constants.h"' % includesLevel)
        # data can be defined specified in structs
        scriptFileWriter.insertInclude('"%sStructs/_Structs.h"' % includesLevel)
        # for IDA's specifications
        scriptFileWriter.insertInclude('"%sinclude/IDADefinitions.h"' % includesLevel)


def exportModules(scriptsDir, versionDir, otherVersionDir, otherVersionBinPath):
    """
    exports all specified modules from IDA into the specified scriptsDir and version subdirectories
    and updates the '_Scripts.h' file to include all of the new module files!
    If the 'subs' module is included, it is assumed to be a full refresh, and old modules are deleted.

    :param mods: (list(str)) List of modules to be exported (should be everything, s
    :param scriptsDir: (str) directory to export scripts to
    :param versionDir: (str) relative subdirectory of scriptsDir for the primary version (analyzed by this IDA DB)
    :param otherVersionDir: (str) relative subdirectory of scriptsDir for the other version
    :param otherVersionBinPath: (str) Path to the ROM of the other version
    :return: None
    """

    exporter = ModuleDefExporter(scriptsDir, versionDir, otherVersionDir, otherVersionBinPath)

    # perform a full refresh
    exporter.deleteOldModules()

    print('Exporting Modules...')
    stopwatch = time.time()
    for mod in GAME_MODULES:
        print("Exporting Module '%s'..." % mod)
        exporter.exportScripts(mod)

    # Generate new '_ScriptDefs.h' file to link all of the exported modules together!
    exporter.generateScriptsFile()

    stopwatch = time.time() - stopwatch
    print("Exporting Complete! It took %d s" % int(stopwatch))

def __exportModules(cmd, *args, **kwargs):
    """

    :param cmd: not used. Python requires it. (sorry)
    :param args: Not used
    :param kwargs: Not used
    :return:
    """
    exportModules(DEFS_DIR, VERSION_DIR, OTHER_VERSION_DIR, OTHER_VERSION_BIN_PATH)


if __name__ == '__main__':
    __exportModules(None)
