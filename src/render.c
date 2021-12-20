#include "SDL2/SDL.h"
#include "render.h"
#include "instance.h"

void CENGINE_RenderPolygon(SDL_Renderer* renderer, Polygon* polygon, COLOR color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    for (u8 i = 0; i < 3; i++) {
        f8 x1 = polygon->vecs[i]->x;
        f8 y1 = polygon->vecs[i]->y;
        f8 x2 = polygon->vecs[(i+1)%3]->x;
        f8 y2 = polygon->vecs[(i+1)%3]->y;
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }
}
