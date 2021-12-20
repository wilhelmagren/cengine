#ifndef POLYGON_H
#define POLYGON_H
#include "utils.h"
#include "vec3.h"

typedef struct {
    Vec3* vecs[3];
} Polygon;

Polygon* Polygon_Constructor(Vec3* u, Vec3* v, Vec3* w);
Polygon* _CopyPolygon(Polygon* polygon);
void CENGINE_DestroyPolygon(Polygon* polygon);

#endif
