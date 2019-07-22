/*
    CH08-320143
    a6-p3-testFraction.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include "Fraction.h"
#include <iostream>
#include <cstdlib>
using namespace std;
int pass = 0;
int fail = 0;
int count = 1;
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
    //test for constructors
    Fraction f1(-1,2);
    Fraction f2(f1);
    Fraction f3("3/-4");
    //test for arithmetic operators and assignment operator
    Fraction f4 = f1+f3;
    Fraction f5 = f1-f3;
    Fraction f6 = f1*f3;
    Fraction f7 = f1/f3;
    cout << f1 << f3;
    cout << "Add: " << f4;
    cout << "Subtract: " << f5;
    cout << "Multiply: " << f6;
    cout << "Divide: " << f7;

    //test for relational operators
    cout << "\nTest for relational operators..." << endl;
    test(f2>f1);
    test(f2<f1);
    test(f2>=f1);
    test(f2<=f1);
    test(f2==f1);
    test(f2!=f1);
    cout << "\nTest for invalidity..." << endl;
    try
    {
        Fraction f8("1/0");
        test(true);
    }
    catch(string &s)
    {
        cout << s << endl;
        test(false);
    }
    try
    {
        Fraction f9(-1,0);
        test(true);
    }
    catch(string &s)
    {
        cout << s << endl;
        test(false);
    }
    try
    {
        Fraction f10("p/-5");
        test(true);
    }
    catch(string &s)
    {
        cout << s << endl;
        test(false);
    }
    //io stream operator test
    cout << "\nIO Stream exception test" << endl;
    Fraction f;
    try
    {
        cin >> f;
        test(true);
    }
    catch(string &s)
    {
        cout << s << endl;
        test(false);
    }
    try
    {
        cout << f;
        test(true);
    }
    catch(string &s)
    {
        cout << s << endl;
        test(false);
    }
    cout << "\nTest for constructors and assignment operator" << endl;
    //test for valid results,and assignment and constructors
    try
    {
        Fraction f11(1,2);
        test(true);
    }
    catch(string &s)
    {
        cout << s << endl;
        test(false);
    }
    try
    {
        Fraction f12("1/-2");
        test(true);
    }
    catch(string &s)
    {
        cout << s << endl;
        test(false);
    }
    //test for copy constructor
    try
    {
        Fraction f11(1,2);
        Fraction fcpy(f11);
        test(true);
    }
    catch(string &s)
    {
        cout << s << endl;
        test(false);
    }
    //test for assignment operator
    try
    {
        Fraction f12("1/-2");
        Fraction fassign = f12;
        test(true);
    }
    catch(string &s)
    {
        cout << s << endl;
        test(false);
    }
    //count for pass and fail tests
    cout << "Passed tests: " << pass << endl;
    cout << "Failed tests: " << fail << endl;
    return 0;
}
