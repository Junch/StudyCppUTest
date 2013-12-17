//
//  HDOJ1010.cpp
//  Tempter of the Bone
//  http://acm.hdu.edu.cn/showproblem.php?pid=1010
//  Created by wolf76 on 13-8-10.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <cassert>
#include <iostream>
#include <stack>
#include <fstream>
#include <CppUTest/TestHarness.h>
#include <sys/time.h>
using namespace std;

namespace HDOJ1010 {

const int MAX = 10;
char maze[MAX][MAX];
int dirs[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

struct Position {
    int x;
    int y;
    int dir; //0,1,2,3,E,S,W,N
};

int n,m,t;
int sx,sy,dx,dy;

enum PosState {
    bSucceed,
    bGreen,
    bRed
};

PosState getPosState(int x, int y, int steps)
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
    
    if (maze[y][x] == 'X')
        return bRed;
       
    return bGreen;
}

bool survive()
{
    assert(n<MAX && m<MAX && n>0 && m>0);

    int temp = t - abs(sx-sy) - abs(dx-dy);
    if (temp<0 || temp & 1)
        return false;

    Position start = {sx, sy, 0};
    stack<Position> s;
    s.push(start);
    maze[sy][sx] = 'X';
    
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
            
            PosState state = getPosState(newx, newy, (int)s.size());
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

int main()
{
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
        
        bool ret = survive();
        cout << (ret? "YES" : "NO") << endl;
    }
    
    return 0;
}

void print() // n->row, m->col
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

IGNORE_TEST(HDOJ1010, HDOJ1010)
{
    timeval t1, t2;
    double elapsedTime;
    
    gettimeofday(&t1, NULL);
    main();
    gettimeofday(&t2, NULL);
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
    elapsedTime +=(t2.tv_usec - t1.tv_usec)/ 1000.0;// us to ms
    cout << elapsedTime << " ms.\n";
}

IGNORE_TEST(HDOJ1010, readfile)
{
    ifstream fs("simple.txt");
    while (fs>>n>>m>>t)
    {
        if( n==0 && m==0 && t==0 )
            break;
        
        for (int i=0; i<n; ++i)
            for (int j=0;j<m; ++j) {
                fs >> maze[i][j];
                if(maze[i][j]=='S')
                    sx=j,sy=i;
                else if (maze[i][j]=='D')
                    dx=j,dy=i;
            }
        
        print();
        bool ret = survive();
        cout << (ret? "YES" : "NO") << endl;
    }
}

TEST(HDOJ1010, surviveYES)
{
    for(int i=0; i<MAX; ++i)
        for (int j=0; j<MAX; ++j)
            maze[i][j] = '.';
    
    n=3, m=4, t=5;
    sx=sy=0;
    dx=3,dy=2;
    
    maze[0][0] = 'S';
    maze[2][3] = 'D';
    maze[0][2] = maze[1][2] = 'X';
       
    bool ret = survive();
    CHECK_TRUE(ret);
}

TEST(HDOJ1010, surviveNO)
{
    for(int i=0; i<MAX; ++i)
        for (int j=0; j<MAX; ++j)
            maze[i][j] = '.';
    
    n=4, m=4, t=5;
    sx=sy=0;
    dx=3,dy=2;

    maze[0][0] = 'S';
    maze[2][3] = 'D';
    maze[0][2] = maze[1][2] = maze[2][2] = 'X';
        
    bool ret = survive();
    CHECK_FALSE(ret);
}

} // namespace