//
//  hdoj1003.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1003
//  Created by wolf76 on 13-8-16.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

namespace HDOJ1003 {

struct Node {
    int start, end, sum;
    bool operator < (const Node& n) const {
        return sum < n.sum;
    }
};

Node maxsum(const vector<int>& a)
{
    vector<Node> b;
    b.resize(a.size());
    
    b[0].sum = a[0];
    b[0].start = 0;
    int start = 0;
    for (int i=1, len=(int)a.size(); i<len; ++i) {
        if (b[i-1].sum < 0){
            b[i].sum = a[i];
            start = i;
        }
        else {
            b[i].sum = b[i-1].sum + a[i];
        }
        
        b[i].start = start;
        b[i].end = i;
    }
    
    const Node& m = *max_element(b.begin(), b.end());
    return m;
}

int main()
{
    int cases;
    int len;
    cin >> cases;
    for (int i=0; i<cases; ++i) {
        cin >> len;
        vector<int> a(len);
        for (int j=0; j<len; ++j)
            cin >> a[j];
        Node m = maxsum(a);
        if (i !=0 )
            cout << endl;
        cout << "Case " << i+1 << ":\n";
        printf("%d %d %d\n", m.sum, m.start+1, m.end+1);
    }
    
    return 0;
}

TEST_GROUP(HDOJ1003){
    
};

TEST(HDOJ1003, case1){
    int a[] = {6, -1, 5, 4, -7};
    vector<int> v(a, a+5);
    Node n = maxsum(v);
    LONGS_EQUAL(14, n.sum);
    LONGS_EQUAL(0, n.start);
    LONGS_EQUAL(3, n.end);
}

TEST(HDOJ1003, case2){
    int a[] = {0, 6, -1, 1, -6, 7, -5};
    vector<int> v(a, a+7);
    Node n = maxsum(v);
    LONGS_EQUAL(7, n.sum);
    LONGS_EQUAL(0, n.start);
    LONGS_EQUAL(5, n.end);
}
    
}
