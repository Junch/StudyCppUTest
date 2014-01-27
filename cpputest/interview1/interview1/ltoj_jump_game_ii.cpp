//
//  ltoj_jump_game_ii.cpp
//  interview1
//  http://oj.leetcode.com/problems/jump-game-ii/
//
//  Created by Jun on 14-1-27.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_JUMP_GAME_II {
    class Solution {
        public:
        int jump(int A[], int n) {
            vector<int> dict(n);
            for (auto& x: dict)
                x = 0;
            
            int max = A[0];
            for (int i=0; i<=max && max<n-1 ; ++i) {
                int pos = A[i] + i;
                if (pos > max)
                    max = pos;
                
                for (int j=i+1; j<=max; ++j) {
                    if (dict[j] == 0)
                        dict[j] = dict[i] + 1;
                }
            }
            
            return dict[n-1];
        }
    };
    
    class Solution2 {
    public:
        int jump(int A[], int n) {
            
            if (n == 1)
                return 0;
            
            int max = 0;
            int level = -1;
            int levelIndex = -1;
            
            for (int i=0; i<n-1 ; ++i) {
                if (i > levelIndex){
                    ++level;
                    levelIndex = max;
                }
                
                int pos = A[i] + i;
                if (pos > max)
                    max = pos;
                
                if (i > max)
                    return 0;
                
                if (max >= n-1) {
                    return level+1;
                }
            }
            
            return level;
        }
    };
    
    class Solution3 {
    public:
        int jump(int A[], int n) {

            int max = 0;
            int level = 0;
            int levelIndex = -1;
            
            for (int i=0; i<n-1 && max<n-1; ++i) {
                if (i > levelIndex){
                    ++level;
                    levelIndex = max;
                }
                
                max = std::max(max, A[i] + i);
            }
            
            return level;
        }
    };
    
    
    /*
     * We use "last" to keep track of the maximum distance that has been reached
     * by using the minimum steps "ret", whereas "curr" is the maximum distance
     * that can be reached by using "ret+1" steps. Thus,
     * curr = max(curr, i+A[i]) where 0 <= i <= last.
     */
    class Solution4 {
    public:
        int jump(int A[], int n) {
            int ret = 0;
            int last = 0;
            int curr = 0;
            for (int i = 0; i < n; ++i) {
                if (i > last) {
                    last = curr;
                    ++ret;
                }
                curr = max(curr, i+A[i]);
            }
            
            return ret;
        }
    };
    
    TEST_GROUP(LTOJ_JUMP_GAME_II){
        Solution4 sln;
    };
    
    TEST(LTOJ_JUMP_GAME_II, 23114){
        int A[]={2,3,1,1,4};
        LONGS_EQUAL(2, sln.jump(A, 5));
    }
    
    TEST(LTOJ_JUMP_GAME_II, 20114){
        int A[]={2,0,1,1,4};
        LONGS_EQUAL(3, sln.jump(A, 5));
    }

    TEST(LTOJ_JUMP_GAME_II, 2){
        int A[]={2};
        LONGS_EQUAL(0, sln.jump(A, 1));
    }
    
    TEST(LTOJ_JUMP_GAME_II, 11){
        int A[]={1,1};
        LONGS_EQUAL(1, sln.jump(A, 2));
    }
    
    TEST(LTOJ_JUMP_GAME_II, 111){
        int A[]={1,1,1};
        LONGS_EQUAL(2, sln.jump(A, 3));
    }
    
    TEST(LTOJ_JUMP_GAME_II, 1111){
        int A[]={1,1,1,1};
        LONGS_EQUAL(3, sln.jump(A, 4));
    }

}