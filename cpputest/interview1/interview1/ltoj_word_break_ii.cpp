//
//  ltoj_word_break_ii.cpp
//  interview1
//
//  Created by Jun on 14-1-27.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_WORD_BREAK_II {
    class Solution {
    public:
        vector<string> wordBreak(string s, unordered_set<string> &dict) {
            vector<string> answer;
                        
            return answer;
        }
    };
    
    TEST_GROUP(LTOJ_WORD_BREAK_II){
        Solution sln;
    };
    
    TEST(LTOJ_WORD_BREAK_II, OneWord){
        unordered_set<string> dict{"a", "b", "ab"};
        auto &&v = sln.wordBreak("ab", dict);
        LONGS_EQUAL(2, v.size());
        STRCMP_EQUAL("a b", v[0].c_str());
        STRCMP_EQUAL("ab", v[1].c_str());
    }
}
