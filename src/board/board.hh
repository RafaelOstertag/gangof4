#ifndef __BOARD_HH
#define __BOARD_HH

#include "../scorer/scorer.hh"
#include "../sdl/color.hh"
#include "../sdl/renderable.hh"
#include "../tetrimino/tetriminostock.hh"
#include "boardcallback.hh"

#include <array>
#include <list>
#include <set>
#include <vector>

class BoardRenderer;

class Board {
  public:
    static constexpr int HEIGHT_IN_MINOS = 24;
    static constexpr int WIDTH_IN_MINOS = 10;
    static constexpr int HALF_WIDTH_IN_MINOS = WIDTH_IN_MINOS / 2;

    Board(std::shared_ptr<TetriminoStock> tetriminoStock, const Color& color,
          ScorerPtr scorer);

    void nextMove();

    void moveCurrentTetriminoLeft();
    void moveCurrentTetriminoRight();
    void rotateCurrentTetrimino();

    bool isGameOver();

    void registerBoardCallback(BoardCallbackPtr callback);

  private:
    std::shared_ptr<TetriminoStock> tetriminoStock;
    Color color;
    ScorerPtr scorer;
    TetriminoPtr currentTetrimino;
    std::list<std::shared_ptr<Mino>> minos;
    std::vector<BoardCallbackPtr> callbacks;
    bool gameOver;

    bool drawTetrimino();
    void centerCurrentTetrimino();
    bool willCurrentTetriminoCollideBottom() const;
    bool willTetriminosCollideBottom(TetriminoPtr tetrimino) const;
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
