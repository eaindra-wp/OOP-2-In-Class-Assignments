/*
    CH08-320143
    a5-p6-Card.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/

#include "Card.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

Card::Card(rank r, suit s, bool ifu):  m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}

int Card::GetValue() const
{
    int value;

    //for facedown cards
    if(!m_IsFaceUp)
        value = 0;
    //for jack,queen and king cards
    else if(m_Rank==JACK|| m_Rank==QUEEN || m_Rank==KING)
        value = 10;
    else
        //return the number on the card
        value = m_Rank;
    return value;
}

void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}
