#ifndef __BOARD_HH
#define __BOARD_HH

#include "color.hh"
#include "renderable.hh"
#include "tetriminostock.hh"

#include <array>
#include <list>
#include <set>

class BoardRenderer;

class Board {
  public:
    static constexpr int height = 24;
    static constexpr int width = 10;

    Board(std::shared_ptr<TetriminoStock> tetriminoStock, const Color& color);

    void nextMove();

    void moveCurrentTetriminoLeft();
    void moveCurrentTetriminoRight();
    void rotateCurrentTetrimino();

    bool isGameOver();

  private:
    std::shared_ptr<TetriminoStock> tetriminoStock;
    Color color;
    std::shared_ptr<Tetrimino> currentTetrimino;
    std::list<std::shared_ptr<Mino>> minos;
    bool gameOver;

    bool drawTetrimino();
    bool willCurrentTetriminoCollideBottom() const;
    bool
    willTetriminosCollideBottom(std::shared_ptr<Tetrimino> tetrimino) const;
    bool willTetriminosCollideLeft() const;
    bool willTetriminosCollideRight() const;
    void handleCollision();
    void compactBoard();
    bool isRowFull(int row) const;
    void removeRow(int row);
    void moveMinosAboveRowDown(int row);

    friend BoardRenderer;
};

#endif
