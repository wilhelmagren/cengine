#ifndef DRAW_H
#define DRAW_H
#include "SDL2/SDL.h"
#include "mesh.h"
#include "color.h"
#include "mats.h"

void Draw_mesh(SDL_Renderer* renderer, Mesh* m, Mat4x4* proj, Mat4x4* rotX, Mat4x4* rotZ, uint8_t color[]);
#endif
