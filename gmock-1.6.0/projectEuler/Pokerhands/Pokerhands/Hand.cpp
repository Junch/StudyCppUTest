//
//  Hand.cpp
//  Pokerhands
//
//  Created by wolf76 on 3/7/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//

#include "Hand.h"
#include <stdexcept>

////////////////////////////////////////
//              Hand
////////////////////////////////////////

int
Hand::add(Card card)
{
    std::vector<Card>::iterator iter=_cards.begin();
    while(iter != _cards.end() &&  card < *iter)
        ++iter;
    
    _cards.insert(iter, card);
    return (int)_cards.size();
}

int
Hand::length() const
{
    return (int)_cards.size();
}

CardsRank
Hand::rank() const
{
    return _rank;
}

bool
Hand::isFlush() const
{
    std::size_t len = _cards.size();
    if (len == 0)
        return false;
    
    CardSuit s = _cards[0].suit();
    for (int i=1; i<len; i++) {
        if (s != _cards[i].suit())
            return false;
    }
    
    return true;
}

bool
Hand::isStraight() const
{
    std::size_t len = _cards.size();
    if (len == 0)
        return false;
    
    for (int i=1; i<len; i++) {
        if ( _cards[i].number() < _cards[i-1].number() - 1)
            return false;
    }
    
    return true;
}

int
Hand::longestSameCardsLength(int& cardNum) const
{
    return longestSameCardsLength(_cards, cardNum);
}

int
Hand::longestSameCardsLength(const std::vector<Card>& cards, int& cardNum) const
{
    int maxLen = 0;
    
    int i = 0, j = 0;
    int size = (int)cards.size();
    
    while (i < size)
    {
        int len = 1;
        
        j = i + 1;
        while (j < size && cards[i] == cards[j])
        {
            ++len;
            ++j;
        }
        
        if (len > maxLen)
        {
            maxLen = len;
            cardNum = cards[i].number();
        }
        
        i = j;
    }
    
    return maxLen;
}

void
Hand::computeRank()
{
    bool bFlush = isFlush();
    bool bStraight = isStraight();
    
    if (bFlush && bStraight) {
        _rank = RankStraightFlush;
        _points.push_back(_cards[0].number());
        return;
    }
    
    if(!bFlush && bStraight){
        _rank = RankStraight;
        _points.push_back(_cards[0].number());
        return;
    }
    
    if (bFlush && !bStraight){
        _rank = RankFlush;
        
        for (size_t i=0, len=_cards.size(); i<len; i++)
            _points.push_back(_cards[i].number());
        return;
    }
        
    int cardNum = 0;
    int length = longestSameCardsLength(cardNum);
    if (length == 4)
    {
        _rank = RankFourOfaKind;
        
        _points.push_back(cardNum);
        for (size_t i=0, len=_cards.size(); i<len; i++)
        {
            if (_cards[i].number() != cardNum)
            {
                _points.push_back(_cards[i].number());
                break;
            }
        }
    }
    else if(length == 3 ||length == 2)
    {
        std::vector<Card> cardsLeft = _cards;
        for (std::vector<Card>::iterator iter = cardsLeft.begin();
             iter != cardsLeft.end();)
        {
            if (iter->number() == cardNum)
                cardsLeft.erase(iter);
            else
                ++iter;
        }
        
        int nextCardNum = 0;
        int nextLength = longestSameCardsLength(cardsLeft, nextCardNum);
        
        if (nextLength == 2)
            _rank = (length == 3)? RankFullHouse : RankTwoPairs;
        else
            _rank = (length == 3)? RankThreeOfaKind : RankOnePair;
        
        _points.push_back(cardNum);
        switch (_rank) {
            case RankFullHouse:
            case RankTwoPairs:
            {
                _points.push_back(nextCardNum);
                
                for (size_t i=0, len=cardsLeft.size(); i<len; i++)
                {
                    if (cardsLeft[i].number() != nextCardNum)
                        _points.push_back(cardsLeft[i].number());
                }
                break;
            }
            case RankThreeOfaKind:
            case RankOnePair:
            {
                for (size_t i=0, len=cardsLeft.size(); i<len; i++)
                    _points.push_back(cardsLeft[i].number());
                break;
            }
            default:
                break;
        }           
    }
    else if ( length == 1)
    {
        _rank = RankHighCard;
        for (size_t i=0, len=_cards.size(); i<len; i++)
            _points.push_back(_cards[i].number());
    }
    else
        throw std::logic_error("The longest card should be [1, 4]");
}

void
Hand::points(std::vector<int>& pts)const
{
    pts = _points;
}
