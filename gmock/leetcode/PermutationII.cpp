//
//  PermutationII.cpp
//  leetcode
//
//  Created by Jun Chen on 16/2/12.
//
//

#include <gmock/gmock.h>
#include <vector>
#include <algorithm>
using namespace std;
using namespace testing;

namespace PermutationII {
    
    class Solution {
    public:
        void dfs(vector<int> nums, int start, vector<vector<int>>& vv) {
            if (start == nums.size()){
                vv.push_back(nums);
                return;
            }
            
            for (int i=start, len=(int)nums.size(); i<len; ++i){
                if (start != i && nums[start] == nums[i])
                    continue;
                
                std::swap(nums[start], nums[i]);
                
                dfs(nums, start+1, vv);
            }
        }
        
        vector<vector<int> > permuteUnique(vector<int> &nums) {
            std::sort(nums.begin(), nums.end());
            
            vector<vector<int>> vv;
            if (nums.empty()){
                return vv;
            }
            
            dfs(nums, 0, vv);
            
            return vv;
        }
    };
    
    
    TEST(PermutationII, simple){
        Solution* s = new Solution();
        vector<int> a {1, 2, 2};
        auto vv = s->permuteUnique(a);
        vector<int> r{1, 2, 2};
        ASSERT_EQ(r, vv[0]);
    }
    
}
