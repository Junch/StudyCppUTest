//
//  ltoj_maximum_depth_of_binary_tree.cpp
//  interview1
//
//  Created by Jun on 14-2-18.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <queue>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_MAXIMUM_DEPTH_OF_BINARY_TREE {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
    class Solution {
    public:
        int maxDepth(TreeNode *root) {
            if (root == nullptr)
                return 0;
            
            queue<pair<TreeNode*, int>> s;
            s.push(make_pair(root, 1));
            
            int depth = 0;
            while (!s.empty()) {
                auto node = s.front();
                s.pop();
                
                depth = node.second;
                if (node.first->left != nullptr)
                    s.push(make_pair(node.first->left, depth + 1));
                
                if (node.first->right != nullptr)
                    s.push(make_pair(node.first->right, depth + 1));
            }
            
            return depth;
        }
    };
    
    TEST_GROUP(LTOJ_MAXIMUM_DEPTH_OF_BINARY_TREE){
        Solution sln;
    };
    
    TEST(LTOJ_MAXIMUM_DEPTH_OF_BINARY_TREE, 2ELEM)
    {
        TreeNode a(1);
        TreeNode b(2);
        a.right = &b;
        
        int depth = sln.maxDepth(&a);
        LONGS_EQUAL(2, depth);
    }
}
