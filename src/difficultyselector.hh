#ifndef __DIFFICULTYSELECTOR_HH
#define __DIFFICULTYSELECTOR_HH

#include "gamedifficulty.hh"
#include "sdl/fontfactory.hh"
#include "sdl/renderable.hh"
#include "sdl/text.hh"
#include "sdl/window.hh"
#include "tetrimino/minotexturestore.hh"
#include "tetrimino/tetrimino.hh"

class DifficultySelector : public Renderable {
  public:
    DifficultySelector(const Window& window, FontFactory& fontFactory);
    virtual ~DifficultySelector() {}

    virtual void render(const Renderer& renderer);

    void selectNextDifficulty();
    void selectPreviousDifficulty();

    constexpr GameDifficulty getDifficulty() const { return difficulty; }

  private:
    GameDifficulty difficulty;
    MinoTextureStore minoTextureStore;
    std::shared_ptr<Tetrimino> selected;
    Text easyText;
    Text mediumText;
    Text hardText;

    void orientSelected();
};

#endif
