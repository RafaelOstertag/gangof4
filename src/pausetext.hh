#ifndef __PAUSETEXT_HH
#define __PAUSETEXT_HH

#include "renderable.hh"
#include "text.hh"

class PauseText : public Renderable {
  public:
    PauseText();
    virtual ~PauseText() {}

    constexpr void reset() { rendered = false; }

    virtual void render(const Renderer& renderer);

  private:
    FontPtr font25;
    Text message;
    bool rendered;
};

#endif
