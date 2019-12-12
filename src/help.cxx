#include "help.hh"

Help::Help()
    : font25{new Font{"resources/lucidasansdemibold.ttf", 25}},
      labelQuit{font25, 232, 100, white, "Quit"}, quitKey{font25, 249, 130,
                                                          white, "Q"},
      labelRestart{font25, 218, 180, white, "Restart"}, restartKey{font25, 252,
                                                                   210, white,
                                                                   "R"},
      labelPause{font25, 223, 260, white, "Pause"}, pauseKey{font25, 253, 290,
                                                             white, "P"},
      labelStart{font25, 137, 340, white, "Press Enter to Start"} {}

void Help::render(const Renderer& renderer) {
    labelQuit.render(renderer);
    quitKey.render(renderer);
    labelRestart.render(renderer);
    restartKey.render(renderer);
    labelPause.render(renderer);
    pauseKey.render(renderer);
    labelStart.render(renderer);
}
