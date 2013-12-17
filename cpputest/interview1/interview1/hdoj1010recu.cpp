//
//  hdoj1010recu.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1010
//  Created by wolf76 on 13-8-12.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <CppUTest/TestHarness.h>
#include <math.h>
#include <sys/time.h>
using namespace std;

namespace HDOJ1010RECU {

int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m;
char a[10][10];
int sx,sy,dx,dy;
int ti,flag;

void DfsSerch(int x,int y,int step)
{
    int temp;
    temp=ti-step-abs(dx-x)-abs(dy-y);
    if (temp<0||temp%2==1) return;

    int tx,ty;
    for(int i=0;i<4;i++)  //方向探索
    {
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        if (a[tx][ty]=='D'&&step==ti-1)
        {
            flag=1;
            return ;
        }
        if (a[tx][ty]=='.'&&
           (tx>=0&&tx<n) &&
           (ty>=0&&ty<m))
        {
            a[tx][ty]='X';  //标记访问
            DfsSerch(tx,ty,step+1);
            a[tx][ty]='.';  //回溯取消标记
            if(flag==1) return;//找到直接返回
        }
    }
}

int main()
{
    while (cin>>n>>m>>ti)
    {
        if( n==0 && m==0 && ti==0 )
            break;
        
        ///////////////////////////////////////
        //输入数据
        int wall=0;
        for (int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='S')
                {
                    sx=i;
                    sy=j;
                }
                if (a[i][j]=='D')
                {
                    dx=i;
                    dy=j;
                }
                if (a[i][j]=='X')
                {
                    wall++;
                }
            }//for-for
        /////////////////////////////////////
        flag=0;
        if (n*m-wall<=ti)
        {
            cout<<"NO"<<endl;
            continue;
        }
        DfsSerch(sx,sy,0);
        if(flag==1)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

/////////////////////////////////////
// TEST
/////////////////////////////////////

TEST_GROUP(HDOJ1010RECU)
{
    
};

IGNORE_TEST(HDOJ1010RECU, HDOJ1010R)
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
}// namespace HDOJ1010RECU