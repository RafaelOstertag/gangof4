#ifndef __GAME_HH
#define __GAME_HH

#include "board.hh"
#include "boardrenderer.hh"
#include "fontfactory.hh"
#include "labelvalue.hh"
#include "normaltetriminostock.hh"
#include "preview.hh"
#include "renderable.hh"
#include "scorer.hh"
#include "soundcallback.hh"
#include "soundmemory.hh"
#include "text.hh"
#include "window.hh"

#include <memory>

class Game : public Renderable {
  public:
    Game(const Window& window, FontFactory& fontFactory);
    virtual ~Game();

    void rotateCurrentTetrimino() { board->rotateCurrentTetrimino(); }
    void moveCurrentTetriminoLeft() { board->moveCurrentTetriminoLeft(); }
    void moveCurrentTetriminoRight() { board->moveCurrentTetriminoRight(); }

    void nextMove();

    scorer_ptr_t getScorer() const { return scorer; }

    virtual void render(const Renderer& renderer);

  private:
    std::shared_ptr<TetriminoStock> tetriminoStock;
    scorer_ptr_t scorer;
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
