#ifndef __BOARD_HH
#define __BOARD_HH

#include "boardcallback.hh"
#include "color.hh"
#include "renderable.hh"
#include "scorer.hh"
#include "tetriminostock.hh"

#include <array>
#include <list>
#include <set>
#include <vector>

class BoardRenderer;

class Board {
  public:
    static constexpr int height = 24;
    static constexpr int width = 10;

    Board(std::shared_ptr<TetriminoStock> tetriminoStock, const Color& color,
          scorer_ptr_t scorer);

    void nextMove();

    void moveCurrentTetriminoLeft();
    void moveCurrentTetriminoRight();
    void rotateCurrentTetrimino();

    bool isGameOver();

    void registerBoardCallback(BoardCallbackPtr callback);

  private:
    std::shared_ptr<TetriminoStock> tetriminoStock;
    Color color;
    scorer_ptr_t scorer;
    std::shared_ptr<Tetrimino> currentTetrimino;
    std::list<std::shared_ptr<Mino>> minos;
    std::vector<BoardCallbackPtr> callbacks;
    bool gameOver;

    bool drawTetrimino();
    bool willCurrentTetriminoCollideBottom() const;
    bool
    willTetriminosCollideBottom(std::shared_ptr<Tetrimino> tetrimino) const;
    bool willTetriminosCollideLeft() const;
    bool willTetriminosCollideRight() const;
    void handleCollision();
    int compactBoard();
    bool isRowFull(int row) const;
    void removeRow(int row);
    void moveMinosAboveRowDown(int row);

    void callCallbacks(BoardEvent event);

    friend BoardRenderer;
};

#endif
