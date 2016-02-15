//
//  Sum3Closest.cpp
//  http://www.lintcode.com/en/problem/3sum-closest/
//
//  Created by Jun Chen on 16/2/12.
//
//

#include <gmock/gmock.h>
#include <vector>
#include <algorithm>
using namespace std;
using namespace testing;

namespace Sum3Closest {

    class Solution {
    public:
        /**
         * @param numbers: Give an array numbers of n integer
         * @param target: An integer
         * @return: return the sum of the three integers, the sum closest target.
         */
        int threeSumClosest(vector<int> nums, int target) {
            m_closest = INT_MAX;
            
            dfs(nums, target,  0,  3, 0);
            return m_sum;
        }
        
    protected:
        void dfs(vector<int>& nums, int target, int start, int k, int sum) {
            if (k == 0) {
                int dist = abs(sum - target);
                if (dist < m_closest){
                    m_closest = dist;
                    m_sum = sum;
                }
                
                return;
            }
            
            
            for (int i=start, len=(int)nums.size(); i<len; ++i) {
                dfs(nums, target, i+1, k-1, sum+nums[i]);
            }
        }
        
        int m_closest;
        int m_sum;
    };

    
    TEST(Sum3Closest, simple) {
        vector<int> a{2, 7, 11, 15};
        Solution* s = new Solution();
        ASSERT_EQ(20, s->threeSumClosest(a, 3));
    }
}
