//
//  template.cpp
//  interview1
//  http://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_EVAL_REVERSE_POLISH {
    class Solution {
    public:
        int evalRPN(vector<string> &tokens) {
           
            map<string, std::function<int(int, int)>> maps {
                {"+", [](int a, int b){return a + b;}},
                {"-", [](int a, int b){return a - b;}},
                {"*", [](int a, int b){return a * b;}},
                {"/", [](int a, int b){return a / b;}},
            };
            
            for (auto e: tokens) {
                auto iter = maps.find(e);
                if (iter != maps.end()) {
                    int a, b;
                    getTwoNumbers(a, b);
                    s.push(iter->second(a, b));
                }
                else
                    s.push(atoi(e.c_str()));
            }

            return s.top();
        }
        
        void getTwoNumbers(int& a, int& b){
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
        }
        
    private:
        stack<int> s;
    };

    TEST_GROUP(LTOJ_EVAL_REVERSE_POLISH){
        Solution sln;
    };
    
    TEST(LTOJ_EVAL_REVERSE_POLISH, Add2Numbers){
        vector<string> tokens{"1", "2", "+"};
        LONGS_EQUAL(3, sln.evalRPN(tokens));
    }
    
    TEST(LTOJ_EVAL_REVERSE_POLISH, Delete2Numbers){
        vector<string> tokens{"5", "1", "-"};
        LONGS_EQUAL(4, sln.evalRPN(tokens));
    }
    
    TEST(LTOJ_EVAL_REVERSE_POLISH, complexOne){
        vector<string> tokens{"4", "13", "5", "/", "+"};
        LONGS_EQUAL(6, sln.evalRPN(tokens));
    }
}//namespace
