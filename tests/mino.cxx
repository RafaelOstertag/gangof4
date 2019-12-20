#include "tetrimino/mino.hh"

#include <cppunit/CompilerOutputter.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

class MinoTest : public CppUnit::TestFixture {
  public:
    static CppUnit::TestSuite* suite() {
        CppUnit::TestSuite* suiteOfTests = new CppUnit::TestSuite("Mino");

        suiteOfTests->addTest(new CppUnit::TestCaller<MinoTest>{
            "Mino Equality", &MinoTest::equals});

        return suiteOfTests;
    }

    void equals() {
        Mino minoA{2, 3, CYAN};
        Mino minoB{2, 3, RED};
        CPPUNIT_ASSERT(minoA == minoB);

        Mino minoC{3, 2, CYAN};
        CPPUNIT_ASSERT(minoA != minoC);
    }
};

int main() {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(MinoTest::suite());
    return runner.run() ? 0 : 1;
}
