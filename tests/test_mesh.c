#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../src/CENGINE.h"


int main(int argc, char** argv) {
    Mesh* mesh = Mesh_Constructor();

    Vec3* a = Vec3_Constructor(  0,  0,  3,  1);
    Vec3* b = Vec3_Constructor(  0,  1,  3,  1);
    Vec3* c = Vec3_Constructor(  1,  1,  3,  1);
    Vec3* d = Vec3_Constructor(  1,  0,  3,  1);

    Polygon* p1 = Polygon_Constructor(a, b, c);
    Polygon* p2 = Polygon_Constructor(a, c, d);

    _MeshPush(mesh, p1);
    _MeshPush(mesh, p2);
    _MeshPop(mesh);
    assert(mesh->idx == 1);


    Mesh* copy = _MeshCopy(mesh);

    _MeshPop(copy);
    assert(copy->idx == 0);

    CENGINE_DestroyMesh(mesh);
    CENGINE_DestroyMesh(copy);

    fprintf(stdout, "All tests passed for struct Mesh!\n");

    return 0;
}
