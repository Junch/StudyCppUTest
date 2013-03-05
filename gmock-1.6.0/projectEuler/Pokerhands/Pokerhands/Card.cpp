//
//  Card.cpp
//  Pokerhands
//
//  Created by wolf76 on 3/5/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//

#include "Card.h"

Card::Card(int num, CardSuit suit)
:_num(num),_suit(suit)
{
    
}

std::string
Card::toString()
{
    return "";
}

int
Card::number()
{
    return _num;
}

CardSuit
Card::suit()
{
    return _suit;
}
