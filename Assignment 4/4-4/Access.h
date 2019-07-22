/*
    CH08-320143
    a4-p4-Access.h
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#ifndef _ACCESS_H
#define _ACCESS_H
#include <set>
#include <iostream>
using namespace std;
class Access
{
public:
    void activate(unsigned long code);
    void deactivate(unsigned long code);
    bool isactive(unsigned long code) const;
private:
    //private set
    set<unsigned long> codeSet;
};
#endif // _ACCESS_H
