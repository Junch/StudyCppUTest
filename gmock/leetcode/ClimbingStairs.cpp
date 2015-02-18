//
//  ClimbingStairs.cpp
//  leetcode
//
//  Created by Jun on 15/2/18.
//
//

#include <gtest/gtest.h>

namespace ClimbingStairs {

class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 1;
        int c = 1;
        
        for (int i=1; i<n; ++i) {
            c = a+b;
            a = b;
            b = c;
        }
        
        return c;
    }
};
    
TEST(ClimbingStairs, 3)
{
    Solution* sln = new Solution();
    int n = sln->climbStairs(3);
    ASSERT_EQ(n, 3);
}
    
TEST(ClimbingStairs, 4)
{
    Solution* sln = new Solution();
    int n = sln->climbStairs(4);
    ASSERT_EQ(n, 5);
}
    
}
