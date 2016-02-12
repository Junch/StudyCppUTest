//
//  PathSumII_113.cpp
//  leetcode
//
//  Created by Jun Chen on 16/2/9.
//
//

#include <gmock/gmock.h>
#include <vector>
#include <list>
using namespace std;
using namespace testing;

namespace PathSumII {
    
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    vector<vector<int>> m_v;

    
    void addToResults(const list<TreeNode*>& path){
        vector<int> v;
//        for (list<TreeNode*>::const_iterator it=path.begin(); it!= path.end(); ++it){
//            v.push_back((*it)->val);
//        }
        
        for (const auto& item: path) {
            v.push_back(item->val);
        }
        
        
        m_v.push_back(v);
    }
    
    void dfs(TreeNode* root, int sum, list<TreeNode*>& path){
        if (!root) return;
        if (!root->left && !root->right) {
            if (root->val == sum) {
                path.push_back(root);
                addToResults(path);
                path.pop_back();
            }
            return;
        }
        
        if (root->left) {
            path.push_back(root);
            dfs(root->left, sum - root->val, path);
            path.pop_back();
        }
        
        if (root->right) {
            path.push_back(root);
            dfs(root->right, sum - root->val, path);
            path.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        m_v.clear();
        std::list<TreeNode*> path;
        dfs(root, sum, path);
        return m_v;
    }
};
    
TEST(PathSumII, simple) {
    TreeNode* p1 = new TreeNode(0);
    p1->left = new TreeNode(1);
    p1->right = new TreeNode(1);
    
    Solution* s = new Solution();
    vector<int> arr = {0, 1};
    ASSERT_EQ(arr, s->pathSum(p1, 1)[0]);
    ASSERT_EQ(arr, s->pathSum(p1, 1)[1]);
}

}
