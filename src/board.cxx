#include "board.hh"

#include <algorithm>
#include <cassert>

Board::Board(std::shared_ptr<TetriminoStock> tetriminoStock, const Color& color)
    : tetriminoStock{tetriminoStock}, color{color},
      currentTetrimino{nullptr}, minos{}, gameOver{false} {}

void Board::nextMove() {
    if (gameOver)
        return;

    if (drawTetrimino()) {
        return;
    }

    if (willCurrentTetriminoCollideBottom()) {
        handleCollision();
        compactBoard();
        return;
    }

    currentTetrimino->moveDown();
}

void Board::moveCurrentTetriminoLeft() {
    if (gameOver)
        return;

    assert(currentTetrimino);
    if (currentTetrimino->getX() > 0 && !willTetriminosCollideLeft()) {
        currentTetrimino->moveLeft();
    }
}

void Board::moveCurrentTetriminoRight() {
    if (gameOver)
        return;

    assert(currentTetrimino);
    if (currentTetrimino->maxX() < (width - 1) &&
        !willTetriminosCollideRight()) {
        currentTetrimino->moveRight();
    }
}

void Board::rotateCurrentTetrimino() {
    if (gameOver)
        return;

    assert(currentTetrimino);
    currentTetrimino->rotateClockwise();
    if (currentTetrimino->maxX() >= width || willTetriminosCollideLeft() ||
        willTetriminosCollideRight()) {
        currentTetrimino->rotateCounterclockwise();
    }
}

bool Board::isGameOver() { return gameOver; }

bool Board::drawTetrimino() {
    if (!currentTetrimino) {
        currentTetrimino = tetriminoStock->draw();
        return true;
    }

    return false;
}

bool Board::willCurrentTetriminoCollideBottom() const {
    assert(currentTetrimino);

    if ((currentTetrimino->maxY() + 1) >= height)
        return true;

    for (auto mino : currentTetrimino->getMinos()) {
        for (auto otherMino : minos) {
            if (otherMino->getY() == (mino.getY() + 1) &&
                otherMino->getX() == mino.getX()) {
                return true;
            }
        }
    }

    return false;
}

bool Board::willTetriminosCollideLeft() const {
    assert(currentTetrimino);

    for (auto mino : currentTetrimino->getMinos()) {
        for (auto otherMino : minos) {
            if (otherMino->getX() == (mino.getX() - 1) &&
                (otherMino->getY() == mino.getY())) {
                return true;
            }
        }
    }

    return false;
}

bool Board::willTetriminosCollideRight() const {
    assert(currentTetrimino);

    for (auto mino : currentTetrimino->getMinos()) {
        for (auto otherMino : minos) {
            if (otherMino->getX() == (mino.getX() + 1) &&
                (otherMino->getY() == mino.getY())) {
                return true;
            }
        }
    }

    return false;
}

void Board::handleCollision() {
    assert(currentTetrimino);

    for (auto mino : currentTetrimino->getMinos()) {
        minos.push_front(std::shared_ptr<Mino>{new Mino{mino}});
    }
    currentTetrimino = std::shared_ptr<Tetrimino>{nullptr};
    drawTetrimino();
    if (willCurrentTetriminoCollideBottom()) {
        gameOver = true;
    }
}

void Board::compactBoard() {
    for (int row = height - 1; row >= 0; row--) {
        while (isRowFull(row)) {
            removeRow(row);
            moveMinosAboveRowDown(row);
        }
    }
}

bool Board::isRowFull(int row) const {
    assert(row >= 0 && row < height);

    int minosOnRow = 0;
    for (auto mino : minos) {
        if (mino->getY() == row)
            minosOnRow++;
    }
    return minosOnRow == width;
}

void Board::removeRow(int row) {
    assert(row >= 0 && row < height);

    auto first = std::remove_if(minos.begin(), minos.end(), [row](auto mino) {
        return mino->getY() == row;
    });

    minos.erase(first, minos.end());
}

void Board::moveMinosAboveRowDown(int row) {
    assert(row > 0 && row < height);

    for (auto mino : minos) {
        if (mino->getY() < row)
            mino->moveY(1);
    }
}
