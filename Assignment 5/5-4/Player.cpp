/*
    CH08-320143
    a5-p4-Player.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Player.h"

//implementation of methods from Player.h header file
Player::Player(const std::string& name):
    GenericPlayer(name)
{}

Player::~Player()
{}

bool Player::IsHitting() const
{
    std::cout << m_Name << ", do you want a hit? (Y/N): ";
    char response;
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::Win() const
{
    std::cout << m_Name <<  " wins.\n";
}

void Player::Lose() const
{
    std::cout << m_Name <<  " loses.\n";
}

void Player::Push() const
{
    std::cout << m_Name <<  " pushes.\n";
}
