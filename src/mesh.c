#include <stdlib.h>
#include <stdio.h>
#include "mesh.h"


Mesh* Mesh_new() {
    Mesh* m = (Mesh*)malloc(sizeof(Mesh));
    m->pidx = 0;
    return m;
}

void Mesh_print(Mesh* m) {
    char* string = "<struct Mesh with %d polygons at %p>\n";
    printf(string, m->pidx, m);
}

void Mesh_add(Mesh* m, Polygon* poly) {
    m->polygons[m->pidx] = poly;
    m->pidx++;
}

int main() {
    Vec3d* u = Vec3d_new(0.0f, 0.0f, 0.0f);
    Vec3d* v = Vec3d_new(0.0f, 1.0f, 0.0f);
    Vec3d* w = Vec3d_new(1.0f, 1.0f, 0.0f);
    Polygon* poly = Polygon_new(u,v,w);
    Polygon_print(poly);
    Mesh* m = Mesh_new();
    Mesh_add(m, poly);
    Mesh_print(m);
    return 0;
}

