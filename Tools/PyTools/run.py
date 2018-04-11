import BinarySearcher
import GameFileDetector
from Command import c
from ModuleExport.ScriptFileWriter import ScriptFileWriter
from ModuleExport import ModuleExporter

import idaapi
idaapi.require('ModuleExport.ModuleExporter')


##
# To add a command to the run module:
# 1. Define the command (function to be executed): c.cmdName = YourModule.cmdFunc
# 2. your cmdFunc will be executed whenever run(c.cmdName) is executed.
# 3. It has to follow this prototype: (command, *args, **kwargs)
##


# defined commands
#
c.moduleFiles = GameFileDetector.moduleFiles
#
c.exportModules = ModuleExporter.__exportModules
#
c.fcmp = BinarySearcher.fcmp

def run(command, *args, **kwargs):
    """
    Executes an action based on the command passed, and potentially additional args
    :param command: command to be executed, check the cmd class
    :param args: arguments passed to a function associated with the command
    """
    if type(command) != type(c.test):
        raise TypeError("Invalid Command passed")
    return command(c(command), *args, **kwargs)

def cmds():
    """
    :return: List of commands, printed.
    """
    s = '['
    for n in vars(c).keys():
        if '__' not in n:
            s += n + ', '
    s += ']'
    print(s)


if __name__ == '__main__':
    run(c.test, 'beep beep!')