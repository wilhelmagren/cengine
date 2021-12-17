#ifndef DRAW_H
#define DRAW_H
#include "SDL2/SDL.h"
#include "mesh.h"
#include "mats.h"

void Draw_polygon(SDL_Renderer* renderer, Polygon* poly, const uint8_t color[]);
void Draw_mesh(SDL_Renderer* renderer, Mesh* m, Mat4x4* proj, Mat4x4* rotX, Mat4x4* rotY, Mat4x4* rotZ, const uint8_t color[]);
#endif
