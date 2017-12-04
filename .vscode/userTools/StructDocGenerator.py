import sys
import re
import StructPadder

class DocEntry:
    table: dict # contains all values in this entry
    docs: str   # docs attached to this entry

    ##
    # @param offset Offset of the variable
    # @param type type of variable: "u8, u16, u32, void, ninja"
    # @param name name of the variable
    # @param docs Documentation attached to this DocEntry.
    # @param others a dictionary containing other values.
    ##
    def __init__(self, offset, type, name, docs, others=None):
        self.table = {}
        self.table["Offset"] = offset
        self.table["Type"] = type
        self.table["Name"] = name
        self.docs = docs
        if others:
            for key in others:
                self.table[key] = others[key]


##
##
class Document:
    name: str       # Name of the structure associated with this document
    size: int       # Size of the structure associated with this document
    header: str     # the header of the document
    keys: list      # the keys in the document table
    keyTabs: dict   # For each key, the length of the longest entry
    members: list

    ##
    # If docFile is not None, the file is parsed to populate the Document object, otherwise, it is to be manually
    # filled.
    # @param name   The name of the structure associated with this document
    # @param size   The size of the structure associated with this document
    # @param header The header of the document: contains its name, size, and any additional information.
    # @param keys   list containing all keys used in the table, this corresponds to what each column represents
    # @param docFile if exists, it is parsed to populate these fields automatically
    ##
    def __init__(self, name=None, size=None, header=None, keys=None, docFile=None):
        self.members = []
        if docFile:
            self.parse(docFile)
        else:
            self.name = name
            self.size = size
            if name in header and ("0x%02X" % size) in header: self.header = header
            else: raise Exception('Invalid header passed to Document')
            if "Offset" in keys and "Type" in keys and "Name" in keys: self.keys = keys
            else: raise  Exception("Invalid keyTable passed to Document")

    ##
    # Required Format: (... means anything goes, . . . means pattern repeats indefinitely)
    # ...
    #   ... <NpcName>
    #   ... <size>
    #   . . .
    # Offset Type   Name
    # <off>  <type> <name>
    #   ...
    # <off>  <type> <name>
    # . . .
    #
    # In case the entry is a structure, its size must be specified in the first line of documentation, second word:
    # <off> <type>  <name>
    #   ... <size>
    #   ...
    ##
    def parse(self, docFile):
        # parse name and size first: they should always be second and third lines respectively, second word.
        SPACES_PER_TAB = 4
        header = ''
        header += docFile.readline()
        line = docFile.readline()
        self.name = list(filter(None, re.split("[ \t\n]", line)))[1]
        header += line
        line = docFile.readline()
        self.size = int(list(filter(None, re.split("[ \t\n]", line)))[1], 16)
        header += line
        stillHeader = True  # goes off when we start parsing the table content
        tabSizes = -1    # The amount of tabbing, it's the index of a character just after the tabbing/spaces
        curr = None # Used to keep track of the current entry being parsed
        for line in docFile:
            keywords = list(filter(None, re.split("[ \t\n]", line)))
            if len(keywords) >= 3 and keywords[0] == "Offset" and keywords[1] == "Type" and keywords[2] == "Name":
                # this is the table keys line, parse this
                self.keys = []
                for key in keywords: self.keys.append(key)
                # OK. From here on out, we parse entries
                stillHeader = False
                self.header = self.adjustHeaderTabbing(header, SPACES_PER_TAB) # Incase the header is tabbed itself, it shouldn't be stored like that
                # OK. We start... from next iteration!
                continue

            if stillHeader:
                header += line
            else:
                # In order for this to be a valid entry (not documentation), The offset must always be present a tabSize
                # later. In case of documentation, that will not be the case because of the extra tabbing

                # Check when the tabbing must end, this is guaranteed to be the first entry if the size is -1.
                if tabSizes == -1:
                    # Ensure to know the size of a tab in  caases of it being a hard tab or spaces
                    tabSizes = {}
                    if line[0] == ' ':
                        tabSizes[' '] = line.index('0x')
                        tabSizes['\t'] = tabSizes[' ']/SPACES_PER_TAB
                    if line[0] == '\t':
                        tabSizes['\t'] = line.index('0x')
                        tabSizes[' '] = SPACES_PER_TAB * tabSizes['\t']
                    if line[0] == '0': # this means that the entries are not tabbed at all. that's not a bad case
                        tabSizes['\t'] = 0
                        tabSizes[' '] = 0

                # In case this is an entry, store the previous entry as it was completely parsed and parse this one
                # Whether the tabbing is spaces, or hard tabs... The rule for both is available.
                if line[0] == "0" or (line[0] == ' ' or line[0] == '\t') and len(line) > tabSizes[line[0]] and line[tabSizes[line[0]]] == "0":
                    # store last entry, if any
                    if curr:
                        self.members.append(curr)
                    # parse all table values: First three must be ["Offset", "Type", "Name"]
                    curr = DocEntry(offset=int(keywords[0], 16),type=keywords[1],name=keywords[2],docs='',others=keywords[3:])
                    # If this is a structure (or array), signal that the first line must be parsed for size
                    if "[" in curr.table["Name"] or curr.table["Type"] not in ["u8", "u16", "u32", "void"] and \
                        '*' not in curr.table["Name"] and '*' not in curr.table["Type"]:
                        curr.table["size"] = -1 # signal for it to be parsed next line

                # if this is a documentation line, just append it to the curr entry's docs
                else:
                    curr.docs += line
                    # if this is a structure (or array), parse its size (the second word)
                    if "size" in curr.table and curr.table["size"] == -1:
                        curr.table["size"] = int(keywords[1], 16)

        # append last entry
        self.members.append(curr)
        # sort members
        self.members = sorted(self.members, key= lambda x: x.table["Offset"], reverse=False)

    ##
    # Prints the document in the following format:
    # [Header]
    #   [Name] <name>
    #   [Size] <size>
    #   [Description]
    # Offset Type    Name
    # <off>  <type>  <name>
    #    <doc>
    # ...
    ##
    def __str__(self):
        self.computeColumnTabs()
        output = ''
        output += self.header
        for key in self.keys:
            output += self.soft_tab(str(key), self.keyTabs[key])
        output += '\n'
        # sort members
        self.members = sorted(self.members, key= lambda x: x.table["Offset"], reverse=False)
        for member in self.members:
            # output all table values
            for key in member.table:
                if key in self.keys:
                    if type(member.table[key]) is int:
                        output += self.soft_tab("0x%02X" % member.table[key], self.keyTabs[key])
                    else:
                        output += self.soft_tab(member.table[key], self.keyTabs[key])
            output += '\n'
            # now output all the docs
            output += member.docs
        return output

    ##
    # returns the string with the length specified. If the str is longer, None is returned.
    ##
    @staticmethod
    def soft_tab(str, length):
        output = None
        if len(str) <= length:
            output = str + ' '*(length - len(str))
        return output

    ##
    # Returns the index for the member with the specified output, or None
    ##
    def getMemberIndex(self, offset):
        output = None
        for i in range(len(self.members)):
            if self.members[i].table["Offset"] == offset:
                output = i
        return output

    ##
    # Merges this document with a struct generated document!
    # This writes/overwrites anything new from the passed document into the current document.
    # However, the header is not copied, but all occurances of the name/size are replaced.
    # Documentation of members is also not merged, only the members' type and name
    ##
    def mergeTemplate(self, doc):
        self.header = self.header.replace(self.name, doc.name)
        self.header = self.header.replace("0x%02X" % self.size, "0x%02X" % doc.size)
        self.name = doc.name
        self.size = doc.size
        for newMember in doc.members:
            index = self.getMemberIndex(newMember.table["Offset"])
            if index != None:
                self.members[index].table["Type"] = newMember.table["Type"]
                self.members[index].table["Name"] = newMember.table["Name"]
            else:
                self.members.append(newMember)
        # sort members
        self.members = sorted(self.members, key= lambda x: x.table["Offset"], reverse=False)

    ##
    # Computes how much tabbing each column should have for stylistic purposes
    ##
    def computeColumnTabs(self):
        self.keyTabs = {}
        for key in self.keys:
            self.keyTabs[key] = 0
        for member in self.members:
            for column in member.table:
                if column in self.keys:
                    if type(member.table[column]) is int:
                        length = len("0x%02X" % member.table[column])
                    else:
                        length = len(member.table[column])
                    if length > self.keyTabs[column]:
                        self.keyTabs[column] = length + 4 # default 4 space tab between columns

    ##
    # Adjusts the tabbing levels on the header so that the header itself is at level 0
    ##
    @staticmethod
    def adjustHeaderTabbing(header, spaces_per_tab):
        if len(header) <= 0: return header
        if len(header) > 0 and header[0] != ' ' and header[0] != '\t': return header
        output = header
        while len(output) > spaces_per_tab and output[0:spaces_per_tab] == spaces_per_tab*' '\
                or len(output) > 1 and output[0] == '\t':
            lines = list(filter(None, re.split("[\n]", output)))
            for i in range(len(lines)):
                if len(lines[i]) >= spaces_per_tab and lines[i][0:spaces_per_tab] == spaces_per_tab*' ':
                    lines[i] = lines[i][spaces_per_tab:]
                if len(lines[i]) >= 1 and lines[i][0] == '\t':
                    lines[i] = lines[i][1:]
            output = '\n'.join(lines) + '\n'
        return output


##
# Prints the usage of the program and terminates the program
##
def errorUsage():
    print("Incorrent usage of the program. Please follow the following format:\n" +
          "progName --in <inputFile> [--merge <mergeFile>] --gen struct|doc")
    exit(1)


##
# Generates documentation from a structure. If merging is enabled, it also merges the docs from mergeFile.
# The merging only overwrites new members, not member documents, and replaces all occurances of name/size in header
# @param inputFile  File containing the structure to generate docs from
# @param mergeFile  An optional file that contains a previous documentation file to merge the one generated with
##
def generateDoc(inputFile, mergeFile=None):
    struct = StructPadder.Structure(structFile=inputFile)
    # Generate document from struct
    header = "[Header]\n\t[Name] %s\n\t[Size] 0x%02X\n\t[Description]\n" % (struct.name, struct.size)
    doc = Document(name=struct.name, size=struct.size, header=header, keys=["Offset","Type","Name"])
    for member in struct.members:
        _type = member.type
        # if this is a primitive, change it from uint<>_t to u<>
        if member.type == "uint8_t": _type = "u8"
        if member.type == "uint16_t": _type = "u16"
        if member.type == "uint32_t": _type = "u32"
        if member.type in ["uint8_t*", "uint16_t*", "uint32_t*"]: _type += "*"
        # if name is unk_<>, change it to ?
        name = member.name[:-1] # remove ;
        if len(name) > len('unk_') and name[0:4] == "unk_": name = '?'
        doc.members.append(DocEntry(offset=member.location, type=_type, name=name, docs=''))
    # If a mergeFile exists, merge both documents together
    if mergeFile:
        originalDoc = Document(docFile=mergeFile)
        originalDoc.mergeTemplate(doc)
        doc = originalDoc
    print(doc, end='')


##
# Generates a structure from an input documentation file
##
def generateStruct(inputFile):
    doc = Document(docFile=inputFile)
    struct = StructPadder.Structure(name=doc.name, size=doc.size)
    maxLen = 0
    for member in doc.members:
        _type = member.table["Type"]
        # if this is a primitive, change it from u<> to uint<>_t
        if member.table["Type"] == "u8": _type = "uint8_t"
        if member.table["Type"] == "u16": _type = "uint16_t"
        if member.table["Type"] == "u32": _type = "uint32_t"
        if member.table["Type"] in ["u8*", "u16*", "u32*"]: _type += "*"
        # if the name is a '?' make it unk_<offset>
        name = member.table["Name"] + ";"
        if name == '?;': name = "unk_%02X;" % member.table["Offset"]
        # determine maxLen for struct tabbing
        currLen = len("%s %s;     " % (_type, name))
        if currLen > maxLen: maxLen = currLen
        # if it's a structure, specify its size
        if "size" in member.table:
            struct.members.append(StructPadder.StructMember(_type=_type, name=name, location=member.table["Offset"],
                                                            otherContent=" size=0x%02X" % member.table["size"],
                                                            structSize=member.table["size"]))
        else:
            struct.members.append(StructPadder.StructMember(_type=_type, name=name, location=member.table["Offset"],
                                                            otherContent="", structSize=None))
    struct.maxLen = maxLen
    struct.pad()
    print(struct, end='')


##
# The format must adhere to "progName --in <inputFile> [--merge <mergeFile>] --gen struct|doc"
# Meaning, the length must either be 5, or 7. The commands must be valid, if not, a usage prompt is displayed and
# the program is terminated.
# -i, -m, and -g may also be used instead.
##
def parseArgv(argv):
    if len(argv) != 5 and len(argv) != 7: errorUsage()
    args = {}
    for i in range(1,len(argv), 2):
        if argv[i] not in ["--in", "-i", "--merge", "-m", "--gen", "-g"]: errorUsage()
        if argv[i] in ["--in", "-i"]: args["in"] = argv[i+1]
        if argv[i] in ["--merge", "-m"]: args["merge"] = argv[i+1]
        if argv[i] in ["--gen", "-g"]: args["gen"] = argv[i+1]
    if "--merge" not in argv and "-m" not in argv: args["merge"] = None
    return args


##
# usage of the program: progName --in <inputFile> [--merge <mergeFile>] --gen struct|doc
# inputFile is the input containing either a structure or documentation of specific format.
# the gen switch determines the content of the output, and hence the input too. (if struct, input assumed to be doc)
# the optional merge option is for when the output is to be overwritten, not redone. This is useful for modifying
# the docs based on the structure instead of generating completely new docs
# Note that merging is ONLY SUPPORTED for generating docs.
# --in, --merge, and --gen may also be used interchangeably with their shorter counterparts: -i, -m, and -g
##
if __name__ == "__main__":
    args = parseArgv(sys.argv)
    inputFile = open(args["in"], "r")
    mergeFile = None
    if args["merge"]:
        mergeFile = open(args["merge"], "r")
    if args["gen"] == "doc":
        generateDoc(inputFile, mergeFile)
    if args["gen"] == "struct":
        if mergeFile:
            print("ERROR: Merging is not supported for structs")
            exit(1)
        generateStruct(inputFile)

