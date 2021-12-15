#ifndef POLYGON_H
#define POLYGON_H
#include "vecs.h"


typedef struct {
    Vec3d* vecs[3];
} Polygon;

Polygon* Polygon_new(Vec3d* u, Vec3d* v, Vec3d* w);
void Polygon_print(Polygon* poly);

#endif
