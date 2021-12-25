#ifndef INSTANCE_H
#define INSTANCE_H
#include "SDL2/SDL.h"
#include "utils.h"

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} Instance;

Instance* CENGINE_INIT(SDL_Window* window, SDL_Renderer* renderer);
Instance* CENGINE_INIT_FULL(f4 delay);
void CENGINE_LOOP(Instance* instance);

#endif
