/*
    CH08-320143
    a5-p4-Game.h
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#ifndef _GAME_H
#define _GAME_H
#include <vector>
#include "Deck.h"
#include "House.h"
#include "Player.h"
//this deck class is dependent on Deck,House and Player class
//as objects of Deck and House classes,and the vector of player list
//are set as private properties.
class Game
{
public:
    Game(const std::vector<std::string>& names);

    ~Game();

    //plays the game of blackjack
    void Play();

private:
    Deck m_Deck;
    House m_House;
    std::vector<Player> m_Players;
};
#endif // _GAME_H
