#include "board.hh"

#include <cassert>

Board::Board(const TetriminoStock& tetriminoStock)
    : tetriminoStock{tetriminoStock}, currentTetrimino{nullptr}, tetrimios{},
      reverseMap{} {}

void Board::nextMove() {
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

    // push_front will make collision detection encounter the latest
    // tetriminos first
    tetrimios.push_front(currentTetrimino);
    addTetriminoToReverseMap(currentTetrimino);
    currentTetrimino = std::shared_ptr<Tetrimino>{nullptr};
    drawTetrimino();
}

void Board::addTetriminoToReverseMap(std::shared_ptr<Tetrimino> tetrimino) {
    for (auto mino : tetrimino->getMinos()) {
        assert(!reverseMap[mino.getY()][mino.getX()]);
        reverseMap[mino.getY()][mino.getX()] = tetrimino;
    }
}

void Board::compactBoard() {
    bool boardChanged = false;
    for (int y = height - 1; y >= 0; y--) {
        if (isRowFull(y)) {
            removeRow(y);
            boardChanged = true;
        }
    }

    if (boardChanged) {
        rebuildBoard();
    }
}

void Board::rebuildBoard() {
    std::array<std::array<std::shared_ptr<Tetrimino>, width>, height>
        newBoard{};

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            auto tetrimino = reverseMap[y][x];
            if (!tetrimino || tetrimino->empty())
                continue;

            for (auto mino : tetrimino->getMinos()) {
                newBoard[mino.getY()][mino.getX()] = tetrimino;
            }
        }
    }

    reverseMap = newBoard;
}

bool Board::isRowFull(int row) const {
    assert(row >= 0 && row < height);
    for (auto tetrimino : reverseMap[row]) {
        if (!tetrimino)
            return false;
    }
    return true;
}

void Board::removeRow(int row) {
    assert(row >= 0 && row < height);
    for (auto tetrimino : reverseMap[row]) {
        if (tetrimino)
            tetrimino->removeMinosOnYAxis(row);
    }
}
