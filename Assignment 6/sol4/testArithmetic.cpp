/*
    CH08-320143
    a6-p4-testArithmetic.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include "Fraction.h"
using namespace std;
int pass = 0;
int fail = 0;
int count = 1;
//function for whether the testcase is passed or not
void test(bool b)
{
    if(b)
    {
        cout << "Test " << count << " passes\n";
        pass++;
    }
    else
    {
        cout << "Test " << count << " fails\n";
        fail++;
    }
    count++;
}
int main()
{
    cout << "\nTest for Arithmetic operators..." << endl;
    Fraction f1 = Fraction(-1,2);
    Fraction f2 = Fraction("3/-4");
    Fraction f4 = Fraction(-5,4);
    Fraction f5 = Fraction(1,4);
    Fraction f6 = Fraction("3/8");
    Fraction f7 = Fraction("2/3");
    cout << f1 << f2;
    //test for arithmetic operators
    cout << "Add: " << f1+f2;
    cout << "Subtract: " << f1-f2;
    cout << "Multiply: " << f1*f2;
    cout << "Divide: " << f1/f2;
    //compare with predicted results
    test(f1+f2 == f4);
    test(f1-f2 == f5);
    test(f1*f2 == f6);
    test(f1/f2 == f7);
    //count for pass and fail tests
    cout << "Passed tests: " << pass << endl;
    cout << "Failed tests: " << fail << endl;

    return 0;
}
