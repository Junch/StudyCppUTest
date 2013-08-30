//
//  hdoj1059.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1059
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace HDOJ1059 {
    int marbles[7];
    int m[7];
    int total;
    bool bFound = false;
    // sum(i*m[i]) == total
    
    void dfs(int i, int v){
        if (v==0) {
            bFound = true;
            return;
        }
        
        for (int j=1; j<=marbles[i]; ++j) {
            int w = v-j*i;
            if (w < 0)
                break;
            
            dfs(i+1, w);
            if (bFound)
                return;
        }
    }
    
    bool split(){
        total = 0 ;
        for (int i=1; i<7;++i){
            if (marbles[i] == 0)
                continue;
            
            total += i*marbles[i];
        }

        if (total % 2)
            return false;
        
        total /= 2;
        
        
        
        
    }
    
    
    
    
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