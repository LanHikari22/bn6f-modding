import re
import sys

SPACES_PER_TAB = 4      # Because this program is sensitive to tabbing, this conversion is necessary

class DataRecord:

    class Entry:
        """
        Counts as one entry in the DataRecord
        """

        validEntry: bool
        Address: int
        Type: str
        Variable: str
        Docs: str

        def __init__(self, entryLine):
            """
            Parses the data from the entryline into this object
            :param entryLine: A string containing the entry in question, padded with arbitrary spaces
            """
            if not entryLine:
                self.validEntry = False
                return

            args = list(filter(None, re.split("[ \t\n]", entryLine)))

            if len(args) == 0:
                self.validEntry = False
                return

            try:
                self.Address = int(args[0], 16)
                self.Type = args[1]
                self.Variable = args[2]
                self.Docs = ''
                self.validEntry = True
            except ValueError:
                self.validEntry = False

    entries: list

    def __init__(self, dataRecordFile):
        """
        This parses the data record found in the path into this object.
        :param dataRecordFile: A string to the file containing the data record
        """
        inputFile = open(dataRecordFile, "r")
        self.entries = []
        mainTabLevel = -1 # Tab amount Initially unknown, will be determined after parsing the first entry.
        line = '\0'
        while line != '':
            line = inputFile.readline()
            if not self._isDocs(line, mainTabLevel): # if mainTabLevel is -1, isDocs automatically returns false.
                entry = DataRecord.Entry(line)
                if entry.validEntry:
                    self.entries.append(entry)
                    # Determine mainTabLevel to be able to parse Docs
                    if mainTabLevel == -1: mainTabLevel = self._determineTabLevel(line)
            else: # current line is Docs belonging to the last entry
                # untab the docs line once, and it should be at a proper tabbing for output later
                self.entries[-1].Docs += self._tab(line, mainTabLevel, -1)




        self.sort() # maybe we should use a sorted liiist!

    def parseAdd(self, recordLine):
        """
        Parses a line containing an entry and adds it into the record, if the passed line is valid.
        The entry cannot have any docs associated with it, however.
        Two formats are allowed:
        [Address, ';', Type, Variable]
        [Address, Type, Variable]
        :param recordLine: line to parse and add the entry of
        :return: whether the operation was successful
        """
        # Maybe it has a ;, remove that
        if ';' in recordLine:
            recordLine = recordLine[:recordLine.index(';')] + recordLine[recordLine.index(';')+1:]

        entry = DataRecord.Entry(recordLine)
        output = True
        if entry.validEntry:
            self.entries.append(entry)
            self.sort() # probably better to just use a sorted list y'know?
        else:
            output = False
        return output

    def sort(self):
        """
        Sorts the record based on the address
        :return: None
        """
        self.entries = sorted(self.entries, key=lambda x: x.Address, reverse=False)
        return

    @staticmethod
    def _determineTabLevel(line):
        """
        :param line: Any old line that could be tabbed at the start
        :return: The tab level this line is at.
        """
        output = 0


        # First, determine the tabbing character in this line (if any)
        tabChar = -1    # Unknown character used for tabbing
        if line[0].isspace and line[0] != '\n': # if the first char is not a space, we're done. There's no tabbing.
            if line[0] == ' ':  tabChar = ' '
            if line[0] == '\t': tabChar = '\t'

            # Now go through line until a none-space character is found. How many tabChars there determines the tabLevel
            for c in line:
                if c.isspace() and c == tabChar:
                    output += 1
                if c == '\n':
                    break
                if c.isspace() and c != tabChar:
                    raise Exception("Mixed tabbing involved. That's too complicated y'know?")
                if not c.isspace():
                    break

            # If the charType is ' ', the output corresponds to the amount already. But if it's a tab, a conversion
            # must be done.
            if tabChar == '\t':
                output *= SPACES_PER_TAB

        return output

    @staticmethod
    def _isDocs(line, mainTabLevel):
        """
        Determines if the current line is Docs or if it's something else (junk? an actual entry?)
        :param line:            Line to check
        :param mainTabLevel:    The amount of tabbing expected in a main entry; a doc entry must have more.
        :return:                Whether this is docs or not
        """
        # If the mainTabLevel is -1, that means that it is impossible to determine whether this is docs yet.
        if mainTabLevel == -1:
            return False
        # If this is an absolutely empty line, it's not docs
        if not line:
            return False
        # In order for this line to be considered Docs, its tabLevel must be HIGHER than the mainTabLevel.
        return DataRecord._determineTabLevel(line) > mainTabLevel

    @staticmethod
    def _tab(line, unitTabLevel, amount):
        """
        Tabs a line at the start by amount*unitTabLevel. If the amount is negative, it removes that many unitTabLevels
        instead. This does not consider the weird case where the tabbing in a line is made of both '\t's and ' 's.
        :param line:            Line to tab or remove tabs from
        :param unitTabLevel:    The tab width to remove or add an amount of
        :param amount:          The amount of which to remove or add
        :return:                The now tabbed or detabbed line
        """
        output = line
        # If what is given is empty, emptiness is what you get...
        if not line:
            return line
        # First, determine the tabbing character in this line (if any)
        tabChar = -1    # Unknown character used for tabbing
        if line[0].isspace:
            if line[0] == ' ':  tabChar = ' '
            if line[0] == '\t': tabChar = '\t'
        else: tabChar = ' ' # If no tabbing, assume tabChar is a space.
        # if the amount is positive, we tab. If negative, we remove tabs. If zero, well... OK.
        if amount < 0:
            # Determine how much padding the line has, remove |amount|*unitTabLevel if available
            lineTabLevel = DataRecord._determineTabLevel(line)
            if lineTabLevel > amount*unitTabLevel:
                if tabChar == ' ':  output = line[-amount*unitTabLevel:]
                if tabChar == '\t': output = line[-amount*unitTabLevel/SPACES_PER_TAB:]
        if amount > 0:
            # prepend amount*unitTabLevel to the line
            if tabChar == ' ':  output = (amount*unitTabLevel)*' ' + line
            if tabChar == '\t': output = (amount*unitTabLevel/SPACES_PER_TAB)*' ' + line

        return output

    def _getVariableName(self, var):
        """
        Filters out array brackets and Pointer stars to return a pure variable name
        :param var: Variable to filter out
        :return:    The variable's name
        """
        output = ''
        inBracket = False
        for i in range(0, len(var)):
            if var[i] == '[':
                inBracket = True
            if var[i] == ']':
                inBracket = False
                continue
            if not inBracket and var[i] != '*':
                output += var[i]
        return output

    def _determineStarAmount(self, var):
        """
        Determines the pointer level of this. If it's an array like dummyVar[5], then its type is a pointer to a value.
        If it's *dummyVar[5], then it's a pointer to a value pointer. This is because C arrays are inherently pointers.
        :param var: Variable to find the pointer level of
        :return:    The number of 'stars' to add.
        """
        output = 0
        inBracket = False
        for c in var:
            if c == '*' or c == '[':
                output += 1
        return output

    def getMacroDefinitions(self):
        """
        Format: #define <variableName>  ((<type>[*|**|...])<Address>)
        :return: Outputs the record table in a text format of  C #define macros
        """
        output = ''

        # First, find the length of the longest variable. Make sure to remove '*' and [ ]s.
        maxVariableLen = 0
        for entry in self.entries:
            variableName = self._getVariableName(entry.Variable)
            if len(variableName) > maxVariableLen: maxVariableLen = len(variableName)

        for entry in self.entries:
            variableName = self._getVariableName(entry.Variable)
            starAmount = self._determineStarAmount(entry.Variable)
            if starAmount == 0: starAmount = 1 # Only references can be macro'd
            output += '#define ' + variableName + (maxVariableLen - len(variableName))*' '+ ' ((' + entry.Type \
                + starAmount*'*' + ')' + ('0x%08X)' % entry.Address) + '\n'

        return output

    def __str__(self):
        """
        :return: The data record in text format!
        """
        output = ''
        # First, find the length of the longest Type entry
        maxTypeLen = 0
        for entry in self.entries:
            if len(entry.Type) > maxTypeLen: maxTypeLen = len(entry.Type)
        # if the maximum is less than len('Type') make it so that it is len('Type') That's a minimum.
        if maxTypeLen < len('Type'): maxTypeLen = len('Type')
        # Output the columns header: All addresses are 8 digits long. The Type depends on the longest Type entry, and
        # the Variable column's width is arbitrary
        output += 'Address ' + ' ' + 'Type' + (maxTypeLen - len('Type'))*' ' + ' ' + 'Variable' + '\n'
        # now output the entries according to the placement of those columns
        for entry in self.entries:
            output += ("%08X" % entry.Address) + ' ' + entry.Type + (maxTypeLen - len(entry.Type))*' ' + ' ' \
                      + entry.Variable + '\n'
            output += entry.Docs
        return output


def errorUsage():
    """
    Prints the usage of the program and terminates the program
    :return: None
    """
    print("Incorrent usage of the program. Please follow the following format:\n" +
          "progName --in <inputFile> [--add <entryString>] --gen table|macro")
    exit(1)



def parseArgv(argv):
    ##
    """
    The format must adhere to "progName --in <inputFile> [--add <entryString>] --gen table|macro")
    Meaning, the length must either be 5, or 7. The commands must be valid, if not, a usage prompt is displayed and
    the program is terminated.
    -i, -a, and -g may also be used instead.

    :param argv:    The Argv to parse into a dictionary of args and authenticate
    :return:        A dictionary of arguments
    """
    if len(argv) != 5 and len(argv) != 7: errorUsage()
    args = {}
    if "--in" not in argv and "-i" not in argv: errorUsage()
    if "--gen" not in argv and "-g" not in argv: errorUsage()
    for i in range(1,len(argv), 2):
        if argv[i] not in ["--in", "-i", "--add", "-a", "--gen", "-g"]: errorUsage()
        if argv[i] in ["--in", "-i"]: args["in"] = argv[i+1]
        if argv[i] in ["--add", "-a"]: args["add"] = argv[i+1]
        if argv[i] in ["--gen", "-g"]: args["gen"] = argv[i+1]
    if "--add" not in argv and "-a" not in argv: args["add"] = None
    return args

if __name__ == "__main__":
    """
    Refer to the docs of parseArgv to get the argument format.
    This maintains a table of pointers to data in a file. Addresses are assumed to be a 4-bytes.
    The table can be added to, and it can also be used to generate C macros.
    """
    args = parseArgv(sys.argv)
    dataRec = DataRecord(args["in"])
    if args["add"]:
        dataRec.parseAdd(args["add"])
    if args["gen"] == "table":
        print(dataRec, end='')
    if args["gen"] == "macro":
        print(dataRec.getMacroDefinitions(), end='')
