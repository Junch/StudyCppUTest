//
//  https://oj.leetcode.com/problems/palindrome-number/
//  leetcode
//
//  Created by Jun on 15/2/15.
//
//

#include <gtest/gtest.h>

namespace PalindromeNumber{

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0){
            return false;
        }
        int old = x;
        
        int n = 0;
        while (x>0) {
            if (INT32_MAX/10 < n) {
                return false;
            }
            n *= 10;
            
            if (INT32_MAX - x%10 < n) {
                return false;
            }
            
            n += x%10;
            x /= 10;
        }
        
        return n == old;
    }
};

    
TEST(PalindromeNumber, int123321){
    Solution *sln = new Solution();
    ASSERT_TRUE( sln->isPalindrome(123321));
}

    
TEST(PalindromeNumber, int_123321){
    Solution *sln = new Solution();
    ASSERT_FALSE(sln->isPalindrome(-123321));
}
    
    
TEST(PalindromeNumber, int_12332){
    Solution *sln = new Solution();
    ASSERT_FALSE(sln->isPalindrome(12332));
}

}
