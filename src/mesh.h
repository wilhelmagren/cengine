#ifndef MESH_H
#define MESH_H
#include "polygon.h"
#include "matrices.h"
#include "utils.h"

typedef struct {
    Polygon* polygons[DEFAULT_MESH_BUFFER];
    u8 idx;
} Mesh;


Mesh* Mesh_Constructor();
Mesh* _MeshCopy(Mesh* mesh);
void _MeshPush(Mesh* mesh, Polygon* polygon);
Polygon* _MeshPop(Mesh* mesh);
void _MeshProject(Mesh* mesh, Mat4x4* proj, Mesh* copy);
void _MeshRotate(Mesh* mesh, Mesh* copy);
void _MeshTranslate(Mesh* mesh, f4 x, f4 y, f4 z, Mesh* copy);

void _MeshPrint(Mesh* mesh);

#endif
