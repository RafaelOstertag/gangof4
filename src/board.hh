#ifndef __BOARD_HH
#define __BOARD_HH

#include "renderable.hh"
#include "tetriminostock.hh"

#include <array>
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
    std::array<std::array<std::shared_ptr<Tetrimino>, width>, height>
        reverseMap;

    bool drawTetrimino();
    bool willCurrentTetriminoCollideBottom() const;
    bool
    willTetriminosCollideBottom(std::shared_ptr<Tetrimino> tetrimino) const;
    bool willTetriminosCollideLeft() const;
    bool willTetriminosCollideRight() const;
    void handleCollision();

    void addTetriminoToReverseMap(std::shared_ptr<Tetrimino> tetrimino);

    void compactBoard();
    void rebuildBoard();
    bool isRowFull(int row) const;
    void removeRow(int row);

    friend BoardRenderer;
};

#endif
