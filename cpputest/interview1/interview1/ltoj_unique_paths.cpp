//
//  ltoj_unique_paths.cpp
//  interview1
//  http://oj.leetcode.com/problems/unique-paths/
//
//  Created by Jun on 14-1-26.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_UNIQUE_PATHS {
    class Solution {
    public:
        int uniquePaths(int m, int n) {
            // m rows, n columns
            vector<int> v(m);
            
            for (int i=0; i<m; ++i)
                v[i] = 1;
            
            for (int j=1; j<n; ++j) {
                for (int i=1; i<m; ++i) {
                    v[i] += v[i-1];
                }
            }
            
            return v[m-1];
        }
    };
    
    TEST_GROUP(LTOJ_UNIQUE_PATHS){
        Solution sln;
    };
    
    TEST(LTOJ_UNIQUE_PATHS, 2x2){
        LONGS_EQUAL(2, sln.uniquePaths(2,2));
    }
    
    TEST(LTOJ_UNIQUE_PATHS, 3x3){
        LONGS_EQUAL(6, sln.uniquePaths(3,3));
    }
    
    TEST(LTOJ_UNIQUE_PATHS, 3x4){
        LONGS_EQUAL(10, sln.uniquePaths(3,4));
    }
}