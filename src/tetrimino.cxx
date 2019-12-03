#include "tetrimino.hh"
#include <algorithm>
#include <limits>

namespace {
void adjustBlockletsToCurrentPosition(int offsetX, int offsetY,
                                      const std::vector<Blocklet*>& blocklets) {
    for (auto blocklet : blocklets) {
        blocklet->moveX(offsetX);
        blocklet->moveY(offsetY);
    }
}

} // namespace

Tetrimino::Tetrimino(int x, int y, const std::vector<Blocklet>& blocklets)
    : blocklets{}, x{x}, y{y} {
    for (auto blocklet : blocklets) {
        auto copy = new Blocklet{blocklet};
        this->blocklets.push_back(copy);
    }
}

Tetrimino::~Tetrimino() {
    std::for_each(blocklets.begin(), blocklets.end(),
                  [](auto blocklet) { delete blocklet; });
}

void Tetrimino::rotateClockwise() {
    auto minX = std::numeric_limits<int>::max();
    auto minY = std::numeric_limits<int>::max();

    for (auto blocklet : blocklets) {
        auto newX = -blocklet->getY();
        auto newY = blocklet->getX();

        blocklet->setX(newX);
        blocklet->setY(newY);

        minX = std::min(minX, newX);
        minY = std::min(minY, newY);
    }

    auto offsetX = x - minX;
    auto offsetY = y - minY;

    adjustBlockletsToCurrentPosition(offsetX, offsetY, blocklets);
}

void Tetrimino::rotateCounterclockwise() {
    auto minX = std::numeric_limits<int>::max();
    auto minY = std::numeric_limits<int>::max();

    for (auto blocklet : blocklets) {
        auto newX = blocklet->getY();
        auto newY = -blocklet->getX();

        blocklet->setX(newX);
        blocklet->setY(newY);

        minX = std::min(minX, newX);
        minY = std::min(minY, newY);
    }

    auto offsetX = x - minX;
    auto offsetY = y - minY;

    adjustBlockletsToCurrentPosition(offsetX, offsetY, blocklets);
}

void Tetrimino::moveDown() {
    y++;
    std::for_each(blocklets.begin(), blocklets.end(),
                  [](auto blocklet) { blocklet->moveY(1); });
}

void Tetrimino::moveLeft() {
    x--;
    std::for_each(blocklets.begin(), blocklets.end(),
                  [](auto blocklet) { blocklet->moveX(-1); });
}

void Tetrimino::moveRight() {
    x++;
    std::for_each(blocklets.begin(), blocklets.end(),
                  [](auto blocklet) { blocklet->moveX(1); });
}

int Tetrimino::maxX() const {
    auto max = std::max_element(
        blocklets.begin(), blocklets.end(), [](auto blocklet1, auto blocklet2) {
            return blocklet1->getX() < blocklet2->getX();
        });

    if (max == blocklets.end()) {
        return std::numeric_limits<int>::min();
    }

    return (*max)->getX();
}

int Tetrimino::maxY() const {
    auto max = std::max_element(
        blocklets.begin(), blocklets.end(), [](auto blocklet1, auto blocklet2) {
            return blocklet1->getY() < blocklet2->getY();
        });

    if (max == blocklets.end()) {
        return std::numeric_limits<int>::min();
    }

    return (*max)->getY();
}

std::vector<Blocklet> Tetrimino::getBlocklets() const {
    std::vector<Blocklet> returnValue{};
    for (auto blocklet : blocklets) {
        returnValue.push_back(Blocklet{*blocklet});
    }
    return returnValue;
}

std::shared_ptr<Tetrimino> createITetrimino() {
    return std::shared_ptr<Tetrimino>{
        new Tetrimino{0, 0,
                      std::vector<Blocklet>{Blocklet{0, 0}, Blocklet{1, 0},
                                            Blocklet{2, 0}, Blocklet{3, 0}}}};
}

std::shared_ptr<Tetrimino> createJTetrimino() {
    return std::shared_ptr<Tetrimino>{
        new Tetrimino{0, 0,
                      std::vector<Blocklet>{Blocklet{0, 0}, Blocklet{0, 1},
                                            Blocklet{1, 1}, Blocklet{2, 1}}}};
}

std::shared_ptr<Tetrimino> createLTetrimino() {
    return std::shared_ptr<Tetrimino>{
        new Tetrimino{0, 0,
                      std::vector<Blocklet>{Blocklet{0, 1}, Blocklet{1, 1},
                                            Blocklet{2, 1}, Blocklet{2, 0}}}};
}

std::shared_ptr<Tetrimino> createOTetrimino() {
    return std::shared_ptr<Tetrimino>{
        new Tetrimino{0, 0,
                      std::vector<Blocklet>{Blocklet{0, 0}, Blocklet{1, 0},
                                            Blocklet{0, 1}, Blocklet{1, 1}}}};
}

std::shared_ptr<Tetrimino> createTTetrimino() {
    return std::shared_ptr<Tetrimino>{
        new Tetrimino{0, 0,
                      std::vector<Blocklet>{Blocklet{1, 0}, Blocklet{0, 1},
                                            Blocklet{1, 1}, Blocklet{2, 1}}}};
}

std::shared_ptr<Tetrimino> createSTetrimino() {
    return std::shared_ptr<Tetrimino>{
        new Tetrimino{0, 0,
                      std::vector<Blocklet>{Blocklet{1, 0}, Blocklet{2, 0},
                                            Blocklet{0, 1}, Blocklet{1, 1}}}};
}

std::shared_ptr<Tetrimino> createZTetrimino() {
    return std::shared_ptr<Tetrimino>{
        new Tetrimino{0, 0,
                      std::vector<Blocklet>{Blocklet{0, 0}, Blocklet{1, 0},
                                            Blocklet{1, 1}, Blocklet{2, 1}}}};
}
