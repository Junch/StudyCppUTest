//
//  ltoj_jump_game.cpp
//  interview1
//
//  Created by Jun on 14-1-27.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_JUMP_GAME {
    class Solution {
    public:
        bool dfs(int A[], int n, int pos){
            if (pos >= n-1)
                return true;
            
            if (buffer[pos] == false)
                return false;
            
            int max_step = A[pos];
            for (int i=1; i<=max_step; ++i){
                int next = pos + i;
                if  (dfs(A, n, next))
                    return true;
            }
            
            buffer[pos] = false;
            return  false;
        }
        
        bool canJump(int A[], int n) {
            buffer.resize(n);
            for (int i=0; i<n; ++i)
                buffer[i] = A[i] != 0;
            
            return dfs(A, n, 0);
        }
        
    private:
        vector<bool> buffer;
    };
    
    TEST_GROUP(LTOJ_JUMP_GAME){
        Solution sln;
    };
    
    TEST(LTOJ_JUMP_GAME, A){
        int A[]={1,1,4};
        CHECK_TRUE(sln.canJump(A, 3));
    }
    
    TEST(LTOJ_JUMP_GAME, B){
        int A[]={1,0,4};
        CHECK_FALSE(sln.canJump(A, 3));
    }
}
