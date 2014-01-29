//
//  ltoj_balanced_binary_tree.cpp
//  interview1
//
//  Created by Jun on 14-1-29.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_BALANCED_BINARY_TREE {
    
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
    class Solution {
    public:
        
        bool balanced(TreeNode *root, int& height){
            if (root == nullptr) {
                height = -1;
                return true;
            }
            
            int hl = -1;
            int hr = -1;
            
            if (!balanced(root->left, hl))
                return false;
            
            if (!balanced(root->right, hr))
                return false;
            
            if (abs(hl - hr) > 1)
                return false;
            
            height = max(hl, hr) + 1;
            
            return true;
        }
        
        bool isBalanced(TreeNode *root) {
            int height;
            return balanced(root, height);
        }
    };
    
    class Solution2 {
    public:
        
        pair<bool, int> balanced(TreeNode *root){
            if (root == nullptr)
                return make_pair(true, -1);
            
            auto&& l = balanced(root->left);
            if (l.first == false)
                return l;
            
            auto&& r = balanced(root->right);
            if (r.first == false)
                return r;
            
            if (abs(l.second - r.second) > 1)
                return make_pair(false, -1);
            
            return make_pair(true, max(l.second, r.second) + 1);
        }
        
        bool isBalanced(TreeNode *root) {
            auto && p = balanced(root);
            return p.first;
        }
    };
    
    TEST_GROUP(LTOJ_BALANCED_BINARY_TREE){
        Solution2 sln;
    };
    
    TEST(LTOJ_BALANCED_BINARY_TREE, ASimple){
        TreeNode t0(0);
        TreeNode t1(1);
        TreeNode t2(2);
        t0.right = &t1;
        t1.right = &t2;
        
        CHECK_FALSE(sln.isBalanced(&t0));
    }
}
