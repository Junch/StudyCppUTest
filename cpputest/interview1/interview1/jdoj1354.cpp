//
//  jdoj1354.cpp
//  interview1
//  http://ac.jobdu.com/problem.php?pid=1354
//  Created by wolf76 on 11/26/13.
//  Copyright (c) 2013 com.wolf76. All rights reserved.
//
#include <CppUTest/TestHarness.h>
#include <stdio.h>
using namespace std;

namespace JDOJ1354 {
    
    void calc(int s)
    {
        bool bExist=false;
        int i = 1; //low index
        int j = 2; //high index
        int sum = 3;
       
        while (i < j) {
            if (sum < s)
                sum += ++j;
            else if(sum > s)
                sum -= i++;
            else{
                bExist = true;
                for (int k=i; k<j; k++)
                    printf("%d ", k);
                printf("%d\n", j);
                sum -= i++;
            }
        }
        
        if (!bExist)
            printf("Pity!\n");
        
        printf("#\n");
    }
    
    
    int main()
    {
        int s;
        while (scanf("%d", &s) != EOF && s >= 0) //s=0 is a legal input
            calc(s);
        
        return 0;
    }
    
    TEST_GROUP(JDOJ1354){
        
    };
    
    IGNORE_TEST(JDOJ1354, main){
        FILE *fin = freopen("./data/jdoj1354.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file jdoj1354.txt");
            return;
        }
        main();
        fclose(fin);
    }
    
    IGNORE_TEST(JDOJ1354, case1){
        calc(5);
        calc(100);
        calc(0);
    }
    
}//namespace

