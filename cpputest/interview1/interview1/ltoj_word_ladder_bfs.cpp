//  ltoj_word_ladder.cpp
//
//  interview1
//  http://oj.leetcode.com/problems/word-ladder/
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <queue>
#include <CppUTest/TestHarness.h>
#include <cassert>
using namespace std;

namespace LTOJ_WORDLADDER_BFS {
    class Solution {
        typedef pair<string, int> Node;
    public:
        int ladderLength(string start, string end, unordered_set<string> &dict){
            
            dict.insert(end);
            q.push(Node{start, 0});
            
            while (!q.empty()) {
                Node top = q.front();
                q.pop();
                
                if (addConnectedStringToQueue(top, end, dict))
                    return top.second + 2;
            }
            
            return 0;
        }

        bool addConnectedStringToQueue(Node& top, string end, unordered_set<string> &dict){
            string s = top.first;
            for (size_t i=0, len=s.length(); i<len; i++) {
                char c = s[i];
                for (char j='a'; j<='z'; ++j) {
                    if (c == j)
                        continue;
                    
                    s[i] = j;
                    const auto iter = dict.find(s);
                    if (iter != dict.end() &&
                        visited.find(s) == visited.end()) {
                        
                        if (s == end)
                            return true;
                        
                        q.push(Node{s, top.second + 1});
                        visited.insert(s);
                        dict.erase(iter);
                    }
                }
                
                s[i] = c;
            }
         
            return false;
        }
        
    private:
        unordered_set<string> visited;
        queue<Node> q;
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
        LONGS_EQUAL(2, sln.ladderLength("a", "c", dict));
    }
}//namespace

