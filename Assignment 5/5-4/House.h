/*
    CH08-320143
    a5-p4-House.h
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#ifndef _HOUSE_H
#define _HOUSE_H
#include "GenericPlayer.h"
//we have to include GenericPlayer.h as House class is
//derived from GenericPlayer class.
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
