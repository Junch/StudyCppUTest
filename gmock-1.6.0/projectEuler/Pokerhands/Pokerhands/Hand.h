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
    Hand():_rank(RankNone), _num(0){}
    int add(Card card); // it will sort the card when adding
    int length() const;
    CardsRank rank() const;
    int       number()const;
    void computeRank();
    
    bool isFlush() const;
    bool isStraight() const;
    int  longestSameCardsLength(int& cardNum) const;
    
private:
    int  longestSameCardsLength(const std::vector<Card>& cards, int& cardNum) const;
    
    std::vector<Card> _cards;
    CardsRank _rank;
    int       _num; // It represent the biggest num of the Rank.
};

#endif /* defined(__Pokerhands__Hand__) */
