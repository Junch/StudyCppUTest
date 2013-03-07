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
            if(num<2 || num >9)
                throw std::logic_error("The num should be [2, 9]");
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
            throw std::logic_error("Unsupported value");
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
