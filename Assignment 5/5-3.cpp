/*
    CH08-320143
    a5-p3.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include <cstdlib>
using namespace std;
//Motor class
class Motor
{
public:
    Motor()
    {
        //throw message
        throw "This motor has problems";
    }
};

//Car class
class Car
{
    Motor *motor;
public:
    Car()
    {
        try
        {
            motor = new Motor();
        }
        catch(const char* err)
        {
            //throw the string caught from Motor object again
            throw err;
        }
    }
    ~Car()
    {
        delete motor;
    }
};
class Garage
{
    Car *car;
public:
    Garage()
    {
        try
        {
            //to catch string thrown from car object
            car = new Car();
        }
        catch(const char* err)
        {
            //throw a new sentence
            throw "The car in this garage has problems with the motor";
        }
    }
    ~Garage()
    {
        delete car;
    }
};
int main()
{
    Garage *garage;
    try
    {
        //catch from garage object
        garage = new Garage();

    }
    catch (const char* err)
    {
        //print what is caught in the main function
        cerr << err << endl;
        return 1;
    }
    //to deallocate
    delete garage;
    return 0;
}
