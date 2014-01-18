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

namespace LTOJ_WORDLADDER_II_2 {
    class Solution {
        typedef struct NodeTag{
            string val;
            int    depth;
            NodeTag* parent;
        }Node;
        
    public:
        vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict){
            vector<vector<string>> vv;
            
            dict.insert(end);
            Node* pNode = new Node{start, 0, nullptr};
            nodes.push_back(pNode);
            q.push(pNode);
            
            int depth = -1;
            
            while (!q.empty()) {
                Node* top = q.front();
                q.pop();
                
                if (depth != -1 && top->depth > depth)
                    break;
                
                if (addConnectedStringToQueue(top, end, dict)){
                    depth = top->depth;
                    
                    vector<string> v{end};
                    pNode = top;
                    while (pNode) {
                        v.push_back(pNode->val);
                        pNode = pNode->parent;
                    }
                    
                    std::reverse(v.begin(), v.end());
                    vv.push_back(v);
                    
//                    for (auto e: v) {
//                        std::cout << e << "\n";
//                    }
                    
                }
            }
            
            for (auto e: nodes)
                delete e;
            
            return vv;
        }
        
        bool addConnectedStringToQueue(Node* top, string end, unordered_set<string> &dict){
            string s = top->val;
            
            for (size_t i=0, len=s.length(); i<len; i++) {
                char c = s[i];
                for (char j='a'; j<='z'; ++j) {
                    if (c == j)
                        continue;
                    
                    s[i] = j;
                    const auto iter = dict.find(s);
                    if (iter != dict.end()) {
                            
                        if (findStringInParent(s, top))
                            continue;
                        
                        if (s == end)
                            return true;
                        
                        Node* pNode = new Node{s, top->depth + 1, top};
                        nodes.push_back(pNode);
                        q.push(pNode);
                      }
                }
                
                s[i] = c;
            }
            
            return false;
        }
        
        bool findStringInParent(string s, Node* top)
        {
            Node* pNode = top;
            for (; pNode != nullptr && pNode->val != s; pNode = pNode->parent) {
            }

            return pNode != nullptr;
        }
        
    private:
        queue<Node*> q;
        vector<Node*> nodes;
    };
    
    TEST_GROUP(LTOJ_WORDLADDER){
        Solution sln;
    };
    
    TEST(LTOJ_WORDLADDER, AnSimpleOne){
        unordered_set<string> dict {"hot","log"};
        auto ret = sln.findLadders("hit", "dot", dict);
        LONGS_EQUAL(3, ret[0].size());
    }
    
    TEST(LTOJ_WORDLADDER, NotFound){
        unordered_set<string> dict {"hat","log"};
        auto ret = sln.findLadders("hit", "dot", dict);
        LONGS_EQUAL(0, ret.size());
    }
    
    TEST(LTOJ_WORDLADDER, AnComplexOne){
        unordered_set<string> dict {"hot","dot","dog", "lot", "log"};
        auto ret =sln.findLadders("hit", "cog", dict);
        LONGS_EQUAL(5, ret[0].size());
    }
    
    TEST(LTOJ_WORDLADDER, FullSize){
        unordered_set<string> dict {"hot","dot","dog"};
        auto ret = sln.findLadders("hit", "cog", dict);
        LONGS_EQUAL(5, ret[0].size());
    }
    
    TEST(LTOJ_WORDLADDER, complex){
        unordered_set<string> dict {"ted","tex","red","tax","tad","den","rex","pee"};
        auto ret = sln.findLadders("red", "tax", dict);
        LONGS_EQUAL(3, ret.size());
        LONGS_EQUAL(4, ret[0].size());
    }
}//namespace

