//
//  hdoj1051.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1051
//  Created by wolf76 on 13-8-19.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace HDOJ1051 {

    struct Stick {
        Stick(int l, int w):length(l), weight(w), flag(false){
        };
        
        bool operator <(const Stick& s) const {
            return (length != s.length)? length < s.length :
                                         weight < s.weight;
        }
        
        int length;
        int weight;
        bool flag;
    };
    
    int miniumTime(vector<Stick>& ss){
        sort(ss.begin(), ss.end());
        
        int ti = 0;
        for (vector<Stick>::iterator p = ss.begin(); p != ss.end(); ++p) {
            Stick& s1 = *p;
            if (s1.flag)
                continue;
            s1.flag  = true;
            ti += 1;
            
            for (vector<Stick>::iterator q=p+1; q != ss.end(); ++q) {
                Stick& s2 = *q;
                if (s2.flag)
                    continue;
                if (s1.weight <= s2.weight) {
                    s2.flag = true;
                    s1 = s2;
                }
            }
        }
        
        return ti;
    }
    
    int main() {
        int cases, stickNum;
        int length, weight;
        cin >> cases;
        for (int i=0; i<cases; ++i) {
            cin >> stickNum;
            vector<Stick> ss;
            for (int i=0; i<stickNum; ++i) {
                cin >> length >> weight;
                ss.push_back(Stick(length, weight));
            }
            
            int ti = miniumTime(ss);
            cout << ti << endl;
        }

        return 0;
    }
    
    TEST_GROUP(HDOJ1051){
        
    };
    
    IGNORE_TEST(HDOJ1051, main){
        FILE *fin = freopen("./data/hdoj1051.txt", "r", stdin);
        if (fin == NULL) {
            FAIL("Filed to open the test file hdoj1051.txt");
            return;
        }
        main();
    }
    
    TEST(HDOJ1051, case1){
        vector<Stick> ss;
        ss.push_back(Stick(4,9));
        ss.push_back(Stick(5,2));
        ss.push_back(Stick(2,1));
        ss.push_back(Stick(3,5));
        ss.push_back(Stick(1,4));
        
        LONGS_EQUAL(2, miniumTime(ss));
    }
    
    TEST(HDOJ1051, case2){
        vector<Stick> ss;
        ss.push_back(Stick(2,2));
        ss.push_back(Stick(1,1));
        ss.push_back(Stick(2,2));
        
        LONGS_EQUAL(1, miniumTime(ss));
    }
    
    TEST(HDOJ1051, case3){
        vector<Stick> ss;
        ss.push_back(Stick(1,3));
        ss.push_back(Stick(2,2));
        ss.push_back(Stick(3,1));
        
        LONGS_EQUAL(3, miniumTime(ss));
    }

}