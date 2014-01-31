//
//  ltoj_path_sum.cpp
//  interview1
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
        CHECK_TRUE(sln.hasPathSum(nullptr, 1));
    }
}
