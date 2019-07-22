/*
    CH08-320143
    a6-p4-testRelational.cpp
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
    cout << "\nTest for relational operators..." << endl;
    Fraction f1 = Fraction(-1,2);
    Fraction f2 = Fraction("3/-4");
    cout << f1 << f2;
    //test for all relational operators
    test(f2>f1);
    test(f2<f1);
    test(f2>=f1);
    test(f2<=f1);
    test(f2==f1);
    test(f2!=f1);
    //count for pass and fail tests
    cout << "Passed tests: " << pass << endl;
    cout << "Failed tests: " << fail << endl;
}
