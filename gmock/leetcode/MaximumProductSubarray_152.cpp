//
//  MaximumProductSubarray.cpp
//  leetcode
//
//  Created by Jun Chen on 16/2/10.
//
//

#include <gmock/gmock.h>
#include <vector>
#include <algorithm>
using namespace std;
using namespace testing;

namespace MaximumProductSubarray {
    
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> min(nums.size());
        vector<int> max(nums.size());
        min[0] = max[0] = nums[0];
        
        for (size_t i=1, len=nums.size(); i<len; ++i) {
            if (max[i-1] == 0) {
                max[i] = min[i] = nums[i];
                continue;
            }
            
            if (nums[i] > 0) {
                if (max[i-1] < 0) {
                    max[i] = nums[i];
                    min[i] = nums[i]*min[i-1];
                }else if(min[i-1] > 0){
                    max[i] = max[i-1]*nums[i];
                    min[i] = nums[i];
                }else{
                    max[i] = max[i-1] * nums[i];
                    min[i] = min[i-1] * nums[i];
                }
            }
            else if(nums[i] < 0) {
                if (max[i-1] < 0) {
                    max[i] = min[i-1]*nums[i];
                    min[i] = nums[i];
                }else if(min[i-1] > 0){
                    max[i] = nums[i];
                    min[i] = max[i-1]*nums[i];
                }else {
                    max[i] = min[i-1] * nums[i];
                    min[i] = max[i-1] * nums[i];
                }
            } else {
                max[i] = min[i] = 0;
            }
        }
        
        return *std::max_element(max.begin(), max.end());
    }
    
    int maxProduct2(vector<int>& nums) {
        vector<int> min(nums.size());
        vector<int> max(nums.size());
        min[0] = max[0] = nums[0];
        
        for (size_t i=1, len=nums.size(); i<len; ++i) {
            max[i] = std::max(std::max(min[i-1]*nums[i], max[i-1]*nums[i]), nums[i]);
            min[i] = std::min(std::min(min[i-1]*nums[i], max[i-1]*nums[i]), nums[i]);
        }
        
        return *std::max_element(max.begin(), max.end());
    }
    
    int maxProduct3(vector<int>& nums) {
        int min;
        int max;
        min = max = nums[0];
        int ret = max;
        
        for (size_t i=1, len=nums.size(); i<len; ++i) {
            int n1 = min*nums[i];
            int n2 = max*nums[i];
            max = std::max(std::max(n1, n2), nums[i]);
            min = std::min(std::min(n1, n2), nums[i]);
            
            if (max > ret) {
                ret = max;
            }
        }
        
        return ret;
    }
};
    
TEST(MaximumProductSubarray, example) {
    vector<int> arr{2, 3, -2, 4};
    
    auto p = new Solution();
    ASSERT_EQ(6, p->maxProduct(arr));
    ASSERT_EQ(6, p->maxProduct2(arr));
}
    
TEST(MaximumProductSubarray, zero) {
    vector<int> arr{2, 0, -2, 4};
    
    auto p = new Solution();
    ASSERT_EQ(4, p->maxProduct(arr));
    ASSERT_EQ(4, p->maxProduct2(arr));
}
    
}
