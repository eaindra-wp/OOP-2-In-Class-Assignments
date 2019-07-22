/*
    CH08-320143
    a5-p4-Card.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/

#include "Card.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

//implementation of Card class from Card.h header file
Card::Card(rank r, suit s, bool ifu):  m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}

int Card::GetValue() const
{
    int value=0;
    //initialize as 0 to remove warning on the compiler

    // to be filled with content

    return value;
}

void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}
