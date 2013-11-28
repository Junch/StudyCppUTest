//
//  jdoj1371.cpp
//  interview1
//  http://ac.jobdu.com/problem.php?pid=1371
//  Created by wolf76 on 11/28/13.
//  Copyright (c) 2013 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <stdio.h>
using namespace std;

namespace JDOJ1371 {
    
    void adjustSmallHeap(int a[], int heapLength, int i)
    {
        int l = 2*i+1;
        int r = l+1;
        
        int smallest = i;
        if (l<heapLength && a[l]<a[i])
            smallest = l;
        
        if (r<heapLength && a[r]<a[smallest])
            smallest = r;
        
        if (smallest != i) {
            int temp = a[i];
            a[i] = a[smallest];
            a[smallest] = temp;
            
            adjustSmallHeap(a, heapLength, smallest);
        }
    }
    
    // Get the least k numbers
    void heapSort(int a[], int length, int k)
    {
        // Setup a heap
        for (int i=length/2-1; i>=0; --i)
            adjustSmallHeap(a, length, i);
        
        for (int i=length-1; i>0 && i>=length-k; --i) {
            int temp = a[i];
            a[i] = a[0];
            a[0] = temp;
            
            adjustSmallHeap(a, i, 0);
        }
    }
    
    int main()
    {
        int length;
        int k;
        while (scanf("%d %d", &length, &k) == 2){
            int *a = new int[length];
            for (int i=0; i<length; ++i)
                scanf("%d", &a[i]);
            
            heapSort(a, length, k);
            
            for (int i=length-1; i>length-k; --i)
                printf("%d ", a[i]);
            printf("%d\n", a[length-k]);
            delete[] a;
        }
        
        return 0;
    }
    
//    void adjustBigHeap(int a[], int heapLength, int i)
//    {
//        int l = 2*i+1;
//        int r = l+1;
//        
//        int largest = i;
//        if (l<heapLength && a[l]>a[i])
//            largest = l;
//        
//        if (r<heapLength && a[r]>a[largest])
//            largest = r;
//        
//        if (largest != i) {
//            int temp = a[i];
//            a[i] = a[largest];
//            a[largest] = temp;
//            
//            adjustBigHeap(a, heapLength, largest);
//        }
//    }
    
    // A complete heap sort
    void heapSort(int a[], int length)
    {
        // Setup a heap
        for (int i=length/2-1; i>=0; --i)
            adjustSmallHeap(a, length, i);
        
        // Get an element and adjust the heap
        for (int i=length-1; i>0; --i) {
            int temp = a[i];
            a[i] = a[0];
            a[0] = temp;
            
            adjustSmallHeap(a, i, 0);
        }
    }

    
    TEST_GROUP(JDOJ1371){
        
    };
    
    IGNORE_TEST(JDOJ1371, main){
        FILE *fin = freopen("./data/jdoj1371.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file jdoj1371.txt");
            return;
        }
        main();
        fclose(fin);
    }
    
    IGNORE_TEST(JDOJ1371, case1){
        int a[] = {1, 3, 4, 5, 7, 2, 6, 8, 0};
        int length = sizeof(a)/sizeof(int);
        heapSort(a, length);
        
        for (int i=0; i<length-1; i++)
            printf("%d ", a[i]);
        printf("%d\n", a[length-1]);
    }
    
    IGNORE_TEST(JDOJ1371, case2){
        int a[] = {1, 3, 4, 5, 7, 2, 6, 8, 0};
        int length = sizeof(a)/sizeof(int);
        int k = 3;
        heapSort(a, length, 3);
        
        for (int i=length-1; i>length-k; --i)
            printf("%d ", a[i]);
        printf("%d\n", a[length-k]);
    }
    
}//namespace

