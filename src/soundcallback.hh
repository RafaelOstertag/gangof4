#ifndef __ROTATECALLBACK_HH
#define __ROTATECALLBACK_HH

#include "SDL_mixer.h"
#include "boardcallback.hh"
#include "sound.hh"

class SoundCallback : public BoardCallback {
  public:
    SoundCallback(BoardEvent listenTo, const Sound& sound, int channel)
        : listenTo{listenTo}, sound{sound}, channel{channel} {}
    virtual ~SoundCallback(){};

    virtual void call(BoardEvent event, const Board& board) {
        if (event != listenTo)
            return;
        Mix_PlayChannel(channel, sound.getMixChunk(), 0);
    }

  private:
    BoardEvent listenTo;
    const Sound& sound;
    int channel;
};

#endif
