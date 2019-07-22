/*
    CH08-320143
    a4-p1.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    typedef vector<char> charlist;
    charlist clist;
    //push alphabets to the vector
    for(char i='a'; i<='z'; i++)
        clist.push_back(i);

    reverse(clist.begin(),clist.end());
    //reverse the vector

    //print the vector with an iterator
    charlist:: const_iterator j;
    for(j=clist.begin(); j!=clist.end(); ++j)
        cout << *j << " ";
    cout << "\n";

    clist.push_back('f');
    //push at the end of vector

    replace(clist.begin(),clist.end(),'f','$');
    //replace f with $

    //print the modified vector
    for(j=clist.begin(); j!=clist.end(); ++j)
        cout << *j << " ";
    cout << "\n";

    return 0;
}
