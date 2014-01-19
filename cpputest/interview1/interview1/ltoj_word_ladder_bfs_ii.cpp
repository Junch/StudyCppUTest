//  ltoj_word_ladder.cpp
//
//  interview1
//  http://oj.leetcode.com/problems/word-ladder-ii/
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <CppUTest/TestHarness.h>
#include <cassert>
#include <memory>
using namespace std;

namespace LTOJ_WORDLADDER_II_2 {
    class Solution {
        typedef pair<string, int> Node;
    public:
        int findLadders(string start, string end, unordered_set<string> &dict){
            vector<vector<string>> ret;
            
            queue<Node> q;
            unordered_map<string, unordered_set<string>> parents;
            size_t strlen = start.length();
            int shortest = 0;
            
            dict.insert(end);
            q.push(Node{start, 1});
            
            while (!q.empty()) {
                Node top = q.front();
                q.pop();
                
                if (shortest > 0 && top.second >= shortest) {
                    break;
                }
                
                const string& s = top.first;
                for (size_t i=0; i<strlen; ++i) {
                    char c = s[i];
                    for (char j='a'; j<='z'; ++j) {
                        if (c == j)
                            continue;
                        
                        string tmp = s;
                        tmp[i] = j;
                        
                        // tmp is not in the dict
                        if (dict.find(tmp) == dict.end())
                            continue;
                        
                        // tmp is just the end node
                        if (tmp == end) {
                            shortest = top.second + 1;
                           // Calculate the path
                        }
                        
                        parents[tmp].insert(s);
                        q.push(Node{tmp, top.second + 1});
                    }
                }
            }
            
            return shortest;
        }
    };
    
    TEST_GROUP(LTOJ_WORDLADDER){
        Solution sln;
    };
    
    TEST(LTOJ_WORDLADDER, AnSimpleOne){
        unordered_set<string> dict {"hot","log"};
        auto ret = sln.findLadders("hit", "dot", dict);
        LONGS_EQUAL(3, ret);
    }

    TEST(LTOJ_WORDLADDER, NotFound){
        unordered_set<string> dict {"hat","log"};
        LONGS_EQUAL(0, sln.findLadders("hit", "dot", dict));
    }
    
    TEST(LTOJ_WORDLADDER, AnComplexOne){
        unordered_set<string> dict {"hot","dot","dog", "lot", "log"};
        LONGS_EQUAL(5, sln.findLadders("hit", "cog", dict));
    }
    
    TEST(LTOJ_WORDLADDER, FullSize){
        unordered_set<string> dict {"hot","dot","dog"};
        LONGS_EQUAL(5, sln.findLadders("hit", "cog", dict));
    }
    
    TEST(LTOJ_WORDLADDER, Duplicated){
        unordered_set<string> dict {"a","b","c"};
        LONGS_EQUAL(2, sln.findLadders("a", "c", dict));
    }

//    TEST(LTOJ_WORDLADDER, complex){
//        unordered_set<string> dict {"ted","tex","red","tax","tad","den","rex","pee"};
//        auto ret = sln.findLadders("red", "tax", dict);
//        LONGS_EQUAL(3, ret.size());
//        LONGS_EQUAL(4, ret[0].size());
//    }
}//namespace

