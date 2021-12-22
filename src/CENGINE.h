#ifndef CENGINE_H
#define CENGINE_H
#include "SDL2/SDL.h"
#include "instance.h"
#include "matrices.h"
#include "polygon.h"
#include "utils.h"
#include "vec3.h"


// void CENGINE_DrawMesh(Mesh* mesh);
void CENGINE_DrawPolygon(SDL_Renderer* renderer, Polygon* polygon, const COLOR color);
void CENGINE_DestroyPolygon(Polygon* polygon);
void CENGINE_DestroyInstance(Instance* instance);

#endif
