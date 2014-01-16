//  ltoj_word_ladder.cpp
//
//  interview1
//  http://oj.leetcode.com/problems/word-ladder/
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#include <CppUTest/TestHarness.h>
#include <cassert>
using namespace std;

namespace LTOJ_WORDLADDER_BFS {
    class Solution {
    public:
        typedef struct NodeTag {
            string  val;
            int     depth;
        }Node;
        
        int ladderLength(string start, string end, unordered_set<string> &dict){
            
            vector<string> v;
            for (const auto& s: dict)
                v.push_back(s);
            
            stringlen = static_cast<int>(start.length());
            
            queue<Node> q;
            q.push(Node{start, 0});
            
            while (!q.empty()) {
                Node top = q.front();
                q.pop();
                
                if (connectedString(top.val, end) && top.depth != 0)
                    return top.depth + 2;
                
                for (auto& s: v) {
                    if (connectedString(top.val, s)) {
                        q.push(Node{s, top.depth+1});
                        s = "";
                    }
                }
            }
            
            return 0;
        }
        
        bool connectedString(const string& a, const string& b){
            if (a.empty() || b.empty())
                return false;
            
            int diff = 0;
            for (size_t i=0; i<stringlen; ++i){
                if (a[i] != b[i]) {
                    ++diff;
                    if (diff>1)
                        return false;
                }
            }
            
            return diff==1;
        }
    private:
        int stringlen=0;
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

