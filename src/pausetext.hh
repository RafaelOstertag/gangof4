#ifndef __PAUSETEXT_HH
#define __PAUSETEXT_HH

#include "sdl/fontfactory.hh"
#include "sdl/renderable.hh"
#include "sdl/text.hh"

class PauseText : public Renderable {
  public:
    PauseText(FontFactory& fontFactory);
    virtual ~PauseText() = default;

    constexpr void reset() { rendered = false; }

    virtual void render(const Renderer& renderer);

  private:
    Text message;
    bool rendered;
};

#endif
