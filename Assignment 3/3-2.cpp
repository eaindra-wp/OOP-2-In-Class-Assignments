/*
    CH08-320143
    a3-p2.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
    string input;
    typedef vector<string> vstring;
    vstring VecStr;
    unsigned int j;
    while(1)
    {
        //accept strings with spaces
        getline(cin,input);
        //if "STOP" is typed, stop accepting the inputs
        if(input == "STOP")
            break;
        else
            VecStr.push_back(input);
        //accept all input strings,except stop
    }

    //if the size of vector is at least 4,
    //the second and fourth element will definitely exist.
    if(VecStr.size()>=4)
    {
        swap(*(VecStr.begin()+1),*(VecStr.begin()+3));
    }
    if (VecStr.size()<4)
    {
        cerr << "Second or Fourth element does not exist\n";
    }
    //check whether the vector is empty
    if(!VecStr.empty())
    {
        VecStr[VecStr.size()-1] = "?";
    }
    if(VecStr.empty())
    {
        cerr << "The vector is empty" <<endl;
    }
    //to execute properly for the empty vector
    else
    {
        //print with index operator
        for (j=0; j<VecStr.size()-1; j++)
        {
            cout << VecStr[j] << ";";
        }
        //to remove ";" at the end
        cout << VecStr[j] << "\n" << endl;

        vstring :: const_iterator i;
        cout << "Print with Iterator" << endl;
        for(i= VecStr.begin(); i!=VecStr.end()-1; i++)
        {
            cout << *i << "-";
        }
        //remove "-" at the end
        cout << *(VecStr.end()-1) << endl;

        cout << "Print with Reverse" << endl;
        //print the vector in reverse
        for(i= VecStr.end()-1; i!=VecStr.begin()-1; i--)
        {
            cout << *i << " ";
        }
        cout << endl;
    }
    return 0;
}
