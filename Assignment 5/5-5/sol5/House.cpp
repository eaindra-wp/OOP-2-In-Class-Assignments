/*
    CH08-320143
    a5-p5-House.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include "House.h"
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

House::House(const std::string& name):
    GenericPlayer(name)
{}

House::~House()
{}

bool House::IsHitting() const
{
    return (GetTotal() <= 16);
}

void House::FlipFirstCard()
{
    if (!(m_Cards.empty()))
	{
        m_Cards[0]->Flip();
	}
    else
	{
		std::cout << "No card to flip!\n";
	}
}
