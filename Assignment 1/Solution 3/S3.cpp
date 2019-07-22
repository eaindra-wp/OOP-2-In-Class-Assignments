/*
    CH08-320143
    a1-p3.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
using namespace std;

class A
{
    int x;
    public:
        void setX(int i)
        {
            x = i;
        }
        void print()
        {
            cout << x;
        }
};

class B:  public virtual A
/*initially, it was
class B: public A*/
{
    public:
        B()
        {
            setX(10);
        }
};

class C:  public virtual A
/*initially, it was
class C: public A*/
{
    public:
        C()
        {
            setX(20);
        }
};

class D: public B, public C
{
};

int main()
{
    D d;
    d.print();
    return 0;
}
/*
the error is "request for member 'print'
is ambiguous". Class D inherits both
class B and C, and both classes are inherited
from class A, which is print() method. Hence,
the compiler doesn't know which class to use.
So, we can fix this problem by extending both
class B and C by adding "virtual" between
"public A".
*/
