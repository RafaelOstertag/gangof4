#include "board.hh"

#include <algorithm>
#include <cassert>

Board::Board(std::shared_ptr<TetriminoStock> tetriminoStock, const Color& color,
             scorer_ptr_t scorer)
    : tetriminoStock{tetriminoStock}, color{color}, scorer{scorer},
      currentTetrimino{nullptr}, minos{}, callbacks{}, gameOver{false} {}

void Board::nextMove() {
    if (gameOver)
        return;

    if (drawTetrimino()) {
        return;
    }

    if (willCurrentTetriminoCollideBottom()) {
        handleCollision();
        auto linesRemoved = compactBoard();
        scorer->scoreLinesRemoved(linesRemoved);

        if (linesRemoved > 0) {
            callCallbacks(FULL_ROW);
        } else {
            callCallbacks(COLLISION);
        }

        return;
    }

    currentTetrimino->moveDown();
    callCallbacks(MOVE_DOWN);
}

void Board::moveCurrentTetriminoLeft() {
    if (gameOver)
        return;

    assert(currentTetrimino);
    if (currentTetrimino->getX() > 0 && !willTetriminosCollideLeft()) {
        currentTetrimino->moveLeft();
        callCallbacks(MOVE_LEFT);
    }
}

void Board::moveCurrentTetriminoRight() {
    if (gameOver)
        return;

    assert(currentTetrimino);
    if (currentTetrimino->maxX() < (WIDTH_IN_MINOS - 1) &&
        !willTetriminosCollideRight()) {
        currentTetrimino->moveRight();
        callCallbacks(MOVE_RIGHT);
    }
}

void Board::rotateCurrentTetrimino() {
    if (gameOver)
        return;

    assert(currentTetrimino);
    currentTetrimino->rotateClockwise();
    if (currentTetrimino->maxX() >= WIDTH_IN_MINOS || willTetriminosCollideLeft() ||
        willTetriminosCollideRight()) {
        currentTetrimino->rotateCounterclockwise();
    } else {
        callCallbacks(ROTATE);
    }
}

bool Board::isGameOver() { return gameOver; }

void Board::registerBoardCallback(BoardCallbackPtr callback) {
    callbacks.push_back(callback);
}

bool Board::drawTetrimino() {
    if (!currentTetrimino) {
        currentTetrimino = tetriminoStock->draw();
        return true;
    }

    return false;
}

bool Board::willCurrentTetriminoCollideBottom() const {
    assert(currentTetrimino);

    if ((currentTetrimino->maxY() + 1) >= HEIGHT_IN_MINOS)
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
        callCallbacks(GAME_OVER);
    }
}

int Board::compactBoard() {
    int rowsRemoved = 0;
    for (int row = HEIGHT_IN_MINOS - 1; row >= 0; row--) {
        while (isRowFull(row)) {
            removeRow(row);
            moveMinosAboveRowDown(row);
            rowsRemoved++;
        }
    }

    return rowsRemoved;
}

bool Board::isRowFull(int row) const {
    assert(row >= 0 && row < HEIGHT_IN_MINOS);

    int minosOnRow = 0;
    for (auto mino : minos) {
        if (mino->getY() == row)
            minosOnRow++;
    }
    return minosOnRow == WIDTH_IN_MINOS;
}

void Board::removeRow(int row) {
    assert(row >= 0 && row < HEIGHT_IN_MINOS);

    auto first = std::remove_if(minos.begin(), minos.end(), [row](auto mino) {
        return mino->getY() == row;
    });

    minos.erase(first, minos.end());
}

void Board::moveMinosAboveRowDown(int row) {
    assert(row > 0 && row < HEIGHT_IN_MINOS);

    for (auto mino : minos) {
        if (mino->getY() < row)
            mino->moveY(1);
    }
}

void Board::callCallbacks(BoardEvent event) {
    for (auto callback : callbacks) {
        callback->call(event, *this);
    }
}
