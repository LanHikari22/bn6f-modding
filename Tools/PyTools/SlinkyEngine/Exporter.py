##
# @Author Lan
# This will be responsible for File IO for the SlinkyEngine!
# Different kinds of things are to be exported:
# dependencies.x, dependencies.s, the various *.s files in the Slinky src folder.
# **Note** that for Dependencies, the files are completely overwritten. So if different files are being linked, their
# dependencies must be combined and linked at once. The disassemblies can be linked individually, however
##

class Exporter:
    def __init__(self, slinkySrcPath, dependenciesXPath, dependenciesSPath, ldScriptPath):
        self.src = slinkySrcPath
        self.xPath = dependenciesXPath
        self.sPath = dependenciesSPath
        self.lPath = ldScriptPath


    def exportDisassembly(self, asmLines, filename, src=None, file=None, include=True):
        """

        :param asmLines: the disassembly to be dumped in the file, basically
        :param filename: the file to have the disassembly being dumped into. BASICALLY! (don't include extension)
        :param src: If not input, default path given in __init__ is used
        :param file: a file object to write to. By default, exportDisassembly will open/close its own file.
                     this allows for writing to a file, without completely overwriting it.
        :param include: if True: '.include "slinkydepenencies.s" is written. Needed at start of file.
        :return: None
        """
        if not src: src = self.src
        f = not file and open(src + filename + '.s', 'w') or file

        # include depenencies.s so that the file is operational, as well as assembly for the linker script and stuff
        if include: f.write('.include "slinkydependencies.s"\n\n')

        # Write disassembly
        f.write('.thumb\n.section .l__%s, "ax"\n' % (filename))
        for asmLine in asmLines:
            if asmLine.isFunctionStart:
                f.write('\n')
            if not asmLine.isFunctionStart and asmLine.withinFunction and asmLine.hasLabel:
                f.write(' ')
            f.write(str(asmLine) + '\n')
        if not file: f.close()

    def exportLinking(self, names, addresses):
        """
        All individually linked objects such as functions or files have to be linked in the proper place
        :param names: Names of all slinky files to be linked
        :param addresses: Starting address of each file
        :return: None
        """
        l = open(self.lPath, 'w')
        for i in range(len(names)):
            l.write('. = 0x%08X;\n.l__%s : {*.o(.l__%s)}\n' % (addresses[i], names[i], names[i]))
        l.close()

    def exportDependencies(self, dependencies):
        """
        Simply overwrites the files dependencies.s and dependencies.x with label definitions and appropriate ldscript
        for each dependency
        :param dependencies: list(Dependency) a list of dependencies the disassembly to be exported relies on
        :param exportMacros: (bool) macroized instructions, and other things used by the IDA disassembler will be exported
        :return: None
        """
        s = open(self.sPath, 'w')
        x = open(self.xPath, 'w')

        for d in dependencies:
            # export dependency.s
            s.write(d.getLabelDefinition() + '\n')
            # export dependency.x
            x.write(d.getLdScript() + '\n')
        s.close()
        x.close()