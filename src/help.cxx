#include "help.hh"

Help::Help(FontFactory& fontFactory)
    : labelQuit{fontFactory.createFont(25), 270, 100, WHITE, "QUIT"},
      quitKey{fontFactory.createFont(25), 292, 130, WHITE, "Q"},
      labelRestart{fontFactory.createFont(25), 247, 180, WHITE, "RESTART"},
      restartKey{fontFactory.createFont(25), 292, 210, WHITE, "R"},
      labelPause{fontFactory.createFont(25), 262, 260, WHITE, "PAUSE"},
      pauseKey{fontFactory.createFont(25), 292, 290, WHITE, "P"},
      labelStart{fontFactory.createFont(25), 150, 380, WHITE,
                 "PRESS ENTER TO START"} {}

void Help::render(const Renderer& renderer) {
    labelQuit.render(renderer);
    quitKey.render(renderer);
    labelRestart.render(renderer);
    restartKey.render(renderer);
    labelPause.render(renderer);
    pauseKey.render(renderer);
    labelStart.render(renderer);
}
