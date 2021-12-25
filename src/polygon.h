#ifndef POLYGON_H
#define POLYGON_H
#include "utils.h"
#include "vec3.h"
#include "matrices.h"

typedef struct {
    Vec3* vecs[3];
    u8 color[3];
} Polygon;

Polygon* Polygon_Constructor(Vec3* u, Vec3* v, Vec3* w, const COLOR color);
Polygon* _PolygonCopy(Polygon* polygon);
void _PolygonProject(Polygon* a, Mat4x4* proj, Polygon* b);

#endif
