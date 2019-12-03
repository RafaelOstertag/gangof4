#ifndef __TETRIMINO_HH
#define __TETRIMINO_HH

#include "blocklet.hh"
#include <memory>
#include <vector>

class Tetrimino {
  public:
    Tetrimino(int x, int y, const std::vector<Blocklet>& blocklets);
    ~Tetrimino();

    Tetrimino(const Tetrimino&) = delete;
    Tetrimino& operator=(const Tetrimino&) = delete;

    void rotateClockwise();
    void rotateCounterclockwise();

    void moveLeft();
    void moveRight();
    void moveDown();

    int getX() const { return x; }
    int getY() const { return y; }
    int maxX() const;
    int maxY() const;

    std::vector<Blocklet> getBlocklets() const;

  private:
    std::vector<Blocklet*> blocklets;
    int x;
    int y;
};

std::shared_ptr<Tetrimino> createITetrimino();
std::shared_ptr<Tetrimino> createJTetrimino();
std::shared_ptr<Tetrimino> createLTetrimino();
std::shared_ptr<Tetrimino> createOTetrimino();
std::shared_ptr<Tetrimino> createTTetrimino();
std::shared_ptr<Tetrimino> createSTetrimino();
std::shared_ptr<Tetrimino> createZTetrimino();

#endif
