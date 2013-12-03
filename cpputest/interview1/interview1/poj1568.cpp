//
//  poj1568.cpp
//  Find the Winning Move
//  http://poj.org/problem?id=1568
//  Created by wolf76 on 12/3/13.
//  Copyright (c) 2013 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <iostream>
using namespace std;

namespace POJ1568 {
    
    int main()
    {
        
        return 0;
    }
    
    TEST_GROUP(POJ1568){
        
    };
    
    IGNORE_TEST(POJ1568, main){
        FILE *fin = freopen("./data/POJ1568.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file POJ1568.txt");
            return;
        }
        main();
        fclose(fin);
    }
    
    TEST(POJ1568, case1){
        FAIL("Filed the test POJ1568");
    }
    
}//namespace
