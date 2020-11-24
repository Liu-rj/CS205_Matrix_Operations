//
// Created by 21548 on 2020/11/24.
//

#ifndef ASSIGNMENT4_MATRIX_OPERATION_MATRIX_H
#define ASSIGNMENT4_MATRIX_OPERATION_MATRIX_H

#include <iostream>

using namespace std;

class Matrix
{
private:
    int row;
    int column;
    float **elements;

public:
    explicit Matrix(int row = 0, int column = 0);

    Matrix(Matrix &matrix);

    int getRow() const;

    void setRow(int row);

    int getColumn() const;

    void setColumn(int column);

    float **getElements() const;

    Matrix &operator=(const Matrix &matrix);

    Matrix operator*(Matrix &matrix);

    friend ostream &operator<<(ostream &os, const Matrix &matrix);

    ~Matrix();
};

#endif //ASSIGNMENT4_MATRIX_OPERATION_MATRIX_H
