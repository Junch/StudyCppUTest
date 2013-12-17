//
//  template.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=xxxx
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace HDOJXXXX {
    
    
        
    int main()
    {
        
        return 0;
    }
    
    TEST_GROUP(HDOJXXXX){
        
    };
    
    IGNORE_TEST(HDOJXXXX, main){
        FILE *fin = freopen("./data/hdojxxxx.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file hdojxxxx.txt");
            return;
        }
        main();
        fclose(fin);
    }
    
    TEST(HDOJXXXX, case1){
        //FAIL("Filed the test HDOJXXXX");
    }
    
}//namespace
