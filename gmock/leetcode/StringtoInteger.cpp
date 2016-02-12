//
//  StringtoInteger.cpp
//  https://leetcode.com/problems/string-to-integer-atoi/
//
//  Created by Jun Chen on 16/2/9.
//
//

#include <gmock/gmock.h>
#include <vector>
#include <string>
using namespace std;
using namespace testing;

namespace StringtoInteger {
    
class Solution {
public:
    int myAtoi(string str) {
        int i=0;
        for (; i<str.length(); ++i){
            if (str[i] != ' ') {
                break;
            }
        }

        int flag = 1;
        if (str[i] == '-') {
            flag = -1;
            ++i;
        } else if(str[i] == '+') {
            ++i;
        }
        
        int num = 0;
        for (; i<str.length(); ++i) {
            if (str[i] > '9' || str[i] < '0') {
                break;
            }
            
            int digit = str[i] - '0';
            int m = (INT_MAX - digit)/10;
            if (num > m) {
                return flag > 0? INT_MAX:INT_MIN;
            }
            
            num = num*10 + digit;
        }
        
        return num*flag;
    }
};
    

TEST(StringtoInteger, blank123){
    auto p = new Solution;
    ASSERT_EQ(123, p->myAtoi("  123"));
}
    
TEST(StringtoInteger, plus123){
    auto p = new Solution;
    ASSERT_EQ(123, p->myAtoi("+123"));
}
    
TEST(StringtoInteger, minus123){
    auto p = new Solution;
    ASSERT_EQ(-123, p->myAtoi("-123"));
}
    
TEST(StringtoInteger, minus123withNondigitChar){
    auto p = new Solution;
    ASSERT_EQ(-12, p->myAtoi("  -0012a42"));
}

TEST(StringtoInteger, maxValue){
    auto p = new Solution;
    ASSERT_EQ(INT_MAX, p->myAtoi("2147483648"));
}
    
}
