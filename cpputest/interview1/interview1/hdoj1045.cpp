//
//  hdoj1045.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1045
//  Created by wolf76 on 13-8-27.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <iostream>
using namespace std;

namespace HDOJ1045 {
    
    
    
    int main()
    {
        
        return 0;
    }
    
    TEST_GROUP(HDOJ1045){
        
    };
    
    IGNORE_TEST(HDOJ1045, main){
        FILE *fin = freopen("./data/hdoj1045.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file hdoj1045.txt");
            return;
        }
        main();
        fclose(fin);
    }
    
    TEST(HDOJ1045, case1){
        FAIL("HDOJ1045 unsolved.");
    }
    
}//namespace
