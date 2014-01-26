//
//  ltoj_word_break.cpp
//  interview1
//  http://oj.leetcode.com/problems/word-break/
//
//  Created by Jun on 14-1-26.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_WORD_BREAK {
    class Solution {
    public:
        bool wordBreak(string s, unordered_set<string> &dict) {
            if (s == "")
                return true;
            
            if (dict.empty())
                return false;
            
            for (size_t i=1, len=s.length(); i<=len; ++i) {
                // string head = string(s.begin(), s.begin()+i);
                string head = s.substr(0, i);
                if (dict.find(head) == dict.end())
                    continue;
                
                dict.erase(head);
                
                // string rear = string(s.begin()+i, s.end());
                string rear = s.substr(i, len-i);
                if (wordBreak(rear, dict))
                    return true;
                
                dict.insert(head);
            }
            
            return false;
        }
        
        bool wordBreak2(string s, unordered_set<string> &dict) {
            size_t len = s.length();
            if (len == 0)
                return false;
            
            vector<bool> v(len);
            
            for (int i=0; i<len; ++i) {
                v[i] = false;
                
                for (int j=i; j>= 0; --j) {
                    if (j != 0 && v[j-1] == false)
                        continue;
                    
                    string tmp = s.substr(j, i-j+1);
                    if (dict.find(tmp) != dict.end()) {
                        v[i] = true;
                        break;
                    }
                }
            }

            return v[len-1];
        }
    };
    
    TEST_GROUP(LTOJ_WORD_BREAK){
        Solution sln;
    };
    
    TEST(LTOJ_WORD_BREAK, OneWord){
        unordered_set<string> dict{"ab"};
        CHECK_TRUE(sln.wordBreak("ab", dict));
    }
    
    TEST(LTOJ_WORD_BREAK, TwoWords){
        unordered_set<string> dict{"a", "b"};
        CHECK_TRUE(sln.wordBreak("ab", dict));
    }
    
    TEST(LTOJ_WORD_BREAK, ThreeWordsTrue){
        unordered_set<string> dict{"a", "b", "c", "d"};
        CHECK_TRUE(sln.wordBreak("abd", dict));
    }
    
    TEST(LTOJ_WORD_BREAK, ThreeWordsFalse){
        unordered_set<string> dict{"a", "b", "c", "d"};
        CHECK_FALSE(sln.wordBreak("abe", dict));
    }
    
    TEST(LTOJ_WORD_BREAK, MoreWords){
        unordered_set<string> dict{"a"};
        CHECK_FALSE(sln.wordBreak("aa", dict));
    }
    
    TEST_GROUP(LTOJ_WORD_BREAK2){
        Solution sln;
    };
    
    TEST(LTOJ_WORD_BREAK2, OneWord){
        unordered_set<string> dict{"ab"};
        CHECK_TRUE(sln.wordBreak2("ab", dict));
    }
    
    TEST(LTOJ_WORD_BREAK2, TwoWords){
        unordered_set<string> dict{"a", "b"};
        CHECK_TRUE(sln.wordBreak2("ab", dict));
    }
    
    TEST(LTOJ_WORD_BREAK2, ThreeWordsFalse){
        unordered_set<string> dict{"a", "b", "c", "d"};
        CHECK_FALSE(sln.wordBreak2("abe", dict));
    }
    
    TEST(LTOJ_WORD_BREAK2, ThreeWordsTrue){
        unordered_set<string> dict{"a", "bd"};
        CHECK_TRUE(sln.wordBreak2("abd", dict));
    }
    
    IGNORE_TEST(LTOJ_WORD_BREAK2, MoreWords){
        unordered_set<string> dict{"a"};
        CHECK_FALSE(sln.wordBreak2("aa", dict));
    }
}