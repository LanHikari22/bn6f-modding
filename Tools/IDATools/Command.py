
def testfunc(cmd, *args):
    print(args[0])


class c:
    # todo: well... this is hacky!
    """
    Defined commands for the run module. Due to recursive dependencies, the object and base functionality
    is extracted out into its own module, but the commands are added to it in the run module.
    """
    test = testfunc

    def __init__(self, thisCmd):
        self.this = thisCmd

    def __iscmd(self, cmd):
        first = str(type(self.this))
        first = first[first.index('c.'):]
        first = first[0:first.index(' ')]
        print(first)
        second = str(type(self.this))
        second = second[second.index('c.'):]
        second = second[0:second.index(' ')]
        print(second)

        return first == second
