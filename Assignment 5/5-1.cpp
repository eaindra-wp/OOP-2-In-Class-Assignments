/*
    CH08-320143
    a5-p1.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

int main()
{
    //create a char vector
    vector<char> vchar;
    unsigned int i = 15;
    vector<char> :: const_iterator it;
    //add @ for 15 times
    while(i<15)
    {
        vchar.push_back('@');
        i++;
    }
    try
    {
        //access 16th element
        throw(vchar.at(15));
    }
    //catch by out_of_range
    catch(const out_of_range& catcher)
    {
        cerr << catcher.what() << endl;
    }
    return 0;
}
