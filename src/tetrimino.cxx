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

Tetrimino::Tetrimino(int x, int y, const std::vector<Mino>& minos)
    : minos{}, x{x}, y{y} {
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

std::shared_ptr<Tetrimino> createITetrimino() {
    return std::shared_ptr<Tetrimino>{new Tetrimino{
        0, 0,
        std::vector<Mino>{Mino{0, 0}, Mino{1, 0}, Mino{2, 0}, Mino{3, 0}}}};
}

std::shared_ptr<Tetrimino> createJTetrimino() {
    return std::shared_ptr<Tetrimino>{new Tetrimino{
        0, 0,
        std::vector<Mino>{Mino{0, 0}, Mino{0, 1}, Mino{1, 1}, Mino{2, 1}}}};
}

std::shared_ptr<Tetrimino> createLTetrimino() {
    return std::shared_ptr<Tetrimino>{new Tetrimino{
        0, 0,
        std::vector<Mino>{Mino{0, 1}, Mino{1, 1}, Mino{2, 1}, Mino{2, 0}}}};
}

std::shared_ptr<Tetrimino> createOTetrimino() {
    return std::shared_ptr<Tetrimino>{new Tetrimino{
        0, 0,
        std::vector<Mino>{Mino{0, 0}, Mino{1, 0}, Mino{0, 1}, Mino{1, 1}}}};
}

std::shared_ptr<Tetrimino> createTTetrimino() {
    return std::shared_ptr<Tetrimino>{new Tetrimino{
        0, 0,
        std::vector<Mino>{Mino{1, 0}, Mino{0, 1}, Mino{1, 1}, Mino{2, 1}}}};
}

std::shared_ptr<Tetrimino> createSTetrimino() {
    return std::shared_ptr<Tetrimino>{new Tetrimino{
        0, 0,
        std::vector<Mino>{Mino{1, 0}, Mino{2, 0}, Mino{0, 1}, Mino{1, 1}}}};
}

std::shared_ptr<Tetrimino> createZTetrimino() {
    return std::shared_ptr<Tetrimino>{new Tetrimino{
        0, 0,
        std::vector<Mino>{Mino{0, 0}, Mino{1, 0}, Mino{1, 1}, Mino{2, 1}}}};
}
