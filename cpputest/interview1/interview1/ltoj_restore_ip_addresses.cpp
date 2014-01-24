//
//  ltoj_restore_ip_addresses.cpp
//  interview1
//
//  Created by Jun on 14-1-24.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_Restore_IP_Addresses {
    class Solution {
    public:
        
        void dfs(const string& s, vector<string>& v){
            size_t len = v.size();
            
            if (s == "" && len != 4)
                return;
            
            if (s != "" && len ==4)
                return;
            
            if (s == "" && len == 4) {
                addresses.push_back(v[0]+"."+v[1]+"."+v[2]+"."+v[3]);
                return;
            }
            
            for (size_t i=1, len=s.length(); i<=len && i<=3; i++) {
                string head = string(s.begin(), s.begin()+i);
                string tail = string(s.begin()+i, s.end());
                
                int num = atoi(head.c_str());
                if (num > 255)
                    continue;
                
                if (head[0] == '0' && head.length() > 1)
                    continue;
                
                v.push_back(head);
                dfs(tail, v);
                v.pop_back();
            }
        }
    
        vector<string> restoreIpAddresses(string s) {
            vector<string> v;
            
            dfs(s, v);
            
            return addresses;
        }
        
    private:
        vector<string> addresses;
    };
    
    TEST_GROUP(LTOJ_PASCAL_TRIANGLE){
        Solution sln;
    };
    
    TEST(LTOJ_PASCAL_TRIANGLE, 0000){
        auto&& v = sln.restoreIpAddresses("0000");
        LONGS_EQUAL(1,v.size());
        STRCMP_EQUAL("0.0.0.0" ,v[0].c_str());
    }
    
    TEST(LTOJ_PASCAL_TRIANGLE, 322222){
        auto&& v = sln.restoreIpAddresses("322222");
        for (auto & s: v)
            CHECK_TRUE(s != "322.2.2.2");
    }

    TEST(LTOJ_PASCAL_TRIANGLE, 222202){
        auto&& v = sln.restoreIpAddresses("222202");
        for (auto & s: v)
            CHECK_TRUE(s != "2.2.22.02");
    }
    
    TEST(LTOJ_PASCAL_TRIANGLE, 2222002){
        auto&& v = sln.restoreIpAddresses("2222002");
        for (auto & s: v)
            CHECK_TRUE(s != "2.222.00.2");
    }
}