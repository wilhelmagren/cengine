#include "draw.h"

void Render_polygon(SDL_Renderer* renderer, Polygon* poly, const uint8_t color[]) {
    uint8_t i;
    SDL_SetRenderRenderColor(renderer, color[0], color[1], color[2], 255);
    for (i = 0; i < 3; i++) {
        float x1 = poly->vecs[i]->x;
        float y1 = poly->vecs[i]->y;
        float x2 = poly->vecs[(i+1)%3]->x;
        float y2 = poly->vecs[(i+1)%3]->y;
        SDL_RenderRenderLine(renderer, x1, y1, x2, y2);
    }
}

void Render_mesh(SDL_Renderer* renderer, Mesh* m, Mat4x4* proj, const uint8_t color[]) {
    uint8_t i;
    for (i = 0; i < m->pidx; i++) {
        Polygon* curr = m->polygons[i], projected;
        memcpy(projected, curr, sizeof(curr));
        MatMul(projected->vecs[0], proj, projected->vecs[0]);
        MatMul(projected->vecs[1], proj, projected->vecs[1]);
        MatMul(projected->vecs[2], proj, projected->vecs[0]);
        Render_polygon(renderer, projected, color);
    }
}

void _Render_mesh(SDL_Renderer* renderer, Mesh* m, Mat4x4* proj, Mat4x4* rotX, Mat4x4* rotY, Mat4x4* rotZ, const uint8_t color[]) {
    uint8_t i;
    for (i = 0; i < m->pidx; i++) {
        Vec3* projVec1 = Vec3_new(0.0f, 0.0f, 0.0f);
        Vec3* projVec2 = Vec3_new(0.0f, 0.0f, 0.0f);
        Vec3* projVec3 = Vec3_new(0.0f, 0.0f, 0.0f);

        Polygon* projected = Polygon_new(projVec1, projVec2, projVec3);

        MatMul(m->polygons[i]->vecs[0], rotZ, projected->vecs[0]);
        MatMul(m->polygons[i]->vecs[1], rotZ, projected->vecs[1]);
        MatMul(m->polygons[i]->vecs[2], rotZ, projected->vecs[2]);

        MatMul(projected->vecs[0], rotY, projected->vecs[0]);
        MatMul(projected->vecs[1], rotY, projected->vecs[1]);
        MatMul(projected->vecs[2], rotY, projected->vecs[2]);

        MatMul(projected->vecs[0], rotX, projected->vecs[0]);
        MatMul(projected->vecs[1], rotX, projected->vecs[1]);
        MatMul(projected->vecs[2], rotX, projected->vecs[2]);

        projected->vecs[0]->z += 3.0f;
        projected->vecs[1]->z += 3.0f;
        projected->vecs[2]->z += 3.0f;

        MatMul(projected->vecs[0], proj, projected->vecs[0]);
        MatMul(projected->vecs[1], proj, projected->vecs[1]);
        MatMul(projected->vecs[2], proj, projected->vecs[2]);

        projected->vecs[0]->x += 1.0f;
        projected->vecs[0]->y += 1.0f;
        projected->vecs[1]->x += 1.0f;
        projected->vecs[1]->y += 1.0f;
        projected->vecs[2]->x += 1.0f;
        projected->vecs[2]->y += 1.0f;
        
        projected->vecs[0]->x *= 0.5f * (float)WINDOW_W;
        projected->vecs[0]->y *= 0.5f * (float)WINDOW_H;
        projected->vecs[1]->x *= 0.5f * (float)WINDOW_W;
        projected->vecs[1]->y *= 0.5f * (float)WINDOW_H;
        projected->vecs[2]->x *= 0.5f * (float)WINDOW_W;
        projected->vecs[2]->y *= 0.5f * (float)WINDOW_H;
        Render_polygon(renderer, projected, color);
        free(projected);
        free(projVec1);
        free(projVec2);
        free(projVec3);
    }
}
