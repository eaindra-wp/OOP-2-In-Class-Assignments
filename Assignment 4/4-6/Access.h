/*
    CH08-320143
    a4-p6-Access.h
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#ifndef _ACCESS_H
#define _ACCESS_H
#include <map>
#include <iostream>
using namespace std;
class Access
{
public:
    void activate(unsigned long code,unsigned int level);
    void deactivate(unsigned long code);
    bool isactive(unsigned long code,unsigned int level) const;
private:
    //private set
    map<unsigned long,unsigned int> codeSet;
};
#endif // _ACCESS_H
