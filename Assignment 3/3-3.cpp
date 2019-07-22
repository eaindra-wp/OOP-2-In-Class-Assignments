/*
    CH08-320143
    a3-p3.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include <list>
#include <fstream>

using namespace std;

int main()
{
    typedef list<int> ilist;
    ilist A,B;
    //two int lists
    int n;
    while(1)
    {
        cin >> n;
        if(n<=0)
            break;
        else
        {
            //push input to A and B
            A.push_front(n);
            B.push_back(n);
        }
    }

    //print the list A in reverse mode
    ilist:: const_iterator i;
    for(i=A.begin(); i!=A.end(); i++)
        cout << *i << " ";
    cout << endl;

    //print the list B in the text file
    //in the reverse mode
    ofstream fp;
    fp.open("listB.txt");

    ilist:: reverse_iterator j;
    for(j=B.rbegin(); j!=B.rend(); j++)
        fp << *j << " ";
    fp << endl;
    fp.close();

    cout << endl;

    //move the last element to the beginning
    int lastA = A.back();
    A.pop_back();
    int lastB = B.back();
    B.pop_back();
    A.push_front(lastA);
    B.push_front(lastB);

    //print A
    for(i=A.begin(); i!=A.end(); i++)
    {
        if(i != A.begin())
            cout << ",";
        cout << *i;
    }
    cout << endl;

    //print B
    for(i=B.begin(); i!=B.end(); i++)
    {
        if(i != B.begin())
            cout << ",";
        cout << *i;
    }
    cout << endl;
    cout << endl;

    //Merge list A into list B
    B.merge(A);
    B.sort();
    //print sorted result
    for(i=B.begin(); i!=B.end(); i++)
        cout << *i << " ";
    cout << endl;

    return 0;

}
