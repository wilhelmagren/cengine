#include <cstddef>
#include "mesh.h"

Mesh::Mesh() {
    idx = 0;
}

void Mesh::push(Polygon* poly) {
    polygons[idx] = poly;
    idx++;
}

Polygon* Mesh::pop() {
    if (idx <= 0 ) return NULL;

    idx--;
    return polygons[idx];
}
