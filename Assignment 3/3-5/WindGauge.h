/*
    CH08-320143
    a3-p5-WindGauge.h
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#ifndef _WIND_GAUGE_H
#define _WIND_GAUGE_H

#include <iostream>
#include <deque>

using namespace std;

class WindGauge
{
public:
    WindGauge(int period = 10);
    void currentWindSpeed(int speed);
    int highest() const;
    int lowest() const;
    int average() const;
    void dump() const;
private:
    //private properties
    int period;
    deque<int> dq;
};
#endif
