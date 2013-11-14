//
//  jdoj1352.cpp
//  interview1
//  http://ac.jobdu.com/problem.php?pid=1352
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <stdio.h>
using namespace std;

namespace JDOJ1352 {
    
    void calc(unsigned long a[], int n, unsigned long k)
    {
        int i=0,j=n-1;
        unsigned long s = 0;
        while (i<j) {
            s = a[i]+a[j];
            if (s==k){
                printf("%lu %lu\n", a[i], a[j]);
                return;
            }
            
            if (s<k)
                ++i;
            else
                --j;
        }
        
        printf("-1 -1\n");
    }
    
    int main()
    {
        int n;
        unsigned long k;
        
        while(scanf("%d %lu", &n, &k) == 2) {
            unsigned long *a = new unsigned long[n];
            for (int i=0; i<n; i++)
                scanf("%lu", &a[i]);
            
            calc(a, n, k);
            
            delete[] a;
        }
        return 0;
    }
    
    TEST_GROUP(JDOJ1352){
        
    };
    
    IGNORE_TEST(JDOJ1352, main){
        FILE *fin = freopen("./data/jdoj1352.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file jdoj1352.txt");
            return;
        }
        main();
        fclose(fin);
    }
    
    IGNORE_TEST(JDOJ1352, case1){
        unsigned long a[]={1,2,4,7,11,15};
        calc(a, sizeof(a)/sizeof(unsigned long), 15);
        calc(a, sizeof(a)/sizeof(unsigned long), 25);
    }
    
}//namespace
