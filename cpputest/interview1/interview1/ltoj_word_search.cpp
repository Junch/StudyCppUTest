//
//  ltoj_word_search.cpp
//  interview1
//
//  Created by Jun on 2014-02-23.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_WORD_SEARCH {
    
    class Solution {
    public:
        struct Node{
            vector<pair<int, int>> path;
        };
        
        bool exist(vector<vector<char> > &board, string word) {
            size_t width = board[0].size();
            size_t height = board.size();
            
            stack<Node> s;
            
            for (int j=0; j<height; ++j) {
                for (int i=0; i<width; ++i) {
                    char c = board[j][i];
                    if (c==word[0]) {
                        vector<pair<int, int>> path;
                        path.push_back(make_pair(i, j));
                        s.push(Node{path});
                    }
                }
            }
            
            int dirs[][2]={{-1,0}, {1,0}, {0, -1}, {0, 1}};
            
            while (!s.empty()) {
                Node t = s.top();
                s.pop();
    
                vector<pair<int, int>>& path = t.path;
                size_t len = path.size();
                
                if (len == word.length())
                    return true;
                
                pair<int, int>& elem = path[len-1];
                
                for (int i=0; i<4; ++i) {
                    int x = elem.first + dirs[i][0];
                    int y = elem.second + dirs[i][1];
                    
                    if (x < 0 || x >= width ||
                        y < 0 || y >= height)
                         continue;
                    
                    if (board[y][x] == word[len]) {
                        pair<int, int> pos{x, y};
                        auto iter = std::find(path.begin(), path.end(), pos);
                        if (iter != path.end())
                            continue;
                        
                        vector<pair<int, int>> newpath = path;
                        newpath.push_back(pos);
                        s.push(Node{newpath});
                    }
                }
             }
            
            return false;
        }
    };
    
    TEST_GROUP(LTOJ_WORD_SEARCH){
        Solution sln;
    };
    
    TEST(LTOJ_WORD_SEARCH, case1){
        vector<vector<char>> vv;
        vv.push_back(vector<char>{'A','B'});
        vv.push_back(vector<char>{'C','C'});
        CHECK_TRUE(sln.exist(vv, "CCA"));
    }
}
