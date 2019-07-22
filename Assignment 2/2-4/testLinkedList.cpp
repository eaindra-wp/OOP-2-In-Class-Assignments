/*
    CH08-320143
    a2-p4.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/

#include <iostream>
#include <cstdio>
#include "LinkedList.h"
using namespace std;
int main()
{
    //testcases
    linkedList<int> intlist;

    cout << "TestCase 1" << endl;
    for(int i=0; i<5; i++)
    {
        intlist.pushback(i);
    }

    cout <<"Size of List: "<<intlist.getSize()<<endl;
    cout << intlist.front() << endl;
    cout << intlist.back() << endl;

    cout << "TestCase 2" << endl;
    linkedList<float> floatlist;

    for(int i = 0; i < 5; i++)
    {
        floatlist.pushfront((float)i);
    }
    while(floatlist.getSize())
    {
        cout << floatlist.popback() << endl;
    }

    cout << "TestCase 3" << endl;
    linkedList<double> doublelist;
    for(int i=0; i<60; i+=10)
    {
        doublelist.pushback((double)i);
    }
    while(doublelist.getSize())
    {
        cout << doublelist.popfront() << endl;
    }
    return 0;
}
