/*
    CH08-320143
    a4-p6-Access.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include "Access.h"
#include <set>
#include <iostream>
void Access::activate(unsigned long code,unsigned int level)
{
    //insert code into the set
    this->codeSet[code] = level;
}
void Access::deactivate(unsigned long code)
{
    //remove code from the set
    this->codeSet.erase(code);
}
bool Access::isactive(unsigned long code,
                      unsigned int level) const
{
    //find the code in the set
    auto f = this->codeSet.find(code);
    //if the code exists,then check level
    if(f!=this->codeSet.end())
    {
        /*access the second element(level)
        from the map*/
        unsigned int l = codeSet.find(code)->second;
        if (l >= level)
            return true;
        else
            return false;
    }
    //if code doesn't exist
    else
        return false;
}
