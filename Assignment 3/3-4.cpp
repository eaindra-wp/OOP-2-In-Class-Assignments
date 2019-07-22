/*
    CH08-320143
    a3-p4.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include <deque>
#include <cstdlib>

using namespace std;

int main()
{
    deque<double> A;
    double n;
    while(1)
    {
        cin >> n;
        if(n==0)
            break;
        //push positive doubles to front
        if(n>0)
            A.push_front(n);
        //push negative doubles to back
        else
            A.push_back(n);
    }
    unsigned int i;
    //print elements in A
    for(i=0; i<A.size(); i++)
        cout << A[i] << " ";
    cout << "\n" << endl;

    /*add 0 between positive and
    /negative doubles*/
    deque<double>:: iterator it;
    it = A.begin();
    while(*it>0)
        it++;
    A.insert(it,0);

    //print elements of A
    for(i=0; i<A.size()-1; i++)
        cout << A[i] << ",";
    cout << A[i] << endl;

    return 0;
}
