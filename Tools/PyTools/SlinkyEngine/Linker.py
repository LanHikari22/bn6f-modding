##
# @Author Lan
# This module is responsible for link operations within the slinky engine.
##
import idc

from SlinkyEngine.Exporter import Exporter
from SlinkyEngine.Extractor import Extractor


class Linker:
    def __init__(self, exporter):
        self.exporter = exporter
        self.asmLines = []
        self.dependencies = []
        pass

    def link(self):
        """
        Performs the complete linking, after specific objects have been queued to be linked
        :return: None
        """
        pass

    def linkFunction(self, func_name):
        ea = idc.get_name_ea(0, func_name)
        if ea == 0xFFFFFFFFL: raise Exception('invalid function name!')
        asmLines, dependencies = Extractor().extractFunction(ea)
        exporter.exportDependencies(dependencies)
        exporter.exportLinking([func_name], [ea])
        exporter.exportDisassembly(asmLines,func_name)

if __name__ == '__main__':
    exporter = Exporter(slinkySrcPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\src\\slinky\\',
                        dependenciesXPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\Build\\slinkydependencies.x',
                        dependenciesSPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\src\\slinkydependencies.s',
                        ldScriptPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\Build\\slinky.x')
    linker = Linker(exporter)
    linker.linkFunction('object_subtract_hp')
