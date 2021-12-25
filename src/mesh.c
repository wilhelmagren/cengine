#include <stdlib.h>
#include <stdio.h>
#include "mesh.h"

Mesh* Mesh_Constructor() {
    Mesh* mesh = (Mesh*)malloc(sizeof(Mesh));
    mesh->idx = 0;
    return mesh;
}

Mesh* _MeshCopy(Mesh* mesh) {
    Mesh* copy = (Mesh*)malloc(sizeof(Mesh));
    copy->idx = mesh->idx;
    for (u8 i = 0; i < mesh->idx; i++) { copy->polygons[i] = _PolygonCopy(mesh->polygons[i]); }
    return copy;
}

void _MeshPush(Mesh* mesh, Polygon* polygon) {
    mesh->polygons[mesh->idx] = polygon;
    mesh->idx++;
}

Polygon* _MeshPop(Mesh* mesh) {
    if (mesh->idx <= 0) return NULL;
    mesh->idx--;
    return mesh->polygons[mesh->idx];
}

void _MeshPrint(Mesh* mesh) {
    fprintf(stdout, "<struct Mesh with %d polygons at %p>\n", mesh->idx, mesh);
}
