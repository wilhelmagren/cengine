#ifndef MESH_H
#define MESH_H
#include "vecs.h"
#include "polygon.h"
#include "defaults.h"

typedef struct {
    Polygon* polygons[MESH_BUFFER_SIZE];
    int num_polygons;
} Mesh;

Mesh* mesh_new();
void mesh_print(Mesh* m);

#endif 
