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
#include <vector>

class Card;
class Hand;

enum CardSuit
{
    SuitSpade,
    SuitHeart,
    SuitClub,
    SuitDiamond
};

class CardConverter
{
public:
    std::string cardToString(Card c);
    Card stringToCard(std::string str);
    void stringToCards(std::string str, std::vector<Card>& cards);
};

class Card
{
public:
    Card(int num, CardSuit suit);
    std::string toString();
    int      number();
    CardSuit suit();
    bool operator == (const Card& val);
    
private:
    int      _num;
    CardSuit _suit;
};

class Hand
{
public:
    int add(Card card);
    int length();
    
private:
    std::vector<Card> _cards;
};

class Game
{
public:
    void run(std::string filename);   
};

#endif /* defined(__Pokerhands__Card__) */
