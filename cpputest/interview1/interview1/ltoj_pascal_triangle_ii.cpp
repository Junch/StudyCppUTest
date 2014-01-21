//
//  ltoj_pascal_triangle_ii.cpp
//  interview1
//  http://oj.leetcode.com/problems/pascals-triangle/
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_PASCAL_TRIANGLE_II {
    class Solution {
    public:
       
        vector<int> getRow(int rowIndex){
            ++rowIndex; // The index is a little different from pascal triangle problem
            vector<int> v(rowIndex);
            
            for (int i=0; i<rowIndex; ++i) {
                for (int j=0; j<i-1; ++j)
                    v[j] += v[j+1];
                
                for (int j=i; j>0; j--)
                    v[j] = v[j-1];
                
                v[0] = 1;
            }
            
            return v;
        }
    };
    
    TEST_GROUP(LTOJ_PASCAL_TRIANGLE){
        Solution sln;
    };
    
    TEST(LTOJ_PASCAL_TRIANGLE, 1rows){
        auto&& vv = sln.getRow(0);
        LONGS_EQUAL(1, vv.size());
    }
    
    TEST(LTOJ_PASCAL_TRIANGLE, 2rows){
        auto&& v = sln.getRow(1);
        LONGS_EQUAL(2, v.size());
        LONGS_EQUAL(1, v[0]);
        LONGS_EQUAL(1, v[1]);
    }
    
    TEST(LTOJ_PASCAL_TRIANGLE, 4rows){
        auto&& v = sln.getRow(3);
        LONGS_EQUAL(4, v.size());
        LONGS_EQUAL(1, v[0]);
        LONGS_EQUAL(3, v[1]);
        LONGS_EQUAL(3, v[2]);
        LONGS_EQUAL(1, v[3]);
    }
}//namespace


