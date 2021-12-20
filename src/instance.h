#ifndef INSTANCE_H
#define INSTANCE_H
#include "SDL2/SDL.h"

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} CENGINE_Instance;

CENGINE_Instance* CENGINE_INIT(SDL_Window* window, SDL_Renderer* renderer);
CENGINE_Instance* CENGINE_INIT_FULL();

#endif
