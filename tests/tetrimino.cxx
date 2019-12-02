#include "tetrimino.hh"

#include <cppunit/CompilerOutputter.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

class TetriminoTest : public CppUnit::TestFixture {
  public:
    static CppUnit::TestSuite* suite() {
        CppUnit::TestSuite* suiteOfTests = new CppUnit::TestSuite("Tetrimino");

        suiteOfTests->addTest(new CppUnit::TestCaller<TetriminoTest>{
            "Rotate Clockwise", &TetriminoTest::rotate_clockwise});

        suiteOfTests->addTest(new CppUnit::TestCaller<TetriminoTest>{
            "Rotate Counterclockwise",
            &TetriminoTest::rotate_counterclockwise});

        suiteOfTests->addTest(new CppUnit::TestCaller<TetriminoTest>{
            "Move Left", &TetriminoTest::move_left});

        suiteOfTests->addTest(new CppUnit::TestCaller<TetriminoTest>{
            "Move Right", &TetriminoTest::move_right});

        suiteOfTests->addTest(new CppUnit::TestCaller<TetriminoTest>{
            "Move Down", &TetriminoTest::move_down});

        return suiteOfTests;
    }

    void rotate_clockwise() {
        Tetrimino tetrimino{
            0, 0,
            std::vector<Blocklet>{Blocklet{0, 0}, Blocklet{1, 0},
                                  Blocklet{1, 1}, Blocklet{2, 1}}};
        tetrimino.rotateClockwise();

        auto blocklets = tetrimino.getBlocklets();
        CPPUNIT_ASSERT(blocklets.size() == 4);
        CPPUNIT_ASSERT(Blocklet(1, 0) == blocklets[0]);
        CPPUNIT_ASSERT(Blocklet(1, 1) == blocklets[1]);
        CPPUNIT_ASSERT(Blocklet(0, 1) == blocklets[2]);
        CPPUNIT_ASSERT(Blocklet(0, 2) == blocklets[3]);

        tetrimino.rotateClockwise();
        blocklets = tetrimino.getBlocklets();
        CPPUNIT_ASSERT(Blocklet(0, 0) == blocklets[3]);
        CPPUNIT_ASSERT(Blocklet(1, 0) == blocklets[2]);
        CPPUNIT_ASSERT(Blocklet(1, 1) == blocklets[1]);
        CPPUNIT_ASSERT(Blocklet(2, 1) == blocklets[0]);
    }

    void rotate_counterclockwise() {
        Tetrimino tetrimino{
            0, 0,
            std::vector<Blocklet>{Blocklet{0, 0}, Blocklet{1, 0},
                                  Blocklet{1, 1}, Blocklet{2, 1}}};
        tetrimino.rotateCounterclockwise();

        auto blocklets = tetrimino.getBlocklets();
        CPPUNIT_ASSERT(blocklets.size() == 4);
        CPPUNIT_ASSERT(Blocklet(0, 2) == blocklets[0]);
        CPPUNIT_ASSERT(Blocklet(0, 1) == blocklets[1]);
        CPPUNIT_ASSERT(Blocklet(1, 1) == blocklets[2]);
        CPPUNIT_ASSERT(Blocklet(1, 0) == blocklets[3]);

        tetrimino.rotateCounterclockwise();
        blocklets = tetrimino.getBlocklets();
        CPPUNIT_ASSERT(Blocklet(2, 1) == blocklets[0]);
        CPPUNIT_ASSERT(Blocklet(1, 1) == blocklets[1]);
        CPPUNIT_ASSERT(Blocklet(1, 0) == blocklets[2]);
        CPPUNIT_ASSERT(Blocklet(0, 0) == blocklets[3]);
    }

    void move_left() {
        Tetrimino tetrimino{
            0, 0,
            std::vector<Blocklet>{Blocklet{0, 0}, Blocklet{1, 0},
                                  Blocklet{1, 1}, Blocklet{2, 1}}};

        tetrimino.moveLeft();

        CPPUNIT_ASSERT_EQUAL(-1, tetrimino.getX());
        CPPUNIT_ASSERT_EQUAL(0, tetrimino.getY());
        CPPUNIT_ASSERT_EQUAL(1, tetrimino.maxX());
        CPPUNIT_ASSERT_EQUAL(1, tetrimino.maxY());

        auto blocklets = tetrimino.getBlocklets();
        CPPUNIT_ASSERT(Blocklet(-1, 0) == blocklets[0]);
        CPPUNIT_ASSERT(Blocklet(0, 0) == blocklets[1]);
        CPPUNIT_ASSERT(Blocklet(0, 1) == blocklets[2]);
        CPPUNIT_ASSERT(Blocklet(1, 1) == blocklets[3]);
    }

    void move_right() {
        Tetrimino tetrimino{
            0, 0,
            std::vector<Blocklet>{Blocklet{0, 0}, Blocklet{1, 0},
                                  Blocklet{1, 1}, Blocklet{2, 1}}};

        tetrimino.moveRight();

        CPPUNIT_ASSERT_EQUAL(1, tetrimino.getX());
        CPPUNIT_ASSERT_EQUAL(0, tetrimino.getY());
        CPPUNIT_ASSERT_EQUAL(3, tetrimino.maxX());
        CPPUNIT_ASSERT_EQUAL(1, tetrimino.maxY());

        auto blocklets = tetrimino.getBlocklets();
        CPPUNIT_ASSERT(Blocklet(1, 0) == blocklets[0]);
        CPPUNIT_ASSERT(Blocklet(2, 0) == blocklets[1]);
        CPPUNIT_ASSERT(Blocklet(2, 1) == blocklets[2]);
        CPPUNIT_ASSERT(Blocklet(3, 1) == blocklets[3]);
    }

    void move_down() {
        Tetrimino tetrimino{
            0, 0,
            std::vector<Blocklet>{Blocklet{0, 0}, Blocklet{1, 0},
                                  Blocklet{1, 1}, Blocklet{2, 1}}};

        tetrimino.moveDown();

        CPPUNIT_ASSERT_EQUAL(0, tetrimino.getX());
        CPPUNIT_ASSERT_EQUAL(1, tetrimino.getY());
        CPPUNIT_ASSERT_EQUAL(2, tetrimino.maxX());
        CPPUNIT_ASSERT_EQUAL(2, tetrimino.maxY());

        auto blocklets = tetrimino.getBlocklets();
        CPPUNIT_ASSERT(Blocklet(0, 1) == blocklets[0]);
        CPPUNIT_ASSERT(Blocklet(1, 1) == blocklets[1]);
        CPPUNIT_ASSERT(Blocklet(1, 2) == blocklets[2]);
        CPPUNIT_ASSERT(Blocklet(2, 2) == blocklets[3]);
    }
};

int main() {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(TetriminoTest::suite());
    return runner.run() ? 0 : 1;
}
