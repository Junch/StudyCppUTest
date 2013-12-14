//
//  main.cpp
//  Soundex
//
//  Created by Jun on 13-12-14.
//  Copyright (c) 2013年 Jun. All rights reserved.
//

#include <gmock/gmock.h>

class Soundex
{
public:
    std::string encode(const std::string& word)const {
        return "A";
    }
};


TEST(SoundexEncoding, RetainSoleLetterOfOneLetterWord)
{
    Soundex soundex;
    auto encoded=soundex.encode("A");
    ASSERT_THAT(encoded, testing::Eq("A"));
}



