/*
    CH08-320143
    a1_p1_Complex.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/

#include <iostream>
#include <cmath>
#include "Complex.h"

using namespace std;

Complex::Complex()    //default constructor
{
    real = imag = 0;
}
Complex::Complex(float r, float i) //constructor with parameters
{
    real = r;
    imag = i;
}
Complex::Complex(const Complex& p) //copy constructor
{
    real = p.real;
    imag = p.imag;
}
Complex::~Complex()
{
    //empty destructor
}
void Complex::setReal(float newreal) //setter for real part
{
    real = newreal;
}
void Complex::setImag(float newimag) //setter for imag part
{
    imag = newimag;
}
void Complex::setConjugate(float newreal, float newimag)
{
    real = newreal * (-1);
    imag = newimag * (-1);
    //setter method to give the conjugate of a complex number
}
//+overload operator
Complex Complex::operator+(const Complex &obj)
{
    Complex res;
    res.real = this->real + obj.real;
    res.imag = this->imag + obj.imag;
    return res;
}
//-overload operator
Complex Complex::operator- (const Complex &obj)
{
    Complex res;
    res.real = this->real - obj.real;
    res.imag = this->imag - obj.imag;
    return res;
}
//*overload operator
Complex Complex::operator*(const Complex &obj)
{
    Complex res;
    res.real = (this->real*obj.real)-(this->imag*obj.imag);
    res.imag = (this->real*obj.imag)+(this->imag*obj.real);
    return res;
}
//=overload operator
Complex& Complex::operator= (const Complex &obj)
{
   Complex res;
   real = obj.real;
   imag = obj.imag;
   return *this;
}
//<<overload operator for output
ostream& operator<<(ostream& out, const Complex& s)
{
    char s1 = '+';
    char s2 = '+';
    //to print correct symbols
    if(s.imag < 0)
        s2 = '-';
    else if (s.real < 0)
        s1 = '-';
    out << s1 << abs(s.real) << s2 << abs(s.imag) << "i" << endl;
    return out;
}
//>>operator for input
istream& operator>>(istream& in, Complex& g)
{
    in >> g.real >> g.imag;
    return in;
}
