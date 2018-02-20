##
# @Author Lan
# This module is responsible for link operations within the slinky engine.
##
import idc

from GameItems.GameFile import GameFile
from SlinkyEngine.Exporter import Exporter
from SlinkyEngine.Extractor import Extractor


class Linker:
    def __init__(self, exporter):
        self.exporter = exporter
        self.asmLines = []
        self.dependencies = []
        self.names = []
        self.addresses = []
        pass

    def linkX(self):
        """
        Performs the complete linking, after specific objects have been queued to be linked
        :return: None
        """
        exporter.exportDependencies(list(set(self.dependencies)))
        exporter.exportLinking(self.names, self.addresses)
        pass

    def linkFunction(self, func_name):
        ea = idc.get_name_ea(0, func_name)
        if ea == 0xFFFFFFFFL: raise Exception('invalid function name!')
        asmLines, dependencies = Extractor().extractFunction(ea)
        for d in dependencies: self.dependencies.append(d)
        self.names.append(func_name)
        self.addresses.append(ea)
        exporter.exportDisassembly(asmLines,func_name)

    def linkFile(self, file_name):
        gamefile = GameFile(file_name)
        asmLines, dependencies = Extractor().extractFile(gamefile)
        for d in dependencies: self.dependencies.append(d)
        self.names.append(gamefile.name)
        self.addresses.append(gamefile.start_ea)
        exporter.exportDisassembly(asmLines,gamefile.name)


    def linkModule(self, module_name):
        pass

if __name__ == '__main__':
    exporter = Exporter(slinkySrcPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\src\\slinky\\',
                        dependenciesXPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\Build\\slinkydependencies.x',
                        dependenciesSPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\src\\slinkydependencies.s',
                        ldScriptPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\Build\\slinky.x')
    linker = Linker(exporter)
    linker.linkFunction('object_subtract_hp')
    linker.linkFile('StartScreen')
    linker.linkX()