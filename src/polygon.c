#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "polygon.h"

Polygon* Polygon_Constructor(Vec3* u, Vec3* v, Vec3* w, const COLOR color) {
    Polygon* polygon = (Polygon*)malloc(sizeof(Polygon));
    u->pointers += 1;
    v->pointers += 1;
    w->pointers += 1;
    polygon->vecs[0] = u;
    polygon->vecs[1] = v;
    polygon->vecs[2] = w;
    memcpy(&polygon->color, &color, 3*sizeof(u8));
    return polygon;
}

Polygon* _PolygonCopy(Polygon* polygon) {
    Polygon* copy = (Polygon*)malloc(sizeof(Polygon));
    for (u8 i = 0; i < 3; i++) { copy->vecs[i] = _Vec3Copy(polygon->vecs[i]); }
    return copy;
}

void _PolygonProject(Polygon* a, Mat4x4* proj, Polygon* b) {
    for (u8 i = 0; i < 3; i++) {
        _MatrixVecMultiply(a->vecs[i], proj, b->vecs[i]);
        _Vec3Divide(b->vecs[i], b->vecs[i]->w);
        _Vec3ScaleToWindow(b->vecs[i]);
    }
}
