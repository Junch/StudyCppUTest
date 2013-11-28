//
//  jdoj1351.cpp
//  数组中只出现一次的数字
//  http://ac.jobdu.com/problem.php?pid=1351
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <stdio.h>

namespace JDOJ1351 {
    
    void findOdds(int a[], int n, int& p, int& q)
    {
        // Get the p^q
        int odd = a[0];
        for (int i=1; i<n; i++)
            odd ^= a[i];

        // Get the bit that p different from q
        int k=1;
        while ((k & odd) == 0)
            k = k<<1;
        
        // Divide the data into two category, in fact to separate the p, q
        p = q = odd; // It is important
        for (int i=0; i<n; i++) {
            if (a[i] & k)
                p ^= a[i];
            else
                q ^= a[i];
        }
    
        if (p > q) {
            p = p ^ q;
            q = p ^ q;
            p = p ^ q;
        }
    }
    
    
    int main()
    {
        int n;
        while (scanf("%d", &n) != EOF) {
            int *a = new int[n];
            for (int i=0; i<n; i++)
                scanf("%d", &a[i]);
            
            int p, q;
            findOdds(a, n, p, q);
            printf("%d %d\n", p, q);
            
            delete []a;
        }
        
        return 0;
    }
    
    TEST_GROUP(JDOJ1351){
        
    };
    
    IGNORE_TEST(JDOJ1351, main){
        FILE *fin = freopen("./data/jdoj1351.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file jdoj1351.txt");
            return;
        }
        main();
        fclose(fin);
    }
    
    TEST(JDOJ1351, case1){
        int a[] = {2,2,4,4,3,5};
        int p,q;
        findOdds(a, sizeof(a)/sizeof(int), p, q);
        LONGS_EQUAL(3, p);
        LONGS_EQUAL(5, q);
    }
    
    TEST(JDOJ1351, case2){
        int a[] = {2,2,4,4,5,3};
        int p,q;
        findOdds(a, sizeof(a)/sizeof(int), p, q);
        LONGS_EQUAL(3, p);
        LONGS_EQUAL(5, q);
    }
    
    TEST(JDOJ1351, case3){
        int a[] = {2,2,11,23,11,5};
        int p,q;
        findOdds(a, sizeof(a)/sizeof(int), p, q);
        LONGS_EQUAL(5, p);
        LONGS_EQUAL(23, q);
    }
    
}//namespace
