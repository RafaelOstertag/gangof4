#ifndef __SOUNDPLAYER_HH
#define __SOUNDPLAYER_HH

#include "soundchannel.hh"
#include "soundeffect.hh"

class SoundPlayer {
  public:
    SoundPlayer(const SoundEffectPtr& soundEffect, SoundChannel channel);
    void play() const;

  private:
    SoundEffectPtr soundEffect;
    SoundChannel channel;
};

#endif
