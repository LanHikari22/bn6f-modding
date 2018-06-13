#
# @Author Lan
# This module classifies a Data type and defines operations done on them using the IDA API
#

class InvalidDataException(Exception):
    def __init__(self, s):
        super(Exception, self).__init__(s)

class Data:
    def __init__(self, ea):
        # type: (int) -> None
        """

        :param ea: effective address of the data item
        """
        raise(NotImplemented())

    def getName(self):
        # type: () -> str
        """
        :return: the data item's name
        """
        raise(NotImplemented())

    def setName(self):
        # type: () -> None
        """
        Sets the name of the data item
        """
        raise(NotImplemented())

    def getSize(self):
        # type: () -> int
        """
        :return: The size of the data item in bytes
        """
        raise(NotImplemented())

    def getContent(self):
        # type: () -> bytearray
        """
        :return: the binary content of the data item
        """
        raise(NotImplemented())

    def getDisassembly(self):
        # type: () -> str
        """
        :return: disassembly of data item
        """
        raise(NotImplemented())

    def getType(self):
        # type: () -> _
        """
        :return: the datatype: whether it's a primitive, enum, or struct, and that specific type.
        """
        raise(NotImplemented())

    def findPoolFunction(self):
        # type: () -> int
        """
        If this data item is within the pool of a function, that function's ea is returned
        otherwise, None is returned. The function is first found by traversing back in ea, and computing the poolsize
        of the function. If that matches, then the data itsem must have at least one code xref from that function.
        :return: None or the start address of the function containing the data item in its pool
        """
        raise(NotImplemented())

