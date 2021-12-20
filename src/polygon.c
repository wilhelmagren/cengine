#include <stdlib.h>
#include <stdio.h>
#include "polygon.h"

Polygon* Polygon_Constructor(Vec3* u, Vec3* v, Vec3* w) {
    Polygon* polygon = (Polygon*)malloc(sizeof(Polygon));
    u->pointers += 1;
    v->pointers += 1;
    w->pointers += 1;
    polygon->vecs[0] = u;
    polygon->vecs[1] = v;
    polygon->vecs[2] = w;
    return polygon;
}

Polygon* _CopyPolygon(Polygon* polygon) {
    Polygon* copy = (Polygon*)malloc(sizeof(Polygon));
    for (u8 i = 0; i < 3; i++) { copy->vecs[i] = _CopyVec3(polygon->vecs[i]); }
    return copy;
}

void CENGINE_DestroyPolygon(Polygon* polygon) {
    for (u8 i = 0; i < 3; i++) {
        u8 pointers = polygon->vecs[i]->pointers;
        if (pointers > 1) {
            polygon->vecs[i]->pointers--;
        } else {
            free(polygon->vecs[i]);
        }
    }
    free(polygon);
}
