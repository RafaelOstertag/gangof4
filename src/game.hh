#ifndef __GAME_HH
#define __GAME_HH

#include "board.hh"
#include "boardrenderer.hh"
#include "font.hh"
#include "normaltetriminostock.hh"
#include "preview.hh"
#include "renderable.hh"
#include "scorer.hh"
#include "soundfile.hh"
#include "text.hh"
#include "window.hh"

#include <memory>

class Game : public Renderable {
  public:
    Game(const Window& window);
    virtual ~Game();

    void rotateCurrentTetrimino();
    void moveCurrentTetriminoLeft();

    void moveCurrentTetriminoRight();
    void nextMove();

    scorer_ptr_t getScorer() const { return scorer; }

    virtual void render(const Renderer& renderer);

  private:
    std::shared_ptr<TetriminoStock> tetriminoStock;
    scorer_ptr_t scorer;
    std::shared_ptr<Board> board;
    FontPtr font18;
    FontPtr font25;
    Text scoreLabel;
    Text scoreText;
    Text levelLabel;
    Text levelText;
    Text nextTetrimino;
    Text gameOverText;
    MinoTextureStore minoTextureStore;
    BoardRenderer boardRenderer;
    Preview preview;
    SoundFile moveSound;
    SoundFile rotateSound;
};

using GamePtr = std::shared_ptr<Game>;
#endif
