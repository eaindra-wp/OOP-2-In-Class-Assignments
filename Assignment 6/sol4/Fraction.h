/*
    CH08-320143
    a6-p4-Fraction.h
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#ifndef _FRACTION_H
#define _FRACTION_H

#include <iostream>
#include <cstdlib>
class Fraction
{
private:
    int num,de;
    int lcm(int a, int b);
public:
    Fraction();
    Fraction(int nu,int de);
    Fraction(std::string rat);
    Fraction(const Fraction& f);
    ~Fraction();

    //overload relational operators
    bool operator>(const Fraction& f) const;
    bool operator<(const Fraction& f) const;
    bool operator>=(const Fraction& f) const;
    bool operator<=(const Fraction& f) const;
    bool operator==(const Fraction& f) const;
    bool operator!=(const Fraction& f) const;

    //overload arithmetic operators
    Fraction operator+(Fraction f);
    Fraction operator-(Fraction f);
    Fraction operator*(Fraction f);
    Fraction operator/(Fraction f);

    //overload IO operators
    friend std::ostream& operator<<(std::ostream& o, const Fraction& f);
    friend std::istream& operator>>(std::istream& i, Fraction& f);

    //Assignment operator
    Fraction operator=(const Fraction& f);
};
#endif // _FRACTION_H
