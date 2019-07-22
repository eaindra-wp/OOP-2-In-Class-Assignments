/*
    CH08-320143
    a5-p4-GenericPlayer.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include "GenericPlayer.h"
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

//implementation of methods from GenericPlayer.h header file
GenericPlayer::GenericPlayer(const std::string& name):
    m_Name(name)
{}

GenericPlayer::~GenericPlayer()
{}

bool GenericPlayer::IsBusted() const
{
    return (GetTotal() > 21);
}

void GenericPlayer::Bust() const
{
    std::cout << m_Name << " busts.\n";
}
