//
// Created by 21548 on 2020/11/9.
//

#ifndef MATRIX_MULTIPLICATION_OPENMXM_H
#define MATRIX_MULTIPLICATION_OPENMXM_H

#include <iostream>

void mxm(float **c, float **a, float **b,int row1, int column1, int row2, int column2);

void mxm_block(float **c, float **a, float **b,int row1, int column1, int row2, int column2);

void mxm_sse(float **c, float **a, float **b,int row1, int column1, int row2, int column2);

void product1(float **c, float **a, float **b, int row1, int column1, int row2, int column2);

#endif //MATRIX_MULTIPLICATION_OPENMXM_H
