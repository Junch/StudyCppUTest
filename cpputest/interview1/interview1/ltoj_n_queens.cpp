//
//  ltoj_n_queens.cpp
//  interview1
//  http://oj.leetcode.com/problems/n-queens/
//
//  Created by Jun on 14-1-28.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_N_QUEENS {
    class Solution {
    public:
        vector<vector<string> > solveNQueens(int n) {
            
            vector<pair<int, int>> pos;
            dfs(pos, n, 0);

//            printf("\n");
//            for (auto& v: vv) {
//                for (auto &s: v) {
//                    printf("%s\n", s.c_str());
//                }
//            }
            
            return vv;
        }
        
        bool collide(const pair<int, int>& p, int row, int col) const{
            if (p.first == row || p.second == col)
                return true;

            if (p.first + p.second == row + col)
                return true;
            
            if (p.first + col == row + p.second)
                return true;
            
            return false;
        }
        
        void dfs(vector<pair<int, int>>& pos, int n, int row) {
            if (row == n){
                vector<string> v(n);
                
                for (auto& s: v)
                    s.resize(n, '.');

                for (const auto& p: pos)
                    v[p.first][p.second] = 'Q';
                
                vv.push_back(v);
                return;
            }
            
            for (int i=0; i<n; ++i) {
                bool bCollide = false;
                
                for (auto & p: pos) {
                    if (collide(p, row, i)) {
                        bCollide = true;
                        break;
                    }
                }
                
                if (!bCollide) {
                    pos.push_back(make_pair(row, i));
                    dfs(pos, n, row+1);
                    pos.pop_back();
                }
            }
        }
        
    private:
         vector<vector<string>> vv;
    };
    
    TEST_GROUP(LTOJ_N_QUEENS){
        Solution sln;
    };
    
    TEST(LTOJ_N_QUEENS, 4x4){
        auto r = sln.solveNQueens(8);
        LONGS_EQUAL(2, r.size());
    }
}