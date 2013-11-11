//
//  jdoj1369.cpp
//  interview1
//  http://ac.jobdu.com/problem.php?pid=1369
//  Created by wolf76 on 11/11/13.
//  Copyright (c) 2013 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <set>
using namespace std;

namespace JDOJ1369 {
    char t[10];
    bool used[10];
    set<string> ss;
    
    void permutation(char s[], char t[], bool used[], int len, int index)
    {
        if (len == index) {
            if (ss.find(t) == ss.end())  {
                ss.insert(t);
                printf("%s\n", t);
            }

            return;
        }
        
        for (int i=0; i<len; i++) {
            if (!used[i])
            {
                t[index] = s[i];
                ++index;
                used[i] = true;
                permutation(s, t, used, len, index);
                used[i] = false;
                --index;
            }
        }
    }
    
    int main()
    {
        char s[10];
        while (true) {
            scanf("%s", s);
            int len = (int)strlen(s);
            if (len == 0)
                break;
            
            assert(len < 10);
            memset(t, 0, sizeof(t));
            memset(used, false, sizeof(used));

            int index = 0;
            std::sort(&s[0], &s[len]);
            permutation(s, t, used, len, index);
            
            memset(s,0,sizeof(s));
            ss.clear();
        }
        
        return 0;
    }
    
    TEST_GROUP(JDOJ1369){
        
    };
    
    IGNORE_TEST(JDOJ1369, main){
        FILE *fin = freopen("./data/jdoj1369.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file jdoj1369.txt");
            return;
        }
        main();
        fclose(fin);
    }
    
    TEST(JDOJ1369, case1){
        char s[]  = "ABC";
        memset(t, 0, sizeof(t));
        memset(used, false, sizeof(used));
        int len = (int)strlen(s);
        int index = 0;
        permutation(s, t, used, len, index);
        ss.clear();
    }
    
    IGNORE_TEST(JDOJ1369, case2){
        char s[]  = "ACB";
        std::sort(&s[0], &s[3]);
        
        memset(t, 0, sizeof(t));
        memset(used, false, sizeof(used));
        int len = (int)strlen(s);
        int index = 0;
        permutation(s, t, used, len, index);
    }
    
    TEST(JDOJ1369, case3){
        char s[]  = "ABA";
        std::sort(&s[0], &s[3]);
        
        memset(t, 0, sizeof(t));
        memset(used, false, sizeof(used));
        int len = (int)strlen(s);
        int index = 0;
        permutation(s, t, used, len, index);
        ss.clear();
    }
    
}//namespace
