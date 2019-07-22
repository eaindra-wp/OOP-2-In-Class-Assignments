/*
    CH08-320143
    a6-p4-testexception.cpp
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
    cout << "\nTest for Exception cases..." << endl;
    //test for invalid results
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
