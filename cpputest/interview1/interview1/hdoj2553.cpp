//
//  hdoj2553.cpp
//  interview1
//
//  Created by wolf76 on 8/28/13.
//  Copyright (c) 2013 com.wolf76. All rights reserved.
//

//
//  hdoj1059.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=2553
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <iostream>
using namespace std;

namespace HDOJ2553 {
    
    
    int main()
    {
        
        return 0;
    }
    
    TEST_GROUP(HDOJ2553){
        
    };
    
    IGNORE_TEST(HDOJ2553, main){
        FILE *fin = freopen("./data/hdoj2553.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file hdoj2553.txt");
            return;
        }
        main();
        fclose(fin);
    }
    
    TEST(HDOJ2553, case1){
        FAIL("HDOJ2553 unsolved.");
    }
    
}//namespace
