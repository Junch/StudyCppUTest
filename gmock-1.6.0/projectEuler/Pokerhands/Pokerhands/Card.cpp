//
//  Card.cpp
//  Pokerhands
//
//  Created by wolf76 on 3/5/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//

#include "Card.h"
#include <stdexcept>
#include <cassert>
#include <sstream>
#include <fstream>
#include <iostream>

std::string
CardConverter::cardToString(Card card)
{
    int num = card.number();
    
    char c;
    switch (num) {
        case 10:
            c='T';
            break;
        case 11:
            c='J';
            break;
        case 12:
            c='Q';
            break;
        case 13:
            c='K';
            break;
        case 14:
            c='A';
            break;
        default:
            assert(num>1 && num<10);
            c='0' + num;
            break;
    };
    
    char s;
    CardSuit suit = card.suit();
    switch (suit) {
        case SuitHeart:
            s = 'H';
            break;
        case SuitClub:
            s = 'C';
            break;
        case SuitDiamond:
            s = 'D';
            break;
        case SuitSpade:
            s = 'S';
            break;
        default:
            assert(!"Unspported");
            break;
    }
    
    std::stringstream ss;
    ss << c << s;
    std::string ret;
    ss >> ret;
    return ret;
}

Card
CardConverter::stringToCard(std::string str)
{
    assert(str.length() == 2);
    char n = str[0];
    char s = str[1];
    
    int num = 0;
    switch (n) {
        case 'T':     //Ten
            num = 10;
            break;
        case 'J':     //Jack
            num = 11;
            break;
        case 'Q':     //Queen
            num = 12;
            break;
        case 'K':     //King
            num = 13;
            break;
        case 'A':     //Ace
            num = 14;
            break;
        default:
            num = n - '0';
            break;
    }
    
    CardSuit suit = SuitSpade;
    switch (s){
        case 'H':
            suit = SuitHeart;
            break;
        case 'C':
            suit = SuitClub;
            break;
        case 'D':
            suit = SuitDiamond;
            break;
        case 'S':
            suit = SuitSpade;
            break;
        default:
            throw std::logic_error("Unsupported value");
            break;
    }
    
    return Card(num, suit);
}

void
CardConverter::stringToCards(std::string str, std::vector<Card> &cards)
{
    std::stringstream ss(str);
    
    while (true) {
        std::string sub;
        ss >> sub;
        if (sub.empty())
            break;

        Card card = stringToCard(sub);
        cards.push_back(card);
    }
}

////////////////////////////////////////
//              Card
////////////////////////////////////////

Card::Card(int num, CardSuit suit)
:_num(num),_suit(suit)
{
    if (_num<2 || _num>14)
        throw std::out_of_range("Card's num should be [2, 14]."); 
}

std::string
Card::toString()
{
    CardConverter converter;
    return converter.cardToString(*this);
}

int
Card::number() const
{
    return _num;
}

CardSuit
Card::suit() const
{
    return _suit;
}

bool
Card:: operator == (const Card& val) const
{
    return _num==val._num /*&& _suit==val._suit*/;
}

bool
Card:: operator < (const Card& val) const
{
    return _num < val._num;
}

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
        
        // TODO
    }
}

////////////////////////////////////////
//              Game
////////////////////////////////////////

void
Game::run(std::string filename)
{
    std::ifstream file(filename.c_str());
    if(file)
    {
        CardConverter converter;
        
        for(std::string line; std::getline(file, line);)
        {
            std::vector<Card> cards;
            converter.stringToCards(line, cards);
            if (cards.size() == 10)
            {
                Hand hand1;
                Hand hand2;
                for (int i=0; i<5; i++)
                {
                    hand1.add(cards[i]);
                    hand2.add(cards[i+5]);
                }
            }
            else{
                throw std::runtime_error("The size is not correct");
            }
        }
    }
}
