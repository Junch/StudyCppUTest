//
//  https://oj.leetcode.com/problems/valid-parentheses/
//  leetcode
//
//  Created by Jun on 15/2/19.
//
//

#include <gtest/gtest.h>
#include <string>
#include <stack>
using namespace std;

namespace ValidParentheses {

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c: s) {
            if (c =='(' || c == '{' || c == '[' ) {
                st.push(c);
            }else{
                if (st.empty()) {
                    return false;
                }
                
                char d = st.top();
                st.pop();
                
                if(   (c==')' && d != '(')
                   || (c==']' && d != '[')
                   || (c=='}' && d != '{')){
                    return false;
                }
            }
        }
        
        return st.empty();
    }
};
    
TEST(ValidParentheses, Invalid){
    string s = "([)]";

    Solution* sln = new Solution();
    ASSERT_FALSE(sln->isValid(s));
}
    
TEST(ValidParentheses, Valid){
    string s = "()[]{}";
    
    Solution* sln = new Solution();
    ASSERT_TRUE(sln->isValid(s));
}
    
TEST(ValidParentheses, Invalid2){
    string s = "]";
    
    Solution* sln = new Solution();
    ASSERT_TRUE(!sln->isValid(s));
}
    
}
