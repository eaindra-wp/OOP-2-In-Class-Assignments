/*
    CH08-320143
    a1-p5.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include "Vector.h"
class Matrix{
    private:
        int m;
        int n;
        //its dimensions
        double* arr;
    public:
        //constructors
        Matrix();
        Matrix(int m, int n);
        //destructor
        ~Matrix();

        void setPos(int m, int n, double data);
        double where(int m, int n) const;
        int calIdx(int m, int n) const;

        void update(int m, int n);
        int row() const
        {
            return m;
        }

        int column() const
        {
            return n;
        }
};

std::istream& operator>>(std::istream& is, Matrix& mat);
std::ostream& operator<<(std::ostream& os, const Matrix& mat);

//matrix vector multiplication
Vector operator*(const Matrix& mat, const Vector& vec);

//vector matrix multiplication
Vector operator*(const Vector& vec, const Matrix& mat);
