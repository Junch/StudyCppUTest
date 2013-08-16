//
//  hdoj1026.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1026
//  http://www.wutianqi.com/?p=2354
//  Created by wolf76 on 13-8-14.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <cassert>
#include <iostream>
#include <sstream> //strstream is deprecated
#include <queue>
#include <stack>
using namespace std;

namespace HDOJ1026BFS {
    
const int MAX = 100;

int N;
int M;
char maze[MAX][MAX];

int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

typedef struct Node{
    int x,y,px,py,ti;
// The following two versions are OK
//    friend bool operator < (const Node& a,const Node& b)
//    {
//        return a.ti > b.ti;
//    }
    bool operator < (const Node& a) const{
        return ti > a.ti;
    }
    
}Node;

   
Node flags[MAX][MAX];

void reset(){
    for (int i=0; i<N;++i)
        for (int j=0;j<M;++j){
            flags[i][j].ti=-1;
        }
}

bool bfs()
{
    priority_queue<Node> q;
    Node a;
    a.x = a.y = a.ti = a.px = a.py = 0;
    q.push(a);
    flags[0][0]=a;
    
    while (!q.empty()) {
        a = q.top();
        q.pop();
        
        for (int i=0; i<4; ++i) {
            int x = a.x + dir[i][0];
            int y = a.y + dir[i][1];
            int ti = a.ti + 1;
            if (x<0 || x>=M || y<0 || y>=N)
                continue;
            
            if (maze[y][x] == 'X')
                continue;
            
            if (flags[y][x].ti != -1)
                continue;
            
            if(maze[y][x]>='1' && maze[y][x]<='9')
                ti += maze[y][x] - '0';
           
            Node b;
            b.x = x;
            b.y = y;
            b.ti = ti;
            b.px = a.x;
            b.py = a.y;
            q.push(b);
            flags[y][x]=b;
            
            if (x==M-1 && y==N-1)
                return true;
        }//for
    }//while
    
    return false;
}

void output()
{
    if (flags[N-1][M-1].ti == -1) {
        cout << "God please help our poor hero.\n";
    }
    else
    {
        int ti = flags[N-1][M-1].ti;
        printf("It takes %d seconds to reach the target position, let me show you the way.\n", ti);
        
        Node a = flags[N-1][M-1];
        stack<Node> path;
        while (a.x != 0 || a.y != 0) {
            path.push(a);
            a = flags[a.py][a.px];
        }
        
        a = flags[0][0];
        Node b;
        
        while (!path.empty()) {
            b = path.top();
            path.pop();
                        
            printf("%ds:(%d,%d)->(%d,%d)\n",a.ti+1, a.y, a.x, b.y, b.x);
            
            for (int j=a.ti+2; j<=b.ti; ++j)
                printf("%ds:FIGHT AT (%d,%d)\n",j, b.y, b.x);
            a = b;
        }
    }
    cout << "FINISH" << endl;
}

int main()
{
    while (cin >> N >> M) {
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                cin >> maze[i][j];
            }
        }
        
        reset();
        bfs();
        output();
    }
    
    return 0;
}

void print() // n->row, m->col
{
    cout << "\n";
    for(int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j)
            cout << maze[i][j];
        cout << '\n';
    }
    cout << endl;
}

TEST_GROUP(HDOJ1026){
};

IGNORE_TEST(HDOJ1026, main){
    main();
}

IGNORE_TEST(HDOJ1026, bfs1){
    N=5,M=6;
    char p[] = ".XX.1." \
               "..X.2." \
               "2...X." \
               "...XX." \
               "XXXXX.";
    stringstream ss;
    ss << p;
    for (int i=0; i<N; ++i)
        for(int j=0; j<M; ++j){
            ss >> maze[i][j];
        }
    
    print();
    reset();
    bfs();
    output();
 }

IGNORE_TEST(HDOJ1026, bfs2){
    N=5,M=6;
    char p[] = ".XX.1." \
               "..X.2." \
               "2...X." \
               "...XX." \
               "XXXXX1";
    stringstream ss;
    ss << p;
    for (int i=0; i<N; ++i)
        for(int j=0; j<M; ++j){
            ss >> maze[i][j];
        }
    
    print();
    reset();
    bfs();
    output();
}

IGNORE_TEST(HDOJ1026, bfsNoAnswer){
    N=5,M=6;
    char p[] = ".XX..." \
    "..XX1." \
    "2...X." \
    "...XX." \
    "XXXXX.";
    stringstream ss;
    ss << p;
    for (int i=0; i<N; ++i)
        for(int j=0; j<M; ++j){
            ss >> maze[i][j];
        }
    
    print();
    reset();
    bfs();
    output();
}

}// namespace HDOJ1026BFS