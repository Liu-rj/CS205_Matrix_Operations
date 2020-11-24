#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    Matrix a(3, 5);
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            a.getElements()[i][j] = (i + j) / 2;
        }
    }
    Matrix b(5, 3);
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            b.getElements()[i][j] = (i + j) / 2;
        }
    }
    Matrix c;
    c = a * b;
    cout << c << a << b;
    return 0;
}
