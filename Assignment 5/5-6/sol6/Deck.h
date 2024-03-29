/*
    CH08-320143
    a5-p6-Deck.h
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/

#ifndef _DECK_H
#define _DECK_H
#include "GenericPlayer.h"
#include "Hand.h"

class Deck : public Hand
{
public:
    Deck();

    virtual ~Deck();

    //create a standard deck of 52 cards
    void Populate();

    //shuffle cards
    void Shuffle();

    //deal one card to a hand
    void Deal(Hand& aHand);

    //give additional cards to a generic player
    void AdditionalCards(GenericPlayer& aGenericPlayer);
};
#endif // _DECK_H
