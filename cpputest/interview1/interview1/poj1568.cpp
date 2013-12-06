//
//  poj1568.cpp
//  Find the Winning Move
//  http://poj.org/problem?id=1568
//  Created by wolf76 on 12/3/13.
//  Copyright (c) 2013 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <stdio.h>
#include <string.h>

namespace POJ1568 {
    
#define INF 100000
    
    
    class Game {
    public:
        Game();
        void init(char buffer[]);
        void print();
        bool over(int x, int y);
        int  minimax(int type, int x, int y, int alpha, int beta);
        bool solve(int& x, int& y);
        
    private:
        char board[4][4];
        int  chess;
    };
    
    
    Game::Game():chess(0)
    {
        ::memset(board, '.',sizeof(board));
    }
    
    void Game::print()
    {
        printf("\n");
        for (int i=0; i<4; ++i){
            for (int j=0; j<4; ++j) {
                printf("%c", board[i][j]);
            }
            printf("\n");
        }
    }
    
    void Game::init(char buffer[])
    {
        int i,j;
        for (int k=0; k<16; k++) {
            i=k/4;
            j=k%4;
            board[i][j]=buffer[k];
            if (buffer[k] == 'x' || buffer[k] == 'o')
                ++chess;
        }
    }
    
    bool Game::over(int x, int y)
    {
        if (x==-1 && y==-1) // During initialization
            return false;
        
        int k=0;
        for (int i=0; i<4; i++) {
            if (board[i][y] == 'x')
                ++k;
            else if(board[i][y] == 'o')
                --k;
        }
        
        if (k==4 || k==-4)
            return true;
        
        k=0;
        for (int i=0; i<4; i++) {
            if (board[x][i] == 'x')
                ++k;
            else if(board[x][i] == 'o')
                --k;
        }
        
        if (k==4 || k==-4)
            return true;
        
        if (x==y){
            k=0;
            for (int i=0; i<4; i++) {
                if (board[i][i] == 'x')
                    ++k;
                else if(board[i][i] == 'o')
                    --k;
            }
            
            if (k==4 || k==-4)
                return true;
        }
        
        if (x+y==3){
            k=0;
            for (int i=0; i<4; i++) {
                if (board[i][3-i] == 'x')
                    ++k;
                else if(board[i][3-i] == 'o')
                    --k;
            }
            
            if (k==4 || k==-4)
                return true;
        }
        
        return false;
    }
    
    int Game::minimax(int type, int x, int y, int alpha, int beta)
    {
        //Check whether the game is over
        if (over(x, y)) // Game is over
            return type==1? -INF:INF;
        
        if (chess == 16) // No winner
            return 0;
        
        if (type) { // MAX Node
            for (int i=0; i<4; i++) {
                for (int j=0; j<4; j++) {
                    if (board[i][j] == '.') {
                        board[i][j] = 'x';
                        ++chess;
                        int score = minimax(0, i, j, alpha, beta);
                        if (score > alpha)
                            alpha = score;
                        
                        board[i][j] = '.';
                        --chess;
                        if (alpha >= beta)
                            return alpha;
                    }
                }
            }
            
            return alpha;
        }
        else{ // MIN Node
            for (int i=0; i<4; i++) {
                for (int j=0; j<4; j++) {
                    if (board[i][j] == '.') {
                        board[i][j] = 'o';
                        ++chess;
                        int score = minimax(1, i, j, alpha, beta);
                        if (score < beta)
                            beta = score;
                        
                        board[i][j] = '.';
                        --chess;
                        if (alpha >= beta)
                            return beta;
                    }
                }
            }
            return beta;
        }
    }
    
    bool Game::solve(int& x, int& y)
    {
        int alpha = -INF;
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                if (board[i][j] == '.') {
                    board[i][j] = 'x';
                    chess++;
                    
                    int ret = minimax(0, i, j, alpha, INF);
                    if (ret > alpha)
                        alpha = ret;
                    
                    if (alpha == INF){
                        x = i;
                        y = j;
                        return true;
                    }
                    
                    board[i][j] = '.';
                    chess--;
                }
            }
        }
        
        return false;
    }
    
    int main()
    {
        char temp[5];
        while(scanf("%s", temp) != EOF && temp[0]=='?')
        {
            char buffer[16];

            for (int i=0; i<4; i++) {
                scanf("%s", temp);
                memcpy(buffer+4*i, temp, 4);
            }
            
            Game g;
            g.init(buffer);
            //g.print();
            
            int x, y;
            if (g.solve(x, y))
                printf("(%d,%d)\n", x, y);
            else
                printf("#####\n");
        }
        
        return 0;
    }
    
    TEST_GROUP(POJ1568){
        
    };
    
    TEST(POJ1568, main){
        FILE *fin = freopen("./data/poj1568.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file poj1568.txt");
            return;
        }
        main();
        fclose(fin);
    }
    
    TEST(POJ1568, over){
        Game g;
        char buffer[] = "..o.xxxx........";
        g.init(buffer);
        CHECK_TRUE(g.over(1,0));
        
        char buffer2[] = "..o.oooo........";
        g.init(buffer2);
        CHECK_TRUE(g.over(1,0));
        
        char buffer3[] = "..o.oo.o........";
        g.init(buffer3);
        CHECK_FALSE(g.over(1,0));

        char buffer4[] = "x....x....x....x";
        g.init(buffer4);
        CHECK_TRUE(g.over(0,0));
        
        char buffer5[] = "...x..x..x..x...";
        g.init(buffer5);
        CHECK_TRUE(g.over(1,2));
    }
    
    TEST(POJ1568, minimax_win){
        Game g;
        char buffer[] = "xx.x.ooo........";
        g.init(buffer);
        int alpha = g.minimax(1, -1, -1, -INF, INF);
        LONGS_EQUAL(INF, alpha);
    }
    
    TEST(POJ1568, minimax_fail){
        Game g;
        char buffer[] = "ooo..xx.xx.....";
        g.init(buffer);
        int alpha = g.minimax(0, 2, 1, -INF, INF);
        LONGS_EQUAL(-INF, alpha);
    }
    
    TEST(POJ1568, minimax_draw){
        Game g;
        char buffer[] = "xoxooxoxxooox...";
        g.init(buffer);
        int alpha = g.minimax(0, -1, -1, -INF, INF);
        LONGS_EQUAL(0, alpha);
    }
    
    TEST(POJ1568, minimax_win3){
        Game g;
        char buffer[] = "o..."
                        ".ox."
                        ".xxx"
                        "xooo";
        g.init(buffer);
        int alpha = g.minimax(1, 0, 1, -INF, INF);
        LONGS_EQUAL(INF, alpha);
        int x, y;
        CHECK_TRUE(g.solve(x, y));
        LONGS_EQUAL(0, x);
        LONGS_EQUAL(1, y);
    }
}//namespace
