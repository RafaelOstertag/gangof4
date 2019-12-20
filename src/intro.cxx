#include "intro.hh"

Intro::Intro(FontFactory& fontFactory)
    : labelQuit{fontFactory.createFont(BIG), 270, 100, WHITE, "QUIT"},
      quitKey{fontFactory.createFont(BIG), 292, 130, WHITE, "Q"},
      labelRestart{fontFactory.createFont(BIG), 247, 180, WHITE, "RESTART"},
      restartKey{fontFactory.createFont(BIG), 292, 210, WHITE, "R"},
      labelPause{fontFactory.createFont(BIG), 262, 260, WHITE, "PAUSE"},
      pauseKey{fontFactory.createFont(BIG), 292, 290, WHITE, "P"},
      labelStart{fontFactory.createFont(BIG), 150, 380, WHITE,
                 "PRESS ENTER TO START"} {}

void Intro::render(const Renderer& renderer) {
    labelQuit.render(renderer);
    quitKey.render(renderer);
    labelRestart.render(renderer);
    restartKey.render(renderer);
    labelPause.render(renderer);
    pauseKey.render(renderer);
    labelStart.render(renderer);
}
