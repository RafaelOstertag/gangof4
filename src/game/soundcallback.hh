#ifndef __ROTATECALLBACK_HH
#define __ROTATECALLBACK_HH

#include "../board/boardcallback.hh"
#include "../sdl/soundchannel.hh"
#include "../sdl/soundeffect.hh"
#include "../sdl/soundplayer.hh"

#include <SDL_mixer.h>

class SoundCallback : public BoardCallback {
  public:
    SoundCallback(BoardEvent listenTo, const SoundEffectPtr& soundEffect,
                  SoundChannel channel)
        : listenTo{listenTo}, soundPlayer{soundEffect, channel} {}
    virtual ~SoundCallback(){};

    virtual void call(BoardEvent event, const Board& board) {
        if (event != listenTo)
            return;
        soundPlayer.play();
    }

  private:
    BoardEvent listenTo;
    SoundPlayer soundPlayer;
};

#endif
