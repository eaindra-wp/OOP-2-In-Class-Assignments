/*
    CH08-320143
    a6-p2.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include <sstream>
using namespace std;

void foo(int *array, int n, int *odds)
{
    for(int i=0; i<n; i++)
        if (array[i] % 2 == 1)
            *odds++;
}

class Test
{
private:
    double *a;
    int n;
public:
    Test()
    {
        a=NULL;
        n=0;
    }
    Test(double *a, int n)
    {
        this->n = n;
        if (this->a != NULL)
        {
            delete this->a;
        }
        this->a = new double[n];
        for(int i=0; i<n; i++)
            this->a[i] = a[i];
    }
    string toString()
    {
        ostringstream ss;
        ss << "Length: " << n << endl << "Elements: ";
        for(int i=0; i<n; i++)
            ss << a[i] << " ";
        ss << endl;
        return ss.str();
    }
    ~Test()
    {
        delete a;
    }
};

int main()
{
    int array[3] = {1, 2, 3};
    int odd_values=0;
    foo(array, 3, &odd_values);
    cout << "Amount of odd values in the array=" << odd_values << endl;
    Test arr[5];
    double v[3] = {1.2, 2.3, 3.45};
    Test *obj1;
    obj1=&arr[0];
    Test *obj2 = new Test(v, 3);
    Test *obj3 = NULL;
    cout << obj1->toString();
    cout << obj2->toString();
    cout << obj3->toString();
    delete obj1;
    delete obj2;
    delete obj3;
    return 0;
}
/*
I used the debugger from CodeBlocks to debug this program.
The program crashes with some trash return values if
I run the program.
array[3] in the main function contains 2 odd numbers, but it prints 0.
So,I set a break point at line 11,which calculates the number odd values.
The mistake is that we just increment the pointer of odds with *odds++,
which does not really increment the value of odds.And it is shown that
*odds++ is unused when I compile the program.
We can modify that problem by editing as (*odds++).

I got the segmentation fault while going to line 69 (cout<<obj3->toString()).
The debugger leads to line 43,which is to print n. Obj3 pointer is assigned
to be NULL in line 66.So,there is no value for n to be printed.

Another problem is delete obj1 in line 70. obj1 is dynamically allocated,
but the value assigned (&arr[0]) is statically allocated. So,we cannot
delete the statically allocated variables.

I got an error with deleting obj3 at line 72.
Deleting obj3 also is a problem as obj3 is assigned to be NULL.So,there is
nothing to be deleted for that object.
*/
