#ifndef __GAME_HH
#define __GAME_HH

#include "board.hh"
#include "boardrenderer.hh"
#include "fontfactory.hh"
#include "labelvalue.hh"
#include "preview.hh"
#include "renderable.hh"
#include "scorer.hh"
#include "soundcallback.hh"
#include "soundmemory.hh"
#include "tetriminostock.hh"
#include "text.hh"
#include "window.hh"

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
