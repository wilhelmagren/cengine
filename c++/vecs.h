#ifndef VECS_H
#define VECS_H

template <typename T>
class Vec2 {
    public:
        T x, y;
        Vec2(T x, T y);
        void add(Vec2<T> u);
};

template <typename T>
class Vec3 {
    public:
        T x, y, z;
        Vec3(T x, T y, T z);
        void add(Vec3<T> u);
        T dotprod(Vec3<T> u);
        Vec3<T> crossprod(Vec3<T> u);
        Vec3<T> matmul(Vec3<T> u);
};

template <typename T>
class Vec4 {
    public:
        T w, x, y, z;
        Vec4(T w, T x, T y, T z);
};

#endif
