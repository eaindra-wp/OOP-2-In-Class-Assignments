/*
    CH08-320143
    a2-p3.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    Queue<int> intq;
    cout << "Testcase 1" << endl;
    //testcase 1 push elements
    for(int i=0; i<6; i++)
        intq.push(i);
    //pop all elements added to the queue
    while(intq.getNumEntries()>0)
    {
        int loc;
        intq.pop(loc);
        cout << loc << endl;
    }


    cout << "Testcase 2" << endl;
    Queue<float> floatq;
    /*try to push more elements, but it won't work
    after it has reached the maximum*/
    for(float i=0; i<11; i++)
        floatq.push(i);

    Queue<float> floatq2(floatq);
    //test front and back methods
    cout << "Front: " << floatq.front() << endl;
    cout << "Back: " << floatq.back() << endl;
    //pop elements in the queue
    while(floatq.getNumEntries()>0)
    {
        float tmp;
        floatq.pop(tmp);
        cout << tmp << endl;
    }
    cout << "TestCase 3" << endl;
    cout<<"Current Size: " <<floatq.getSize()<<endl;
    floatq2.resize(4);
    cout << "Current Size: "<<floatq2.getSize() << endl;
    while(floatq2.getNumEntries()>0)
    {
        float tmp;
        floatq2.pop(tmp);
        cout << tmp << endl;
    }

    return 0;
}
