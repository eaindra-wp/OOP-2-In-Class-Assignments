/*
    CH08-320143
    a4-p4-Access.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include "Access.h"
#include <set>
#include <iostream>
void Access::activate(unsigned long code)
{
    //insert code into the set
    this->codeSet.insert(code);
}
void Access::deactivate(unsigned long code)
{
    //remove code from the set
    this->codeSet.erase(code);
}
bool Access::isactive(unsigned long code) const
{
    //find the code in the set
    auto f = this->codeSet.find(code);
    return (f!=this->codeSet.end());
}
