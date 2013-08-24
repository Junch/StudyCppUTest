//
//  hdoj1058.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1058
//  Created by wolf76 on 13-8-22.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <iostream>
#include <cassert>
#include <sstream>
using namespace std;

namespace JDOJ1058 {
    
#define N 5843
    uint64_t F[N];
    
    uint64_t min(uint64_t a,uint64_t b,uint64_t c,uint64_t d){
        uint64_t mini = (a<b)?a:b;
        mini = (mini<c)?mini:c;
        mini = (mini<d)?mini:d;
        return mini;
    }
    
    // F(n)=min(F(i)*2,F(j)*3,F(k)*5,F(m)*7)
    // i,j,k,m 只有在本项被选中后才移动
    void humbleNumber(int n) {
        assert(n<N);
        
        int i,j,k,m;
        i=j=k=m=1;
        
        F[1] = 1;
        for (int r=2; r<=n; ) {
            uint64_t a =min(F[i]*2, F[j]*3, F[k]*5, F[m]*7);
            
            if(a == F[i]*2)
                ++i;
            else if(a == F[j]*3)
                ++j;
            else if(a == F[k]*5)
                ++k;
            else if(a == F[m]*7)
                ++m;
            
            if (a > F[r-1]) {
                F[r] = a;
                ++r;
            }
        }
    }
    
    string StringFromNum(int n){
        assert(n>0);
        stringstream ss;
        
        int k = n%100;
        if (k == 11 || k == 12 || k==13)
            ss << n << "th";
        else {
            switch (n%10) {
                case 1:
                    ss << n << "st";
                    break;
                case 2:
                    ss << n << "nd";
                    break;
                case 3:
                    ss << n << "rd";
                    break;
                default:
                    ss << n << "th";
                    break;
            }
        }
        
        string ret;
        ss >> ret;
        return ret;
    }
    
    int main() {
        humbleNumber(5842);
        
        int n;
        while (cin >> n && n) {
            printf("The %s humble number is %lld.\n", StringFromNum(n).c_str(), F[n]);
        }
        
        return 0;
    }
    
    
    TEST_GROUP(JDOJ1058){
        
    };
    
    IGNORE_TEST(JDOJ1058, main){
        FILE *fin = freopen("./data/hdoj1058.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file hdoj1058.txt");
            return;
        }
        main();
    }
    
    TEST(JDOJ1058, case1){
        humbleNumber(23);
        LONGS_EQUAL(32, F[23]);
    }
    
}//namespace