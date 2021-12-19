#ifndef RENDER_H
#define RENDER_H
#include "SDL2/SDL.h"
#include "mesh.h"
#include "matrices.h"

void Render_polygon(SDL_Renderer* renderer, Polygon* poly, const uint8_t color[]);
void Render_mesh(SDL_Renderer* renderer, Mesh* m, Mat4x4* proj, const uint8_t color[]);
void _Render_mesh(SDL_Renderer* renderer, Mesh* m, Mat4x4* proj, Mat4x4* rotX, Mat4x4* rotY, Mat4x4* rotZ, const uint8_t color[]);
#endif
