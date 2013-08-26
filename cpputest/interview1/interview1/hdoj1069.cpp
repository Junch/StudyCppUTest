//
//  hdoj1069.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1069
//  Created by wolf76 on 8/26/13.
//  Copyright (c) 2013 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <iostream>
using namespace std;

namespace HDOJ1069 {
    
    struct Block {
        int x,y,z; // x>>y>>z
    };
    
    struct Shape {
        int width, length, height;
        
    };
    
    int maxHeight(){
        
    }
    
    int main()
    {
        
        return 0;
    }
    
    TEST_GROUP(HDOJ1069){
        
    };
    
    IGNORE_TEST(HDOJ1069, main){
        FILE *fin = freopen("./data/hdoj1069.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file hdoj1069.txt");
            return;
        }
        main();
        fclose(fin);
    }
    
    TEST(HDOJ1069, case1){
        FAIL("HDOJ1069 unsolved.");
    }
    
}//namespace
