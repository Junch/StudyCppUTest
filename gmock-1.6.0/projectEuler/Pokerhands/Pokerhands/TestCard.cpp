//
//  TestCard.cpp
//  Pokerhands
//
//  Created by wolf76 on 3/5/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//

#include "Card.h"
#include <gtest/gtest.h>

TEST(Card, toString)
{
    int num = 2;
    CardSuit suit = SuitHeart;
    Card card(num, suit);
    EXPECT_STREQ("2H", card.toString().c_str());
}