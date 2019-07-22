/*
    CH08-320143
    a4-p6-testAccess.cpp
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
    acc.activate(123456,1);
    acc.activate(999999,5);
    acc.activate(187692,9);
    //insert 3 codes to the list

    unsigned long input;
    //ask input code until input is true
    while(1)
    {
        cin >> input;
        //with level 5
        if(acc.isactive(input,5))
        {
            cout << "Door opens successfully."<<endl;
            break;
        }
        else
            cout<<"Please try again!"<<endl;
    }
    acc.deactivate(input);
    //update the codes
    acc.activate(999999,8);
    acc.activate(111111,7);
    //ask input code until input is true
    while(1)
    {
        cin >> input;
        //with level 7
        if(acc.isactive(input,7))
        {
            cout << "Door opens successfully."<<endl;
            break;
        }
        else
            cout<<"Please try again!"<<endl;
    }
    return 0;
}
