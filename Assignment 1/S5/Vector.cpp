/*
    CH08-320143
    a1-p5.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include "Vector.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
//constructors
Vector::Vector()
{
    arr = NULL;
    size = 0;
}

Vector::Vector(int s)
{
    size = s;
    arr = new double[s];
}

Vector::Vector(const Vector& cpy)
{
    size = cpy.size;
    arr = new double[size];
    memcpy(arr, cpy.arr, sizeof(double)*size);
    //copy the memory to the original array
}
//destructor
Vector::~Vector()
{
    if(arr != NULL)
        delete []arr;
        // delete if not null
}

double Vector::search(int i) const
{
    return arr[i];
}

void Vector::add(int i, double v)
{
    if(i >= size)
        exit(1);
    arr[i] = v;
}
//return the size of array
int Vector::length() const
{
    return size;
}


void Vector::update(int i)
{
    double* tmp = arr;
    int p_size = size;
    //save previous info
    if(i <= size)
        return;
    //set proper value and grow
    arr = new double[i];
    size = i;
    if(p_size == 0 || tmp == NULL)
        return;
    //make sure the pointers are valid
    memcpy(arr, tmp, sizeof(double) * p_size);
    //copy the content
    delete []tmp;
    //deallocate
}
//print the vector
void Vector::print() const
{
    if(size == 0)
    {
        std::cout << "()" << std::endl;
        return;
    }
    std::cout << "( ";
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << ")" << std::endl;
}

double Vector::norm() const
{
    double sq_sum = 0.0;
    for(int i = 0; i < size; i++)
        sq_sum += arr[i];
    return sqrt(sq_sum);
}

Vector Vector::sum(const Vector& cpy) const
{
    if(size != cpy.size)
        return Vector();
    Vector res(size);
    // create a equal size vector
    for(int i = 0; i < size; i++)
    {
        res.add(i, search(i) + cpy.search(i));
    }
    //add the result
    return res;
}

Vector Vector::diff(const Vector& cpy) const
{
    if(size != cpy.size)
        return Vector();
    Vector res(size); // create a equal size vector
    for(int i = 0; i < size; i++)
    {
        res.add(i, search(i) - cpy.search(i));
    }//add the result
    return res;
}

double Vector::scalarP(const Vector& cpy) const
{
    if(size == 0 || size != cpy.size)
        return 0;
    double p = 0.0;
    for(int i = 0; i < size; i++)
    {
        p += search(i) * cpy.search(i);
    }
    return p;
}

std::istream& operator>>(std::istream& is, Vector& vec)
{
    //retrieve a integer for the dimension of the vector
    //then retrieve every entry of the vector
    int n;
    int tmp;

    is >> n;
    vec.update(n);

    for(int i = 0; i < n; i++)
    {
        is >> tmp; //retrieve the data
        vec.add(i, tmp);
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Vector& vec)
{
    //give the output of the file
    if(vec.length() == 0)
        return os;
    os << "(";
    for(int i = 0; i < vec.length() - 1; i++)
    {
        os << vec.search(i) << ",";
    }
    os << vec.search(vec.length() - 1) << ")" << std::endl;
    //comma seperated
    return os;
}
