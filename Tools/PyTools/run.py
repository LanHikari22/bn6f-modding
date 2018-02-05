import GameFileDetector
import ModuleExporter
import BinarySearcher

from Command import c


# defined commands
c.moduleFiles = GameFileDetector.moduleFiles
c.exportModules = ModuleExporter.__exportModules
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