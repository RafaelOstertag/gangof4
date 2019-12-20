#ifndef __INTRO_HH
#define __INTRO_HH

#include "sdl/fontfactory.hh"
#include "sdl/renderable.hh"
#include "sdl/window.hh"
#include "sdl/text.hh"

class Intro : public Renderable {
  public:
    Intro(FontFactory& fontFactory);
    virtual ~Intro(){};

    virtual void render(const Renderer& renderer);

  private:
    Text labelQuit;
    Text quitKey;
    Text labelRestart;
    Text restartKey;
    Text labelPause;
    Text pauseKey;
    Text cursorKeys;
    Text labelStart;
};

#endif
