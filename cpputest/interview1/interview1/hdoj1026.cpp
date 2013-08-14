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
#include <string>
using namespace std;

namespace HDOJ1026 {

const int MAX = 100;

char maze[MAX][MAX];
int N;
int M;

typedef struct Position{
    Position(int tagx, int tagy):x(tagx), y(tagy){}
    int x;
    int y;
}Position;

int dir[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<Position> ShortestPath;
int ShortestTime = 0;

void dfs(int x, int y, vector<Position>& path, int& ti)
{
    if (x<0 || x>=M || y<0 || y>=N)
        return;

    for (int i=0; i<4; i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
                
        if (maze[ny][nx] == '.') {
            path.push_back(Position(nx, ny));
            ++ti;
           
            if (nx==M-1 && ny==N-1) {
                if (ShortestTime == 0 || ti < ShortestTime ) {
                    ShortestTime = ti;
                    ShortestPath = path;
                }
            }
            
            maze[ny][nx] = 'X';
            
            dfs(nx, ny, path, ti);
            
            path.pop_back();
            maze[ny][nx] = '.';
            --ti;
        }
        else if (maze[ny][nx] >= '1' && maze[ny][nx] <='9') {
            int fighting = maze[ny][nx] - '0' + 1;
            ti += fighting;
            for (int j=0; j<fighting; ++j)
                path.push_back(Position(nx, ny));
            
            if (nx==M-1 && ny==N-1) {
                if (ShortestTime == 0 || ti < ShortestTime ) {
                    ShortestTime = ti;
                    ShortestPath = path;
                }
            }
            
            maze[ny][nx] = 'X';
            
            dfs(nx, ny, path, ti);
            
            for (int j=0; j<fighting; ++j)
                path.pop_back();
        
            maze[ny][nx] = fighting + '0';
            ti -= fighting;
        }
        else if(maze[ny][nx] == 'X'){
            
        }
        else
            assert("Wrong value");
    }
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
        ShortestTime = 0;
        MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
    }
    
    void teardown(){
        MemoryLeakWarningPlugin::turnOnNewDeleteOverloads();
    }
};

TEST(HDOJ1026, dfs){
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
    int ti=0;
    dfs(0, 0, path, ti);
    cout << ShortestTime;
    
    for (auto e: ShortestPath) {
        cout << "(" <<e.y << "," << e.x <<")\n" ;
    }
    cout << endl;
}
    
}// namespace HDOJ1026