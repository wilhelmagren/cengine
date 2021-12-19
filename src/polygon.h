#ifndef POLYGON_H
#define POLYGON_H
#include "vecs.h"


typedef struct {
    Vec3* vecs[3];
} Polygon;

Polygon* Polygon_new(Vec3* u, Vec3* v, Vec3* w);
void Polygon_print(Polygon* poly);

#endif
