##
# @Author Lan
# This module handles the parsing and execution of Slinky script! (*.slx)
##
# from SlinkyEngine.Exporter import Exporter
# from SlinkyEngine.Linker import Linker


class Interpreter:
    def __init__(self, slinkySrcPath, dependenciesXPath, dependenciesSPath, ldScriptPath):
        self.src = slinkySrcPath
        self.xPath = dependenciesXPath
        self.sPath = dependenciesSPath
        self.lPath = ldScriptPath

    def interpret(self, instruction):
        """
        Interpretes a slinky instruction and executes it
        :param instruction: a slinky instruction compatible with slinky script
        :return: None
        """
        raise Exception('Under development... 0%')


    def link(self, startEA, endEA, path=None, filename=None):
        raise Exception('Under development... 0%')

    def linkfunction(self, funcName, path=None, filename=None):
        raise Exception('Under development... 0%')

    def linkfile(self, fileName, path=None, filename=None):
        raise Exception('Under development... 0%')

    def setVariable(self, variableName, variableValue):
        raise Exception('Under development... 0%')

    # This inner class is responsible for parsing any one line. All relevent data about any line is in it.
    # Instructions can take many lines, this will make handling them easier
    class Line:
        def __init__(self, lineStr):
            raise Exception('Under development... 0%')



if __name__ == '__main__':
    inter = Interpreter(slinkySrcPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\asm\\',
                        dependenciesXPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\Build\\slinkydependencies.x',
                        dependenciesSPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\include\\slinkydependencies.s',
                        ldScriptPath='C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\Build\\slinky.x')
    inter.interpret('linkfunction(StartScreen, /* name of file to link */'
                     '             path="C:\\Users\\alzakariyamq\\Documents\\Game Modding\\mods\\MMBN6\\asm\\";')
