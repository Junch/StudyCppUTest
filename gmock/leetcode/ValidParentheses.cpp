//
//  https://oj.leetcode.com/problems/valid-parentheses/
//  leetcode
//
//  Created by Jun on 15/2/19.
//
//

#include <gtest/gtest.h>
#include <string>
using namespace std;

namespace ValidParentheses {

class Solution {
public:
    bool isValid(string s) {
        return true;
    }
};
    
TEST(ValidParentheses, NotValid){
    string s = "([)]";

    Solution* sln = new Solution();
    ASSERT_FALSE(sln->isValid(s));
}
    
TEST(ValidParentheses, Valid){
    string s = "()[]{}";
    
    Solution* sln = new Solution();
    ASSERT_TRUE(sln->isValid(s));
}
    
}
