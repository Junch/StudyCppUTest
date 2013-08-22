//
//  jdoj_chessboard.cpp
//  interview1 棋盘寻宝
//  http://ac.jobdu.com/problem.php?cid=1048&pid=0
//  Created by wolf76 on 13-8-21.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <iostream>
#include <cassert>
using namespace std;

namespace JDOJ_CHESSBOARD {
    // a(x,y)=max(a(x-1,y),a(x,y-1)) + v(x,y)
    // a(x,0)=a(x-1,0)+v(x,0)=v(0,0)+...v(x,0)
    // a(0,y)=a(0,y-1)+v(0,y)=v(0,0)+...v(0,y)
#define N 10
    int v[N][N];
    int a[N][N]={0};
    
    int max(int n){
        assert(n <= N);
        
        a[0][0] = v[0][0];
        for (int i=1; i<n; i++){
            a[i][0] = a[i-1][0] + v[i][0];
            a[0][i] = a[0][i-1] + v[0][i];
        }
        
        for (int i=1; i<n; ++i)
            for (int j=1; j<n; ++j)
                a[i][j] = std::max(a[i-1][j], a[i][j-1]) + v[i][j];
        
        return a[n-1][n-1];
    }
    
    int main() {
        int n=8;
        for(int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                cin >> v[i][j];
        cout<< max(n);

        return 0;
    }
    
    TEST_GROUP(JDOJ_CHESSBOARD){
        
    };
    
    IGNORE_TEST(JDOJ_CHESSBOARD, main){
        FILE *fin = freopen("./data/jdojchess.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file jdojchess.txt");
            return;
        }
        main();
    }
    
    TEST(JDOJ_CHESSBOARD, case1){
        v[0][0] = 1;
        v[0][1] = 2;
        v[1][0] = 3;
        v[1][1] = 4;
        LONGS_EQUAL(8, max(2));
    }

}//namespace