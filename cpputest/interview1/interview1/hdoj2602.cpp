//
//  hdoj2602.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=2602
//  http://www.wutianqi.com/?p=533
//  Created by wolf76 on 13-8-18.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <iostream>
using namespace std;

namespace HDOJ2602 {
   
    int bone(int c[], int w[], int n, int v){
        int f[11][11];
        memset(f, 0, sizeof(f));
        
        for (int i=1; i<=n; ++i) {
            for (int j=v; j>0; --j) {
                f[i][j] = f[i-1][j];
                if (j < c[i])
                    continue;
                int t = f[i-1][j-c[i]] + w[i];
                if (f[i-1][j] < t)
                    f[i][j] = t;
            }
        }
        
        return f[n][v];
    }
    
    int bone2(int c[], int w[], int n, int v){
        int f[1001] = {0};
        
        for (int i=1; i<=n; ++i) {
            for (int j=v; j>=c[i]; --j) {
                int t = f[j-c[i]] + w[i];
                if (f[j] < t)
                    f[j] = t;
            }
        }
        
        return f[v];
    }
    
    int main()
    {
        int c[1001];
        int w[1001];
        
        int cases;
        cin >> cases;
        for (int i=0; i<cases; ++i) {
            int n, v;
            cin >> n >> v;
            
            for (int j=1; j<=n; j++)
                cin >> w[j];
            
            for (int j=1; j<=n; j++)
                cin >> c[j];
            
            int ret = bone2(c, w, n, v);
            cout << ret <<endl;
        }
        
        return 0;
    }
    
    TEST_GROUP(HDOJ2602){
        
    };
    
    IGNORE_TEST(HDOJ2602, main){
        FILE *fin = freopen("./data/hdoj2602.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file hdoj2602.txt");
            return;
        }
        main();
        fclose(fin);
    }
    
    TEST(HDOJ2602, case1){
        int w[] = {0,4,5,6};
        int c[] = {0,3,4,5};
        
        int max = bone2(c, w, 3, 10);
        LONGS_EQUAL(11, max);
    }
    
    TEST(HDOJ2602, case2){
        int w[] = {0,1,2,3,4,5};
        int c[] = {0,5,4,3,2,1};
        
        int max = bone2(c, w, 5, 10);
        LONGS_EQUAL(14, max);
    }
}//namespace
