#include <iostream>
#include "vecs.h"

template <typename T>
Vec2<T>::Vec2(T x, T y) {
    x = x;
    y = y;
}


template <typename T>
Vec3<T>::Vec3(T x, T y, T z) {
    x = x;
    y = y;
    z = z;
}

template <typename T>
void Vec3<T>::add(Vec3<T> u) {
    x += u.x;
    y += u.y;
    z += u.z;
}

template <typename T>
T Vec3<T>::dotprod(Vec3<T> u) {
    return x*u.x + y*u.y + z*u.z;
}

template <typename T>
Vec3<T> Vec3<T>::crossprod(Vec3<T> u) {
    T crossx = y*u.z - z*u.y;
    T crossy = z*u.x - x*u.z;
    T crossz = x*u.y - y*u.x;
    return Vec3<T>(crossx, crossy, crossz);
}

template <typename T>
Vec3<T> Vec3<T>::matmul(Vec3<T> u) {
    T mulx = x*u.x;
    T muly = y*u.y;
    T mulz = x*u.z;
    return Vec3<T>(mulx, muly, mulz);
}

template <typename T>
Vec4<T>::Vec4(T w, T x, T y, T z) {
    w = w;
    x = x;
    y = y;
    z = z;
}


int main(int argc, char** argv) {
    std::cout << "Hello!\n";
    return 0;
}
