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
            int step = 1;
            
            while (true) {
                int positiveNum = 0;
                int mini = INT_MAX;

                for (int i=0; i<n;) {
                    if (A[i] == 0){
                        ++i;
                        continue;
                    }
                    
                    A[i] -= step;
                    if(A[i] > 0) {
                        ++positiveNum;
                    
                        if (A[i] < mini)
                            mini = A[i];
                    }
                    
                    int j = i+1;
                    for (; j < n && A[j] == 0; ++j)
                    ;
                    
                    if (j < n)
                        w += (j - i - 1)*step;
                    
                    i = j;
                }
                
                step = mini;
                
//                for (int i=0; i<n; i++)
//                    printf("%d -> ", A[i]);
//                
//                printf("\n");
                
                if (positiveNum < 2)
                    break;
            }
            
            return w;
        }
        
        int trap2(int A[], int n) {
            int w = 0;
            
            for (int i=0; i<n; ) {
                int j = i + 1;
                int maxVal = 0;
                int maxIndex = 0;
                
                for ( ; j < n && A[j] < A[i]; j++){
                    if (A[j] > maxVal) {
                        maxVal = A[j];
                        maxIndex = j;
                    }
                }
                
                if (j == n && maxVal > 0)
                        j = maxIndex;
            
                if (j < n) {
                    int high = min(A[i], A[j]);
                    
                    for (int k=i+1; k<j; ++k)
                        w += high - A[k];
                }
                
                i = j;
            }
            
            return w;
        }
    };
    
    TEST_GROUP(LTOJ_TRAPPING_RAIN_WATER){
        Solution sln;
    };
    
    IGNORE_TEST(LTOJ_TRAPPING_RAIN_WATER, 10101){
        int A[] = {1,0,1,0,1};
        int w = sln.trap(A, 5);
        LONGS_EQUAL(2, w);
    }
    
    IGNORE_TEST(LTOJ_TRAPPING_RAIN_WATER, 10202){
        int A[] = {1,0,2,0,2};
        int w = sln.trap(A, 5);
        LONGS_EQUAL(3, w);
    }
    
    IGNORE_TEST(LTOJ_TRAPPING_RAIN_WATER, 00100){
        int A[] = {0,0,1,0,0};
        int w = sln.trap(A, 5);
        LONGS_EQUAL(0, w);
    }
    
    IGNORE_TEST(LTOJ_TRAPPING_RAIN_WATER, 102023){
        int A[] = {1,0,2,0,2,3};
        int w = sln.trap(A, 6);
        LONGS_EQUAL(3, w);
    }
    
    IGNORE_TEST(LTOJ_TRAPPING_RAIN_WATER, 404){
        int A[] = {4,0,4};
        int w = sln.trap(A, 3);
        LONGS_EQUAL(4, w);
    }
    
    TEST_GROUP(LTOJ_TRAPPING_RAIN_WATER_2){
        Solution sln;
    };
    
    IGNORE_TEST(LTOJ_TRAPPING_RAIN_WATER_2, 10101){
        int A[] = {1,0,1,0,1};
        int w = sln.trap2(A, 5);
        LONGS_EQUAL(2, w);
    }
    
    IGNORE_TEST(LTOJ_TRAPPING_RAIN_WATER_2, 10202){
        int A[] = {1,0,2,0,2};
        int w = sln.trap2(A, 5);
        LONGS_EQUAL(3, w);
    }
    
    IGNORE_TEST(LTOJ_TRAPPING_RAIN_WATER_2, 00100){
        int A[] = {0,0,1,0,0};
        int w = sln.trap2(A, 5);
        LONGS_EQUAL(0, w);
    }
    
    IGNORE_TEST(LTOJ_TRAPPING_RAIN_WATER_2, 102023){
        int A[] = {1,0,2,0,2,3};
        int w = sln.trap2(A, 6);
        LONGS_EQUAL(3, w);
    }
    
    IGNORE_TEST(LTOJ_TRAPPING_RAIN_WATER_2, 423){
        int A[] = {4,2,3};
        int w = sln.trap2(A, 3);
        LONGS_EQUAL(1, w);
    }
    
    IGNORE_TEST(LTOJ_TRAPPING_RAIN_WATER_2, 020){
        int A[] = {0, 2, 0};
        int w = sln.trap2(A, 3);
        LONGS_EQUAL(0, w);
    }
}