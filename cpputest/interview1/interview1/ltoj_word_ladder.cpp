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
#include <cassert>
using namespace std;

namespace LTOJ_WORDLADDER {
    
    class Solution{
    public:
        
        int ladderLength(string start, string end, unordered_set<string> &dict){
            dictlen = static_cast<int>(dict.size());
            
            unordered_set<string> used;
            int len = dfs(start, end, dict, used);
            if (len > dictlen)
                return 0;
            
            return len + 2;
        }
        
        int dfs(string start, string end, const unordered_set<string> &dict, unordered_set<string>& used){
            int shortest = dictlen + 1;
            
            for (const auto& e: dict) {
                if (used.find(e) != used.end())
                    continue;
                
                if (connectedString(start, e)) {
                    if (connectedString(end, e))
                        return 1;
                    
                    used.insert(e);
                    int len = dfs(e, end, dict, used);
                    used.erase(e);
                    
                    if (len < shortest)
                        shortest = len;
                }
            }
            
            return shortest+1;
        }

        bool connectedString(string a, string b){
            size_t len = a.length();
            int diff = 0;
            for (size_t i=0; i<len; ++i){
                if (a[i] != b[i]) {
                    ++diff;
                    if (diff>1)
                        return false;
                }
            }
            
            return diff==1;
        }
        
    private:
        int dictlen=0;
    };
    
    TEST_GROUP(LTOJ_WORDLADDER){
        Solution sln;
    };
    
    TEST(LTOJ_WORDLADDER, AnSimpleOne){
        unordered_set<string> dict {"hot","log"};
        LONGS_EQUAL(3, sln.ladderLength("hit", "dot", dict));
    }
    
    TEST(LTOJ_WORDLADDER, NotFound){
        unordered_set<string> dict {"hat","log"};
        LONGS_EQUAL(0, sln.ladderLength("hit", "dot", dict));
    }
    
    TEST(LTOJ_WORDLADDER, AnComplexOne){
        unordered_set<string> dict {"hot","dot","dog", "lot", "log"};
        LONGS_EQUAL(5, sln.ladderLength("hit", "cog", dict));
    }
    
    TEST(LTOJ_WORDLADDER, FullSize){
        unordered_set<string> dict {"hot","dot","dog"};
        LONGS_EQUAL(5, sln.ladderLength("hit", "cog", dict));
    }
    
    TEST(LTOJ_WORDLADDER, Duplicated){
        unordered_set<string> dict {"a","b","c"};
        LONGS_EQUAL(3, sln.ladderLength("a", "c", dict));
    }
    
}//namespace

