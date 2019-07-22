/*
    CH08-320143
    a4-p4-testAccess.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <map>
#include <iostream>
#include "Access.h"
using namespace std;
int main()
{
    Access acc;
    acc.activate(123456);
    acc.activate(999999);
    acc.activate(187692);
    //insert 3 codes to the list

    unsigned long input;
    //ask input code until input is true
    while(1)
    {
        cin >> input;
        if(acc.isactive(input))
        {
            cout << "Door opens successfully."<<endl;
            break;
        }
        else
            cout<<"Please try again!"<<endl;
    }
    //step 6
    acc.deactivate(input);
    acc.deactivate(999999);
    acc.activate(111111);
    //ask input code until input is true
    while(1)
    {
        cin >> input;
        if(acc.isactive(input))
        {
            cout << "Door opens successfully."<<endl;
            break;
        }
        else
            cout<<"Please try again!"<<endl;
    }
    return 0;
}
