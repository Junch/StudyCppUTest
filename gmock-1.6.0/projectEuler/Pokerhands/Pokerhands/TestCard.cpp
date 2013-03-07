//
//  TestCard.cpp
//  Pokerhands
//
//  Created by wolf76 on 3/5/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//

#include <gtest/gtest.h>
#include "Card.h"
#include "Hand.h"
#include "Game.h"

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

TEST(Card, operatorLittle)
{
    EXPECT_TRUE(Card(2, SuitSpade) < Card(14, SuitHeart));
    EXPECT_FALSE(Card(14, SuitSpade) < Card(10, SuitSpade));
    EXPECT_FALSE(Card(2, SuitSpade) < Card(2, SuitHeart));
}

TEST(Hand, add)
{
    Hand hand;
    EXPECT_EQ(0, hand.length());
    hand.add(Card(14, SuitSpade));
    hand.add(Card(2, SuitSpade));
    EXPECT_EQ(2, hand.length());
}

TEST(Hand, computeRank_highcard)
{
    // 7S 5S 9S JD KD
    Hand hand;
    hand.add(Card(7, SuitSpade));
    hand.add(Card(5, SuitSpade));
    hand.add(Card(9, SuitSpade));
    hand.add(Card(11, SuitDiamond));
    hand.add(Card(13, SuitDiamond));
    
    hand.computeRank();
    EXPECT_EQ(RankHighCard, hand.rank());
    EXPECT_EQ(13, hand.number());
}

TEST(Hand, computeRank_onePair)
{
    // 5H 5C 6S 7S KD
    Hand hand;
    hand.add(Card(5,  SuitHeart));
    hand.add(Card(5,  SuitClub));
    hand.add(Card(6,  SuitSpade));
    hand.add(Card(7,  SuitSpade));
    hand.add(Card(13, SuitDiamond));
    
    hand.computeRank();
    EXPECT_EQ(RankOnePair, hand.rank());
    EXPECT_EQ(5, hand.number());
}

TEST(Hand, computeRank_twoPairs)
{
    // 5H 5C 6S 6D KD
    Hand hand;
    hand.add(Card(5,  SuitHeart));
    hand.add(Card(5,  SuitClub));
    hand.add(Card(6,  SuitSpade));
    hand.add(Card(6,  SuitDiamond));
    hand.add(Card(13, SuitDiamond));
    
    hand.computeRank();
    EXPECT_EQ(RankTwoPairs, hand.rank());
    EXPECT_EQ(6, hand.number());
}

TEST(Hand, computeRank_threeOfaKind)
{
    // 5H 5C 5S 6D KD
    Hand hand;
    hand.add(Card(5,  SuitHeart));
    hand.add(Card(5,  SuitClub));
    hand.add(Card(5,  SuitSpade));
    hand.add(Card(6,  SuitDiamond));
    hand.add(Card(13, SuitDiamond));
    
    hand.computeRank();
    EXPECT_EQ(RankThreeOfaKind, hand.rank());
    EXPECT_EQ(5, hand.number());
}

TEST(Hand, computeRank_straight)
{
    // 3H 4C 5S 6D 7D
    Hand hand;
    hand.add(Card(3, SuitHeart));
    hand.add(Card(4, SuitClub));
    hand.add(Card(5, SuitSpade));
    hand.add(Card(6, SuitDiamond));
    hand.add(Card(7, SuitDiamond));
    
    hand.computeRank();
    EXPECT_EQ(RankStraight, hand.rank());
    EXPECT_EQ(7, hand.number());
}

TEST(Hand, computeRank_flush)
{
    // 5H 5H 5H 6H KH
    Hand hand;
    hand.add(Card(5, SuitHeart));
    hand.add(Card(5, SuitHeart));
    hand.add(Card(5, SuitHeart));
    hand.add(Card(6, SuitHeart));
    hand.add(Card(13, SuitHeart));
    
    hand.computeRank();
    EXPECT_EQ(RankFlush, hand.rank());
    EXPECT_EQ(13, hand.number());
}

TEST(Hand, computeRank_fullHouse)
{
    // 5H 5C 5D 9H 9S
    Hand hand;
    hand.add(Card(5, SuitHeart));
    hand.add(Card(5, SuitClub));
    hand.add(Card(5, SuitDiamond));
    hand.add(Card(9, SuitHeart));
    hand.add(Card(9, SuitSpade));
    
    hand.computeRank();
    EXPECT_EQ(RankFullHouse, hand.rank());
    EXPECT_EQ(9, hand.number());
}

TEST(Hand, computeRank_fourOfaKind)
{
    // 5H 5C 5S 5D KD
    Hand hand;
    hand.add(Card(5,  SuitHeart));
    hand.add(Card(5,  SuitClub));
    hand.add(Card(5,  SuitSpade));
    hand.add(Card(5,  SuitDiamond));
    hand.add(Card(13, SuitDiamond));
    
    hand.computeRank();
    EXPECT_EQ(RankFourOfaKind, hand.rank());
    EXPECT_EQ(5, hand.number());
}

TEST(Hand, computeRank_straightFlush)
{
    // 3C 4C 5C 6C 7C
    Hand hand;
    hand.add(Card(3, SuitClub));
    hand.add(Card(4, SuitClub));
    hand.add(Card(5, SuitClub));
    hand.add(Card(6, SuitClub));
    hand.add(Card(7, SuitClub));
    
    hand.computeRank();
    EXPECT_EQ(RankStraightFlush, hand.rank());
    EXPECT_EQ(7, hand.number());
}

TEST(Hand, isFlush_True)
{
    // 5H 5H 5H 6H KH
    Hand hand;
    hand.add(Card(5, SuitHeart));
    hand.add(Card(5, SuitHeart));
    hand.add(Card(5, SuitHeart));
    hand.add(Card(6, SuitHeart));
    hand.add(Card(13, SuitHeart));
    
    EXPECT_TRUE(hand.isFlush());
}

TEST(Hand, isFlush_False)
{
    // 5H 5H 5H 6H KH
    Hand hand;
    hand.add(Card(5, SuitHeart));
    hand.add(Card(5, SuitHeart));
    hand.add(Card(5, SuitHeart));
    hand.add(Card(6, SuitDiamond));
    hand.add(Card(13, SuitHeart));
    
    EXPECT_FALSE(hand.isFlush());
}

TEST(Hand, isStraight_True)
{
    // 3C 4H 5S 6H 7D
    Hand hand;
    hand.add(Card(3, SuitClub));
    hand.add(Card(4, SuitHeart));
    hand.add(Card(5, SuitSpade));
    hand.add(Card(6, SuitHeart));
    hand.add(Card(7, SuitDiamond));
    
    EXPECT_TRUE(hand.isStraight());
}

TEST(Hand, isStraight_False)
{
    // 3C 4H 7S 8H 9D
    Hand hand;
    hand.add(Card(3, SuitClub));
    hand.add(Card(4, SuitHeart));
    hand.add(Card(7, SuitSpade));
    hand.add(Card(8, SuitHeart));
    hand.add(Card(9, SuitDiamond));
    
    EXPECT_FALSE(hand.isStraight());
}

TEST(Hand, longestSameCardsLength_3)
{
    // 3C 7H 7S 7H 9D
    Hand hand;
    hand.add(Card(3, SuitClub));
    hand.add(Card(7, SuitHeart));
    hand.add(Card(7, SuitSpade));
    hand.add(Card(7, SuitHeart));
    hand.add(Card(9, SuitDiamond));
    
    int cardNum;
    int len = hand.longestSameCardsLength(cardNum);
    
    EXPECT_EQ(3, len);
    EXPECT_EQ(7, cardNum);
}

TEST(Hand, longestSameCardsLength_1)
{
    // 3C 7H AS TH 9D
    Hand hand;
    hand.add(Card(3, SuitClub));
    hand.add(Card(7, SuitHeart));
    hand.add(Card(14, SuitSpade));
    hand.add(Card(10, SuitHeart));
    hand.add(Card(9, SuitDiamond));
    
    int cardNum;
    int len = hand.longestSameCardsLength(cardNum);
    
    EXPECT_EQ(1, len);
    EXPECT_EQ(14, cardNum);
}

TEST(Game, run)
{
    Game game;
    game.run("poker.txt");
}