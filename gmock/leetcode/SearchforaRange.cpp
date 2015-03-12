//
//  https://oj.leetcode.com/problems/search-for-a-range/
//  leetcode
//
//  Created by Jun on 15/2/19.
//
//

#include <gmock/gmock.h>
#include <vector>
using namespace std;
using namespace testing;

namespace SearchforaRange {
    
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> r;
        
        int k = search(A, 0, n, target);
        if (k == -1) {
            r.push_back(-1);
            r.push_back(-1);
            return r;
        }
        
        int s = k-1;
        while (A[s] == target && s >= 0) {
            --s;
        }
        r.push_back(s+1);
        
        int e = k+1;
        while (A[e] == target && e < n) {
            ++e;
        }
        r.push_back(e-1);
        
        return r;
    }
    
    int search(int A[], int s, int e, int target) {
        if (A[s] > target || A[e-1] < target) {
            return -1;
        }
        
        int m = (s + e)/2;
        if (A[m] == target) {
            return m;
        }else if (A[m] < target) {
            return search(A, m, e, target);
        }else{
            return search(A, s, m, target);
        }
    }
};

TEST(SearchforaRange, case1) {
    int a [] = {5, 7, 7, 8, 8, 10};
    Solution* sln = new Solution();
    auto r = sln->searchRange(a,  sizeof(a)/sizeof(int), 8);
    ASSERT_THAT(r, ElementsAre(3, 4));
}
    
TEST(SearchforaRange, search) {
    int a [] = {5, 7, 7, 8, 8, 10};
    Solution* sln = new Solution();
    auto r = sln->search(a,  0, sizeof(a)/sizeof(int), 8);
    ASSERT_THAT(r, Eq(3));
}
    
    TEST(SearchforaRange, search2) {
        int a [] = {5, 7, 7, 8, 8, 10};
        Solution* sln = new Solution();
        auto r = sln->search(a,  0, sizeof(a)/sizeof(int), 10);
        ASSERT_THAT(r, Eq(5));
    }
    
    TEST(SearchforaRange, search3) {
        int a [] = {5, 7, 7, 8, 8, 11};
        Solution* sln = new Solution();
        auto r = sln->search(a,  0, sizeof(a)/sizeof(int), 10);
        ASSERT_THAT(r, Eq(-1));
    }
    
    TEST(SearchforaRange, search4) {
        int a [] = {5, 7, 7, 8, 8, 11};
        Solution* sln = new Solution();
        auto r = sln->search(a,  0, sizeof(a)/sizeof(int), 6);
        ASSERT_THAT(r, Eq(-1));
    }

}


