//
//  template.cpp
//  interview1
//  http://oj.leetcode.com/problems/implement-strstr/
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <cassert>
#include <CppUTest/TestHarness.h>

namespace LTOJ_STRSTR {

    class Solution;
    typedef const char* (Solution::*StrstrFunc)(const char *, const char *);
    
    class Solution {
    public:
        const char *strStr(const char *haystack, const char *needle) {
            return (this->*m_pFunc)(haystack, needle);
        }
        
        const char *bruteSearch(const char* s, const char* p)
        {
            assert(s != nullptr && p != nullptr);
            
            if (*p == '\0')
                return s;
            
            size_t len = strlen(p);
            while (*s != '\0') {
                if (strncmp(s, p, len) ==0 )
                    return s;
                ++s;
            }
            
            return nullptr;
        }
        
        const char *bruteSearch2(const char* s, const char* p)
        {
            assert(s != nullptr && p != nullptr);
            
            if (*p == '\0')
                return s;
            
            const char* sp = nullptr;
            const char* pp = nullptr;
            
            while (*s != '\0') {
                sp = s;
                pp = p;
                
                while (*pp && *sp == *pp){
                    sp++;
                    pp++;
                }
                
                if (*pp == '\0')
                    return s;
                
                s++;
            }

            return nullptr;
        }

        const char *bruteSearch3(const char* s, const char* p)
        {
            assert(s != nullptr && p != nullptr);
            
            if (*p == '\0')
                return s;
            
            const char* sp = nullptr;
            const char* pp = nullptr;
            
            while (*s != '\0') {
                sp = s;
                pp = p;
                
                do {
                    if (*pp == '\0')
                        return s;
                }while (*sp++ == *pp++);
                
                s++;
            }
            
            return nullptr;
        }

        StrstrFunc m_pFunc = nullptr;
    };
    
    TEST_GROUP(LTOJ_STRSTR){
        Solution sln;
        StrstrFunc fcs[3]{&Solution::bruteSearch,
                          &Solution::bruteSearch2,
                          &Solution::bruteSearch3};
    };
    
    TEST(LTOJ_STRSTR, BothStringAreEmpty){
        for (auto f: fcs)
        {
            sln.m_pFunc = f;
            
            const char* s = sln.strStr("", "");
            STRCMP_EQUAL("", s);
        }
    }
    
    TEST(LTOJ_STRSTR, MatchStringIsEmpty){
        for (auto f: fcs)
        {
            sln.m_pFunc = f;
            
            const char* s = sln.strStr("abc", "");
            STRCMP_EQUAL("abc", s);
        }
    }
    
    TEST(LTOJ_STRSTR, MatchStringFound){
        for (auto f: fcs)
        {
            sln.m_pFunc = f;
            
            const char* s = sln.strStr("abcd", "bc");
            STRCMP_EQUAL("bcd", s);
        }
    }
    
    TEST(LTOJ_STRSTR, MatchStringNotFound){
        for (auto f: fcs)
        {
            sln.m_pFunc = f;
            const char* s = sln.strStr("abc", "d");
            POINTERS_EQUAL((void *)nullptr, s);
        }
    }
}//namespace

