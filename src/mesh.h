#ifndef MESH_H
#define MESH_H
#include "vecs.h"
#include "polygon.h"
#include "defaults.h"

typedef struct {
    Polygon* polygons[DEFAULT_MESH_BUFFER_SIZE];
    int pidx;
} Mesh;

Mesh* Mesh_new();
void Mesh_push(Mesh* m, Polygon* poly);
Polygon* Mesh_pop(Mesh* m);
void Mesh_print(Mesh* m);

#endif 
