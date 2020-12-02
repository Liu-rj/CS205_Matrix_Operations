#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    float a[15] = {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f};
    auto **b = new float *[5];
    for (int i = 0; i < 5; ++i)
    {
        b[i] = new float[3];
        for (int j = 0; j < 3; ++j)
        {
            b[i][j] = i * j;
        }
    }
    float c = 2, d = 3;
    Matrix A(3, 5, a);
    Matrix B(5, 3, b);
    Matrix D(A), E(B);
    Matrix C = A * B;
    Matrix F = A + B;
    D = A * c;
    E = d * B;
    cout << A << B << C << D << E << F;
    cout << A * B;

    for (int i = 0; i < 5; ++i)
    {
        delete[] b[i];
    }
    delete[] b;
    return 0;
}
