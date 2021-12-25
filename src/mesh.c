#include <stdlib.h>
#include <stdio.h>
#include "mesh.h"

Mesh* Mesh_Constructor() {
    Mesh* mesh = (Mesh*)malloc(sizeof(Mesh));
    mesh->idx = 0;
    return mesh;
}

void _MeshPush(Mesh* mesh, Polygon* polygon) {
    mesh->polygons[mesh->idx] = polygon;
    mesh->idx ++;
}

Polygon* _MeshPop(Mesh* mesh) {
    if (!mesh->idx) return NULL;
    Polygon* polygon = mesh->polygons[mesh->idx];
    mesh->idx--;
    return polygon;
}

void _MeshPrint(Mesh* mesh) {
    fprintf(stdout, "<struct Mesh with %d polygons at %p>\n", mesh->idx--, mesh);
}
