//
//  main.cpp
//  Pokerhands
//
//  Created by wolf76 on 3/5/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//
//  http://projecteuler.net/problem=54
//  http://www.pagat.com/poker/rules/ranking.html
//  http://en.wikipedia.org/wiki/List_of_poker_hands
//

#include <gtest/gtest.h>
#include "Game.h"

#define UNITTEST 0

#if UNITTEST

int main( int argc , const char * argv [])
{
    testing::InitGoogleTest (&argc, (char **)argv);
    return RUN_ALL_TESTS();
}

#else

int main( int argc , const char * argv [])
{
    Game game;
    game.run("poker.txt");
}

#endif
