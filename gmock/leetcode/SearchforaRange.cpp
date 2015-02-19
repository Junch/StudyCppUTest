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
        return r;
    }
};

TEST(SearchforaRange, case1) {
    int a [] = {5, 7, 7, 8, 8, 10};
    Solution* sln = new Solution();
    auto r = sln->searchRange(a,  sizeof(a)/sizeof(int), 8);
    ASSERT_THAT(r, ElementsAre(3, 4));
}

}


