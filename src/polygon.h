#ifndef POLYGON_H
#define POLYGON_H
#include "vecs.h"
#include <stdint.h>


typedef struct {
    Vec3* vecs[3];
    float angle;
    float vx, vy, vz;
    const uint8_t color[3];
} Polygon;

Polygon* Polygon_new(Vec3* u, Vec3* v, Vec3* w,
        float angle, float vx, float vy, float vz, const uint8_t color[]);
void Polygon_print(Polygon* poly);

#endif
