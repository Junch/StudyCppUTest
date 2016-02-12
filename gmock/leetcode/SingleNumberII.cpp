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
        int count[32] = {0};
        int result = 0;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < n; j++) {
                if ((A[j] >> i) & 1) {
                    count[i]++;
                }
            }
            result |= ((count[i] % 3) << i);
        }
        return result;
    }
};

TEST(SingleNumberII, case1){
    int a[]={3, 3, 3, 2};
    
    Solution* sln = new Solution();
    ASSERT_EQ(2, sln->singleNumber(a, 4));
}
    
}
