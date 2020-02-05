#ifndef __DIFFICULTYTEXT_HH
#define __DIFFICULTYTEXT_HH

#include "gamedifficulty.hh"
#include "sdl/fontfactory.hh"
#include "sdl/renderable.hh"
#include "sdl/text.hh"
#include <memory>

class DifficultyText : public Renderable {
  public:
    DifficultyText(GameDifficulty gameDifficulty, FontFactory& fontFactory);
    virtual ~DifficultyText() = default;

    virtual void render(const Renderer& renderer);

  private:
    Text message;
};

using DifficultyTextPtr = std::shared_ptr<DifficultyText>;

#endif
