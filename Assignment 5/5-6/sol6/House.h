/*
    CH08-320143
    a5-p6-House.h
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#ifndef _HOUSE_H
#define _HOUSE_H
#include "GenericPlayer.h"

class House : public GenericPlayer
{
public:
    House(const std::string& name = "House");

    virtual ~House();

    //indicates whether house is hitting - will always hit on 16 or less
    virtual bool IsHitting() const;

    //flips over first card
    void FlipFirstCard();
};
#endif // _HOUSE_H
