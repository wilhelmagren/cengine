#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "CENGINE.h"

void CENGINE_DrawPolygon(SDL_Renderer* renderer, Polygon* polygon) {
    SDL_SetRenderDrawColor(renderer, polygon->color[0], polygon->color[1], polygon->color[2], 255);
    Vec3* l1 = _Vec3Copy(polygon->vecs[1]);
    Vec3* l2 = _Vec3Copy(polygon->vecs[2]);
    _Vec3Subtract(polygon->vecs[1], polygon->vecs[0], l1);
    _Vec3Subtract(polygon->vecs[2], polygon->vecs[0], l2);
    _Vec3CrossProduct(l1, l2, l1);
    _Vec3Normalize(l1);
    Vec3* camera = Vec3_Constructor(0.0, 0.0, 0.0, 1.0);
    _Vec3Subtract(polygon->vecs[0], camera, camera);

    if (_Vec3DotProduct(l1, camera) < 0.0) {
        for (u8 i = 0; i < 3; i++) {
            f8 x1 = polygon->vecs[i]->x;
            f8 y1 = polygon->vecs[i]->y;
            f8 x2 = polygon->vecs[(i + 1) % 3]->x;
            f8 y2 = polygon->vecs[(i + 1) % 3]->y;
            SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
        }
    }
    free(l1);
    free(l2);
    free(camera);
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
