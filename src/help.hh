#ifndef __HELP_HH
#define __HELP_HH

#include "fontfactory.hh"
#include "renderable.hh"
#include "text.hh"
#include "window.hh"

class Help : public Renderable {
  public:
    Help(FontFactory& fontFactory);
    virtual ~Help(){};

    virtual void render(const Renderer& renderer);

  private:
    Text labelQuit;
    Text quitKey;
    Text labelRestart;
    Text restartKey;
    Text labelPause;
    Text pauseKey;
    Text labelStart;
};

#endif
