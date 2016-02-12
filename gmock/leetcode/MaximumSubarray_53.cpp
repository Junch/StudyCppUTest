//
//  MaximumSubarray_53.cpp
//  https://leetcode.com/problems/maximum-subarray/
//
//  Created by Jun Chen on 16/2/10.
//
//

#include <gmock/gmock.h>
#include <vector>
#include <algorithm>
using namespace std;
using namespace testing;

namespace MaximumSubarray {

class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
        int sums = nums[0];
        int max = sums;
        
        for (size_t i=1, len=nums.size(); i<len; ++i) {
            if (sums < 0) {
                sums = nums[i];
            } else {
                sums += nums[i];
            }
            
            if (sums > max) {
                max = sums;
            }
        }
        
        return max;
    }
    
    
    int maxSubArray2(vector<int>& nums) {
        vector<int> sums(nums.size());
        sums[0] = nums[0];
        
        for (int i=1; i<nums.size(); ++i) {
            if (sums[i-1] < 0) {
                sums[i] = nums[i];
            } else {
                sums[i] = sums[i-1] + nums[i];
            }
        }
        
        return *std::max_element(sums.begin(), sums.end());
    }
};
    
TEST(MaximumSubarray, example) {
    vector<int> arr{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    auto p = new Solution();
    ASSERT_EQ(6, p->maxSubArray(arr));
}
    
TEST(MaximumSubarray, example2) {
    vector<int> arr{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    auto p = new Solution();
    ASSERT_EQ(6, p->maxSubArray(arr));
}

}