//
// Created by 21548 on 2020/12/2.
//
#include "matrix.h"

using namespace std;

void mxm(float **c, float **a, float **b, int row1, int column1, int row2, int column2)
{
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < column1; ++j) {
            for (int k = 0; k < column2; ++k) {
                c[i][k] += a[i][j] * b[j][k];
            }
        }
    }
}

void mxa(float **c, float **a, float **b, int row, int column)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void mxs(float **c, float **a, float **b, int row, int column)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}
