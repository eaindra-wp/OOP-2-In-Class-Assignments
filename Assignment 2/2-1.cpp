/*
    CH08-320143
    a2-p1.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
class Complex
{
    private:
        double real;
        double imag;
    public:
        Complex(double r,double i)
        {
           this->real = r;
           this->imag = i;
        }
        Complex& operator= (const Complex& obj)
        {
            this->real = obj.real;
            this->imag = obj.imag;
            return *this;
        }
        /*overload the < operator to find minimum
        value for each complex value pair*/
        bool operator< (const Complex obj)
        {
            double abs1,abs2,rl1,im1,rl2,im2;
            rl1 = obj.real * obj.real;
            im1 = obj.imag * obj.imag;
            rl2 = this->real * this->real;
            im2 = this->imag *  this->imag;
            //find the absolute value of two complex numbers
            abs1 = sqrt(rl1+im1);
            abs2 = sqrt(rl2+im2);
            /*return whether the first complex number is
            smaller than the second complex number
            (true or false)*/
            return (abs1<abs2);
        }
        //overload output operator
		friend ostream& operator<<(ostream &o, Complex obj)
		{
			o << obj.real << "+" << obj.imag << "i" << endl;
			return o;
		}
};
//generic template to find minimum value
template <class T>
T array_min(T arr[], int size)
{
	int i;
	T mini = arr[0];
	//set minimum value as the first value
	for (i = 1; i < size; i++)
    {
		if (arr[i] < mini)
            mini = arr[i];
        /*change the minimum if a smaller value
        is found*/
	}
	return mini;
	//return the minimum value
}
int main()
{
    //test for different data types
	int intarr[] = {1, 2, 3, 4, 5, 6};
	cout << array_min(intarr, 6) << endl;

	double darr[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
	cout << array_min(darr, 6) << endl;

	string sarr[] = {"apple", "cherry", "orange"};
	cout << array_min(sarr, 3) << endl;

	Complex carr[] = {Complex(1, 2), Complex(3, 4), Complex(-3, -5)};
	cout << array_min(carr, 3) << endl;
}
