# This module interacts with IDA databases either through the the API, or by accessing the database directly through
# idbtool library. When using idbtool, you can only read from the database. Using the API allows writing also
# 415 964 6499 Webbs

class IDB:
    def __init__(self, APIMode):
        # type: (bool) -> None
        """
        :param APIMode: in APIMode, the IDAPython API within IDA is used. This must be a script executed within IDA.
            This also allows for writing to data structures (functions, files, etc) not just reading
            Otherwise, the IDB will purely use the idbtool interface to read IDA databases
        """
        self.APIMode = APIMode
        raise(NotImplemented())

