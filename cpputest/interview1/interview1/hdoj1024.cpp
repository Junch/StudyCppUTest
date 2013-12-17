//
//  hdoj1024.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1024
//  http://blog.163.com/sentimental_man/blog/static/7300161820119109533172/
//  Created by wolf76 on 13-8-16.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <algorithm>
#include <fstream>
#include <CppUTest/TestHarness.h>
#include <unistd.h>
using namespace std;

namespace HDOJ1024 {
    
    int dp[2][1000001];
    
    int maxsum(int e[], int n, int m)
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
        // int e[1000001] causes STACK_OVERFLOW on HDOJ
        int* e = new int[1000001];
        while (scanf("%d%d", &m, &n) != EOF) {
            for (int i=1; i<=n; ++i)
                scanf("%d", &e[i]);
            int ret = maxsum(e, n, m);
            printf("%d\n", ret);
        }
        delete[] e;
    
        return 0;
    }
    
    TEST_GROUP(HDOJ1024){
        
        
    };
    
    TEST(HDOJ1024, main){
        FILE *fin = freopen("./data/hdoj1024.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file hdoj1024.txt");
            return;
        }
        
        // Use the dup and dup2 instead of the freopen below, because
        // I want to get the output in the Output window of xcode.
        char templ[] = "/tmp/cjXXXXXX";
        int fd = mkstemp(templ);
        int oldstdout = dup(STDOUT_FILENO);
        dup2(fd, STDOUT_FILENO);
        
        main();
        fclose(fin); // Close the file stdin
        
        dup2(oldstdout, STDOUT_FILENO); // Restore the previous STDOUT
        close(oldstdout);
        close(fd);
        
        ifstream fs(templ);
        unlink(templ); // Erase the temp file when the file is closed
        int num;
        fs >> num;
        LONGS_EQUAL(6, num);
        fs >> num;
        LONGS_EQUAL(8, num);
        
        //int oldstdin = dup(STDIN_FILENO);
        //int fd = open("./data/hdoj1024.txt", O_RDONLY);
        //dup2(fd, STDIN_FILENO);
        //main();
        //dup2(oldstdin, STDIN_FILENO);
        //close(oldstdin);
        //close(fd);
    }
    
    TEST(HDOJ1024, case1){
        int a[] = {0, 6, -1, 5, 4, -7};
        int n = maxsum(a, 5, 1);
        LONGS_EQUAL(14, n);
    }
    
    TEST(HDOJ1024, case2){
        int a[] = {0, 0, 6, -1, 1, -6, 7, -5};
        int n = maxsum(a, 7, 1);
        LONGS_EQUAL(7, n);
    }
    
    TEST(HDOJ1024, case3){
        int a[] = {0, -1, 4, -2, 3, -2, 3};
        int n = maxsum(a, 6, 2);
        LONGS_EQUAL(8, n);
    }

}
