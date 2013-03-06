//
//  TestCard.cpp
//  Pokerhands
//
//  Created by wolf76 on 3/5/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//

#include "Card.h"
#include <gtest/gtest.h>

#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

TEST(CardConverter, cardToString)
{
    CardConverter converter;
    EXPECT_STREQ("2D", converter.cardToString(Card(2, SuitDiamond)).c_str());
    EXPECT_STREQ("JS", converter.cardToString(Card(11, SuitSpade)).c_str());
    EXPECT_STREQ("TH", converter.cardToString(Card(10, SuitHeart)).c_str());
    EXPECT_STREQ("AC", converter.cardToString(Card(14, SuitClub)).c_str());
}

TEST(CardConverter, stringToCard)
{
    CardConverter converter;
    
    EXPECT_TRUE(Card(2, SuitDiamond) == converter.stringToCard("2D"));
    EXPECT_TRUE(Card(10, SuitSpade) == converter.stringToCard("TS"));
    EXPECT_TRUE(Card(12, SuitClub) == converter.stringToCard("QC"));
    EXPECT_TRUE(Card(14, SuitHeart) == converter.stringToCard("AH"));
}

TEST(CardConverter, stringToCards)
{
    CardConverter converter;
    
    std::string str("7S 5S 9S JD KD 9C JC AD 2D 7C");
    std::vector<Card> cards;
    converter.stringToCards(str, cards);
    
    EXPECT_EQ(10, cards.size());
    EXPECT_STREQ("7S", cards[0].toString().c_str());
    EXPECT_STREQ("JD", cards[3].toString().c_str());
    EXPECT_STREQ("7C", cards[9].toString().c_str());
}

TEST(Card, toString)
{
    EXPECT_STREQ("2S", Card(2, SuitSpade).toString().c_str());
    EXPECT_STREQ("TS", Card(10, SuitSpade).toString().c_str());
    EXPECT_STREQ("AH", Card(14,  SuitHeart).toString().c_str());
}

TEST(Card, operatorEqual)
{
    EXPECT_TRUE(Card(2, SuitSpade) == Card(2, SuitHeart));
    EXPECT_TRUE(Card(2, SuitSpade) == Card(2, SuitSpade));
}

TEST(Hand, add)
{
    Hand hand;
    EXPECT_EQ(0, hand.length());
    hand.add(Card(14, SuitSpade));
    hand.add(Card(2, SuitSpade));
    EXPECT_EQ(2, hand.length());
}

TEST(Card, operatorLittle)
{
    EXPECT_TRUE(Card(2, SuitSpade) < Card(14, SuitHeart));
    EXPECT_FALSE(Card(14, SuitSpade) < Card(10, SuitSpade));
    EXPECT_FALSE(Card(2, SuitSpade) < Card(2, SuitHeart));
}

TEST(Game, run)
{
    Game game;
    game.run("poker.txt");
}