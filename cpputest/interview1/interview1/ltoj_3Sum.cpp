//
//  ltoj_3Sum .cpp
//  interview1
//  http://oj.leetcode.com/problems/3sum/
//  Created by Jun on 14-1-1.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace ThreeSum {
    
    class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            vector<vector<int> > a;
            std::sort(num.begin(), num.end());
            size_t len=num.size();
            if (len < 3)
                return a;
            
            size_t i=0;
            while (i<len-2 && num[i]<=0) {
                size_t j=i+1;
                size_t k=len-1;
                while (j<k) {
                    int sum = num[j] + num[k];
                    if (sum > -num[i]){
                        do {
                            k--;
                        }while (k>j && num[k] == num[k+1]);
                    }
                    else if(sum < -num[i])
                        do {
                            j++;
                        }while (k>j && num[j] == num[j-1]);
                    else {
                        a.insert(a.end(), vector<int>{num[i], num[j], num[k]});
                        
                        do {
                            j++;
                        }while (k>j && num[j] == num[j-1]);
                        
                        do {
                            k--;
                        }while (k>j && num[k] == num[k+1]);
                    }
                } //while
                
                do {
                    ++i;
                }while (i<len-2 && num[i] == num[i-1]);
            } //while
            
            return a;
        }
    };
    
    TEST_GROUP(ThreeSum){
        Solution sln;
    };
    
    TEST(ThreeSum, testGeneral){
        vector<int> s{-1, 0, 1, 2, -1 ,-4};
        auto r=sln.threeSum(s);
        for (const auto& v: r)  {
            for (const auto& item: v){
                cout << item << " ";
            }
            cout << "\r";
        }
        
            LONGS_EQUAL(2, r.size());
    }
    
    TEST(ThreeSum, testBoundary){
        vector<int> s;
        auto r=sln.threeSum(s);
        LONGS_EQUAL(0, r.size());
    }
}//namespace

