//
//  ltoj_permutations.cpp
//  interview1
//
//  Created by Jun on 14-2-11.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <vector>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_PERMUTATIONS {
    class Solution {
    public:
        vector<vector<int> > permute(vector<int> &num) {
            vector<vector<int>> vv;
            vector<vector<int>> ww;
            
            vector<vector<int>> *p = &vv;
            vector<vector<int>> *q = &ww;
            
            vector<int> v;
            v.push_back(num[0]);
            vv.push_back(v);
            
            for (int i=1; i<num.size(); ++i) {
                for (auto v: *p) {
                    size_t len = v.size();
                    
                    for (int j=0; j<len+1; j++) {
                        vector<int> a = v;
                        a.insert(a.begin()+j, num[i]);
                        q->push_back(a);
                    }
                }
                
                p->clear();
                std::swap(p, q);
            }
            
            return *p;
        }
    };
    
    TEST_GROUP(LTOJ_PERMUTATIONS){
        Solution sln;
    };
    
    TEST(LTOJ_PERMUTATIONS, 2Elm){
        vector<int> v{1,2};
        auto ret = sln.permute(v);
        LONGS_EQUAL(2, ret.size());
    }
    
    TEST(LTOJ_PERMUTATIONS, 3Elm){
        vector<int> v{1,2,3};
        auto ret = sln.permute(v);
        LONGS_EQUAL(6, ret.size());
    }
}
