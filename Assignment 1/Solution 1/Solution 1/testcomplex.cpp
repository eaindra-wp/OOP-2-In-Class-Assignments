/*
    CH08-320143
    a1_p1_testcomplex.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Complex.h"

using namespace std;

int main()
{
    Complex c1,c2,cadd,csub,cmul;
    //input for the first file and check error
    ifstream in1("in1.txt",ios::in);
    if(!in1.good())
    {
        cerr << "Error opening input file 1" << endl;
        exit(1);
    }
    //input for the second file and check error
    ifstream in2("in2.txt",ios::in);
    if(!in2.good())
    {
        cerr << "Error opening input file 2" << endl;
        exit(2);
    }
    //output file and check for error
    ofstream out("output.txt",ios::out);
    if(!out.good())
    {
        cerr << "Error opening output file" << endl;
        exit(3);
    }
    //input the values read to the object
    in1 >> c1;
    in2 >> c2;

    cout << "Result from the first file: ";
    cout << c1;
    cout << "Result from the second file: ";
    cout << c2;

    //print the results on the screen<<
    cadd = c1 + c2;
    cout << "Result of addition file: ";
    cout << cadd;

    csub = c1 - c2;
    cout << "Result of subtraction file: ";
    cout << csub;

    cmul = c1 * c2;
    cout << "Result of multiplication file: ";
    cout << cmul;

    //write the result in the new file
    out << "Addition: " << c1 + c2 << endl;
    out << "Subtraction: " <<c1 - c2 << endl;
    out << "Multiplication: " << c1 * c2 << endl;

    //close the files
    in1.close();
    in2.close();
    out.close();
	return 0;
}
