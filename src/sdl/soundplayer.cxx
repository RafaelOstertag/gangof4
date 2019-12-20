#include "soundplayer.hh"

#include <SDL_mixer.h>

namespace {
constexpr int NO_REPEAT = 0;
}

SoundPlayer::SoundPlayer(const SoundEffectPtr& soundEffect,
                         SoundChannel channel)
    : soundEffect{soundEffect}, channel{channel} {}

void SoundPlayer::play() const {
    auto chunk = soundEffect->getMixChunk();
    if (chunk != nullptr)
        Mix_PlayChannel(channel, chunk, NO_REPEAT);
}
