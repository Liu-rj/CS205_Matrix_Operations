//
// Created by 21548 on 2020/11/24.
//

#ifndef ASSIGNMENT4_MATRIX_OPERATION_MATRIX_H
#define ASSIGNMENT4_MATRIX_OPERATION_MATRIX_H

#include <iostream>

using namespace std;

struct Data
{
    unsigned long count;
    float **elements;
};

class Matrix
{
private:
    int row;
    int column;
    int size{};
    struct Data *data;

public:
    explicit Matrix(int row = 0, int column = 0);

    Matrix(int row, int column, float **p);

    Matrix(int row, int column, const float *p);

    Matrix(Matrix const &matrix);

    int getRow() const;

    void setRow(int i);

    int getColumn() const;

    void setColumn(int i);

    float **getElements() const;

    Matrix &operator=(const Matrix &matrix);

    Matrix operator*(Matrix &matrix);

    Matrix operator+(Matrix &matrix);

    Matrix operator-(Matrix &matrix);

    Matrix operator*(float t) const;

    friend Matrix operator*(float t, Matrix &matrix);

    friend ostream &operator<<(ostream &os, const Matrix &matrix);

    ~Matrix();

};

void mxm(float **c, float **a, float **b, int row1, int column1, int row2, int column2);

void mxa(float **c, float **a, float **b, int row, int column2);

void mxs(float **c, float **a, float **b, int row, int column2);

#endif //ASSIGNMENT4_MATRIX_OPERATION_MATRIX_H
