#include "board.hh"

#include <cassert>

Board::Board(const TetriminoStock& tetriminoStock)
    : tetriminoStock{tetriminoStock}, currentTetrimino{nullptr}, tetrimios{} {}

void Board::nextMove() {
    if (drawTetrimino()) {
        return;
    }

    if (willCurrentTetriminoCollideBottom()) {
        handleCollision();
        return;
    }

    currentTetrimino->moveDown();
}

void Board::moveCurrentTetriminoLeft() {
    assert(currentTetrimino);
    if (currentTetrimino->getX() > 0 && !willTetriminosCollideLeft()) {
        currentTetrimino->moveLeft();
    }
}

void Board::moveCurrentTetriminoRight() {
    assert(currentTetrimino);
    if (currentTetrimino->maxX() < (width - 1) &&
        !willTetriminosCollideRight()) {
        currentTetrimino->moveRight();
    }
}

void Board::rotateCurrentTetrimino() {
    assert(currentTetrimino);
    currentTetrimino->rotateClockwise();
}

bool Board::isGameOver() { assert(false); }

bool Board::drawTetrimino() {
    if (!currentTetrimino) {
        currentTetrimino = tetriminoStock.draw();
        return true;
    }

    return false;
}

bool Board::willCurrentTetriminoCollideBottom() const {
    assert(currentTetrimino);

    if ((currentTetrimino->maxY() + 1) >= height)
        return true;

    for (auto tetrimino : tetrimios) {
        if (willTetriminosCollideBottom(tetrimino))
            return true;
    }

    return false;
}

bool Board::willTetriminosCollideBottom(
    std::shared_ptr<Tetrimino> tetrimino) const {
    assert(currentTetrimino);

    for (auto mino : currentTetrimino->getMinos()) {
        for (auto otherMino : tetrimino->getMinos()) {
            if (otherMino.getY() == (mino.getY() + 1) &&
                otherMino.getX() == mino.getX()) {
                return true;
            }
        }
    }

    return false;
}

bool Board::willTetriminosCollideLeft() const {
    assert(currentTetrimino);

    for (auto tetrimino : tetrimios) {
        for (auto mino : currentTetrimino->getMinos()) {
            for (auto otherMino : tetrimino->getMinos()) {
                if (otherMino.getX() == (mino.getX() - 1) &&
                    (otherMino.getY() == mino.getY())) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool Board::willTetriminosCollideRight() const {
    assert(currentTetrimino);

    for (auto tetrimino : tetrimios) {
        for (auto mino : currentTetrimino->getMinos()) {
            for (auto otherMino : tetrimino->getMinos()) {
                if (otherMino.getX() == (mino.getX() + 1) &&
                    (otherMino.getY() == mino.getY())) {
                    return true;
                }
            }
        }
    }

    return false;
}

void Board::handleCollision() {
    assert(currentTetrimino);

    // push_front will make hasTetriminoCollision encounter the latest
    // tetriminos first
    tetrimios.push_front(currentTetrimino);
    currentTetrimino = std::shared_ptr<Tetrimino>{nullptr};
    drawTetrimino();
}
