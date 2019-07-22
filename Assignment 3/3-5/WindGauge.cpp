/*
    CH08-320143
    a3-p5-WindGauge.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <deque>
#include <iostream>
#include <climits>
#include <algorithm>
#include "WindGauge.h"
using namespace std;
//default constructor
WindGauge::WindGauge(int period)
{
    this->period = period;
}
void WindGauge::currentWindSpeed(int speed)
{
    /*if the history is longer than period,
    discard the oldest wind record*/
    if((int)this->dq.size()>this->period)
        dq.pop_back();

    dq.push_front(speed);
}
int WindGauge::highest() const
{
    int res = INT_MIN;
    deque<int> :: const_iterator i;
    //to return the highest value
    for(i=this->dq.begin(); i!=this->dq.end(); i++)
    {
        res = max(res, *i);
    }
    return res;
}
int WindGauge::lowest() const
{
    int res = INT_MAX;
    deque<int> :: const_iterator i;
    //to return the lowest value
    for(i=this->dq.begin(); i!=this->dq.end(); i++)
    {
        res = min(res,*i);
    }
    return res;
}
int WindGauge::average() const
{
    int res = 0;
    deque<int> :: const_iterator i;
    //to return the average value
    for(i=this->dq.begin(); i!=this->dq.end(); i++)
    {
        res += *i;
    }
    return res/this->dq.size();
    //average value
}
//to dump highest,lowest and average from deque
void WindGauge::dump() const
{
    cout<<"Lowest: "<<this->lowest();
    cout<<"\nHighest: "<<this->highest();
    cout<<"\nAverage: "<<this->average()<<endl;
}
