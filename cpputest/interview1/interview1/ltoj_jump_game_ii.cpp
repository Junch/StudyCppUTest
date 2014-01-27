//
//  ltoj_jump_game_ii.cpp
//  interview1
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
    
    TEST_GROUP(LTOJ_JUMP_GAME_II){
        Solution sln;
    };
    
    TEST(LTOJ_JUMP_GAME_II, 2Step){
        int A[]={2,3,1,1,4};
        LONGS_EQUAL(2, sln.jump(A, 5));
    }
    
    TEST(LTOJ_JUMP_GAME_II, 3Step){
        int A[]={2,0,1,1,4};
        LONGS_EQUAL(3, sln.jump(A, 5));
    }
    
    TEST(LTOJ_JUMP_GAME_II, 0Step){
        int A[]={2};
        LONGS_EQUAL(0, sln.jump(A, 1));
    }
}