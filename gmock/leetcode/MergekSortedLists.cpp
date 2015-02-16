//
//  https://oj.leetcode.com/problems/merge-k-sorted-lists/
//  leetcode
//
//  Created by Jun on 15/2/16.
//
//

#include <gtest/gtest.h>
#include <vector>
using namespace std;
using namespace testing;

namespace MergekSortedLists {

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
    
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return nullptr;
    }
};
    

TEST(MergekSortedLists, case1) {
    ADD_FAILURE()<< "Not implemented";}
}
