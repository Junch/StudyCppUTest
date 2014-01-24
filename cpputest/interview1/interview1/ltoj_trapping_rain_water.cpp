//
//  ltoj_trapping_rain_water.cpp
//  interview1
//  http://oj.leetcode.com/problems/trapping-rain-water/
//
//  Created by Jun on 14-1-24.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_TRAPPING_RAIN_WATER {
    class Solution {
    public:
        
        int trap(int A[], int n) {
            int w = 0;
            
            while (true) {
                int positiveNum = 0;

                for (int i=0; i<n;) {
                    if (A[i] == 0){
                        ++i;
                        continue;
                    }
                    
                    if(--A[i] > 0)
                        ++positiveNum;
                    
                    int j = i+1;
                    for (; j < n && A[j] == 0; ++j)
                    ;
                    
                    if (j < n)
                        w += j - i - 1;
                    
                    i = j;
                }
                
                if (positiveNum < 2)
                    break;
            }
            
            return w;
        }
    };
    
    TEST_GROUP(LTOJ_TRAPPING_RAIN_WATER){
        Solution sln;
    };
    
    TEST(LTOJ_TRAPPING_RAIN_WATER, 10101){
        int A[] = {1,0,1,0,1};
        int w = sln.trap(A, 5);
        LONGS_EQUAL(2, w);
    }
    
    TEST(LTOJ_TRAPPING_RAIN_WATER, 10202){
        int A[] = {1,0,2,0,2};
        int w = sln.trap(A, 5);
        LONGS_EQUAL(3, w);
    }
    
    TEST(LTOJ_TRAPPING_RAIN_WATER, 00100){
        int A[] = {0,0,1,0,0};
        int w = sln.trap(A, 5);
        LONGS_EQUAL(0, w);
    }
    
    TEST(LTOJ_TRAPPING_RAIN_WATER, 102023){
        int A[] = {1,0,2,0,2,3};
        int w = sln.trap(A, 6);
        LONGS_EQUAL(3, w);
    }
    
    TEST(LTOJ_TRAPPING_RAIN_WATER, 402024){
        int A[] = {4,0,2,0,2,4};
        int w = sln.trap(A, 6);
        LONGS_EQUAL(12, w);
    }
}