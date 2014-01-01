//
//  ltoj_LongestCommonPrefix .cpp
//  interview1
//  http://oj.leetcode.com/problems/longest-common-prefix/
//  Created by Jun on 14-1-1.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <vector>
#include <string>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LongestCommonPrefix {
    
    class Solution {
    public:
        
        string commonPrefix(const string& a, const string& b)
        {
            string common;
            
            for (size_t i=0, al=a.length(), bl=b.length(); i<al && i<bl; i++) {
                if (a[i] != b[i] )
                    break;
                else
                    common.push_back(a[i]);
            }
             
            return common;
        }
        
        string longestCommonPrefix(vector<string> &strs) {
            size_t len= strs.size();
            if (len == 0)
                return "";
            
            string prefix=strs[0];
            for (int i=1; i<len; ++i) {
                prefix = commonPrefix(prefix, strs[i]);
                if (prefix == "")
                    break;
            }
            
            return prefix;
        }
    };
    
    TEST_GROUP(LongestCommonPrefix){
        Solution sln;
    };
    
   
    TEST(LongestCommonPrefix, commonPrefix){
        STRCMP_EQUAL("abc", sln.commonPrefix("abc", "abc").c_str());
        STRCMP_EQUAL("a", sln.commonPrefix("a", "abc").c_str());
        STRCMP_EQUAL("", sln.commonPrefix("1", "abc").c_str());
    }
    
    TEST(LongestCommonPrefix, longestCommonPrefix){
        vector<string> a{"ab1", "ab2", "ab3"};
        STRCMP_EQUAL("ab", sln.longestCommonPrefix(a).c_str());
    }
    
}//namespace
