/*
    CH08-320143
    a3-p1.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int main(int argc, char** argv)
{
    unsigned int j;
    string input;
    typedef vector<string> vstring;
    vstring VecStr;
    //accept inputs to the string
    while(1)
    {
        cin >> input;
        //if "stop" is typed, stop accepting the inputs
        if(input == "stop")
            break;
        else
            VecStr.push_back(input);
        //accept all input strings,except stop
    }
    //to execute properly for empty vector
    if(!VecStr.empty())
    {
        //print by using the index operator
        cout << "Print with Index Operator" << endl;
        for (j=0; j<VecStr.size()-1; j++)
        {
            cout << VecStr[j] << ",";
        }
        cout << VecStr[j] << "\n" << endl;
        //print the words with the iterator
        vstring :: const_iterator i;
        cout << "Print with Iterator" << endl;
        for(i= VecStr.begin(); i!=VecStr.end(); i++)
        {
            cout << *i << " ";
        }
    }
    return 0;
}
