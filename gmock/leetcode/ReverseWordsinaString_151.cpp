//
//  ReverseWordsinaString_151.cpp
//  leetcode
//
//  Created by Jun Chen on 16/2/10.
//
//

#include <gmock/gmock.h>
#include <vector>
#include <algorithm>
using namespace std;
using namespace testing;

namespace ReverseWordsinaString {
    
class Solution {
public:
    void reverseWords(char *s) {
        int len = (int)strlen(s);
        char * p = (char *)malloc(len+1);
        memset(p, 0, len+1);
        
        int j = len-1;
        int k = 0;
        while (j>=0) {
            while (j>=0 && s[j] == ' ') {
                --j;
            }
            
            int i = j;
            while (i>=0 && s[i] != ' ') {
                --i;
            }
            
            if (k != 0 && i != j) {
                p[k++] = ' ';
            }
            
            memcpy(p+k, s+i+1, j-i);
            k += j-i;
            j = i;
        }
        p[k] = '\0';
        
        strcpy(s, p);
        
        free(p);
    }
    
    void reverseWords(string& s) {
        string ss;
        
        for (int j = (int)s.length()-1; j >= 0;) {
            while (j >= 0 && s[j] == ' ') --j;
            
            int i=j;
            while (i >= 0 && s[i] != ' ') {
                --i;
            }
            
            if (!ss.empty() && i != j) {
                ss.push_back(' ');
            }
            
            ss.append(s.substr(i+1, j-i));
            j = i;
        }
        
        s = ss;
    }
};
 
TEST(ReverseWordsinaString, example) {
    char s[] = "the sky is blue";
    
    auto p = new Solution();
    p->reverseWords(s);
    ASSERT_STREQ("blue is sky the", s);
    
    string ss = "the sky is blue";
    p->reverseWords(ss);
    ASSERT_EQ("blue is sky the", ss);
}
    
TEST(ReverseWordsinaString, blank) {
    char s[] = "   ";
    
    auto p = new Solution();
    p->reverseWords(s);
    ASSERT_STREQ("", s);
    
    string ss = "   ";
    p->reverseWords(ss);
    ASSERT_EQ("", ss);
}
    
TEST(ReverseWordsinaString, blank2) {
    char s[] = " 1 ";
    
    auto p = new Solution();
    p->reverseWords(s);
    ASSERT_STREQ("1", s);
    
    string ss = "   1   ";
    p->reverseWords(ss);
    ASSERT_EQ("1", ss);
}
    
}
