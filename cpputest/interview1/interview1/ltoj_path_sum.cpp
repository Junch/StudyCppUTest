//
//  ltoj_path_sum.cpp
//  interview1
//  http://oj.leetcode.com/problems/path-sum-ii/
//
//  Created by Jun on 14-1-31.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_PATH_SUM {
    
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
    class Solution {
    public:
        bool hasPathSum(TreeNode *root, int sum) {
            if (root == nullptr)
                return false;
            
            queue<pair<TreeNode *, int>> Q;
            Q.push(make_pair(root, root->val));
            
            bool hasPath = false;
            while (!Q.empty()) {
                auto top = Q.front();
                Q.pop();
                
                TreeNode* l = top.first->left;
                if (l)
                    Q.push(make_pair(l, top.second + l->val));
                
                TreeNode* r = top.first->right;
                if (r)
                    Q.push(make_pair(r, top.second + r->val));
    
                if (!l && !r) {
                    if (top.second == sum) {
                        hasPath = true;
                        break;
                    }
                }
            }
            
            return hasPath;
        }
    };
    
    class Solution2 {
    public:
        vector<vector<int> > pathSum(TreeNode *root, int sum) {
            vector<vector<int>> vv;
            
            if (root == nullptr)
                return vv;
            
            queue<tuple<TreeNode*, int, vector<int>>> Q;
            
            vector<int> v{root->val};
            Q.push(make_tuple(root, root->val, v));
            
            while (!Q.empty()) {
                auto& top = Q.front();
                
                TreeNode* node = get<0>(top);
                int val = get<1>(top);
                const auto& v = get<2>(top);
                
                TreeNode* l = node->left;
                TreeNode* r = node->right;
                if (!l && !r && val==sum)
                    vv.push_back(v);
                
                if (l) {
                    int newVal = val + l->val;
                    auto lv = v;
                    lv.push_back(l->val);
                    Q.push(make_tuple(l, newVal, lv));
                }

                if (r) {
                    int newVal = val + r->val;
                    auto rv = v;
                    rv.push_back(r->val);
                    Q.push(make_tuple(r, newVal, rv));
                }
                
                Q.pop();
            }
            
            return vv;
        }
    };

    
    TEST_GROUP(LTOJ_PATH_SUM){
        Solution sln;
    };
    
    TEST(LTOJ_PATH_SUM, 2elems){
        TreeNode t0(1);
        TreeNode t1(2);
        t0.right = &t1;
        CHECK_TRUE(sln.hasPathSum(&t0, 3));
    }
    
    TEST(LTOJ_PATH_SUM, NoElems){
        CHECK_FALSE(sln.hasPathSum(nullptr, 1));
    }
    
    
    
    TEST_GROUP(LTOJ_PATH_SUM_II){
        Solution2 sln;
    };
    
    TEST(LTOJ_PATH_SUM_II, NoElems){
        LONGS_EQUAL(0, sln.pathSum(nullptr, 1).size());
    }
    
    TEST(LTOJ_PATH_SUM_II, 2elems){
        TreeNode t0(1);
        TreeNode t1(2);
        t0.right = &t1;
        auto && v = sln.pathSum(&t0, 3);
        LONGS_EQUAL(1, v.size());
        LONGS_EQUAL(1, v[0][0]);
        LONGS_EQUAL(2, v[0][1]);
    }
    
    TEST(LTOJ_PATH_SUM_II, 1elems){
        TreeNode t0(1);
        auto && v = sln.pathSum(&t0, 1);
        LONGS_EQUAL(1, v.size());
        LONGS_EQUAL(1, v[0][0]);
    }
}
