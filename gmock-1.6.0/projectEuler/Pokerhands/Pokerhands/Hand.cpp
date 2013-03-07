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

int
Hand::number() const
{
    return _num;
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
    int maxLen = 0;
    
    int i = 0;
    int j = 0;
    int size = (int)_cards.size();
    
    while (i < size)
    {
        int len = 1;
        
        j = i + 1;
        while (j < size && _cards[i] == _cards[j])
        {
            ++len;
            ++j;
        }
        
        if (len > maxLen)
        {
            maxLen = len;
            cardNum = _cards[i].number();
        }
        
        i = j;
    }
    
    return maxLen;
}

void
Hand::computeRank()
{
    if (_rank == RankNone)
    {
        bool bFlush = isFlush();
        bool bStraight = isStraight();
        
        if (bFlush && bStraight) {
            _rank = RankStraightFlush;
            _num = _cards[0].number();
            return;
        }
        
        if (bFlush && !bStraight){
            _rank = RankFlush;
            _num = _cards[0].number();
            return;
        }
        
        if(!bFlush && bStraight){
            _rank = RankStraight;
            _num = _cards[0].number();
            return;
        }
        
        int cardNum = 0;
        int length = longestSameCardsLength(cardNum);
        if (length == 4)
            _rank = RankFourOfaKind;
        else if(length == 3)
        {
            //TODO: it maybe is a full house.
            _rank = RankThreeOfaKind;
        }
        else if( length == 2)
        {
            //TODO: it maybe is a two pairs.
            _rank = RankOnePair;
        }
        else if ( length == 1)
            _rank = RankHighCard;
        else
            throw std::logic_error("The longest card should be [1, 4]");
    
        _num  = cardNum;  
    }
}
