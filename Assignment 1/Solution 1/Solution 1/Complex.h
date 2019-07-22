/*
    CH08-320143
    a1_p1_Complex.h
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
class Complex
{
private:
	float real;  // real value
	float imag;  // imag value

public:
	Complex(); // empty constructor
	Complex(float, float); // constructor taking values for real and imag
	Complex(const Complex&); // copy constructor
    ~Complex(); //destructor

    //setter methods
	void setReal(float newreal);
	void setImag(float newimag1);
	void setConjugate(float , float);

	//getter methods
	double getReal();
	double getImag();

	//prototypes for calculation with overload operators
	Complex operator+(const Complex&);
    Complex operator-(const Complex&);
    Complex operator*(const Complex&);
    Complex& operator= (const Complex&);

    //input and output overload operators
    friend std::ostream& operator<<(std::ostream&, const Complex&);
	friend std::istream& operator>>(std::istream&, Complex&);
};
