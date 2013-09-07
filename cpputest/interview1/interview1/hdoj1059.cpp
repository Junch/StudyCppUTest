//
//  hdoj1059.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1059
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <iostream>
using namespace std;

namespace HDOJ1059 {
    
    int main()
    {
        
        return 0;
    }
    
    TEST_GROUP(HDOJ1059){
        
    };
    
    IGNORE_TEST(HDOJ1059, main){
        FILE *fin = freopen("./data/hdoj1059.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file hdoj1059.txt");
            return;
        }
        main();
        fclose(fin);
    }
    
    TEST(HDOJ1059, case1){
        FAIL("HDOJ1059 unsolved.");
    }    
}//namespace