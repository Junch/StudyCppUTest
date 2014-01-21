//
//  ltoj_triangle.cpp
//  interview1
//
//  Created by Jun on 14-1-21.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_TRIANGLE {
    class Solution {
    public:
        
        int minimumTotal(vector<vector<int> > &triangle) {
            size_t num = triangle.size();
            if (num==0)
                return 0;

            vector<int> v(num);
            v[0] = triangle[0][0];
            for (int i=1; i<num; ++i) {
                v[i] = triangle[i][i] + v[i-1];
                for (int j=i-1; j>0; --j)
                    v[j] = triangle[i][j] + min(v[j-1], v[j]);
                v[0] = triangle[i][0] + v[0];
            }
            
            auto iter = min_element(v.begin(), v.end());
            return *iter;
        }
    };
    
    TEST_GROUP(LTOJ_TRIANGLE){
        Solution sln;
    };
    
    TEST(LTOJ_TRIANGLE, 0rows){
        vector<vector<int>> triangle;
        int total = sln.minimumTotal(triangle);
        LONGS_EQUAL(0, total);
    }
    
    TEST(LTOJ_TRIANGLE, 1rows){
        vector<vector<int>> triangle;
        triangle.push_back({5});
        int total = sln.minimumTotal(triangle);
        LONGS_EQUAL(5, total);
    }
    
    TEST(LTOJ_TRIANGLE, 2rows){
        vector<vector<int>> triangle;
        triangle.push_back({1});
        triangle.push_back({2, 3});
        int total = sln.minimumTotal(triangle);
        LONGS_EQUAL(3, total);
    }
    
    TEST(LTOJ_TRIANGLE, 3rows){
        vector<vector<int>> triangle;
        triangle.push_back({1});
        triangle.push_back({2, 3});
        triangle.push_back({3, 2, 1});
        int total = sln.minimumTotal(triangle);
        LONGS_EQUAL(5, total);
    }

}//namespace

