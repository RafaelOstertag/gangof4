#include "sdl.hh"

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>

bool init_sdl() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cerr << "Cannot initialize SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 4, 4096) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: "
                  << Mix_GetError() << std::endl;
        return false;
    }

    if (TTF_Init() == -1) {
        std::cerr << "Cannot initialize SDL TTF: " << TTF_GetError()
                  << std::endl;
        return false;
    }

    return true;
}

void quit_sdl() {
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
}
