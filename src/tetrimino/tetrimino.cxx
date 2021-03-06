#include "tetrimino.hh"
#include <algorithm>
#include <limits>

namespace {
void adjustMinosToCurrentPosition(int offsetX, int offsetY,
                                  const std::vector<Mino*>& minos) {
    for (auto mino : minos) {
        mino->moveX(offsetX);
        mino->moveY(offsetY);
    }
}

} // namespace

Tetrimino::Tetrimino(const std::vector<Mino>& minos) : minos{}, x{0}, y{0} {
    for (auto mino : minos) {
        auto copy = new Mino{mino};
        this->minos.push_back(copy);
    }
}

Tetrimino::~Tetrimino() {
    std::for_each(minos.begin(), minos.end(), [](auto mino) { delete mino; });
}

void Tetrimino::rotateClockwise() {
    auto minX = std::numeric_limits<int>::max();
    auto minY = std::numeric_limits<int>::max();

    for (auto mino : minos) {
        auto newX = -mino->getY();
        auto newY = mino->getX();

        mino->setX(newX);
        mino->setY(newY);

        minX = std::min(minX, newX);
        minY = std::min(minY, newY);
    }

    auto offsetX = x - minX;
    auto offsetY = y - minY;

    adjustMinosToCurrentPosition(offsetX, offsetY, minos);
}

void Tetrimino::rotateCounterclockwise() {
    auto minX = std::numeric_limits<int>::max();
    auto minY = std::numeric_limits<int>::max();

    for (auto mino : minos) {
        auto newX = mino->getY();
        auto newY = -mino->getX();

        mino->setX(newX);
        mino->setY(newY);

        minX = std::min(minX, newX);
        minY = std::min(minY, newY);
    }

    auto offsetX = x - minX;
    auto offsetY = y - minY;

    adjustMinosToCurrentPosition(offsetX, offsetY, minos);
}

void Tetrimino::moveDown() {
    y++;
    std::for_each(minos.begin(), minos.end(),
                  [](auto mino) { mino->moveY(1); });
}

void Tetrimino::moveLeft() {
    x--;
    std::for_each(minos.begin(), minos.end(),
                  [](auto mino) { mino->moveX(-1); });
}

void Tetrimino::moveRight() {
    x++;
    std::for_each(minos.begin(), minos.end(),
                  [](auto mino) { mino->moveX(1); });
}

int Tetrimino::maxX() const {
    auto max = std::max_element(
        minos.begin(), minos.end(),
        [](auto mino1, auto mino2) { return mino1->getX() < mino2->getX(); });

    if (max == minos.end()) {
        return std::numeric_limits<int>::min();
    }

    return (*max)->getX();
}

int Tetrimino::maxY() const {
    auto max = std::max_element(
        minos.begin(), minos.end(),
        [](auto mino1, auto mino2) { return mino1->getY() < mino2->getY(); });

    if (max == minos.end()) {
        return std::numeric_limits<int>::min();
    }

    return (*max)->getY();
}

std::vector<Mino> Tetrimino::getMinos() const {
    std::vector<Mino> returnValue{};
    for (auto mino : minos) {
        returnValue.push_back(Mino{*mino});
    }
    return returnValue;
}

//
// Factories
//

TetriminoPtr createITetrimino() {
    return TetriminoPtr{
        new Tetrimino{std::vector<Mino>{Mino{0, 0, CYAN}, Mino{1, 0, CYAN},
                                        Mino{2, 0, CYAN}, Mino{3, 0, CYAN}}}};
}

TetriminoPtr createJTetrimino() {
    return TetriminoPtr{
        new Tetrimino{std::vector<Mino>{Mino{0, 0, BLUE}, Mino{0, 1, BLUE},
                                        Mino{1, 1, BLUE}, Mino{2, 1, BLUE}}}};
}

TetriminoPtr createLTetrimino() {
    return TetriminoPtr{new Tetrimino{
        std::vector<Mino>{Mino{0, 1, ORANGE}, Mino{1, 1, ORANGE},
                          Mino{2, 1, ORANGE}, Mino{2, 0, ORANGE}}}};
}

TetriminoPtr createOTetrimino() {
    return TetriminoPtr{new Tetrimino{
        std::vector<Mino>{Mino{0, 0, YELLOW}, Mino{1, 0, YELLOW},
                          Mino{0, 1, YELLOW}, Mino{1, 1, YELLOW}}}};
}

TetriminoPtr createTTetrimino() {
    return TetriminoPtr{new Tetrimino{
        std::vector<Mino>{Mino{1, 0, PURPLE}, Mino{0, 1, PURPLE},
                          Mino{1, 1, PURPLE}, Mino{2, 1, PURPLE}}}};
}

TetriminoPtr createSTetrimino() {
    return TetriminoPtr{
        new Tetrimino{std::vector<Mino>{Mino{1, 0, GREEN}, Mino{2, 0, GREEN},
                                        Mino{0, 1, GREEN}, Mino{1, 1, GREEN}}}};
}

TetriminoPtr createZTetrimino() {
    return TetriminoPtr{new Tetrimino{std::vector<Mino>{
        Mino{0, 0, RED}, Mino{1, 0, RED}, Mino{1, 1, RED}, Mino{2, 1, RED}}}};
}
