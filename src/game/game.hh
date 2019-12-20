#ifndef __GAME_HH
#define __GAME_HH

#include "../board/board.hh"
#include "../board/boardrenderer.hh"
#include "../scorer/scorer.hh"
#include "../sdl/fontfactory.hh"
#include "../sdl/renderable.hh"
#include "../sdl/window.hh"
#include "../tetrimino/tetriminostock.hh"
#include "../text.hh"
#include "labelvalue.hh"
#include "preview.hh"
#include "soundcallback.hh"

#include <memory>

class Game : public Renderable {
  public:
    Game(const Window& window, FontFactory& fontFactory,
         TetriminoStockPtr tetriminoStock, ScorerPtr scorer);
    virtual ~Game();

    void rotateCurrentTetrimino() { board->rotateCurrentTetrimino(); }
    void moveCurrentTetriminoLeft() { board->moveCurrentTetriminoLeft(); }
    void moveCurrentTetriminoRight() { board->moveCurrentTetriminoRight(); }

    void nextMove();

    ScorerPtr getScorer() const { return scorer; }

    virtual void render(const Renderer& renderer);

  private:
    TetriminoStockPtr tetriminoStock;
    ScorerPtr scorer;
    std::shared_ptr<Board> board;
    LabelValue score;
    LabelValue level;
    Text nextTetrimino;
    Text gameOverText;
    MinoTextureStore minoTextureStore;
    BoardRenderer boardRenderer;
    Preview preview;
};

using GamePtr = std::shared_ptr<Game>;
#endif
