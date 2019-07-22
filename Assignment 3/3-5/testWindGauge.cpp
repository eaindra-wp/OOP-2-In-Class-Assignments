/*
    CH08-320143
    a3-p5-testWindGauge.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include <deque>
#include <algorithm>
#include "WindGauge.h"

using namespace std;
int main()
{
    //object with testcases
    WindGauge w;
    w.currentWindSpeed(14);
    w.currentWindSpeed(16);
    w.currentWindSpeed(13);
    w.currentWindSpeed(15);
    w.currentWindSpeed(15);
    w.dump();

    w.currentWindSpeed(15);
    w.currentWindSpeed(17);
    w.currentWindSpeed(17);
    w.currentWindSpeed(16);
    w.currentWindSpeed(20);
    w.currentWindSpeed(15);
    w.currentWindSpeed(16);
    w.currentWindSpeed(20);
    w.dump();

    return 0;
}
