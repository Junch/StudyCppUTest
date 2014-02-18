//
//  ltoj_minimum_path_sum.cpp
//  interview1
//
//  Created by Jun on 14-2-18.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_MINIMUM_PATH_SUM {
    class Solution {
    public:
        int minPathSum(vector<vector<int> > &grid) {
            vector<int> v(grid[0]);
            size_t cols = v.size();
            
            for (size_t i=1; i<cols; ++i)
                v[i] += v[i-1];

            for (size_t j=1, rows=grid.size(); j<rows; ++j) {
                v[0] += grid[j][0];
                for (size_t i=1; i<cols; ++i)
                    v[i] = min(v[i], v[i-1]) + grid[j][i];
            }
            
            return v[cols - 1];
        }
    };
    
    TEST_GROUP(LTOJ_MINIMUM_PATH_SUM){
        Solution sln;
    };
    
    TEST(LTOJ_MINIMUM_PATH_SUM, 2x2){
        vector<vector<int>> grid;
        grid.push_back(vector<int>{1,2});
        grid.push_back(vector<int>{0,1});
        int val = sln.minPathSum(grid);
        LONGS_EQUAL(2, val);
    }
    
    TEST(LTOJ_MINIMUM_PATH_SUM, 2x3){
        vector<vector<int>> grid;
        grid.push_back(vector<int>{1,2,-2});
        grid.push_back(vector<int>{0,1,5});
        int val = sln.minPathSum(grid);
        LONGS_EQUAL(6, val);
    }
}
