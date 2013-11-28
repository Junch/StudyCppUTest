//
//  jdoj1348.cpp
//  数组中的逆序对
//  http://ac.jobdu.com/problem.php?pid=1348
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <stdio.h>

namespace JDOJ1348 {
    
    unsigned long reverseOrder = 0; //逆序数
    
    void merge(int a[], int low, int high, int t[])
    {
        int mid = (low + high)/2;
        int i=low;
        int j=mid;
        int k=low;
        while (i < mid && j< high) {
            if (a[i] <= a[j])
                t[k++] = a[i++];
            else {
                t[k++] = a[j++];
                //a[j]与{a[i],...,a[mid-1]}的所有元素都构成逆序数
                reverseOrder += mid-i;
            }
        }
        
        while (i<mid)
            t[k++] = a[i++];
        
        while (j<high)
            t[k++] = a[j++];
        
        for (i=low; i<high; i++)
            a[i] = t[i];
    }
    
    void mergesort(int a[], int low, int high, int t[])
    {
        if (high - low > 1) // If the array contains two more elements
        {
            int mid = (low + high)/2;
            mergesort(a, low, mid, t);
            mergesort(a, mid, high, t);
            merge(a, low, high, t);
        }
    }
    
    int main()
    {
        int num;
        while (scanf("%d", &num) != EOF) {
            int *a = new int[num];
            int *t = new int[num];
        
            for (int i=0; i<num; i++)
                scanf("%d", &a[i]);
            
            reverseOrder = 0;
            mergesort(a, 0, num, t);
            printf("%lu\n", reverseOrder);
            
            delete[] a;
            delete[] t;
        }
        
        return 0;
    }
    
    TEST_GROUP(JDOJ1348){
        
    };
    
    IGNORE_TEST(JDOJ1348, main){
        FILE *fin = freopen("./data/jdoj1348.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file jdoj1348.txt");
            return;
        }
        main();
        fclose(fin);
    }
    
    TEST(JDOJ1348, case1){
        reverseOrder=0;
        
        int a[]={4, 2, 5, 3};
        int size = sizeof(a)/sizeof(int);
        int *temp = new int[size];
        mergesort(a, 0, size, temp);
        delete[] temp;
        
        //for(int i=0; i<size; i++)
        //    printf("%d\n", a[i]);
        
        LONGS_EQUAL(3, reverseOrder);
    }
    
    TEST(JDOJ1348, case2){
        reverseOrder=0;
        
        int a[]={7, 5, 6, 4};
        int size = sizeof(a)/sizeof(int);
        int *temp = new int[size];
        mergesort(a, 0, size, temp);
        delete[] temp;
        
        //for(int i=0; i<size; i++)
        //    printf("%d\n", a[i]);
        
        LONGS_EQUAL(5, reverseOrder);
    }
    
}//namespace
