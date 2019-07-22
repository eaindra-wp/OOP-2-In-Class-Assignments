/*
    CH08-320143
    a5-p4-Hand.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/

#include "Hand.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
//implementation of methods from Hand.h header file
Hand::Hand()
{
    m_Cards.reserve(7);
}

Hand::~Hand()
{
    Clear();
}

void Hand::Add(Card* pCard)
{
    m_Cards.push_back(pCard);
}

void Hand::Clear()
{
    //iterate through vector, freeing all memory on the heap
    std::vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    //clear vector of pointers
    m_Cards.clear();
}

int Hand::GetTotal() const
{
	int total=0;
	//initialize as 0 to remove warning on the compiler

    // to be filled with content

    return total;
}
