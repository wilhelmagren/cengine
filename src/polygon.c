#include <stdio.h>
#include <stdlib.h>
#include "polygon.h"

Polygon* Polygon_new(Vec3* u, Vec3* v, Vec3* w) {
    Polygon* poly = (Polygon*)malloc(sizeof(Polygon));
    poly->vecs[0] = u;
    poly->vecs[1] = v;
    poly->vecs[2] = w;
    return poly;
}

void Polygon_print(Polygon* poly) {
    char* string = "<struct Polygon at %p>\n";
    printf(string, poly);
}

