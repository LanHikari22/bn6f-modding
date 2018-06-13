from Tests import Test
from IDAItems import Function
import idaapi
idaapi.require("Tests.Test")
idaapi.require("IDAItems.Function")


class FunctionTest:

    class TestParams:
        """
        represents manually computed function parameters
        """
        def __init__(self, ea, name, comment, size_pool, size_nopool, xrefsTo):
            # type: (int, str, str, int, int, tuple[list[int],list[int]]) -> None
            """
            :param ea: start address of the function
            :param name: name of the function
            :param comment: comment found on the function
            :param size_pool: function's size, with data after its end
            :param size_nopool: function's size, until its code end.
            :param xrefsTo: code/data xrefs to the function
            """
            self.ea = ea
            self.name = name
            self.comment = comment
            self.size_pool = size_pool
            self.size_nopool = size_nopool
            self.xrefsTo = xrefsTo

    def __init__(self):
        test = Test.Test("IDAItems.Function")

        # test function
        ea = 0x080471F8
        name = "Shop_uncomp_80471F8"
        comment = "I use this as a test function."
        size_pool = 0x0804722C - ea
        size_nopool = 0x08047216 - ea
        xrefsTo = ([0x08046D4C+0x10],[])
        f1 = self.TestParams(ea, name, comment, size_pool, size_nopool, xrefsTo)
        test.add(self.createTest(name, f1))
        self.test = test

    def run(self):
        self.test.run()

    def createTest(self, testName, testParams):
        # type: (self.TestParams) -> Test
        """
        Creates tests for one function
        :testParams: encapsulated object showing manually computed function parameters
        :return: a Test compromising tests running on a single function
        """
        t = Test.Test(testName)
        t.add(Test.Test("testBasic()", self.testBasic, testParams))
        t.add(Test.Test("testComments()", self.testComments, testParams))
        # t1.add(Test.Test("testContent()", self.testContent, testParams))
        t.add(Test.Test("testFunctionDefinition()", self.testFunctionDefinition, testParams))
        t.add(Test.Test("testXRefsTo()", self.testXRefsTo, testParams))
        # t.add(Test.Test("testXRefsFrom()", self.testXRefsFrom, testParams))

        return t


    def testBasic(self, testParams):
        # type: (self.TestParams) -> None
        """
        Tests that InvalidFunctionException is raised if instantiated with invalid EA.
        And tests that valid functions give valid behavior
        :testParams: encapsulated object showing manually computed function parameters
        """
        # necessary test params
        ea = testParams.ea
        name = testParams.name
        size_pool = testParams.size_pool
        size_nopool = testParams.size_nopool

        try:
            f = Function.Function(0x00)
            Test.fail("InvalidFunctionException not raised")
        except(Function.InvalidFunctionException):
            pass
        f = Function.Function(ea)
        Test.assertEquals(f.func_ea, ea, "Function EA mistmatch: 0x%08X" % f.func_ea)
        # getName()
        Test.assertEquals(f.getName(), name, "Function name mismatch")
        # setName()
        f.setName(name + "0")
        Test.assertEquals(f.getName(), name + "0", "setName() not working")
        f.setName(name)
        Test.assertEquals(f.getName(), name, "could not set name back to normal")
        # getSize()
        Test.assertEquals(f.getSize(withPool=True), size_pool, "invalid pool size")
        Test.assertEquals(f.getSize(), size_nopool, "invalid no pool size")

    def testComments(self, testParams):
        # type: (self.TestParams) -> None
        """
        Makes sure that function comments are viewable and modifiable
        :testParams: encapsulated object showing manually computed function parameters
        """
        # there's an issue where GUI comments filter out system input comments, but
        # both exist anyway. Only one is showed in the GUI.
        f = Function.Function(testParams.ea)
        comment = testParams.comment
        Test.assertEquals(f.getComment(), comment, "comment mismatch: '%s'" % f.getComment())
        f.setComment(comment + "0")
        Test.assertEquals(f.getComment(), comment + "0", "setComment() not modifying")
        f.setComment(comment)
        Test.assertEquals(f.getComment(), comment, "comment didn't return to original")

    def testContent(self, testParams):
        # type: (int) -> None
        Test.fail("Not implemented: content is not parsed within the function")


    def testFunctionDefinition(self, testParams):
        # type: (self.TestParams) -> None
        """
        This decompiles the function and tries to get a C-style pointer #define
        macro
        It also tests just getting the prototype. This requires decompilation.
        :testParams: encapsulated object showing manually computed function parameters
        """
        f = Function.Function(testParams.ea)
        macro = "#define %s ((void (*) ()) (0x%08X +1))" % (testParams.name, testParams.ea)
        Test.assertEquals(f.getFuncPtrCMacro(), macro,
                          "macro mismatch: %s" % f.getFuncPtrCMacro())

    def testXRefsTo(self, testParams):
        # type: (self.TestParams) -> None
        """
        Tests valid code/data xrefs to the function
        :testParams: encapsulated object showing manually computed function parameters
        """
        f = Function.Function(testParams.ea)
        # testing xrefs to function
        Test.assertEquals(f.getXRefsTo(), testParams.xrefsTo,
                          "XrefsTo Mismatch")

    def testXRefsFrom(self, testParams):
        # type: (self.TestParams) -> None
        """
        Tests valid code/data xrefs to the function
        :testParams: encapsulated object showing manually computed function parameters
        """
        Test.fail("not implemented")

if __name__ == "__main__":
    test = FunctionTest()
    test.run()