/*
    CH08-320143
    a1-p5.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/

#include <iostream>
class Vector
{
    private:
        double* arr;
        int size;
    public:
        Vector();
        Vector(int n_size);
        Vector(const Vector&);
        ~Vector();

        double search(int i) const;
        //return the value at given index
        void add(int i, double v);
        //add elements at given index

        int length() const;
        void update(int s); //extend the size of the Vector to a given number

        //method services
        void print() const;
        double norm() const;
        Vector sum(const Vector& other) const;
        Vector diff(const Vector& other) const;
        double scalarP(const Vector& other) const;
};
//overload operators for input and output
std::istream& operator>>(std::istream& is, Vector& vec);
std::ostream& operator<<(std::ostream& os, const Vector& vec);
