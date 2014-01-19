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
        typedef struct NodeTag{
            string val;
            int    depth;
            NodeTag* parent;
        }Node;
        
    public:
        vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict){
            vector<vector<string>> vv;
            
            dict.insert(start);
            dict.insert(end);
            
            Node* pNode = new Node{start, 0, nullptr};
            nodes.push_back(pNode);
            q.push(pNode);
            
            setupMap(dict);
            
            int preDepth = 0;
            int shortestDepth = -1; //magic number
            
            while (!q.empty()) {
                auto top = q.front();
                q.pop();
                
                if (shortestDepth != -1  && top->depth > shortestDepth)
                    break;
                
                // Begin a new depth
                if (top->depth == preDepth + 1) {
                    cleanMap();
                    ++preDepth;
                }else{ // The same depth
                    oldNodes.push_back(top);
                }
                
                // Get the end node
                if (top->val == end) {
                    shortestDepth = top->depth;
                    
                    vector<string> v;
                    pNode = top;
                    while (pNode) {
                        v.push_back(pNode->val);
                        pNode = pNode->parent;
                    }
                    
                    std::reverse(v.begin(), v.end());
                    vv.push_back(v);
                }
                
                const auto& nexts = graph[top->val];
                for (const auto& s: nexts) {
                    pNode = new Node{s, top->depth+1, top};
                    nodes.push_back(pNode);
                    q.push(pNode);
                }
                
            }
            
            for (auto e: nodes)
                delete e;
            
            return vv;
        }
        
        void setupMap(unordered_set<string>& dict) {
            size_t len= (*dict.begin()).length();
            
            for (auto it=dict.begin(); it != dict.end();) {
                string key = *it;
                string s = key;
                
                for (size_t i=0; i<len; i++) {
                    char c = s[i];
                    
                    for (char j='a'; j<='z'; ++j) {
                        if (c == j)
                            continue;

                        s[i] = j;
                        const auto iter = dict.find(s);
                        if (iter != dict.end()) {
                            graph[key].insert(s);
                            graph[s].insert(key);
                        }
                    }
                    
                    s[i] = c;
                }
                
                dict.erase(it++);
            }
        }
        
        void cleanMap() {
            for (auto pOldNode: oldNodes) {
                string& s = pOldNode->val;
                
                auto& nextNodes = graph[s];
                for (auto& node: nextNodes)
                    graph[node].erase(s);
            }
        }
        
    public:
        queue<Node*> q;
        vector<Node*> oldNodes;
        vector<Node*> nodes;
        unordered_map<string, unordered_set<string>> graph;
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
    
    TEST(LTOJ_WORDLADDER, complex){
        unordered_set<string> dict {"ted","tex","red","tax","tad","den","rex","pee"};
        auto ret = sln.findLadders("red", "tax", dict);
        LONGS_EQUAL(3, ret.size());
        LONGS_EQUAL(4, ret[0].size());
    }
    
//    TEST(LTOJ_WORDLADDER, setupMap){
//        unordered_set<string> dict {"hit","hot","dot","dog"};
//        sln.setupMap(dict);
//        for (auto& v: sln.graph) {
//            printf("%s: ", v.first.c_str());
//            
//            for (auto& s: v.second)
//                printf("%s -> ", s.c_str());
//            
//            printf("\n");
//        }
//    }
}//namespace

