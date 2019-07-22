/*
    CH08-320143
    a6-p4-testio.cpp
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
    cout << "\nTest for IO and constructors..." << endl;
    //exception test for valid input and output
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
    cout << "Test for IO operators..." << endl;
    //count for pass and fail tests
    cout << "Passed tests: " << pass << endl;
    cout << "Failed tests: " << fail << endl;

    return 0;
}
