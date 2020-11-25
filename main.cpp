#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    float a[15]={1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f};
    float b[15]={1.0f, 1.0f, 1.0f, 2.0f, 2.0f, 2.0f, 3.0f, 3.0f, 3.0f, 4.0f, 4.0f, 4.0f, 5.0f, 5.0f, 5.0f};
    float c = 2, d = 3;
    Matrix A(3, 5, a);
    Matrix B(5, 3 ,b);
    Matrix D, E;
    Matrix C = A * B;
    Matrix F(A);
    D = A * c;
    E = d * B;
    cout << A << B << C << D << E << F;
    return 0;
}
