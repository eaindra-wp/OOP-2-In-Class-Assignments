/*
    CH08-320143
    a5-p6-Hand.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/

#include "Hand.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
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
	//initialize the total points from cards to zero
    std::vector<Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); iter++)
    {
        //pointer object for card class
        Card *cur = *iter;
        if(cur->GetValue() == Card::ACE)
        {
            //check whether the total number would be less
            //than or equal to 21 if ace is found
            if (total+11 <= 21)
                total += 11;
            else
                total++;
        }
        else
            total += cur->GetValue();
            //update total with numbers found on each card
    }
    return total;
}
