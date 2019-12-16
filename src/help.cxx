#include "help.hh"
#include "veramonobold.hh"

Help::Help()
    : font25{new Font{veraMonoBoldTTF.data, veraMonoBoldTTF.size, 25}},
      labelQuit{font25, 270, 100, white, "QUIT"}, quitKey{font25, 292, 130,
                                                          white, "Q"},
      labelRestart{font25, 247, 180, white, "RESTART"}, restartKey{font25, 292,
                                                                   210, white,
                                                                   "R"},
      labelPause{font25, 262, 260, white, "PAUSE"}, pauseKey{font25, 292, 290,
                                                             white, "P"},
      labelStart{font25, 150, 380, white, "PRESS ENTER TO START"} {}

void Help::render(const Renderer& renderer) {
    labelQuit.render(renderer);
    quitKey.render(renderer);
    labelRestart.render(renderer);
    restartKey.render(renderer);
    labelPause.render(renderer);
    pauseKey.render(renderer);
    labelStart.render(renderer);
}
