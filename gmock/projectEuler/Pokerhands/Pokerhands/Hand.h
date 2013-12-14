//
//  Hand.h
//  Pokerhands
//
//  Created by wolf76 on 3/7/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//

#ifndef __Pokerhands__Hand__
#define __Pokerhands__Hand__

#include "Card.h"

enum CardsRank
{
    RankNone,         //Not ranked
    RankHighCard,     //Highest value card.
    RankOnePair,      //Two cards of the same value.
    RankTwoPairs,     //Two different pairs.
    RankThreeOfaKind, //Three cards of the same value.
    RankStraight,     //All cards are consecutive values.
    RankFlush,        //All cards of the same suit.
    RankFullHouse,    //Three of a kind and a pair.
    RankFourOfaKind,  //Four cards of the same value.
    RankStraightFlush,//All cards are consecutive values of same suit.
};

class Hand
{
public:
    Hand():_rank(RankNone){}
    Hand(std::string str);
    int add(Card card); // it will sort the card when adding
    int length() const;

    CardsRank rank() const;
    void    points(std::vector<int>& pts)const;
    void    computeRank();
    
    bool    isFlush() const;
    bool    isStraight() const;
    int     longestSameCardsLength(int& cardNum) const;
    
    bool    operator > (Hand& hand);
    
private:
    int  longestSameCardsLength(const std::vector<Card>& cards, int& cardNum) const;
    
    std::vector<Card> _cards;
    CardsRank _rank;
    std::vector<int> _points;
};

#endif /* defined(__Pokerhands__Hand__) */
