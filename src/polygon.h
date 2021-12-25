#ifndef POLYGON_H
#define POLYGON_H
#include "utils.h"
#include "vec3.h"
#include "matrices.h"

typedef struct {
    Vec3* vecs[3];
    u8 color[3];
    f4 ax, ay, az;
    f4 dx, dy, dz;
} Polygon;

Polygon* Polygon_Constructor(Vec3* u, Vec3* v, Vec3* w,
        f4 ax, f4 ay, f4 az, f4 dx, f4 dy, f4 dz, const COLOR color);
Polygon* _PolygonCopy(Polygon* polygon);
void _PolygonProject(Polygon* a, Mat4x4* proj, Polygon* b);
void _PolygonMatrixVecMultiply(Polygon* a, Mat4x4* matrix, Polygon* b);
void _PolygonTick(Polygon* polygon);

#endif
