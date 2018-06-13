# @Author Lan
# This module is reponsibile for providing the utility to write a script header file, and insert content into it.

class ScriptFileWriter:
    def __init__(self, path, filename, headerguard):
        """
        :param path: (str) Path to write file
        :param filename: (str) the name of the file
        :param headerguard: (str) label to be used in #ifdef and #endif
        """
        self.path = path
        self.filename = filename
        self.headerContent = ''
        self.headerGuard = '#ifndef %s\n#define %s\n\n' % (headerguard, headerguard)
        self.endHeaderGuard = '\n#endif // %s\n' % headerguard
        self.includes = ''
        self.content = ''

    def write(self):
        """
        Writes the constructed file to the path specified
        :return: none
        """
        f = open(self.path + self.filename + '.h', 'w')
        if type(self.headerContent) == str and self.headerContent != '':
            f.write(self.headerContent + '\n')
        f.write(self.headerGuard)
        if self.includes: f.write(self.includes + '\n')
        f.write(self.content)
        f.write(self.endHeaderGuard)
        f.close()

    def setHeader(self, headerText):
        """
        :param header: (str) text to be set as the start
        :return: none
        """
        self.headerContent = headerText

    def insertInclude(self, includePath):
        """
        :param includePath: (str) path to be included. Should be enclosed in "" or <>. Otherwise assuming ""
        :return: none
        """
        if includePath[0] == '"' or includePath[0] == '<':
            self.includes += '#include ' + includePath + '\n'
        else:
            self.includes += '#include ' + '"' + includePath + '"' + '\n'

    def insertSegmentComment(self, segName):
        """
        This is used to segregate definitions.
        '
        // SegA
        DefA1...
        DefA2...

        // SegB
        DefB1...
        DefB2...'

        :param segName: name of the new segment to be inserted
        :return:
        """
        # FileA --------------------------------------------------
        self.content += ('\n// %s' % segName) + ' ' + '-'*(50 - len(segName)) + '\n'

    def insertFunction(self, func, otherFunc_ea=None):
        """
        This takes a function and creates a C function and converts it to a C Macro Function pointer,
        and comments.
        After parsing the prototype, it's inserted into the contents
        :param func: (Function.Function) the function to be parsed and inserted
        :param otherFunc_ea: If not None, this address replaces the original from func in the macro!
        """
        cmt = func.getComment()
        macro = func.getFuncPtrCMacro()
        if otherFunc_ea:
            macro = macro.replace('0x%08X' % func.func_ea, '0x%08X' % otherFunc_ea)
            macro = macro.replace('%07X' % func.func_ea,
                                            '%07X' % otherFunc_ea)  # in case of names containing their own func_ea
        output = macro
        tempCmt = '// '
        if cmt:
            cmt = self._formatComment(cmt)
            output = cmt + '\n' + macro
        # write to contents
        self.content += output + '\n\n'


    def insertFile(self, gamefile):
        """
        :param gamefile:
        :return:
        """
        pass

    @staticmethod
    def _formatComment(cmt):
        # type: (str) -> str
        """
        Puts '//' at the beginning of every line in the comment
        :param cmt: the comment to be formatted
        :return: the new formatted comment
        """
        output = '// '
        for c in cmt:
            if c == '\n':
                c = '\n// '
            output += c
        return output

        