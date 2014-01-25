//
//  ltoj_longest_substring_without_repeating_characters.cpp
//  interview1
//
//  Created by Jun on 14-1-25.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS {
    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            size_t len = s.size();
            if (len == 0)
                return 0;

            int longtest = 1;
            int prevCharLongest = 1;
            
            for (int i=1; i<len; ++i) {
                int j = 1;
                for (; j<=prevCharLongest && s[i] != s[i-j]; ++j)
                    ;
                prevCharLongest = j;
                
                if (prevCharLongest > longtest)
                    longtest = prevCharLongest;
            }
            
            return longtest;
        }
    };
    
    TEST_GROUP(LTOJ_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS){
        Solution sln;
    };
    
    TEST(LTOJ_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS, twoSameCharacter){
        LONGS_EQUAL(1, sln.lengthOfLongestSubstring("aa"));
    }
    
    TEST(LTOJ_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS, twoDifferentCharacther){
        LONGS_EQUAL(2, sln.lengthOfLongestSubstring("ab"));
    }
    
    TEST(LTOJ_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS, abcabcbb){
        LONGS_EQUAL(3, sln.lengthOfLongestSubstring("abcabcbb"));
    }
    
    TEST(LTOJ_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS, emptyString){
        LONGS_EQUAL(0, sln.lengthOfLongestSubstring(""));
    }
    
    TEST(LTOJ_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS, OneCharacter){
        LONGS_EQUAL(1, sln.lengthOfLongestSubstring("a"));
    }
}
