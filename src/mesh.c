#include <stdlib.h>
#include <stdio.h>
#include "mesh.h"


Mesh* Mesh_new() {
    Mesh* m = (Mesh*)malloc(sizeof(Mesh));
    m->pidx = 0;
    return m;
}

void Mesh_push(Mesh* m, Polygon* poly) {
    m->polygons[m->pidx] = poly;
    m->pidx++;
}

Polygon* Mesh_pop(Mesh* m) {
    if (m->pidx <= 0) {
        return NULL;
    }
    m->pidx--;
    Polygon* ret = m->polygons[m->pidx];
    return ret;
}

void Mesh_print(Mesh* m) {
    char* string = "<struct Mesh with %d polygons at %p>\n";
    printf(string, m->pidx, m);
}
