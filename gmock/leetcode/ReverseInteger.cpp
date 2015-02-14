//
//  ReverseInteger.cpp
//  leetcode
//
//  Created by Jun on 15/2/14.
//
//

#include <gtest/gtest.h>

namespace ReverseInteger{

class Solution {
public:
    int reverse(int x) {
        int sign = x > 0? 1: -1;
        x = x * sign;
        
        int n = 0;
        while (x>0) {
            if (INT32_MAX/10 < n) {
                return 0;
            }
            n *= 10;

            if (INT32_MAX - x%10 < n) {
                return 0;
            }
            
            n += x%10;
            x = x/10;
        }

        return n*sign;
    }
};

TEST(ReverseInteger, int123){
    Solution *sln = new Solution();
    int val = sln->reverse(123);
    ASSERT_EQ(321, val);
}
    
TEST(ReverseInteger, int1){
    Solution *sln = new Solution();
    int val = sln->reverse(1);
    ASSERT_EQ(1, val);
}

TEST(ReverseInteger, int_123){
    Solution *sln = new Solution();
    int val = sln->reverse(-123);
    ASSERT_EQ(-321, val);
}
    
TEST(ReverseInteger, int1534236469){
    Solution *sln = new Solution();
    int val = sln->reverse(1534236469);
    ASSERT_EQ(0, val);
}

}