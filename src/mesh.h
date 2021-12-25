#ifndef MESH_H
#define MESH_H
#include "polygon.h"
#include "utils.h"

typedef struct {
    Polygon* polygons[DEFAULT_MESH_BUFFER];
    u8 idx;
} Mesh;


Mesh* Mesh_Constructor();
void _MeshPush(Mesh* mesh, Polygon* polygon);
Polygon* _MeshPop(Mesh* mesh);
void _MeshPrint(Mesh* mesh);

#endif
