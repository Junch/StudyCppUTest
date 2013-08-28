//
//  hdoj2553.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=2553
//  Created by wolf76 on 8/28/13.
//  Copyright (c) 2013 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <iostream>
#include <cassert>
using namespace std;

namespace HDOJ2553 {
    
    int N=8;
    int total = 0;
    int a[10]; // The row queen is placed at a[row] column
    
    bool inline placable(int row, int col){
        assert(row < N && col < N);
        
        for (int i=0; i<row; ++i) {
            if (a[i] == col)
                return false;
            
            if( row - i == abs(col - a[i]))
                return false;
        }
        
        return true;
    }
    
    void dfs(int n){
        if (n == N){
            ++total;
            return;
        }
        
        for (int i=0; i<N; ++i) {
            if (placable(n, i)) {
                a[n] = i;
                dfs(n+1);
            }
        }        
    }
    
    int main()
    {
        int n;
        while (cin >> n && n) {
            N = n;
            total = 0;
            dfs(0);
            cout << total << endl;
        }
        
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
        N = 5;
        total = 0;
        dfs(0);
        LONGS_EQUAL(10, total);
    }
    
    TEST(HDOJ2553, case2){
        N = 8;
        total = 0;
        dfs(0);
        LONGS_EQUAL(92, total);
    }
    
    TEST(HDOJ2553, case3){
        N = 1;
        total = 0;
        dfs(0);
        LONGS_EQUAL(1, total);
    }
    
}//namespace
