//
//  hdoj1059.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1059
//  http://coolsooner.iteye.com/blog/1357539
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <iostream>
#define INF 100000000
using namespace std;

namespace HDOJ1059 {
    
    int f[240005], v;
    
    void complete_pack(int *a, int c, int w) {
        for (int i=c; i<=v;i++)
            a[i] = max(a[i], a[i-c]+w);
    }
    
    void zeroone_pack(int *a, int c, int w) {
        for (int i=v; i>=c; i--)
            a[i] = max(a[i], a[i-c]+w);
    }
    
    void multiple_pack(int *a, int c, int w, int M) {
        if (c*M >=v) {
            complete_pack(a, c, w);
            return;
        }
        
        int k=1;
        while (k < M) {
            zeroone_pack(a, k*c, k*w);
            M = M-k;
            k = 2*k;
        }
        zeroone_pack(a, c*M, w*M);
    }
        
    int main()
    {
        int sum, i, c[7], w[7], m[7],cas = 0;
        while(scanf("%d%d%d%d%d%d", &m[1], &m[2], &m[3], &m[4], &m[5], &m[6]))
        {
            if(m[1] == 0 && m[2] == 0 && m[3] == 0 && m[4] == 0 && m[5] == 0 && m[6] == 0)
                break;
            sum = 0;
            for(i = 1; i <= 6; i++)
            {
                c[i] = w[i] = i;
                sum += c[i] * m[i];
            }
            
            printf("Collection #%d:\n", ++cas);
            if (sum & 1)
                puts("Can't be divided.\n");
            else {
                sum /= 2;
                for (i=1; i<=sum; i++)
                    f[i] = -INF;
                f[0] = 0;
                v = sum;
                for (i=1; i<=6; i++)
                    multiple_pack(f, c[i], w[i], m[i]);
                if (f[v] < 0)
                    puts("Can't be divided.\n");
                else
                    puts("Can be divided.\n");
            }
        }
        
        return 0;
    }
    
    TEST_GROUP(HDOJ1059){
        
    };
    
    IGNORE_TEST(HDOJ1059, main){
        FILE *fin = freopen("./data/hdoj1059.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file hdoj1059.txt");
            return;
        }
        main();
        fclose(fin);
    }
}//namespace