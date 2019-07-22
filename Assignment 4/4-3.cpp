/*
    CH08-320143
    a4-p3.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
int main()
{
    set<int> A; //set A
    multiset<int> B; //multiset b
    int n;
    //insert ints to A and B
    while(1)
    {
        cin >> n;
        //check for non-negative inputs
        if(n<0)
            break;
        A.insert(n);
        B.insert(n);
        //add same ints to A and B
    }
    //print elements from A
    set<int> :: const_iterator i;
    for(i=A.begin(); i!=A.end(); i++)
        cout << *i << " ";
    cout << "\n";

    //print elements from B
    multiset<int> :: const_iterator j;
    for(j=B.begin(); j!=B.end(); j++)
        cout << *j << " ";
    cout << endl;
    cout << endl;

    //remove 11 from both A and B if exists
    while(A.count(11) != 0)
        A.erase(11);
    while(B.count(11) != 0)
        B.erase(11);

    //print the updated result again
    for(i=A.begin(); i!=A.end(); i++)
        cout << *i << " ";
    cout << "\n";
    for(j=B.begin(); j!=B.end(); j++)
        cout << *j << " ";
    cout << endl;
    cout << endl;

    A.insert(5);
    A.insert(421);

    //print union of A and B
    multiset<int> Union;
    set_union(A.begin(),A.end(),
              B.begin(),B.end(),
              inserter(Union,Union.begin()));
    multiset<int>:: const_iterator k;
    for(k=Union.begin(); k!=Union.end(); k++)
        cout << *k << " ";
    cout << "\n" << endl;


    //print intersection of A and B
    multiset<int> Intersect;
    set_intersection(A.begin(),A.end(),
              B.begin(),B.end(),
              inserter(Intersect,
                       Intersect.begin()));
    for(k=Intersect.begin();k!=Intersect.end();k++)
        cout << *k << " ";
    cout << "\n"<< endl;

    //print set difference
    set<int> diff;
    set_difference(A.begin(),A.end(),
              B.begin(),B.end(),
            inserter(diff,diff.begin()));
    set<int>:: const_iterator d;
    for(d=diff.begin(); d!=diff.end(); d++)
        cout << *d << " ";
    cout << "\n" << endl;

    //print set symmetric difference
    set<int> sdiff;
    set_symmetric_difference(A.begin(),A.end(),
              B.begin(),B.end(),
            inserter(sdiff,sdiff.begin()));
    for(d=sdiff.begin(); d!=sdiff.end(); d++)
        cout << *d << " ";
    cout << "\n";

    return 0;
}
