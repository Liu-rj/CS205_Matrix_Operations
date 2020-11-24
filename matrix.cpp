//
// Created by 21548 on 2020/11/24.
//

#include "matrix.h"
#include "mxm.h"

Matrix::Matrix(int row, int column)
{
    this->row = row;
    this->column = column;
    elements = new float *[row + 1];
    for (int i = 0; i < row; ++i)
    {
        elements[i] = new float[column]{};
    }
    elements[row] = new float{0};
}

Matrix::Matrix(Matrix &matrix)
{
    row = matrix.row;
    column = matrix.column;
    elements = matrix.elements;
    elements[row][0]++;
}

int Matrix::getRow() const
{
    return row;
}

void Matrix::setRow(int row)
{
    Matrix::row = row;
}

int Matrix::getColumn() const
{
    return column;
}

void Matrix::setColumn(int column)
{
    Matrix::column = column;
}

float **Matrix::getElements() const
{
    return elements;
}

Matrix::~Matrix()
{
    cout << "matrix with size (" << row << "," << column << ") is being destroyed." << endl;
    if (elements[row][0] == 0)
    {
        for (int i = 0; i < row; ++i)
        {
            delete elements[i];
        }
        delete[] elements;
        cout << "elements are being destroyed" << endl;
    }
    else
    {
        elements[row][0]--;
    }
}

Matrix &Matrix::operator=(const Matrix &matrix)
{
    if (&matrix == this)
        return *this;

    if (elements != nullptr && elements[row][0] == 0)
    {
        for (int i = 0; i < row; ++i)
        {
            delete[] elements[i];
        }
        delete[] elements;
    }
    else
        elements[row][0]--;

    row = matrix.row;
    column = matrix.column;
    elements = matrix.elements;
    elements[row][0]++;
    return *this;
}

ostream &operator<<(ostream &os, const Matrix &matrix)
{
    cout << '[';
    for (int i = 0; i < matrix.row; ++i)
    {
        for (int j = 0; j < matrix.column; ++j)
        {
            cout << matrix.elements[i][j];
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
    if (this->column != matrix.row)
    {
        cout << "matrix size mismatch!" << endl;
        return result;
    }
    result = Matrix(this->row, matrix.column);
    mxm_row(result.elements, this->elements, matrix.elements, this->row, this->column, matrix.row, matrix.column);
    return result;
}
