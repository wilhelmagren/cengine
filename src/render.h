#ifndef RENDER_H
#define RENDER_H
#include "instance.h"
#include "polygon.h"
#include "utils.h"

void CENGINE_RenderPolygon(SDL_Renderer* renderer, Polygon* polygon, const COLOR color);

#endif
