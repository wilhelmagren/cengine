#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char** argv) {
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Could not initialize SDL: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("cengine++", SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, 1024, 768, 0);
    if (!window) {
        std::cout << "Could not create SDL window: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (!renderer) {
        std::cout << "Could not create SDL renderer: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_bool quit = SDL_FALSE;

    while (!quit) {

        SDL_Event event;
        SDL_RenderSetLogicalSize(renderer, 0, 0);
        SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = SDL_TRUE;
            }
        }
    }

    return 0;
}
