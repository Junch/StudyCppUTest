//  ltoj_word_ladder.cpp
//
//  interview1
//  http://oj.leetcode.com/problems/word-ladder-ii/
//  http://discuss.leetcode.com/questions/1051/word-ladder-ii
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
        
        void getLadders(string s, vector<string>& path){
            const auto& ps = parents[s];
            if (ps.size() == 1 && ps[0]==s){
                ret.push_back(vector<string>(path.rbegin(), path.rend()));
                return;
            }
            
            for (auto parent: ps) {
                path.push_back(parent);
                getLadders(parent, path);
                path.pop_back();
            }
        }
        
        vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict){
            
            ret.clear();
            parents.clear();
            
            queue<Node> q;

            unordered_map<string, int> L;
            parents[start].push_back(start);
            size_t strlen = start.length();
            int shortest = 0;
            
            dict.insert(end);
            q.push({start, 1});
            
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
                            vector<string> path;
                            path.push_back(end);
                            path.push_back(s);
                            getLadders(s, path);
                        }

                        // 难度就在下面这几句，如何来拓展节点？
                        // 这个tmp节点第一次出现的时候，一定是最小高度，
                        // 在同一高度其还可能出现，这个tmp就可能有多个父亲节点
                        // 其他高度出现的tmp就不必要处理了
                        
                        else if(parents.find(tmp) == parents.end()){
                            parents[tmp].push_back(s);
                            L[tmp] = top.second + 1;
                            q.push({tmp, top.second + 1});
                        }
                        else if(L[tmp] == top.second + 1){
                            parents[tmp].push_back(s);
                        }
                    }
                }
            }

            return ret;
        }
        
    private:
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> parents;
    };
    
    TEST_GROUP(LTOJ_WORDLADDER){
        Solution sln;
    };
    

    TEST(LTOJ_WORDLADDER, FullSize){
        unordered_set<string> dict {"hot","dot","dog"};
        LONGS_EQUAL(5, sln.findLadders("hit", "cog", dict)[0].size());
    }


    TEST(LTOJ_WORDLADDER, complex){
        unordered_set<string> dict {"ted","tex","red","tax","tad","den","rex","pee"};
        auto ret = sln.findLadders("red", "tax", dict);
        LONGS_EQUAL(3, ret.size());
        LONGS_EQUAL(4, ret[0].size());
    }
}//namespace

