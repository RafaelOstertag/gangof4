#ifndef __INTRO_HH
#define __INTRO_HH

#include "fontfactory.hh"
#include "renderable.hh"
#include "text.hh"
#include "window.hh"

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
