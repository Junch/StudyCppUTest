//
//  MergeSortedArray.cpp
//  leetcode
//
//  https://oj.leetcode.com/problems/merge-sorted-array/
//
//
#include <gtest/gtest.h>

namespace MergeSortedArray {

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int k=m+n-1;
        int i=m-1;
        int j=n-1;
        
        while (i>=0 && j>=0) {
            if (A[i] > B[j]) {
                A[k] = A[i];
                --i;
            }else{
                A[k] = B[j];
                --j;
            }
            --k;
        }

        if (i<0) {
            for (int l=0; l<=j; ++l) {
                A[l]=B[l];
            }
        }
    }
};

TEST(MergeSortedArray, case1){
    Solution* s = new Solution();
    
    int a[] = {3,0,0};
    int b[] = {1,2};
    
    s->merge(a, 1, b, 2);
    ASSERT_EQ(1, a[0]);
    ASSERT_EQ(2, a[1]);
    ASSERT_EQ(3, a[2]);
}
    
TEST(MergeSortedArray, case2){
    Solution* s = new Solution();
    
    int a[] = {2,4,0,0};
    int b[] = {1,3};
    
    s->merge(a, 2, b, 2);
    ASSERT_EQ(1, a[0]);
    ASSERT_EQ(2, a[1]);
    ASSERT_EQ(3, a[2]);
    ASSERT_EQ(4, a[3]);
}

}




