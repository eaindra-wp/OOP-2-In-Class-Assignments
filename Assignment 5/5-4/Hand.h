/*
    CH08-320143
    a5-p4-Hand.h
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#ifndef _HAND_H
#define _HAND_H
#include "Card.h"
#include <vector>
//this hand class is dependent on Card class
//as we have to use the card vector from that class.
//So, Card.h header file included.
class Hand
{
public:
    Hand();

    virtual ~Hand();

    //adds a card to the hand
    void Add(Card* pCard);

    //clears hand of all cards
    void Clear();

    //gets hand total value, intelligently treats aces as 1 or 11
    int GetTotal() const;

protected:
    std::vector<Card*> m_Cards;
};

#endif // _HAND_H
