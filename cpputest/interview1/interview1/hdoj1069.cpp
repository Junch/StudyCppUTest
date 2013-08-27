//
//  hdoj1069.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1069
//  Created by wolf76 on 8/26/13.
//  Copyright (c) 2013 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

namespace HDOJ1069 {
    
    struct Block {
        Block(int _x,int _y,int _z):x(_x),y(_y),z(_z){
            if( x < y)
                std::swap(x, y);
            if (y < z) {
                std::swap(y, z);
                if(x < y)
                    std::swap(x, y);
            }
        }
        int x,y,z; // x>>y>>z
    };
    typedef vector<Block> BLOCKS;
    
    struct Section {
        Section(int w, int l, int h):width(w),length(l),height(h){
            assert(w>=l);
        }
        
        bool operator < (const Section& s) const {
            if (width != s.width) return width < s.width;
            if (length != s.length) return length < s.length;   
            return height > s.height;
        }
        
        int width, length, height; // Width >= length
    };
    typedef vector<Section> SECTIONS;
    
    // S(i) = max(S0,S1,...,S(i-1)) + height(i)
    int maxHeight(const BLOCKS& blocks){
        SECTIONS ss;
        
        for (size_t i=0; i<blocks.size(); ++i) {
            const Block& b = blocks[i];
            ss.push_back(Section(b.x, b.y, b.z));
            if (b.y != b.z)
                ss.push_back(Section(b.x, b.z, b.y));
            if (b.x != b.y)
                ss.push_back(Section(b.y, b.z, b.x));
        }
        
        sort(ss.begin(), ss.end());
        
        vector<int> s(ss.size());
        
        for (int i=0; i<ss.size(); ++i) {
            s[i]= ss[i].height;
            
            int max = 0;
            for (int j=0; j<i; ++j) {
                if(ss[i].width > ss[j].width && ss[i].length > ss[j].length){
                    if (s[j] > max)
                        max= s[j];
                }
            }
            
            s[i] += max;
        }
        
        int maxh = *max_element(s.begin(), s.end());
        return maxh;
    }
    
    int main()
    {
        int cases=0;
        int n;
        int a,b,c;
        while (scanf("%d", &n) && n) {
            BLOCKS bs;
            for (int i=0; i<n; ++i) {
                scanf("%d%d%d", &a,&b,&c);
                bs.push_back(Block(a,b,c));
            }
            
            printf("Case %d: maximum height = %d\n", ++cases, maxHeight(bs));
        }
                
        return 0;
    }
    
    TEST_GROUP(HDOJ1069){
        
    };
    
    IGNORE_TEST(HDOJ1069, main){
        FILE *fin = freopen("./data/hdoj1069.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file hdoj1069.txt");
            return;
        }
        main();
        fclose(fin);
    }
    
    TEST(HDOJ1069, block){
        Block b(26, 53, 58);
        LONGS_EQUAL(58, b.x);
        LONGS_EQUAL(53, b.y);
        LONGS_EQUAL(26, b.z);
        
        Block b2(53, 58, 26);
        LONGS_EQUAL(58, b2.x);
        LONGS_EQUAL(53, b2.y);
        LONGS_EQUAL(26, b2.z);
    }
    
    TEST(HDOJ1069, case1){
        BLOCKS bs;
        bs.push_back(Block(10, 20, 30));
        LONGS_EQUAL(40, maxHeight(bs));
    }
    
    TEST(HDOJ1069, case2){
        BLOCKS bs;
        bs.push_back(Block(6, 8, 10));
        bs.push_back(Block(5, 5, 5));
        LONGS_EQUAL(21, maxHeight(bs));
    }
    
    TEST(HDOJ1069, case3){
        BLOCKS bs;
        bs.push_back(Block(4, 3, 2));
        bs.push_back(Block(4, 3, 5));
        LONGS_EQUAL(12, maxHeight(bs));
    }
    
    TEST(HDOJ1069, case4){
        BLOCKS bs;
        bs.push_back(Block(2, 2, 2));
        bs.push_back(Block(4, 4, 5));
        bs.push_back(Block(4, 4, 2));
        LONGS_EQUAL(8, maxHeight(bs));
    }
    
    TEST(HDOJ1069, case5){
        BLOCKS bs;
        bs.push_back(Block(2, 2, 2));
        bs.push_back(Block(4, 4, 5));
        bs.push_back(Block(4, 4, 3));
        LONGS_EQUAL(10, maxHeight(bs));
    }
    
}//namespace
