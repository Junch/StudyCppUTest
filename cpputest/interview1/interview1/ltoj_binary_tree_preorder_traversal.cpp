//
//  ltoj_binary_tree_preorder_traversal.cpp
//  interview1
//  http://oj.leetcode.com/problems/binary-tree-preorder-traversal/
//  http://fengchj.diandian.com/?p=1164
//  http://biaobiaoqi.me/blog/2013/04/27/travsal-binary-tree/
//  http://blog.sina.com.cn/s/blog_5168a9e40100af36.html
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
//        vector<int> preorderTraversal(TreeNode *root) {
//            vector<int> v;
//            stack<TreeNode *> s;
//            
//            while (root) {
//                v.push_back(root->val);
//                
//                if (root->right)
//                    s.push(root->right);
//                
//                if (root->left) {
//                    root = root->left;
//                }
//                else{
//                    if (s.empty())
//                        break;
//                    
//                    root = s.top();
//                    s.pop();
//                }
//            }
//            
//            return v;
//        }
        
//        vector<int> preorderTraversal(TreeNode *root) {
//            vector<int> v;
//            stack<TreeNode *> s;
//            
//            s.push(root);
//            while (!s.empty()) {
//                auto p = s.top();
//                s.pop();
//
//                v.push_back(p->val);
//                
//                if (p->right)
//                    s.push(p->right);
//                
//                if (p->left)
//                    s.push(p->left);
//            }
//            
//            return v;
//        }
        

        void preorderTraversalImp(TreeNode *root, vector<int>& v){
            if (root) {
                v.push_back(root->val);
                preorderTraversalImp(root->left, v);
                preorderTraversalImp(root->right, v);
            }
        }
        
        vector<int> preorderTraversalRecursive(TreeNode *root) {
            vector<int> v;
            preorderTraversalImp(root, v);
            return v;
        }
        
        /*
         该方法模拟了递归的前序遍历中程序调用栈的行为过程：在调用栈中，会不断的递归进入左儿子链中，
         直到没有左儿子，再进入对右儿子的处理中。与递归方法的调用栈的不同之处在于，内层 while 
         循环将递归方法中针对左儿子链上所有节点的递归过程集中到了一起。
         */
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> v;
            stack<TreeNode *> s;
            
            while (root || !s.empty()) {
                while (root) {
                    v.push_back(root->val);
                    
                    s.push(root);
                    root = root->left;
                }
                
                root = s.top();
                s.pop();
                root = root->right;
            }
            
            return v;
        }
        
        
        void postorderTraversalImp(TreeNode *root, vector<int>& v){
            if (root) {
                preorderTraversalImp(root->left, v);
                preorderTraversalImp(root->right, v);
                v.push_back(root->val);
            }
        }
        
        vector<int> postorderTraversalRecursive(TreeNode *root) {
            vector<int> v;
            postorderTraversalImp(root, v);
            return v;
        }
        
//        vector<int> postorderTraversal(TreeNode *root) {
//            vector<int> v;
//            stack<pair<TreeNode *, bool>> s;
//            
//            while (root || !s.empty()) {
//                while (root) {
//                    s.push({root, false});
//                    root = root->left;
//                }
//
//                auto& node = s.top();
//                if (node.second == false) {
//                    node.second = true;
//                    root = node.first->right;
//                }else{
//                    v.push_back(node.first->val);
//                    s.pop();
//                    root = nullptr;
//                }
//            }
//            
//            return v;
//        }
        
        vector<int> postorderTraversal(TreeNode *root) {
            vector<int> v;
            stack<TreeNode *> s;
            TreeNode* pre=nullptr;
            
            while (root || !s.empty()) {
                while (root) {
                    s.push(root);
                    root = root->left;
                }
                
                root = s.top();
                // 如果root没有右孩子或者右孩子刚刚被访问过
                if (root->right == nullptr || root->right == pre) {
                    v.push_back(root->val);
                    s.pop();
                    pre = root;
                    root = nullptr;
                }else{
                    root = root->right;
                }
            }
            
            return v;
        }
    };
    
    TEST_GROUP(LTOJ){
        Solution sln;
    };
    
    TEST(LTOJ, Pre_OneNode){
        TreeNode node(2);
        auto && v = sln.preorderTraversal(&node);
        LONGS_EQUAL(1, v.size());
        LONGS_EQUAL(2, v[0]);
    }
    
    TEST(LTOJ, Pre_ThreeNode){
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
    
    TEST(LTOJ, Post_OneNode){
        TreeNode node(2);
        auto && v = sln.postorderTraversal(&node);
        LONGS_EQUAL(1, v.size());
        LONGS_EQUAL(2, v[0]);
    }
    
    TEST(LTOJ, Post_ThreeNode){
        TreeNode node1(1);
        TreeNode node2(2);
        TreeNode node3(3);
        node1.left = &node2;
        node1.right = &node3;
        
        auto && v = sln.postorderTraversal(&node1);
        LONGS_EQUAL(3, v.size());
        LONGS_EQUAL(2, v[0]);
        LONGS_EQUAL(3, v[1]);
        LONGS_EQUAL(1, v[2]);
    }
    
    class Solution2 {
    public:
        vector<int> inorderTranversal(TreeNode *root){
            vector<int> v;
            stack<TreeNode *> s;

            while (root || !s.empty()) {
                while (root) {
                    s.push(root);
                    root = root->left;
                }
                
                root = s.top();
                s.pop();
                v.push_back(root->val);
                
                root = root->right;
            }
            
            return v;
        }
    };
    
    TEST_GROUP(INORDER){
        Solution2 sln;
    };
    
    TEST(INORDER, 3Ele) {
        TreeNode node1(1);
        TreeNode node2(2);
        TreeNode node3(3);
        node1.right = &node2;
        node2.left = &node3;
        
        auto v = sln.inorderTranversal(&node1);
        LONGS_EQUAL(3, v.size());
        LONGS_EQUAL(1, v[0]);
        LONGS_EQUAL(3, v[1]);
        LONGS_EQUAL(2, v[2]);
    }
}//namespace

