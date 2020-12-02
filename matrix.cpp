//
// Created by 21548 on 2020/11/24.
//

#include "matrix.h"

Matrix::Matrix(int row, int column)
{
    this->row = row;
    this->column = column;
    this->size = row * column;
    this->data = new Data;
    data->elements = new float *[row];
    for (int i = 0; i < row; ++i)
    {
        data->elements[i] = new float[column]{};
    }
    data->count = 1;
}

Matrix::Matrix(int row, int column, float **p)
{
    this->row = row;
    this->column = column;
    this->size = row * column;
    this->data = new Data;
    if (row > 4 && column > 4)
    {
        data->elements = p;
        data->count = 2;
    }
    else
    {
        data->elements = new float *[row];
        for (int i = 0; i < row; ++i)
        {
            data->elements[i] = new float[column];
            for (int j = 0; j < column; ++j)
            {
                data->elements[i][j] = p[i][j];
            }
        }
        data->count = 1;
    }
}

Matrix::Matrix(Matrix const &matrix)
{
    row = matrix.row;
    column = matrix.column;
    size = row * column;
    data = matrix.data;
    data->count++;
}

Matrix::Matrix(int row, int column, const float *p)
{
    this->row = row;
    this->column = column;
    size = row * column;
    data = new Data;
    data->elements = new float *[row];
    int pos = 0;
    for (int i = 0; i < row; ++i)
    {
        data->elements[i] = new float[column];
        for (int j = 0; j < column; ++j)
        {
            data->elements[i][j] = p[pos++];
        }
    }
    data->count = 1;
}

int Matrix::getRow() const
{
    return row;
}

void Matrix::setRow(int i)
{
    Matrix::row = i;
}

int Matrix::getColumn() const
{
    return column;
}

void Matrix::setColumn(int i)
{
    Matrix::column = i;
}

float **Matrix::getElements() const
{
    return data->elements;
}

Matrix::~Matrix()
{
    cout << "matrix with size (" << row << "," << column << ") is being destroyed." << endl;
    if (data->count == 1)
    {
        for (int i = 0; i < row; ++i)
        {
            delete[] data->elements[i];
        }
        delete[] data->elements;
        delete data;
        cout << "data is being destroyed" << endl;
    }
    else
    {
        data->count--;
    }
}

Matrix &Matrix::operator=(const Matrix &matrix)
{
    if (&matrix == this)
        return *this;

    if (data != nullptr && data->count == 1)
    {
        for (int i = 0; i < row; ++i)
        {
            delete[] data->elements[i];
        }
        delete[] data->elements;
        delete data;
        cout << "data is being destroyed" << endl;
    }
    else
        data->count--;

    row = matrix.row;
    column = matrix.column;
    size = row * column;
    data = matrix.data;
    data->count++;

    return *this;
}

ostream &operator<<(ostream &os, const Matrix &matrix)
{
    cout << '[';
    for (int i = 0; i < matrix.row; ++i)
    {
        for (int j = 0; j < matrix.column; ++j)
        {
            cout << matrix.data->elements[i][j];
            if (j != matrix.column - 1)
                cout << ',';
        }
        if (i != matrix.row - 1)
        {
            cout << ';' << endl << ' ';
        }
    }
    cout << ']' << endl;
    return os;
}

Matrix Matrix::operator*(Matrix &matrix)
{
    Matrix result;
    if (column != matrix.row)
    {
        cout << "matrix size mismatch!" << endl;
        return result;
    }
    result = Matrix(row, matrix.column);
    mxm(result.data->elements, data->elements, matrix.data->elements, row, column, matrix.row, matrix.column);
    return result;
}

Matrix Matrix::operator*(float t) const
{
    Matrix result(this->row, this->column);
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            result.data->elements[i][j] = this->data->elements[i][j] * t;
        }
    }
    return result;
}

Matrix operator*(float t, Matrix &matrix)
{
    Matrix result(matrix.row, matrix.column);
    for (int i = 0; i < matrix.row; ++i)
    {
        for (int j = 0; j < matrix.column; ++j)
        {
            result.data->elements[i][j] = matrix.data->elements[i][j] * t;
        }
    }
    return result;
}

Matrix Matrix::operator+(Matrix &matrix)
{
    Matrix result;
    if (row != matrix.row || column != matrix.column)
    {
        cout << "matrix size mismatch!" << endl;
        return result;
    }
    result = Matrix(row, column);
    mxa(result.data->elements, data->elements, matrix.data->elements, row, column);
    return result;
}

Matrix Matrix::operator-(Matrix &matrix)
{
    Matrix result;
    if (row != matrix.row || column != matrix.column)
    {
        cout << "matrix size mismatch!" << endl;
        return result;
    }
    result = Matrix(row, column);
    mxs(result.data->elements, data->elements, matrix.data->elements, row, column);
    return result;
}


