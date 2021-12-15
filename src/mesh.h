#ifndef MESH_H
#define MESH_H
#include "vecs.h"
#include "polygon.h"
#include "defaults.h"

typedef struct {
    Polygon* polygons[MESH_BUFFER_SIZE];
    int pidx;
} Mesh;

Mesh* Mesh_new();
void Mesh_print(Mesh* m);
void Mesh_add(Mesh* m, Polygon* poly);

#endif 
