//
//  Card.h
//  Pokerhands
//
//  Created by wolf76 on 3/5/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//

#ifndef __Pokerhands__Card__
#define __Pokerhands__Card__
#include <string>

enum CardSuit
{
    SuitSpade,
    SuitHeart,
    SuitClub,
    SuitDiamond
};

class Card
{
public:
    Card(int num, CardSuit suit);
    std::string toString();
    int      number();
    CardSuit suit();
private:
    int      _num;
    CardSuit _suit;
};


#endif /* defined(__Pokerhands__Card__) */
