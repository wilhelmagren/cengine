#include <stdlib.h>
#include <stdio.h>
#include "instance.h"
#include "defaults.h"
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

    Polygon* p1 = Polygon_new(a, b, c);
    Polygon* p2 = Polygon_new(a, c, d);
    Polygon* p3 = Polygon_new(d, c, g);
    Polygon* p4 = Polygon_new(d, g, h);
    Polygon* p5 = Polygon_new(h, g, f);
    Polygon* p6 = Polygon_new(h, f, e);
    Polygon* p7 = Polygon_new(e, f, b);
    Polygon* p8 = Polygon_new(e, b, a);
    Polygon* p9 = Polygon_new(b, f, g);
    Polygon* p10 = Polygon_new(b, g, c);
    Polygon* p11 = Polygon_new(e, a, d);
    Polygon* p12 = Polygon_new(e, d, h);

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
    Instance_Mesh(instance, mesh);
    Instance_RUN(instance);
    return 0;
}
