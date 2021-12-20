#ifndef RENDER_H
#define RENDER_H
#include "instance.h"
#include "polygon.h"

void CENGINE_RenderPolygon(SDL_Renderer* renderer, Polygon* polygon, COLOR color);

#endif
