//
//  hdoj1028.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1028
//  Created by wolf76 on 8/19/13.
//  Copyright (c) 2013 com.wolf76. All rights reserved.
//

#include <iostream>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace HDOJ1028 {

    // divides(4) = f(4,1) + f(4,2) + f(4,3) + f(4,4)
    // f(4,3) = g(4-3) = f(1)
    // f(4,2) = f(4-2,2) + f(4-2, 1)= f(2,2)+ f(2,1) = g(2)
    // f(4,1) = 1 // f(n,1) = 1,f(n,n) = 1
    // f(i,j) = f(i-j,j) + f(i-j, j-1) + ... + f(i-j, 1) i>=j
    int f[121][121];
    
    int divides(int n){
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=i; ++j) {
                if (i==j || j==1)
                    f[i][j] = 1;
                else {
                    f[i][j] = 0;
                    for(int k=1; k<=j;++k)
                        f[i][j] += f[i-j][k];
                }
            }
        }
        
        int s = 0;
        for (int i=1; i<=n; ++i)
            s += f[n][i];
        
        return s;
    }
    
    int main() {
        int n;
        while (cin >> n)
            cout << divides(n) << endl;
        return 0;
    }
    
    TEST_GROUP(HDOJ1028){
        
    };
    
    TEST(HDOJ1028, case1){
        LONGS_EQUAL(5, divides(4));
        LONGS_EQUAL(42, divides(10));
        LONGS_EQUAL(627, divides(20));
    }
    
}
