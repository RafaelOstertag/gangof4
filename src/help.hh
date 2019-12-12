#ifndef __HELP_HH
#define __HELP_HH

#include "renderable.hh"
#include "text.hh"
#include "window.hh"

class Help : public Renderable {
  public:
    Help();
    virtual ~Help(){};

    virtual void render(const Renderer& renderer);

  private:
    FontPtr font25;
    Text labelQuit;
    Text quitKey;
    Text labelRestart;
    Text restartKey;
    Text labelPause;
    Text pauseKey;
    Text labelStart;
};

#endif
