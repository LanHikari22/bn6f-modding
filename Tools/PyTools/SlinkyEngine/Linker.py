##
# @Author Lan
# This module is responsible for link operations within the slinky engine.
##
import idc
import idaapi

# import wingdbstub
# wingdbstub.Ensure()
idaapi.require('GameItems.GameFile')
idaapi.require('SlinkyEngine.Exporter')
idaapi.require('SlinkyEngine.Extractor')

from GameItems.GameFile import GameFile

from SlinkyEngine.Exporter import Exporter
from SlinkyEngine.Extractor import Extractor


class Linker:
    def __init__(self, exporter):
        self.exporter = exporter
        self.asmLines = []
        self.dependencies = []
        self.linkNames = []
        self.addresses = []
        pass

    def linkX(self):
        """
        Performs the complete linking, after specific objects have been queued to be linked
        :return: None
        """
        exporter.exportDependencies(list(set(self.dependencies)))
        exporter.exportLinking(self.linkNames, self.addresses)
        pass

    def linkRange(self, startEA, endEA, linkName=None, src=None, file=None, include=None):
        """
        Links and exports a .s file. By default, the name is range_<startEA>.s like range_8040000.s
        This can be overridden by specifying linkName.
        This also adds in the range section to link, and all of the depenencies to link for linkX() to operate on.
        :param startEA: Start Address of the range
        :param endEA: End address of the range
        :param linkName: Name of the file to be exported, and section as well
        :param src: The path of the file to be exported
        :param file: The file to write to, instead of completeling writing a new file
        :param include: whether to ip
        :return: None
        """
        if not linkName: linkName = 'range_%X' % startEA
        asmLines, dependencies = Extractor().extractRange(startEA, endEA)
        for d in dependencies: self.dependencies.append(d)
        self.linkNames.append(linkName)
        self.addresses.append(startEA)
        exporter.exportDisassembly(asmLines,linkName, src=src, file=file, include=include)


    def linkFunction(self, func_name, src=None, filename=None, file=None, include=None):
        ea = idc.get_name_ea(0, func_name)
        if ea == 0xFFFFFFFFL: raise Exception('invalid function name!')
        asmLines, dependencies = Extractor().extractFunction(ea)
        for d in dependencies: self.dependencies.append(d)
        self.linkNames.append(func_name)
        self.addresses.append(ea)
        exporter.exportDisassembly(asmLines,func_name, src=src, file=file, include=include)


    def linkFile(self, file_name, file=None, include=None):
        gamefile = GameFile(file_name)
        asmLines, dependencies = Extractor().extractFile(gamefile)
        for d in dependencies: self.dependencies.append(d)
        self.linkNames.append(gamefile.name)
        self.addresses.append(gamefile.start_ea)
        exporter.exportDisassembly(asmLines,gamefile.name)


    def linkModule(self, module_name):
        pass

    def linkFiles(self):
        pass

    def linkRemaining(self):
        raise Exception('Developing... 0%')


if __name__ == '__main__':
    exporter = Exporter(slinkySrcPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\asm\\',
                        dependenciesXPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\Build\\slinkydependencies.x',
                        dependenciesSPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\include\\slinkydependencies.s',
                        ldScriptPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\Build\\slinky.x')
    linker = Linker(exporter)
    linker.linkRange(0x08000000, 0x087FFFF0, linkName='rom.s')
    # linker.linkFunction('object_subtract_hp')
    # linker.linkFile('StartScreen')
    # linker.linkFiles()
    # linker.linkRemaining()
    linker.linkX()
