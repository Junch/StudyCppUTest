//
//  ltoj_jump_game.cpp
//  interview1
//
//  Created by Jun on 14-1-27.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_JUMP_GAME {
    class Solution {
    public:
        bool dfs(int A[], int n, int pos){
            if (pos >= n-1)
                return true;
            
            int max_step = A[pos];
            for (int i=1; i<=max_step; ++i){
                int next = pos + i;
                if (buffer[next] == false)
                    continue;
                
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
    
    class Solution2 {
    public:
        bool canJump(int A[], int n) {
            
            vector<bool> buffer(n);
            for (int i=0; i<n; ++i)
                buffer[i] = false;
            
            stack<int> st;
            st.push(0);
            buffer[0] = true;
            while (!st.empty()) {
                auto pos = st.top();
                st.pop();
                
                if (pos >= n-1)
                    return true;
                
                int max_step = A[pos];
                for (int i=1; i<=max_step; ++i) {
                    int newPos = pos + i;
                    
                    if (!buffer[newPos]) {
                        st.push(newPos);
                        buffer[newPos] = true;
                    }
                }
            }
            
            return false;
        }
    };
    
    class Solution3 {
    public:
        bool canJump(int A[], int n) {
            int max_pos = A[0];
            if (max_pos >= n-1)
                return true;
            
            for (int i = 1; i < n && i <= max_pos; ++i) {
                int pos = i + A[i];
                if (pos > max_pos)
                    max_pos = pos;
                
                if (max_pos >= n-1)
                    return true;
            }

            return false;
        }
    };
    
    class Solution4 {
    public:
        bool canJump(int A[], int n) {
            int i = 0;
            int max_pos = -1;
            
            do {
                int pos = i + A[i];
                if (pos > max_pos) {
                    max_pos = pos;
                    if (max_pos >= n-1)
                        return true;
                }
                
                ++i;
            }while (i<n && i<=max_pos);
            
            return false;
        }
    };
    
    class Solution5 {
    public:
        bool canJump(int A[], int n) {
            int max = A[0];
            
            for (int i = 1; i <= max && max < n-1; ++i) {
                if (i+A[i] > max)
                    max = i+A[i];
            }
            
            return max >= n-1;
        }
    };
    
    TEST_GROUP(LTOJ_JUMP_GAME){
        Solution5 sln;
    };
    
    IGNORE_TEST(LTOJ_JUMP_GAME, A){
        int A[]={1,1,4};
        CHECK_TRUE(sln.canJump(A, 3));
    }
    
    TEST(LTOJ_JUMP_GAME, B){
        int A[]={1,0,4};
        CHECK_FALSE(sln.canJump(A, 3));
    }
    
    TEST(LTOJ_JUMP_GAME, C){
        int A[]={0};
        CHECK_TRUE(sln.canJump(A, 1));
    }
}
