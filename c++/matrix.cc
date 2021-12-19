#include <iostream>
#include <algorithm>
#include "matrix.h"

template <typename T>
Mat4x4<T>::Mat4x4() {
    uint8_t i;
    for (i = 0; i < 16; i++) {data[i] = (T) 0.0;}
}

template <typename T>
T Mat4x4<T>::get(int idx) {
    return data[idx];
}

template <typename T>
void Mat4x4<T>::put(T d[]) {
    uint8_t i;
    for (i = 0; i < 16; i++) {data[i] = d[i];}
}

template <typename T>
void Mat4x4<T>::print() {
    printf("<class Mat4x4<%s> at %p>\n", typeid(T).name(), this);
    uint8_t i;
    for (i = 0; i < 4; i++) {printf("| %0.4f %0.4f %0.4f %0.4f |\n", data[4*i], data[1 + 4*i], data[2 + 4*i], data[3 + 4*i]);}
}

int main(int argc, char** argv) {
    Mat4x4 mat = Mat4x4<float>();
    mat.print();
    printf("idx=%d   value=%f\n", 2, mat.get(2));
    float xd[16];
    std::fill_n(xd, 16, 1.0f);
    mat.put(xd);
    mat.print();
    printf("idx=%d   value=%f\n", 2, mat.get(2));
    return 0;
}
