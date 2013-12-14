//
//  main.cpp
//  Soundex
//
//  Created by Jun on 13-12-14.
//  Copyright (c) 2013年 Jun. All rights reserved.
//

#include <gmock/gmock.h>
using ::testing::Eq;

class Soundex
{
public:
    std::string encode(const std::string& word)const {
        return word;
    }
};


TEST(SoundexEncoding, RetainSoleLetterOfOneLetterWord)
{
    Soundex soundex;
    auto encoded=soundex.encode("A");
    ASSERT_THAT(encoded, Eq("A"));
}



