//
//  Chow.cpp
//  test2
//
//  Created by wolf76 on 13-3-3.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <vector>
using namespace std;

bool isChowAble(const vector<int>& vec, int tile)
{
    bool bTilePre2=false;
    bool bTilePre1=false;
    bool bTilePost1=false;
    bool bTilePost2=false;
    
    for(vector<int>::const_iterator iter=vec.begin(); iter!=vec.end(); ++iter)
    {
        if (*iter==tile-2)
            bTilePre2 = true;
        else if(*iter==tile-1)
            bTilePre1=true;
        else if(*iter==tile+1)
            bTilePost1=true;
        else if(*iter==tile+2)
            bTilePost2=true;
    }
    
    if(bTilePre2 && bTilePre1)
        return true;
    else if(bTilePre1 && bTilePost1)
        return true;
    else if(bTilePost1&& bTilePost2)
        return true;
    
    return false;
}

//////////////////////////////////////
//
//    Test code is written first
//
///////////////////////////////////////


TEST_GROUP(TileArray)
{
    
};

TEST(TileArray, cannotChow)
{
    const int a[]={2,3};
    int tile = 5;
    vector<int> vec(a, a+sizeof(a)/sizeof(a[0]));
    CHECK(!isChowAble(vec, tile));
}

TEST(TileArray, ChowAtTheEnd)
{
    const int a[]={2,3};
    int tile = 4;
    vector<int> vec(a, a+sizeof(a)/sizeof(a[0]));
    CHECK(isChowAble(vec, tile));
}

TEST(TileArray, ChowAtTheHead)
{
    const int a[]={2,3};
    int tile = 1;
    vector<int> vec(a, a+sizeof(a)/sizeof(a[0]));
    CHECK(isChowAble(vec, tile));
}

TEST(TileArray, ChowAtTheMiddle)
{
    const int a[]={2,4};
    int tile = 3;
    vector<int> vec(a, a+sizeof(a)/sizeof(a[0]));
    CHECK(isChowAble(vec, tile));
}
