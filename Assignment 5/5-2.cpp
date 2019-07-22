/*
    CH08-320143
    a5-p2.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include <exception>
#include <cstring>
#include <cstdlib>
using namespace std;
//OwnException: overwrite exception class
class OwnException: public exception
{
public:
    char cmp[100];
    //constructor with char* parameter
    OwnException(const char* cmp = NULL)
    {
        //copy the message thrown
        if(cmp)
            strcpy(this->cmp,cmp);
        else
            strcpy(this->cmp,"This is a default exception case.");
    }
    //overwrite what() method
    virtual const char* what() const throw()
    {
        return "This is an OwnException";
        //return a new string
    }
};
//throw different data types according to input char parameter
void check_exception(char n)
{
    if(n=='1')
        throw 'e';
    if(n=='2')
        throw 99;
    if(n=='3')
        throw false;
    else
        //for default throw
        throw OwnException("This is a default case exception");
}

int main()
{
    cout << "Type 1,2,3 or other" << endl;
    char n;
    cin >> n;
    try
    {
        check_exception(n);
    }
    catch(char& ch)
    {
        //exception for char
        cerr << "Exception caught in main: " << ch << endl;
    }
    catch(int& i)
    {
        //exception for int
        cerr << "Exception caught in main: " << i << endl;
    }
    catch(bool& b)
    {
        //exception for bool
        cerr << "Exception caught in main: " << boolalpha << b << endl;
    }
    catch(OwnException& oe)
    {
        //exception for default
        cerr << "Exception caught in main: " << oe.what() << endl;
    }
    return 0;
}
