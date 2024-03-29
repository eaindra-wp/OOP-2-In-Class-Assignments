/*
    CH08-320143
    a5-p6-Deck.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Deck.h"

Deck::Deck()
{
    m_Cards.reserve(52);
    Populate();
}

Deck::~Deck()
{}

void Deck::Populate()
{
    Clear();
    //create standard deck
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
    {
        for (int r = Card::ACE; r <= Card::KING; ++r)
        {
            Add(new Card(static_cast<Card::rank>(r),
                         static_cast<Card::suit>(s)));
        }
    }
}

void Deck::Shuffle()
{
    random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(Hand& aHand)
{
	//if the deck is not empty
    if(m_Cards.size() != 0)
    {
        Populate();
        Shuffle();
    }
    Card* card = *m_Cards.rbegin();
    m_Cards.pop_back();
    //pop the backmost card from the deck and
    //put into player's hand
    aHand.Add(card);
}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
    std::cout << std::endl;
    //continue to deal a card as long as generic player isn't busted and
    //wants another hit
    while ( !(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting() )
    {
        Deal(aGenericPlayer);
        std::cout << aGenericPlayer << std::endl;

        if (aGenericPlayer.IsBusted())
		{
            aGenericPlayer.Bust();
		}
    }
}
