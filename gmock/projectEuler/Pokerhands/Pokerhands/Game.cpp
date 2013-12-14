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

#include <iostream>
#include <fstream>
#include <stdexcept>

void
Game::run(std::string filename)
{
    std::ifstream file(filename.c_str());
    if(file)
    {
        CardConverter converter;
        
        int nCount = 0;
        int total = 0;
        
        for(std::string line; std::getline(file, line);)
        {
            ++total;
            
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
                
                if (hand1 > hand2)
                    ++nCount;
            }
            else{
                throw std::runtime_error("The size is not correct");
            }
        }
        
        std::cout << "Total=" << total << "  winning=" << nCount <<std::endl;
    }
    else{
        std::cout << "Fail to open the file:" << filename << std::endl;
    }
}