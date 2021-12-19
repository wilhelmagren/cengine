#ifndef MATRIX_H
#define MATRIX_H

template <typename T>
class Mat4x4 {
    private:
        T data[16];

    public:
        Mat4x4();
        T get(int idx);
        void put(T data[]);
        void print();
};


#endif
