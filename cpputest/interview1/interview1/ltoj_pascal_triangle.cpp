//
//  ltoj_pascal_triangle.cpp
//  interview1
//  http://oj.leetcode.com/problems/pascals-triangle/
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_PASCAL_TRIANGLE {
    class Solution {
    public:
        vector<vector<int> > generateSlow(int numRows){
            vector<vector<int>> vv;
           
            for (int i=0; i<numRows; ++i) {
                vv.push_back({1});
                
                if (i==0)
                    continue;
                
                auto& upper = vv[i-1];
                for (int j=1; j<i; ++j) {
                    vv[i].push_back(upper[j-1]+upper[j]);
                }
                
                vv[i].push_back(1);
            }
            
            return vv;
        }
        
        vector<vector<int> > generate(int numRows){
            vector<vector<int>> vv(numRows);
            
            for (int i=0; i<numRows; ++i) {
                vv[i].resize(i+1);
                vv[i][0] = 1;

                for (int j=1; j<i; ++j)
                    vv[i][j] = vv[i-1][j-1] + vv[i-1][j];
                
                vv[i][i] = 1;
            }
            
            return vv;
        }
    };
    
    TEST_GROUP(LTOJ_PASCAL_TRIANGLE){
        Solution sln;
    };
    
    
    TEST(LTOJ_PASCAL_TRIANGLE, 0rows){
        auto&& vv = sln.generate(0);
        LONGS_EQUAL(0, vv.size());
    }
    
    TEST(LTOJ_PASCAL_TRIANGLE, 2rows){
        auto&& vv = sln.generate(2);
        LONGS_EQUAL(2, vv.size());
        LONGS_EQUAL(1, vv[1][0]);
        LONGS_EQUAL(1, vv[1][1]);
    }
    
    TEST(LTOJ_PASCAL_TRIANGLE, 3rows){
        auto&& vv = sln.generate(3);
        LONGS_EQUAL(3, vv.size());
        LONGS_EQUAL(1, vv[2][0]);
        LONGS_EQUAL(2, vv[2][1]);
        LONGS_EQUAL(1, vv[2][2]);
    }

}//namespace

