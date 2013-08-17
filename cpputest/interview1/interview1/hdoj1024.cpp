//
//  hdoj1024.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1024
//  http://blog.163.com/sentimental_man/blog/static/7300161820119109533172/
//  Created by wolf76 on 13-8-16.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <algorithm>
using namespace std;

namespace HDOJ1024 {
    
    int dp[2][1000001];
    
    int maxsum(int e[], int n /* n element */, int m /* m segments */)
    {
        int t=1;
        
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<=m; ++i) {
            dp[t][i] = dp[1-t][i-1]+ e[i]; //对角线上的值
            int max = dp[1-t][i-1]; // 非常巧妙，max代表了i-1那一行的最大值
            for (int j=i+1; j<=n-m+i; ++j) {
                max = std::max(max, dp[1-t][j-1]);
                dp[t][j] = std::max(dp[t][j-1], max) + e[j];
            }
            t=1-t;
        }
        
        t=1-t;
        
        int res = dp[t][m];
        for (int j=m+1; j<=n; ++j) {
            if (res < dp[t][j])
                res = dp[t][j];
        }
        return res;
    }
    
    int main()
    {
        int m, n;
        int e[1000001];
        while (scanf("%d%d", &m, &n) != EOF) {
            for (int i=1; i<=n; ++i)
                scanf("%d", &e[i]);
            int ret = maxsum(e, n, m);
            printf("%d\n", ret);
        }
        
        return 0;
    }
    
    TEST_GROUP(HDOJ1024){
        
        
    };
    
    TEST(HDOJ1024, case3){
        int a[] = {0, 6, -1, 5, 4, -7};
        int n = maxsum(a, 5, 1);
        LONGS_EQUAL(14, n);
    }
    
    TEST(HDOJ1024, case4){
        int a[] = {0, 0, 6, -1, 1, -6, 7, -5};
        int n = maxsum(a, 7, 1);
        LONGS_EQUAL(7, n);
    }
    
    TEST(HDOJ1024, case5){
        int a[] = {0, -1, 4, -2, 3, -2, 3};
        int n = maxsum(a, 6, 2);
        LONGS_EQUAL(8, n);
    }

}
