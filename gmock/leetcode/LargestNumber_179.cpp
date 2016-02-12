//
//  LargestNumber_179.cpp
//  leetcode
//
//  Created by Jun on 16/2/6.
//
//

#include <gmock/gmock.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
using namespace testing;

namespace LargestNumber {
    
class Solution {
public:
   
    string getDigits(int m){
        stringstream ss;
        ss << m;
        return ss.str();
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> a(nums.size());
        for (int i=0; i<nums.size(); ++i) {
            a[i] = getDigits(nums[i]);
        }

        std::sort(a.rbegin(), a.rend(), [](const string&x, const string &y){
            return x+y < y+x;
        });
        
        if (a[0][0] == '0') {
            return "0";
        }
        
        stringstream res;
        for (string& s: a) {
            res << s;
        }
        
        return res.str();
    }
};
   
TEST(LargestNumber, zero) {
    vector<int> a = {0, 0, 0};
    
    auto s = new Solution();
    string sn = s->largestNumber(a);
    ASSERT_EQ("0", sn);
}

TEST(LargestNumber, largestNumber) {
    vector<int> a = {5, 2, 3};
    
    auto s = new Solution();
    string sn = s->largestNumber(a);
    ASSERT_EQ("532", sn);
}

TEST(LargestNumber, getDigits) {
    auto s = new Solution();
    string sn = s->getDigits(23456);
    ASSERT_EQ("23456", sn);
}
    
}
