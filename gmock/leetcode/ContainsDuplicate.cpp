//
//  217ContainsDuplicate.cpp
//  leetcode
//
//  Created by Jun Chen on 16/2/5.
//
//

#include <gmock/gmock.h>
#include <vector>
#include <algorithm>
using namespace std;
using namespace testing;

namespace ContainsDuplicate {
    
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i=0; i+1<nums.size(); ++i) {
            if (nums[i] == nums[i+1]) {
                return true;
            }
        }
        
        return false;
    }
};
    

TEST(ContainsDuplicate, duplicated){
    vector<int> a = {1, 2, 2, 3};
    
    Solution* sln = new Solution();
    bool r = sln->containsDuplicate(a);
    ASSERT_EQ(true, r);
}
    
TEST(ContainsDuplicate, unique){
    vector<int> a = {1, 2, 3};
    
    Solution* sln = new Solution();
    bool r = sln->containsDuplicate(a);
    ASSERT_EQ(false, r);
}

}



