#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "polygon.h"

Polygon* Polygon_new(Vec3* u, Vec3* v, Vec3* w,
        float angle, float vx, float vy, float vz, const uint8_t color[]) {
    Polygon* polygon = (Polygon*)malloc(sizeof(Polygon));
    polygon->vecs[0] = u;
    polygon->vecs[1] = v;
    polygon->vecs[2] = w;
    polygon->angle = angle;
    polygon->vx = vx;
    polygon->vy = vy;
    polygon->vz = vz;
    memcpy(polygon->color, color, sizeof(color));
    return polygon;
}

void Polygon_print(Polygon* poly) {
    char* string = "<struct Polygon at %p>\n";
    printf(string, poly);
}

void Polygon_Destroy(Polygon* poly) {
    Vec3_Destroy(poly->vecs[0]);
    Vec3_Destroy(poly->vecs[1]);
    Vec3_Destroy(poly->vecs[2]);
    free(poly);
}

void _TickPolygon(Polygon* poly) {
    poly->angle += 0.01f;
}

