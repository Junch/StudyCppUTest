//  ltoj_word_ladder.cpp
//
//  interview1
//  http://oj.leetcode.com/problems/word-ladder-ii/
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <queue>
#include <CppUTest/TestHarness.h>
#include <cassert>
#include <memory>
using namespace std;

namespace LTOJ_WORDLADDER_II {
    class Solution {
        typedef struct NodeTag{
            NodeTag(string val_, int depth_, const shared_ptr<NodeTag>& parent_):
            val(val_), depth(depth_), parent(parent_){}
            
            string val;
            int    depth;
            shared_ptr<NodeTag> parent;
        }Node;
        
    public:
        vector<vector<string>> ladderLength(string start, string end, unordered_set<string> &dict){
            vector<vector<string>> vv;
            
            dict.insert(end);
            q.push(make_shared<Node>(start, 0, nullptr));
            
            int depth = -1;
            
            while (!q.empty()) {
                shared_ptr<Node> top = q.front();
                q.pop();
                
                if (depth != -1 && top->depth > depth)
                    break;
                
                if (addConnectedStringToQueue(top, end, dict)){
                    depth = top->depth;
                    
                    vector<string> v{end};
                    shared_ptr<Node> pNode = top;
                    while (pNode) {
                        v.push_back(pNode->val);
                        pNode = pNode->parent;
                    }
                    
                    std::reverse(v.begin(), v.end());
                    vv.push_back(v);
                 }
            }
            
            return vv;
        }
        
        bool addConnectedStringToQueue(shared_ptr<Node> top, string end, unordered_set<string> &dict){
            string s = top->val;
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
                        
                        q.push(make_shared<Node>(s, top->depth + 1, top));
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
        queue<shared_ptr<Node>> q;
    };
    
    TEST_GROUP(LTOJ_WORDLADDER){
        Solution sln;
    };
    
    TEST(LTOJ_WORDLADDER, AnSimpleOne){
        unordered_set<string> dict {"hot","log"};
        auto ret = sln.ladderLength("hit", "dot", dict);
        LONGS_EQUAL(3, ret[0].size());
    }
    
    TEST(LTOJ_WORDLADDER, NotFound){
        unordered_set<string> dict {"hat","log"};
        auto ret = sln.ladderLength("hit", "dot", dict);
        LONGS_EQUAL(0, ret.size());
    }
    
    TEST(LTOJ_WORDLADDER, AnComplexOne){
        unordered_set<string> dict {"hot","dot","dog", "lot", "log"};
        auto ret =sln.ladderLength("hit", "cog", dict);
        LONGS_EQUAL(5, ret[0].size());
    }

    TEST(LTOJ_WORDLADDER, FullSize){
        unordered_set<string> dict {"hot","dot","dog"};
        auto ret = sln.ladderLength("hit", "cog", dict);
        LONGS_EQUAL(5, ret[0].size());
    }
    
    TEST(LTOJ_WORDLADDER, Duplicated){
        unordered_set<string> dict {"a","b","c"};
        auto ret = sln.ladderLength("a", "c", dict);
        LONGS_EQUAL(2, ret[0].size());
    }
}//namespace

