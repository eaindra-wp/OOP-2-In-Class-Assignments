/*
    CH08-320143
    a1-p5.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include "Matrix.h"
//constructors
Matrix::Matrix()
{
    this->m = 0;
    this->n = 0;
    this->arr = NULL;
}

Matrix::Matrix(int m, int n)
{
    this->arr = new double[m*n];
    this->m = m;
    this->n = n;
}
//destructor
Matrix::~Matrix()
{
    delete []this->arr;
}
//resize the matrix with updated sizes
void Matrix::update(int m, int n)
{
    delete []this->arr;
    this->arr = new double[m * n];
    this->m = m;
    this->n = n;
    return;
}

void Matrix::setPos(int m, int n, double d){
    //set data in corresponding position
    int i = calIdx(m, n);
    this->arr[i] = d; //assign the data
    return;
}
int Matrix::calIdx(int m, int n) const
{
    //calculate the index at the dynamic array
    return m * (this->n) + n;
}

double Matrix::where(int m, int n) const
{
    return this->arr[calIdx(m, n)];
}
//matrix vector multiplication
Vector operator*(const Matrix& mat, const Vector& vec)
{
    if(mat.column() != vec.length())
        return Vector();
    Vector res(mat.row());
    for(int i = 0; i < mat.row(); i++)
    {
        double sum = 0.0;
        for(int j = 0; j < mat.column(); j++)
        {
            sum += mat.where(i,j) * vec.search(j);
        }
        res.add(i, sum);
    }
    return res;
}
//vector matrix multiplication
Vector operator*(const Vector& vec, const Matrix& mat){
    if(mat.row() != vec.length())
        return Vector();
    Vector res(mat.column());
    //start from the column as matrix is 2nd element
    //for multiplication
    for(int i = 0; i < mat.column(); i++)
    {
        double sum = 0.0;
        for(int j = 0; j < mat.row(); j++)
        {
            sum += mat.where(j, i) * vec.search(j);
        }
        res.add(i, sum);
    }
    return res;
}

//overload >> operator
std::istream& operator>>(std::istream& is, Matrix& mat)
{
    //read dimensions
    int m;
    int n;
    is >> m;
    is >> n;
    mat.update(m, n);

    double tmp;

    //read elements row by row,and then col by col
    for(int i = 0; i < mat.row(); i++)
    {
        for(int j = 0; j < mat.column(); j++)
        {
            is >> tmp;
            mat.setPos(i, j, tmp);
        }
    }
    return is;
}
//overload << operator
std::ostream& operator<<(std::ostream& os, const Matrix& mat){
    for(int i = 0; i < mat.row(); i++)
    {
        for(int j = 0; j < mat.column(); j++)
        {
            os << mat.where(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}
