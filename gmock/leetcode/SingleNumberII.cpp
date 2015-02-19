//
//  https://oj.leetcode.com/problems/single-number-ii/
//  leetcode
//
//  Created by Jun on 15/2/19.
//
//

#include <gtest/gtest.h>

namespace SingleNumberII {

class Solution {
public:
    int singleNumber(int A[], int n) {
        return 0;
    }
};

TEST(SingleNumberII, case1){
    int a[]={3, 3, 3, 2};
    
    Solution* sln = new Solution();
    ASSERT_EQ(2, sln->singleNumber(a, 4));
}
    
}
