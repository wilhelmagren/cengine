#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "CENGINE.h"

void CENGINE_DrawPolygon(SDL_Renderer* renderer, Polygon* polygon, const COLOR color) {
    SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], 255);
    for (u8 i = 0; i < 3; i++) {
        f8 x1 = polygon->vecs[i]->x;
        f8 y1 = polygon->vecs[i]->y;
        f8 x2 = polygon->vecs[(i + 1) % 3]->x;
        f8 y2 = polygon->vecs[(i + 1) % 3]->y;
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }
}

void CENGINE_DestroyPolygon(Polygon* polygon) {
    for (u8 i = 0; i < 3; i++) {
        u8 pointers = polygon->vecs[i]->pointers;
        if (pointers > 1) { polygon->vecs[i]->pointers--; }
        else { free(polygon->vecs[i]); }
    }

    free(polygon);
}

void CENGINE_DestroyInstance(Instance* instance) {
    SDL_DestroyWindow(instance->window);
    SDL_DestroyRenderer(instance->renderer);
    SDL_Quit();
    free(instance);
}
