#include "render.h"
#include "instance.h"

void _RenderPolygon(SDL_Renderer* renderer, Polygon* poly, const uint8_t color[]) {
    uint8_t i;
    SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], 255);
    for (i = 0; i < 3; i++) {
        float x1 = poly->vecs[i]->x;
        float y1 = poly->vecs[i]->y;
        float x2 = poly->vecs[(i+1)%3]->x;
        float y2 = poly->vecs[(i+1)%3]->y;
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }
}

void CENGINE_RenderMesh(Instance* instance, Mesh* m) {
    uint8_t i;
    for (i = 0; i < m->pidx; i++) {
        Polygon* curr = m->polygons[i];
        _RenderPolygon(instance->renderer, curr, curr->color);
    }
}
