#include "sdl.hh"
#include "soundchannel.hh"

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>

void SDL::initialize() {
    if (initialized) {
#ifndef NDEBUG
        std::cerr << "Already initialized\n";
#endif
        return;
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cerr << "Cannot initialize SDL: " << SDL_GetError() << "\n";
        initialized = false;
        return;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, NUMBER_OF_CHANNELS, 4096) <
        0) {
        std::cerr << "No sound available, SDL_mixer error: " << Mix_GetError()
                  << "\n";
        soundAvailable = false;
    } else {
        soundAvailable = true;
    }

    if (TTF_Init() == -1) {
        std::cerr << "Cannot initialize SDL TTF: " << TTF_GetError() << "\n";
        initialized = false;
        return;
    }

    initialized = true;
}

void SDL::shutdown() {
    if (!initialized) {
#ifndef NDEBUG
        std::cerr << "Not initialized, won't shutdown\n";
#endif
        return;
    }
    if (soundAvailable) {
        Mix_Quit();
    }
    TTF_Quit();
    SDL_Quit();
    initialized = false;
}

bool SDL::initialized = false;
bool SDL::soundAvailable = false;
