/*
    CH08-320143
    a5-p5-Game.h
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#ifndef _GAME_H
#define _GAME_H
#include <vector>
#include "Deck.h"
#include "House.h"
#include "Player.h"
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
