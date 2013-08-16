//
//  hdoj1026.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1026
//  Created by wolf76 on 13-8-14.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <cassert>
#include <iostream>
#include <vector>
#include <sstream> //strstream is deprecated
using namespace std;

namespace HDOJ1026DFS {

const int MAX = 100;

char maze[MAX][MAX];
int N;
int M;

typedef struct Position{
    Position(int tagx, int tagy):x(tagx), y(tagy){}
    int x;
    int y;
}Position;

int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<Position> ShortestPath;

void dfs(int x, int y, vector<Position>& path)
{
    if (x<0 || x>=M || y<0 || y>=N)
        return;
    
    if (ShortestPath.size() != 0 && ShortestPath.size() < path.size())
        return;

    for (int i=0; i<4; i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
                
        if (maze[ny][nx] == '.') {
            path.push_back(Position(nx, ny));
           
            if (nx==M-1 && ny==N-1) 
                if (ShortestPath.size() == 0 || ShortestPath.size() > path.size()) {
                    ShortestPath = path;
            }
               
            maze[ny][nx] = 'X';
            
            dfs(nx, ny, path);
            
            path.pop_back();
            maze[ny][nx] = '.';
        }
        else if (maze[ny][nx] >= '1' && maze[ny][nx] <='9') {
            int fighting = maze[ny][nx] - '0' + 1;
            for (int j=0; j<fighting; ++j)
                path.push_back(Position(nx, ny));
            
            if (nx==M-1 && ny==N-1)
                if (ShortestPath.size() == 0 || ShortestPath.size() > path.size()) {
                    ShortestPath = path;
            }
            
            maze[ny][nx] = 'X';
            
            dfs(nx, ny, path);
            
            for (int j=0; j<fighting; ++j)
                path.pop_back();
        
            maze[ny][nx] = fighting + '0' -1;
        }
        else if(maze[ny][nx] == 'X'){
            
        }
        else
            assert("Wrong value");
    }
}
    
void output()
{
    if (ShortestPath.empty()) {
        cout << "God please help our poor hero.\n";
    }
    else
    {
        printf("It takes %ld seconds to reach the target position, let me show you the way.\n", ShortestPath.size()-1);
        for (size_t i=1, len=ShortestPath.size(); i<len; ++i) {
            if (ShortestPath[i-1].x == ShortestPath[i].x &&
                ShortestPath[i-1].y == ShortestPath[i].y)
                printf("%lds:FIGHT AT (%d,%d)\n",i,
                       ShortestPath[i].y,
                       ShortestPath[i].x);
            else
                printf("%lds:(%d,%d)->(%d,%d)\n",i,
                       ShortestPath[i-1].y,
                       ShortestPath[i-1].x,
                       ShortestPath[i].y,
                       ShortestPath[i].x);
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
        
        ShortestPath.clear();
        vector<Position> path;
        path.push_back(Position(0,0));
        dfs(0, 0, path);
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
    void setup() {
        ShortestPath.clear();
        MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
    }
    
    void teardown(){
        MemoryLeakWarningPlugin::turnOnNewDeleteOverloads();
    }
};
    
    
IGNORE_TEST(HDOJ1026, main){
    main();
}

IGNORE_TEST(HDOJ1026, dfs){
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
    vector<Position> path;
    path.push_back(Position(0,0));
    dfs(0, 0, path);
    
    output();
}

IGNORE_TEST(HDOJ1026, dfsNoAnswer){
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
    vector<Position> path;
    path.push_back(Position(0,0));
    dfs(0, 0, path);
    
    output();
}
    
}// namespace HDOJ1026DFS