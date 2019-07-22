/*
    CH08-320143
    a6-p3-Fraction.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include "Fraction.h"
using namespace std;

//function for LCM value
int Fraction::lcm(int a, int b)
{
    //check for negative inputs
    if (a < 0)
        a = a * (-1);
    else if (b < 0)
        b = b * (-1);
    return a*b / __gcd(a, b);
}
Fraction::Fraction()
{
    this->num = 1;
    this->de = 1;
}
//constructor with integers parameters
Fraction::Fraction(int nu,int de)
{
    if(de==0)
        throw string("Invalid data or logical error");
    //to take the greatest common divisor
    int gcd = __gcd(abs(nu),abs(de));
    this->de = de/gcd;
    this->num = de/gcd;
    //for one negative numerators or denominators
    if(this->de < 0 || this->num < 0)
    {
        this->num = -abs(this->num);
        this->de = abs(this->de);
    }
    //for both negative numerators and denominators
    else if(this->de < 0 && this->num < 0)
    {
        this->de = abs(this->de);
        this->num = abs(this->num);
    }
    this->num = nu;
    this->de = de;
}
//constructor with string parameter
Fraction::Fraction(string rat)
{
    if(rat.length()==0)
        throw "Invalid data or logical error";

    //to find '/' in the string
    size_t slash = rat.find('/');
    if (slash==string::npos)
        throw string("Invalid data or logical error");

    string buff = rat.substr(0,slash);
    for(size_t i=0; i<buff.length(); i++)
    {
        //to check valid symbols in the string
        if (i==0)
        {
            if(buff[i]=='+' || buff[i]=='-' || isdigit(buff[i]))
                continue;
            else
                throw string("Invalid data or logical error");
        }
        else
        {
            if(isdigit(buff[i]))
                continue;
            else
                throw string("Invalid data or logical error");
        }
    }
    //change string to integer (numerator and denominator)
    int nume = atoi(buff.c_str());
    buff = rat.substr(slash+1);
    for(size_t i = 0; i < buff.length(); i++)
    {
        if(i == 0)
        {
            if(buff[i] == '-' || buff[i] == '+' || isdigit(buff[i]))
                continue;
            else
                throw string("Invalid data or logical error");
        }
        else
        {
            if(isdigit(buff[i]))
                continue;
            else
                throw string("Invalid data or logical error");
        }
    }
    int den = atoi(buff.c_str());
    if(den == 0)
    {
        throw string("Invalid data or logical error");
    }
    //to take the greatest common divisor of the fraction
    int gcd = __gcd(abs(nume),abs(den));
    this->de = den/gcd;
    this->num = nume/gcd;
    if(this->de < 0 && this->num < 0)
    {
        this->de = abs(this->de);
        this->num = abs(this->num);
    }
    else if(this->de < 0 || this->num < 0)
    {
        this->num = -abs(this->num);
        this->de = abs(this->de);
    }
}
//copy constructor
Fraction::Fraction(const Fraction& f)
{
    //check for integer validity
    if(!f.num)
        throw string("Invalid data or logical error");
    if(f.de==0)
        throw string("Invalid data or logical error");
    this->de = f.de;
    this->num = f.num;
}
//destructor
Fraction::~Fraction() {}

//relational operators overload
//> overloading
bool Fraction::operator>(const Fraction& f) const
{
    if(this->de == f.de)
        return this->num > f.num;
    else
        return this->num*f.de > f.num*this->de;
}
//<overloading
bool Fraction::operator<(const Fraction& f) const
{
    if(this->de == f.de)
        return this->num < f.num;
    else
        return this->num*f.de < f.num*this->de;
}
//>= overloading
bool Fraction::operator>=(const Fraction& f) const
{
    if(this->de == f.de)
        return this->num >= f.num;
    else
        return this->num*f.de >= f.num*this->de;
}
//<=overloading
bool Fraction::operator<=(const Fraction& f) const
{
    if(this->de == f.de)
        return this->num <= f.num;
    else
        return this->num*f.de <= f.num*this->de;
}
//compare whether two fractions are equal or not
bool Fraction::operator==(const Fraction& f) const
{
    if(this->de == f.de)
        return this->num == f.num;
    else
        return this->num*f.de == f.num*this->de;
}
bool Fraction::operator!=(const Fraction& f) const
{
    if(this->de == f.de)
        return this->num != f.num;
    else
        return this->num*f.de != f.num*this->de;
}
//arithmetic operators
Fraction Fraction::operator+(Fraction add)
{
    Fraction ares;
    int nn, dd;
    nn = (num*lcm(de,add.de)/de)+
    (add.num*lcm(de,add.de)/add.de);
    dd = lcm(de,add.de);
    ares.num = nn / __gcd(nn,dd);
    ares.de = dd / __gcd(nn,dd);
    return ares;
}
Fraction Fraction::operator-(Fraction sub)
{
    Fraction sres;
    int nn,dd;
    nn= (num*lcm(de,sub.de)/de) -
    (sub.num*lcm(de,sub.de)/sub.de);
    dd = lcm(de,sub.de);
    //check if the result of numerator is negative
    if (nn < 0)
    {
        //to return the correct and simplest form of the negative number
        nn = nn * (-1);
        sres.num = nn / __gcd(nn,dd);
        sres.num = sres.num * (-1);
    }
    else
    {
        sres.num = nn / __gcd(nn,dd);
    }
    sres.de = dd / __gcd(nn,dd);
    return sres;
}
Fraction Fraction::operator*(Fraction mul)
{
    Fraction mres;
    int d,n;
    //returning the result in the simplest form
    n = this->num * mul.num;
    d = this->de * mul.de;
    mres.de = d / __gcd(n,d);
    mres.num = n / __gcd(n,d);
    return mres;
}
Fraction Fraction::operator/(Fraction div)
{
    Fraction dres;
    int d,n;
    //returning the result in the simplest form
    n = this->num * div.de;
    d = this->de * div.num;
    dres.de = d / __gcd(n,d);
    dres.num = n/ __gcd(n,d);
    return dres;
}
//overload io operators
ostream& operator<<(ostream& os, const Fraction& f)
{
    //check for integer validity
    if(!f.num)
        throw string("Invalid data or logical error");
    //check for validity of denominator
    if(f.de == 0)
        throw string("Invalid data or logical error");

    os << f.num << "/" << f.de << endl;
    return os;
}
istream& operator>>(istream& is, Fraction& f)
{
    is >> f.num >> f.de;
    //check for integer validity
    if(!f.num)
        throw string("Invalid data or logical error");
    //check for validity of denominator
    if(f.de == 0)
        throw string("Invalid data or logical error");

    int gcd = __gcd(abs(f.num),abs(f.de));
    f.num /= gcd;
    f.de /= gcd;
    //for negative numerator or denominator
    if(f.de < 0 || f.num < 0)
    {
        f.num = -abs(f.num);
        f.de = abs(f.de);
    }
    //for both negative numerator and denominator
    else if(f.num<0 && f.de<0)
    {
        f.num = abs(f.num);
        f.de = abs(f.de);
    }
    return is;
}
//assignment operator
Fraction Fraction::operator=(const Fraction& f)
{
    return Fraction(f);
}

