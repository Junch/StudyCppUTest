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
    
    class Solution2 {
    public:
        
        bool exist(vector<vector<char> > &board, string word) {
            size_t width = board[0].size();
            size_t height = board.size();
            
            for (int j=0; j<height; ++j) {
                for (int i=0; i<width; ++i) {
                    char c = board[j][i];
                    if (c==word[0]) {
                        board[j][i] = '#';
                        bool ret = dfs(board, word, 0, i, j);
                        if (ret)
                            return true;
                        board[j][i] = c;
                    }
                }
            }
            
            return false;
        }
        
        
        bool dfs(vector<vector<char> > &board,  const string& word, int index, int x, int y)
        {
            static int dirs[][2]={{-1,0}, {1,0}, {0, -1}, {0, 1}};
            size_t width = board[0].size();
            size_t height = board.size();
            
            if (index+1 == word.length())
                return true;
            
            for (int i=0; i<4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                
                if (nx < 0 || nx >= width ||
                    ny < 0 || ny >= height)
                    continue;
                
                if (board[ny][nx] == word[index + 1]) {
                    board[ny][nx] = '#';
                    if (dfs(board, word, index+1, nx, ny))
                        return true;
                    board[ny][nx] = word[index + 1];
                }
            }
            
            return false;
        }
    };
    
    class Solution3 {
    public:
        
        bool exist(vector<vector<char> > &board, string word) {
            size_t width = board[0].size();
            size_t height = board.size();
            
            for (int j=0; j<height; ++j) {
                for (int i=0; i<width; ++i) {
                    char c = board[j][i];
                    if (c==word[0]) {
                        bool ret = process(board, word, i, j);
                        if (ret)
                            return true;
                    }
                }
            }
            
            return false;
        }
        
        
        bool process(vector<vector<char> > &board,  const string& word, int x, int y)
        {
            static int dirs[][2]={{-1,0}, {1,0}, {0, -1}, {0, 1}};
            size_t width = board[0].size();
            size_t height = board.size();

            struct Node{
                int x;
                int y;
                int dir;
            };
            
            stack<Node> s;
            board[y][x] = '#';
            s.push(Node{x, y, 0});
            
            while (!s.empty()) {
                Node& t = s.top();
                
                size_t index = s.size();
                if (index == word.length())
                    return true;
                
                if (t.dir == 4) {
                    board[t.y][t.x] = word[index-1];
                    s.pop();
                    continue;
                }
                
                int nx = t.x + dirs[t.dir][0];
                int ny = t.y + dirs[t.dir][1];
                ++t.dir;
                
                if (nx < 0 || nx >= width ||
                    ny < 0 || ny >= height) {
                    continue;
                }
                
                if (board[ny][nx] == word[index]) {
                    board[ny][nx] = '#';
                    s.push(Node{nx, ny, 0});
                }
            }
            
            return false;
        }
    };

    
    TEST_GROUP(LTOJ_WORD_SEARCH){
        Solution3 sln;
    };
    
    TEST(LTOJ_WORD_SEARCH, case1){
        vector<vector<char>> vv;
        vv.push_back(vector<char>{'A','B'});
        vv.push_back(vector<char>{'C','D'});
        CHECK_TRUE(sln.exist(vv, "DCBA"));
    }
    
    TEST(LTOJ_WORD_SEARCH, case2){
        vector<vector<char>> vv;
        vv.push_back(vector<char>{'A','B'});
        CHECK_TRUE(sln.exist(vv, "AB"));
    }
    
    TEST(LTOJ_WORD_SEARCH, case3){
        vector<vector<char>> vv;
        vv.push_back(vector<char>{'A'});
        vv.push_back(vector<char>{'B'});
        CHECK_TRUE(sln.exist(vv, "AB"));
    }
}
