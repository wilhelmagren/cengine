#include <stdlib.h>
#include <stdio.h>
#include "instance.h"
#include "defaults.h"
#include "colors.h"
#include "render.h"
#include "mesh.h"
#include "polygon.h"
#include "matrices.h"
#include "vecs.h"


int main(int argc, char** argv) {
    Vec3* a = Vec3_new(0.0f, 0.0f, 0.0f);
    Vec3* b = Vec3_new(0.0f, 1.0f, 0.0f);
    Vec3* c = Vec3_new(1.0f, 1.0f, 0.0f);
    Vec3* d = Vec3_new(1.0f, 0.0f, 0.0f);
    Vec3* e = Vec3_new(0.0f, 0.0f, 1.0f);
    Vec3* f = Vec3_new(0.0f, 1.0f, 1.0f);
    Vec3* g = Vec3_new(1.0f, 1.0f, 1.0f);
    Vec3* h = Vec3_new(1.0f, 0.0f, 1.0f);

    Polygon* p1 = Polygon_new(a, b, c, 0.0f, 0.5f, 0.0f, 0.8f, WHITE);
    Polygon* p2 = Polygon_new(a, c, d, 0.0f, 0.5f, 0.0f, 0.8f, WHITE);
    Polygon* p3 = Polygon_new(d, c, g, 0.0f, 0.5f, 0.0f, 0.8f, WHITE);
    Polygon* p4 = Polygon_new(d, g, h, 0.0f, 0.5f, 0.0f, 0.8f, WHITE);
    Polygon* p5 = Polygon_new(h, g, f, 0.0f, 0.5f, 0.0f, 0.8f, WHITE);
    Polygon* p6 = Polygon_new(h, f, e, 0.0f, 0.5f, 0.0f, 0.8f, WHITE);
    Polygon* p7 = Polygon_new(e, f, b, 0.0f, 0.5f, 0.0f, 0.8f, WHITE);
    Polygon* p8 = Polygon_new(e, b, a, 0.0f, 0.5f, 0.0f, 0.8f, WHITE);
    Polygon* p9 = Polygon_new(b, f, g, 0.0f, 0.5f, 0.0f, 0.8f, WHITE);
    Polygon* p10 = Polygon_new(b, g, c, 0.0f, 0.5f, 0.0f, 0.8f, WHITE);
    Polygon* p11 = Polygon_new(e, a, d, 0.0f, 0.5f, 0.0f, 0.8f, WHITE);
    Polygon* p12 = Polygon_new(e, d, h, 0.0f, 0.5f, 0.0f, 0.8f, WHITE);

    Mesh* mesh = Mesh_new();
    Mesh_push(mesh, p1);
    Mesh_push(mesh, p2);
    Mesh_push(mesh, p3);
    Mesh_push(mesh, p4);
    Mesh_push(mesh, p5);
    Mesh_push(mesh, p6);
    Mesh_push(mesh, p7);
    Mesh_push(mesh, p8);
    Mesh_push(mesh, p9);
    Mesh_push(mesh, p10);
    Mesh_push(mesh, p11);
    Mesh_push(mesh, p12);

    Mesh_print(mesh);

    Instance* instance = Instance_FULL_INIT();
    instance->mesh = mesh;
    Mesh_print(instance->mesh);
    Instance_RUN(instance);
    return 0;
}
