//
//  hdoj1506.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1506
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <iostream>
#include <cassert>
using namespace std;

namespace HDOJ1506 {
    uint64_t height[100001];
    int N;
   
    uint64_t area(int i, int j){
        assert(i<=j);
        uint64_t min = height[i];
        for (int k=i+1; k<=j; ++k)
            if (min > height[k])
                min = height[k];
        return min*(j-i+1);
    }
    
    uint64_t largestRect()
    {
        uint64_t max=0;
        
        for (int i=1; i<=N; ++i) {
            for (int j=i; j<=N; ++j) {
                uint64_t a = area(i, j);
                if (max < a)
                    max = a;
            }
        }
        
        return max;
    }
    
    int main()
    {
        int n;
        while (cin >> n && n != 0) {
            for (int i=1; i<=n; ++i) {
                cin >> height[i];
            }
            N = n;
            cout << largestRect() << endl;
        }
        
        return 0;
    }
    
    TEST_GROUP(HDOJ1506){
        
    };
    
    IGNORE_TEST(HDOJ1506, main){
        FILE *fin = freopen("./data/hdoj1506.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file hdoj1506.txt");
            return;
        }
        main();
        fclose(fin);
    }
    
    TEST(HDOJ1506, case1){
        N=3;
        height[1]=2;
        height[2]=1;
        height[3]=2;
        
        uint64_t m = largestRect();
        LONGS_EQUAL(3, m);
    }
    
    TEST(HDOJ1506, case2){
        N=7;
        height[1]=2;
        height[2]=1;
        height[3]=4;
        height[4]=5;
        height[5]=1;
        height[6]=3;
        height[7]=3;
        
        uint64_t m = largestRect();
        LONGS_EQUAL(8, m);
    }
    
}//namespace
