//
//  HDOJ1010.cpp
//  Tempter of the Bone
//  http://acm.hdu.edu.cn/showproblem.php?pid=1010
//  Created by wolf76 on 13-8-10.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <cassert>
#include <iostream>
#include <stack>
using namespace std;

const int MAX = 7;
char maze[MAX][MAX];
int dirs[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

struct Position {
    int x;
    int y;
    int dir; //0,1,2,3,E,S,W,N
};

int sx,sy,dx,dy;

enum PosState {
    bSucceed,
    bGreen,
    bRed
};

PosState getPosState(int x, int y, int n, int m, int t, int steps)
{
    if(x<0 || x>= m || y <0 || y>=n)
        return bRed;
    
    int temp = t - steps - abs(x-dx) - abs(y-dy);
    if (temp<0 || temp & 1)
        return bRed;
    
    if(maze[y][x] == 'D'){
        if (steps == t)
            return bSucceed;
        else
            return bRed;
    }
    
    if (maze[y][x] == 'S'  ||
        maze[y][x] == 'X')
        return bRed;
       
    return bGreen;
}

bool survive(int n, int m, int t)
{
    assert(n<MAX && m<MAX && n>1 && m>1);

    int temp = t - abs(sx-sy) - abs(dx-dy);
    if (temp<0 || temp & 1)
        return false;

    Position start = {sx, sy, 0};
    stack<Position> s;
    s.push(start);
    
    while (!s.empty()) {
        Position& pos = s.top();
        int x = pos.x;
        int y = pos.y;

        //Get the next position
        int dir = pos.dir;
        bool bFoundNextStep = false; 
        while (dir < 4 && !bFoundNextStep)
        {
            int newx = x + dirs[dir][0];
            int newy = y + dirs[dir][1];
            
            PosState state = getPosState(newx, newy, n, m, t, (int)s.size());
            if (state == bSucceed)
                return true;
            else if (state == bGreen){
                bFoundNextStep = true;
                
                pos.dir = dir + 1; // Next direction to step
                Position nextPos = {newx,newy,0};
                s.push(nextPos);
                maze[newy][newx] = 'X';
            }
            else
                dir += 1;
        }
        
        if (!bFoundNextStep) {
            maze[y][x] = '.';
            s.pop(); // Cannot found the steps
        }
    }
    
    return false;
}

int HDOJ1010(int argc, char* argv[])
{
    int n,m,t;
    while (cin>>n>>m>>t)
    {
        if( n==0 && m==0 && t==0 )
            break;
        
        for (int i=0; i<n; ++i)
            for (int j=0;j<m; ++j) {
                cin >> maze[i][j];
                if(maze[i][j]=='S')
                    sx=j,sy=i;
                else if (maze[i][j]=='D')
                    dx=j,dy=i;
            }
        
        bool ret = survive(n, m, t);
        cout << (ret? "YES" : "NO") << endl;
    }
    
    return 0;
}

void print(int n, int m) // n->row, m->col
{
    cout << "\n";
    for(int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j)
            cout << maze[i][j];
        cout << '\n';
    }
    cout << endl;
}

/////////////////////////////
//   TESTS
/////////////////////////////

TEST_GROUP(HDOJ1010)
{
    
};


IGNORE_TEST(HDOJ1010, sss)
{
    int my_array[5] = {1, 2, 3, 4, 5};
    
    for(int x : my_array)
        cout << x << " ";
    cout << endl;
}

TEST(HDOJ1010, surviveYES)
{
    for(int i=0; i<MAX; ++i)
        for (int j=0; j<MAX; ++j)
            maze[i][j] = '.';
    
    int n = 3, m = 4;
    sx=sy=0;
    dx=3,dy=2;
    
    maze[0][0] = 'S';
    maze[2][3] = 'D';
    maze[0][2] = maze[1][2] = 'X';
    
    print(n, m);
    
    bool ret = survive(n, m, 5);
    CHECK_TRUE(ret);
}

TEST(HDOJ1010, surviveNO)
{
    for(int i=0; i<MAX; ++i)
        for (int j=0; j<MAX; ++j)
            maze[i][j] = '.';
    
    int n = 4, m = 4;
    sx=sy=0;
    dx=3,dy=2;
    
    maze[0][0] = 'S';
    maze[2][3] = 'D';
    maze[0][2] = maze[1][2] = maze[2][2] = 'X';
    
    print(n, m);
    
    bool ret = survive(n, m, 5);
    CHECK_FALSE(ret);
}

TEST(HDOJ1010, surviveYES2)
{
    for(int i=0; i<MAX; ++i)
        for (int j=0; j<MAX; ++j)
            maze[i][j] = '.';
    
    int n = 4, m = 4;
    sx=sy=0;
    dx=3,dy=2;
    
    maze[0][0] = 'S';
    maze[2][3] = 'D';
    maze[0][2] = maze[1][2] = maze[2][2] = 'X';
    
    print(n, m);
    
    bool ret = survive(n, m, 7);
    CHECK_TRUE(ret);
}