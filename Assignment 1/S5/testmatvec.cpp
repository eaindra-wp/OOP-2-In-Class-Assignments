/*
    CH08-320143
    a1-p5.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include "Matrix.h"
#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    Matrix m;
    Vector v;

    ifstream in1("in1.txt");
    ifstream in2("in2.txt");
    in1 >> m;
    in2 >> v;

    cout << "Vector:" << endl;
    cout << v;

    cout << "Matrix:" << endl;
    cout << m;

    ofstream out1("out1.txt");
    ofstream out2("out2.txt");
    out1 << m;
    out2 << v;

    cout << "Matrix * Vector:" << endl;
    cout << m* v;
    cout << "Vector * Matrix" << endl;
    cout << v* m;
    return 0;
}
