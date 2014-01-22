//
//  ltoj_convert_sorted_array_to_bst.cpp
//  interview1
//  http://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
//
//  Created by Jun on 14-1-22.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_CONVERT_SORTED_ARRAY_TO_BST {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
    class Solution {
    public:
        TreeNode *sortedArrayToBST(vector<int> &num) {
            TreeNode *pNode = nullptr;
            for (int i: num)
                insert(i, pNode);
            
            return pNode;
        }
        
        void insert(int val, TreeNode * & p){
            if (p == nullptr) {
                p = new TreeNode(val);
                heightMap[p] = 0;
            }else if(val < p->val) {
                insert(val, p->left);
            }else if(val > p->val) {
                insert(val, p->right);
            }
            
            balance(p);
        }
        
        void balance(TreeNode * & p){
            if (p == nullptr)
                return;

            if (height(p->right) - height(p->left) > 1) {
                if (height(p->right->right) >= height(p->right->left)) {
                    rotateWithRightChild(p);
                }
            }
            
            heightMap[p] = max(height(p->left), height(p->right)) + 1;
        }
        
        void  rotateWithRightChild(TreeNode * & p) {
            TreeNode* pRight = p->right;
            p->right = pRight->left;
            pRight->left = p;
            
            heightMap[p] = max(height(p->left), height(p->right)) + 1;
            heightMap[pRight] = max(height(pRight->left), height(pRight->right)) + 1;
            
            p = pRight;
        }
        
        int height(TreeNode *p){
            return p==nullptr? -1: heightMap[p];
        }
        
    private:
        unordered_map<TreeNode *, int> heightMap;
    };
    
    TEST_GROUP(LTOJ_CONVERT_SORTED_ARRAY_TO_BST){
        Solution sln;
    };
    
    TEST(LTOJ_CONVERT_SORTED_ARRAY_TO_BST, 1num){
        vector<int> num{1};
        auto p = sln.sortedArrayToBST(num);
        LONGS_EQUAL(1, p->val);
        delete p;
    }
    
    TEST(LTOJ_CONVERT_SORTED_ARRAY_TO_BST, 2num){
        vector<int> num{1, 2};
        auto p = sln.sortedArrayToBST(num);
        LONGS_EQUAL(1, p->val);
        LONGS_EQUAL(2, p->right->val);
        delete p->right;
        delete p;
    }
    
    TEST(LTOJ_CONVERT_SORTED_ARRAY_TO_BST, 3num){
        vector<int> num{1, 2, 3};
        auto p = sln.sortedArrayToBST(num);
        LONGS_EQUAL(2, p->val);
        LONGS_EQUAL(1, p->left->val);
        LONGS_EQUAL(3, p->right->val);
        delete p->left;
        delete p->right;
        delete p;
    }
    
}//namespace
