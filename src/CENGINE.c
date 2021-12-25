#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "CENGINE.h"

void CENGINE_DrawPolygon(SDL_Renderer* renderer, Polygon* polygon) {
    SDL_SetRenderDrawColor(renderer, polygon->color[0], polygon->color[1], polygon->color[2], 255);
    for (u8 i = 0; i < 3; i++) {
        f8 x1 = polygon->vecs[i]->x;
        f8 y1 = polygon->vecs[i]->y;
        f8 x2 = polygon->vecs[(i + 1) % 3]->x;
        f8 y2 = polygon->vecs[(i + 1) % 3]->y;
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }
}

void CENGINE_DrawMesh(SDL_Renderer* renderer, Mesh* mesh) {
    for (u8 i = 0; i < mesh->idx; i++) { CENGINE_DrawPolygon(renderer, mesh->polygons[i]); }
}

void CENGINE_TickMesh(Mesh* mesh) {
    for (u8 i = 0; i < mesh->idx; i++) { _PolygonTick(mesh->polygons[i]); }
}

void CENGINE_DestroyPolygon(Polygon* polygon) {
    for (u8 i = 0; i < 3; i++) {
        u8 pointers = polygon->vecs[i]->pointers;
        if (pointers > 1) { polygon->vecs[i]->pointers--; }
        else { free(polygon->vecs[i]); }
    }

    free(polygon);
}

void CENGINE_DestroyMatrix(Mat4x4* matrix) {
    free(matrix);
}

void CENGINE_DestroyMesh(Mesh* mesh) {
    for (u8 i = 0; i < mesh->idx; i++) { free(mesh->polygons[i]); }
    free(mesh);
}

void CENGINE_DestroyInstance(Instance* instance) {
    SDL_DestroyWindow(instance->window);
    SDL_DestroyRenderer(instance->renderer);
    SDL_Quit();
    free(instance);
}
