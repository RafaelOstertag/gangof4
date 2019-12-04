#ifndef __BOARD_HH
#define __BOARD_HH

#include "renderable.hh"
#include "tetriminostock.hh"
#include <list>

class BoardRenderer;

class Board {
  public:
    static constexpr int height = 24;
    static constexpr int width = 10;

    Board(const TetriminoStock& tetriminoStock);

    void nextMove();

    void moveCurrentTetriminoLeft();
    void moveCurrentTetriminoRight();
    void rotateCurrentTetrimino();

    bool isGameOver();

  private:
    TetriminoStock tetriminoStock;
    std::shared_ptr<Tetrimino> currentTetrimino;
    std::list<std::shared_ptr<Tetrimino>> tetrimios;

    bool drawTetrimino();
    bool willCurrentTetriminoCollide() const;
    bool willTetriminosCollide(std::shared_ptr<Tetrimino> tetrimino) const;
    void handleCollision();

    friend BoardRenderer;
};

#endif
