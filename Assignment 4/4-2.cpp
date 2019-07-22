/*
    CH08-320143
    a4-p2.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <set>
using namespace std;
int main()
{
    srand (time(NULL));
    //set the local time
    set<int> sint;
    //set is used as it does not allow
    //duplicate data types and saves
    //elements in the ascending order

    //put exact 6 different integers
    //to the set
    while(sint.size() < 6)
        sint.insert(rand()%49+1);

    //print the set result
    set<int>:: iterator it;
    for(it = sint.begin(); it != sint.end(); it++)
		cout << *it << " ";
	cout << endl;

	return 0;
}
