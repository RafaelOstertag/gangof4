#include "renderer.hh"

Renderer::Renderer(SDL_Renderer* renderer) : sdlRenderer{renderer} {}

Renderer::~Renderer() {
    if (sdlRenderer) {
        SDL_DestroyRenderer(sdlRenderer);
    }
}

Renderer::Renderer(Renderer&& o) : sdlRenderer{o.sdlRenderer} {
    o.sdlRenderer = nullptr;
}

Renderer& Renderer::operator=(Renderer&& o) {
    if (sdlRenderer != nullptr) {
        SDL_DestroyRenderer(sdlRenderer);
    }
    
    sdlRenderer = o.sdlRenderer;
    o.sdlRenderer = nullptr;

    return *this;
}
