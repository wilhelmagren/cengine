#include <SDL2/SDL.h>
#include <iostream>
#include "vec3.h"
#include "polygon.h"
#include "mesh.h"

int main(int argc, char** argv) {

    Vec3* a = new Vec3(0.0f, 0.0f, 1.0f);
    Vec3* b = new Vec3(0.0f, 1.0f, 1.0f);
    Vec3* c = new Vec3(1.0f, 1.0f, 1.0f);
    Vec3* d = new Vec3(1.0f, 0.0f, 1.0f);
    Polygon* poly1 = new Polygon(a, b, c);
    Polygon* poly2 = new Polygon(a, c, d);
    Mesh m = Mesh();
    m.push(poly1);
    m.push(poly2);
    
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
