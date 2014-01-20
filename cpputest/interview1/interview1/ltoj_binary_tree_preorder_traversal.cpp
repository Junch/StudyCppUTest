//
//  ltoj_binary_tree_preorder_traversal.cpp
//  interview1
//  http://oj.leetcode.com/problems/binary-tree-preorder-traversal/
//  Created by Jun on 14-1-20.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_BINARY_TREE_PREORDER_TRAVERSAL{

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> v;
            stack<TreeNode *> s;
            
            while (root) {
                v.push_back(root->val);
                
                if (root->right)
                    s.push(root->right);
                
                if (root->left) {
                    root = root->left;
                }
                else{
                    if (s.empty())
                        break;
                    
                    root = s.top();
                    s.pop();
                }
            }
            
            return v;
        }
    };
    
    TEST_GROUP(LTOJ){
        Solution sln;
    };
    
    TEST(LTOJ, OneNode){
        TreeNode node(2);
        auto && v = sln.preorderTraversal(&node);
        LONGS_EQUAL(1, v.size());
        LONGS_EQUAL(2, v[0]);
    }
    
    TEST(LTOJ, ThreeNode){
        TreeNode node1(1);
        TreeNode node2(2);
        TreeNode node3(3);
        node1.left = &node2;
        node1.right = &node3;
        
        auto && v = sln.preorderTraversal(&node1);
        LONGS_EQUAL(3, v.size());
        LONGS_EQUAL(1, v[0]);
        LONGS_EQUAL(2, v[1]);
        LONGS_EQUAL(3, v[2]);
    }
    
}//namespace

