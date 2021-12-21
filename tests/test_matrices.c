#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../src/matrices.h"


int main(int argc, char** argv) {
    Mat4x4* zeros = Mat4x4_Zeros();
    Mat4x4* ones = Mat4x4_Ones();
    Mat4x4* identity = Mat4x4_Identity();

    _MatrixPrint(zeros, false);
    _MatrixPrint(ones, false);
    _MatrixPrint(identity, false);


    Mat4x4* zerostmp = Mat4x4_Zeros();
    Mat4x4* onestmp = Mat4x4_Zeros();
    Mat4x4* randtmp = Mat4x4_Zeros();
    f4 tmp[4][4] = {
    {1.0, 2.0, 3.0, 4.0},
    {2.0, 1.0, 2.0, 3.0},
    {3.0, 2.0, 1.0, 2.0},
    {4.0, 3.0, 2.0, 1.0} };
    Mat4x4* rand = Mat4x4_Create(tmp);

    _MatrixPrint(rand, true);

    _MatrixMatrixMultiply(zeros, ones, zerostmp);
    _MatrixMatrixMultiply(ones, ones, onestmp);
    _MatrixMatrixMultiply(rand, identity, randtmp);

    _MatrixPrint(zerostmp, true);
    _MatrixPrint(onestmp, true);
    _MatrixPrint(randtmp, true);

    assert(_MatrixAllEqual(zerostmp, 0.0));
    assert(_MatrixAllEqual(onestmp, 4.0));
    assert(_MatrixEqualMatrix(rand, randtmp));

    CENGINE_DestroyMat4x4(zeros);
    CENGINE_DestroyMat4x4(ones);
    CENGINE_DestroyMat4x4(identity);
    CENGINE_DestroyMat4x4(rand);
    CENGINE_DestroyMat4x4(zerostmp);
    CENGINE_DestroyMat4x4(onestmp);
    CENGINE_DestroyMat4x4(randtmp);

    fprintf(stdout, "All tests passed for struct Mat4x4!\n");
    return 0;
}
