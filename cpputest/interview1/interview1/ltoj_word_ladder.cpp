//  ltoj_word_ladder.cpp
//
//  interview1
//  http://oj.leetcode.com/problems/word-ladder/
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_WORDLADDER {
    
    class Solution{
    public:
        int ladderLength(string start, string end, unordered_set<string> &dict){
            // DFS
            
            
            
            return 0;
        }
    };
    
    int main()
    {
        
        return 0;
    }
    
    TEST_GROUP(LTOJ_WORDLADDER){
        Solution sln;
    };
    
    TEST(LTOJ_WORDLADDER, case1){
        unordered_set<string> dict {"hit","hot","dot"};
        LONGS_EQUAL(3, sln.ladderLength("hit", "dot", dict));
    }
}//namespace

