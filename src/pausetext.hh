#ifndef __PAUSETEXT_HH
#define __PAUSETEXT_HH

#include "fontfactory.hh"
#include "renderable.hh"
#include "text.hh"

class PauseText : public Renderable {
  public:
    PauseText(FontFactory& fontFactory);
    virtual ~PauseText() {}

    constexpr void reset() { rendered = false; }

    virtual void render(const Renderer& renderer);

  private:
    Text message;
    bool rendered;
};

#endif
