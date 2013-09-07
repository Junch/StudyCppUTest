//
//  hdoj1059.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1059
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <iostream>
using namespace std;

namespace HDOJ1059DFS {
    int marbles[7];
    int total;
    bool bFound = false;
    
    void dfs(int i, int v){
        if (v==0) {
            bFound = true;
            return;
        }
        
        if (i==7)
            return;
        
        for (int j=0; j<=marbles[i]; ++j) {
            int w = v-j*i;
            if (w < 0)
                break;
            
            dfs(i+1, w);
            if (bFound)
                break;
        }
    }
    
    bool divide(){
        total = 0 ;
        bFound = false;
        for (int i=1; i<7;++i){
            if (marbles[i] == 0)
                continue;
            
            total += i*marbles[i];
        }

        if (total % 2)
            return false;
        
        total /= 2;
        
        dfs(1, total);
        return bFound;
    }
       
    int main()
    {
        int cases=1;
        
        while (true) {
            int i=1;
            while (i<=6)
                cin >> marbles[i++];
            
            i=1;
            while(i<=6 && !marbles[i])
                ++i;
            
            if (i == 7)
                break;
            
            bool ret = divide();
            
            cout<<"Collection #" << cases++ <<":\n";
            if (ret)
                cout<<"Can be divided.\n"<< endl;
            else
                cout<<"Can't be divided.\n"<< endl;
            
        }
        
        
        return 0;
    }
    
    TEST_GROUP(HDOJ1059DFS){
        
    };
    
    IGNORE_TEST(HDOJ1059DFS, main){
        FILE *fin = freopen("./data/hdoj1059.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file hdoj1059.txt");
            return;
        }
        main();
        fclose(fin);
    }
    
    TEST(HDOJ1059DFS, case1){
        memset(marbles, 0, sizeof(marbles));
        marbles[1]=marbles[3]=1;
        marbles[4]=2;
        CHECK_FALSE(divide());
    }
    
    TEST(HDOJ1059DFS, case2){
        memset(marbles, 0, sizeof(marbles));
        marbles[1]=marbles[5]=1;
        marbles[6]=1;
        CHECK_TRUE(divide());
    }
    
}//namespace