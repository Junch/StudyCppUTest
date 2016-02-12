//
//  SumRoottoLeafNumbers.cpp
//  https://leetcode.com/problems/sum-root-to-leaf-numbers/
//
//  Created by Jun Chen on 16/2/9.
//
//

#include <gmock/gmock.h>
using namespace std;
using namespace testing;

namespace SumRoottoLeafNumbers {
    
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode* root, int sum, int& total) {
        if (!root) return;
        if (!root->left && !root->right) {
            total += sum*10 + root->val;
            return;
        }
        
        if (root->left)
            dfs(root->left, sum*10 + root->val, total);
        
        if (root->right)
            dfs(root->right, sum*10 + root->val, total);
    }
    
    
    int sumNumbers(TreeNode* root) {
        int total = 0;
        dfs(root, 0, total);
        return total;
    }
};
    
TEST(SumRoottoLeafNumbers, abc){
    TreeNode* p1 = new TreeNode(1);
    p1->left = new TreeNode(2);
    p1->right = new TreeNode(3);
    
    Solution* s = new Solution();
    ASSERT_EQ(25, s->sumNumbers(p1));
}
    
}
