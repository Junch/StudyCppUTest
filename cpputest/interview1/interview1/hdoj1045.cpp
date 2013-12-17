//
//  hdoj1045.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1045
//  Created by wolf76 on 13-8-27.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace HDOJ1045 {
    char board[4][4];
    int  citySize;
    int  maximum=0;
    int  count=0;
    
    bool place(int index){
        assert(index < citySize*citySize);
        int row = index/citySize;
        int col = index % citySize;
        
        if (board[row][col]=='X')
            return false;
        
        return true;
    }
    
    void dfs(int index){
        assert(index <= citySize*citySize);
        if (index == citySize*citySize){
            if (count>maximum)
                maximum = count;
            
            return;
        }
        
        // place a blockhouse or not to place the blockhouse
        dfs(index+1);
        if (place(index)) {
            int row = index/citySize;
            int col = index % citySize;
            
            board[row][col]='X';
            ++count;
            
//            int i=row+1;
//            for (;i<citySize;++i)
//                if (board[i][col]=='.')
//                    board[i][col]='X';
//                else if(board[i][col]=='X')
//                    break;
//
//            int j=col+1;
//            for (;j<citySize;++j)
//                if (board[row][j]=='.')
//                    board[row][j]='X';
//                else if(board[row][j]=='X')
//                    break;
            
            int i=row+1;
            while (i<citySize && board[i][col]=='.')
                board[i++][col]='X';
            
            int j=col+1;
            while (j<citySize && board[row][j]=='.')
                board[row][j++]='X';
            
            dfs(index+1);
            
            board[row][col]='.';
            for (int k=row+1; k<i; k++)
                board[k][col]='.';
            for (int k=col+1; k<j; k++)
                board[row][k]='.';
            --count;
        }
    }
    
    
    int main()
    {
        int n;
        while (scanf("%d", &n) && n) {            
            for (int i=0;i<n;++i)
                scanf("%s",board[i]);
    
            citySize = n;
            maximum = 0;
            dfs(0);
            printf("%d\n",maximum);
        }
        
//        while (cin>>n && n) {
//            for (int i=0;i<n;++i)
//                for (int j=0; j<n;++j)
//                    cin >> board[i][j];
//
//            citySize = n;
//            maximum = 0;
//            dfs(0);
//            printf("%d\n",maximum);
//        }
        
        return 0;
    }
    
    TEST_GROUP(HDOJ1045){
        
    };
    
    IGNORE_TEST(HDOJ1045, main){
        FILE *fin = freopen("./data/hdoj1045.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file hdoj1045.txt");
            return;
        }
        main();
        fclose(fin);
    }
    
    TEST(HDOJ1045, case1){
        memset(board, '.', sizeof(board));
        board[1][1]=board[1][2]='X';
        board[2][1]=board[2][2]='X';
        citySize = 3;
        maximum = 0;
        dfs(0);
        LONGS_EQUAL(2, maximum);
    }
    
    TEST(HDOJ1045, case2){       
        memset(board, '.', sizeof(board));
        board[0][1]='X';
        board[2][0]=board[2][1]='X';
        citySize = 4;
        maximum = 0;
        dfs(0);
        LONGS_EQUAL(5, maximum);
    }
    
}//namespace
