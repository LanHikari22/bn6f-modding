##
# @ Author Lan
# This is just a template file for using the SlinkyEngine
##

import idaapi

from SlinkyEngine.Exporter import Exporter
from SlinkyEngine.Linker import Linker

idaapi.require('SlinkyEngine.Linker')
idaapi.require('SlinkyEngine.Exporter')


if __name__ == '__main__':
    exporter = Exporter(slinkySrcPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\asm\\',
                        dependenciesXPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\Build\\slinkydependencies.x',
                        dependenciesSPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\include\\slinkydependencies.s',
                        ldScriptPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\Build\\slinky.x')
    linker = Linker(exporter)
    # linker.linkFunction('object_subtract_hp')
    linker.linkFile('StartScreen')
    linker.linkFiles()
    linker.linkX()
