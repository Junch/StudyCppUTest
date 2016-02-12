//
//  PathSum_112.cpp
//  https://leetcode.com/problems/path-sum/
//
//  Created by Jun Chen on 16/2/9.
//
//

#include <gmock/gmock.h>
using namespace std;
using namespace testing;

namespace PathSum {
    
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
    
class Solution {
public:
    
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return false;
        }
        
        if (root->left == nullptr && root->right== nullptr){
            return root->val == sum;
        }
        
        if (root->left) {
            bool bLeft = hasPathSum(root->left, sum - root->val);
            if (bLeft) {
                return true;
            }
        }
        
        if (root->right) {
            bool bRight = hasPathSum(root->right, sum - root->val);
            if (bRight) {
                return true;
            }
        }
        
        return false;
    }
    
    // Short one
    bool hasPathSum2(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) return root->val == sum;
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};
    
    
TEST(PathSum, simple) {
    TreeNode* p1 = new TreeNode(1);
    p1->left = new TreeNode(3);
    p1->right = new TreeNode(6);
    
    Solution* s = new Solution();
    ASSERT_EQ(true, s->hasPathSum(p1, 7));
}
    
}
