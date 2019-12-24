#include "circulartetriminostock.hh"

CircularTetriminoStock::CircularTetriminoStock() {
    factories[0] = createITetrimino;
    factories[1] = createJTetrimino;
    factories[2] = createLTetrimino;
    factories[3] = createOTetrimino;
    factories[4] = createTTetrimino;
    factories[5] = createSTetrimino;
    factories[6] = createZTetrimino;

    selectedFactory = 0;
}

TetriminoPtr CircularTetriminoStock::draw() {
    TetriminoPtr tetrimino = factories[selectedFactory]();
    selectedFactory++;
    selectedFactory %= NUMBER_OF_TETRIMINOS;
    return tetrimino;
}

TetriminoPtr CircularTetriminoStock::preview() {
    return factories[(selectedFactory + 1) % NUMBER_OF_TETRIMINOS]();
}
