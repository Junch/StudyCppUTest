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

enum CardsRank
{
    RankNone,        //Not ranked
    RankHighCard,    //Highest value card.
    RankOnePair,     //Two cards of the same value.
    RankTwoPairs,    //Two different pairs.
    RankThreeOfaKind,//Three cards of the same value.
    RankStraight,    //All cards are consecutive values.
    RankFlush,       //All cards of the same suit.
    RankFullHouse,   //Three of a kind and a pair.
    RankFourOfaKind, //Four cards of the same value.
    RankStraightFlush,//All cards are consecutive values of same suit.
    RankRoyalFlush   //Ten, Jack, Queen, King, Ace, in same suit.
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
    bool operator < (const Card& val);
    
private:
    int      _num;
    CardSuit _suit;
};

class Hand
{
public:
    Hand():_rank(RankNone), _num(0){}
    int add(Card card); // it will sort the card when adding
    int length();
    CardsRank rank();
    int       number();
    void computeRank();

private:
    std::vector<Card> _cards;
    CardsRank _rank;
    int       _num; // It represent the biggest num of the Rank.
};

class Game
{
public:
    void run(std::string filename);   
};

#endif /* defined(__Pokerhands__Card__) */
