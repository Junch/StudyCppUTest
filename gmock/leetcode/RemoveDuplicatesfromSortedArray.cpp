//
//  https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
//  leetcode
//
//  Created by Jun on 15/2/18.
//
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace testing;

namespace RemoveDuplicatesfromSortedArray {
    
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i = 0;
        int j = 1;
        int r = n;
        while (j < n) {
            if (A[i] == A[j]) {
                --r;
            }else{
                ++i;
                A[i] = A[j];
            }
            
            ++j;
        }
        
        return r;
    }
};
    
TEST(RemoveDuplicatesfromSortedArray, case112){
    int a[] = {1, 1, 2};
    
    Solution* sln = new Solution();
    int num = sln->removeDuplicates(a, 3);
    
    ASSERT_THAT(a, ElementsAre(1, 2, 2));
    ASSERT_THAT(num,Eq(2));
}

TEST(RemoveDuplicatesfromSortedArray, case1122){
    int a[] = {1, 1, 2, 2};
    
    Solution* sln = new Solution();
    int num = sln->removeDuplicates(a, 4);
    
    ASSERT_THAT(a, ElementsAre(1, 2, 2, 2));
    ASSERT_THAT(num,Eq(2));
}
    
}

