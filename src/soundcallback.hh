#ifndef __ROTATECALLBACK_HH
#define __ROTATECALLBACK_HH

#include "SDL_mixer.h"
#include "boardcallback.hh"
#include "soundeffect.hh"

class SoundCallback : public BoardCallback {
  public:
    SoundCallback(BoardEvent listenTo, const SoundEffect& soundEffect,
                  int channel)
        : listenTo{listenTo}, soundEffect{soundEffect}, channel{channel} {}
    virtual ~SoundCallback(){};

    virtual void call(BoardEvent event, const Board& board) {
        if (event != listenTo)
            return;
        Mix_PlayChannel(channel, soundEffect.getMixChunk(), 0);
    }

  private:
    BoardEvent listenTo;
    const SoundEffect& soundEffect;
    int channel;
};

#endif
