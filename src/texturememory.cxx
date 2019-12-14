#include "texturememory.hh"

#include <sstream>
#include <stdexcept>

TextureMemory::TextureMemory(void* ptr, int size, const Renderer& renderer)
    : texture{nullptr} {

    auto rwOpsPtr = SDL_RWFromMem(ptr, size);
    if (rwOpsPtr == nullptr) {
        std::ostringstream errorMessage;
        errorMessage << "Cannot create RWOps from memory: " << SDL_GetError();
        throw std::runtime_error(errorMessage.str());
    }

    auto bitmapSurface = SDL_LoadBMP_RW(rwOpsPtr, 0);
    if (bitmapSurface == nullptr) {
        std::ostringstream errorMessage;
        errorMessage << "Error loading bitmap from memory: " << SDL_GetError();

        throw std::invalid_argument(errorMessage.str());
    }

    texture = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    if (texture == nullptr) {
        std::ostringstream errorMessage;
        errorMessage << "Cannot convert surface to texture: " << SDL_GetError();

        throw std::invalid_argument(errorMessage.str());
    }

    SDL_FreeRW(rwOpsPtr);
    SDL_FreeSurface(bitmapSurface);
}

TextureMemory::TextureMemory(TextureMemory&& other) : texture{other.texture} {
    other.texture = nullptr;
}

TextureMemory& TextureMemory::operator=(TextureMemory&& other) {
    texture = other.texture;
    other.texture = nullptr;

    return *this;
}

TextureMemory::~TextureMemory() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
}
