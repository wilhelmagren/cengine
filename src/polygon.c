#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "polygon.h"

Polygon* Polygon_Constructor(Vec3* u, Vec3* v, Vec3* w,
        f4 ax, f4 ay, f4 az, f4 dx, f4 dy, f4 dz, const COLOR color) {
    Polygon* polygon = (Polygon*)malloc(sizeof(Polygon));
    u->pointers += 1;
    v->pointers += 1;
    w->pointers += 1;
    polygon->vecs[0] = u;
    polygon->vecs[1] = v;
    polygon->vecs[2] = w;
    polygon->ax = ax;
    polygon->ay = ay;
    polygon->az = az;
    polygon->dx = dx;
    polygon->dy = dy;
    polygon->dz = dz;
    polygon->color[0] = color[0];
    polygon->color[1] = color[1];
    polygon->color[2] = color[2];
    return polygon;
}

Polygon* _PolygonCopy(Polygon* polygon) {
    Polygon* copy = (Polygon*)malloc(sizeof(Polygon));
    for (u8 i = 0; i < 3; i++) { copy->vecs[i] = _Vec3Copy(polygon->vecs[i]); }
    copy->ax = polygon->ax;
    copy->ay = polygon->ay;
    copy->az = polygon->az;
    copy->dx = polygon->dx;
    copy->dy = polygon->dy;
    copy->dz = polygon->dz;
    copy->color[0] = polygon->color[0];
    copy->color[1] = polygon->color[1];
    copy->color[2] = polygon->color[2];
    return copy;
}

void _PolygonProject(Polygon* a, Mat4x4* proj, Polygon* b) {
    for (u8 i = 0; i < 3; i++) {
        _MatrixVecMultiply(a->vecs[i], proj, b->vecs[i]);
        _Vec3Divide(b->vecs[i], b->vecs[i]->w);
        _Vec3ScaleToWindow(b->vecs[i]);
    }
}

void _PolygonMatrixVecMultiply(Polygon* a, Mat4x4* matrix, Polygon* b) {
    for (u8 i = 0; i < 3; i++) { _MatrixVecMultiply(a->vecs[i], matrix, b->vecs[i]); }
}

void _PolygonTick(Polygon* polygon) {
    polygon->ax += polygon->dx;
    polygon->ay += polygon->dy;
    polygon->az += polygon->dz;
}
