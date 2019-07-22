/*
    CH08-320143
    a1-p4.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include<iostream>
using namespace std;

class A
{
    int x;
    public:
        A(int i)
        {
            x = i;
        }
        void print()
        {
            cout << x;
        }
};

class B: virtual public A
{
    public:
        B():A(10) {  }
};

class C:  virtual public A
{
    public:
        C():A(10) {  }
};

class D: public B, public C
{
    public:
        D() :A(20), B(), C() {}
        //call constructors manually
};

int main()
{
    D d;
    d.print();
    return 0;
}
/*The error is that there is no matching
function to call A::A(). Since Class B and C
are 'public virtual' of A, extending D with B
and C does not directly connect with A. Hence,
each constructor of A,B and C should be called
separately.
*/
