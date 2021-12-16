#include "draw.h"

void Draw_polygon(SDL_Renderer* renderer, Polygon* poly, uint8_t color[]) {
    // x1,y1,x2,y2
    int i;
    SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], 255);
    for (i = 0; i < 3; i++) {
        float x1 = poly->vecs[i]->x;
        float y1 = poly->vecs[i]->y;
        float x2 = poly->vecs[(i+1)%3]->x;
        float y2 = poly->vecs[(i+1)%3]->y;
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }
}

void Draw_mesh(SDL_Renderer* renderer, Mesh* m, Mat4x4* proj, Mat4x4* rotX, Mat4x4* rotZ, uint8_t color[]) {
    int i;
    for (i = 0; i < m->pidx; i++) {
        Vec3d* projVec1 = Vec3d_new(0.0f, 0.0f, 0.0f);
        Vec3d* projVec2 = Vec3d_new(0.0f, 0.0f, 0.0f);
        Vec3d* projVec3 = Vec3d_new(0.0f, 0.0f, 0.0f);
        Vec3d* trslVec1 = Vec3d_new(0.0f, 0.0f, 0.0f);
        Vec3d* trslVec2 = Vec3d_new(0.0f, 0.0f, 0.0f);
        Vec3d* trslVec3 = Vec3d_new(0.0f, 0.0f, 0.0f);
        Vec3d* rotzVec1 = Vec3d_new(0.0f, 0.0f, 0.0f);
        Vec3d* rotzVec2 = Vec3d_new(0.0f, 0.0f, 0.0f);
        Vec3d* rotzVec3 = Vec3d_new(0.0f, 0.0f, 0.0f);
        Vec3d* rotVec1 = Vec3d_new(0.0f, 0.0f, 0.0f);
        Vec3d* rotVec2 = Vec3d_new(0.0f, 0.0f, 0.0f);
        Vec3d* rotVec3 = Vec3d_new(0.0f, 0.0f, 0.0f);
        Polygon* projected = Polygon_new(projVec1, projVec2, projVec3);
        Polygon* translated = Polygon_new(trslVec1, trslVec2, trslVec3);
        Polygon* rotatedZ = Polygon_new(rotzVec1, rotzVec2, rotzVec3);
        Polygon* rotatedZX = Polygon_new(rotVec1, rotVec2, rotVec3);
        /*
        rotatedZ->vecs[0]->x = m->polygons[i]->vecs[0]->x;
        rotatedZ->vecs[1]->x = m->polygons[i]->vecs[1]->x;
        rotatedZ->vecs[2]->x = m->polygons[i]->vecs[2]->x;
        rotatedZ->vecs[0]->y = m->polygons[i]->vecs[0]->y;
        rotatedZ->vecs[1]->y = m->polygons[i]->vecs[1]->y;
        rotatedZ->vecs[2]->y = m->polygons[i]->vecs[2]->y;
        rotatedZ->vecs[0]->z = m->polygons[i]->vecs[0]->z;
        rotatedZ->vecs[1]->z = m->polygons[i]->vecs[1]->z;
        rotatedZ->vecs[2]->z = m->polygons[i]->vecs[2]->z;
        */
        MatMul(m->polygons[i]->vecs[0], rotZ, rotatedZ->vecs[0]);
        MatMul(m->polygons[i]->vecs[1], rotZ, rotatedZ->vecs[1]);
        MatMul(m->polygons[i]->vecs[2], rotZ, rotatedZ->vecs[2]);

        MatMul(rotatedZ->vecs[0], rotX, rotatedZX->vecs[0]);
        MatMul(rotatedZ->vecs[1], rotX, rotatedZX->vecs[1]);
        MatMul(rotatedZ->vecs[2], rotX, rotatedZX->vecs[2]);

        translated->vecs[0]->x = rotatedZX->vecs[0]->x;
        translated->vecs[1]->x = rotatedZX->vecs[1]->x;
        translated->vecs[2]->x = rotatedZX->vecs[2]->x;
        translated->vecs[0]->y = rotatedZX->vecs[0]->y;
        translated->vecs[1]->y = rotatedZX->vecs[1]->y;
        translated->vecs[2]->y = rotatedZX->vecs[2]->y;
        translated->vecs[0]->z = rotatedZX->vecs[0]->z;
        translated->vecs[1]->z = rotatedZX->vecs[1]->z;
        translated->vecs[2]->z = rotatedZX->vecs[2]->z;
        translated->vecs[0]->z = rotatedZX->vecs[0]->z + 3.0f;
        translated->vecs[1]->z = rotatedZX->vecs[1]->z + 3.0f;
        translated->vecs[2]->z = rotatedZX->vecs[2]->z + 3.0f;

        MatMul(translated->vecs[0], proj, projected->vecs[0]);
        MatMul(translated->vecs[1], proj, projected->vecs[1]);
        MatMul(translated->vecs[2], proj, projected->vecs[2]);

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
        Draw_polygon(renderer, projected, color);
        free(projected);
        free(translated);
        free(rotatedZ);
        free(rotatedZX);
        free(projVec1);
        free(projVec2);
        free(projVec3);
        free(trslVec1);
        free(trslVec2);
        free(trslVec3);
        free(rotVec1);
        free(rotVec2);
        free(rotVec3);
        free(rotzVec1);
        free(rotzVec2);
        free(rotzVec3);
    }
}
