//
//  Game.cpp
//  Pokerhands
//
//  Created by wolf76 on 3/7/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//

#include "Card.h"
#include "Hand.h"
#include "Game.h"

#include <fstream>
#include <stdexcept>

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