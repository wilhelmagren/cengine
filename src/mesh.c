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

void _MeshProject(Mesh* mesh, Mat4x4* proj, Mesh* copy) {
    for (u8 i = 0; i < mesh->idx; i++) { _PolygonProject(mesh->polygons[i], proj, copy->polygons[i]); }
}

void _MeshRotate(Mesh* mesh, Mesh* copy) {
    for (u8 i = 0; i < mesh->idx; i++) {
        Mat4x4* rotZ = Mat4x4_RotationZ(mesh->polygons[i]->az);
        _PolygonRotate(mesh->polygons[i], rotZ, copy->polygons[i]);
        free(rotZ);

        Mat4x4* rotY = Mat4x4_RotationY(mesh->polygons[i]->ay);
        _PolygonRotate(copy->polygons[i], rotY, copy->polygons[i]);
        free(rotY);

        Mat4x4* rotX = Mat4x4_RotationX(mesh->polygons[i]->ax);
        _PolygonRotate(copy->polygons[i], rotX, copy->polygons[i]);
        free(rotX);
    }
}

void _MeshPrint(Mesh* mesh) {
    fprintf(stdout, "<struct Mesh with %d polygons at %p>\n", mesh->idx, mesh);
}
