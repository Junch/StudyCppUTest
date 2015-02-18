//
//  https://oj.leetcode.com/problems/merge-k-sorted-lists/
//  leetcode
//
//  Created by Jun on 15/2/16.
//
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <array>
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
        if (lists.size() == 0) {
            return nullptr;
        }
        
        ListNode* r = lists[0];
        for (int i=1; i<lists.size(); ++i){
            r = mergeLists(r, lists[i]);
        }
        
        return r;
    }
    
    ListNode* mergeLists(ListNode* p, ListNode* q){
        ListNode* h = new ListNode(0);
        ListNode* r = h;
        
        while (p != nullptr && q != nullptr) {
            if (p->val < q->val){
                r->next = p;
                p = p->next;
            }else{
                r->next = q;
                q = q->next;
            }
            
            r = r->next;
        }
        
        if (p != nullptr) {
            r->next = p;
        }else{
            r->next = q;
        }
        
        r = h->next;
        delete h;
        return r;
    }
};
    

template <size_t size>
bool listAreEqual(ListNode* p, const std::array<int, size>& arr){
    int i = 0;
    while (p != nullptr && i < arr.size()) {
        if (p->val != arr[i]) {
            return false;
        }
        
        p = p->next;
        ++i;
    }
    
    return p == nullptr && i == arr.size() ;
}
    

template <size_t size>
ListNode* createList(const std::array<int, size>& arr){
    ListNode* h = new ListNode(-1);
    
    ListNode* p = h;
    for (auto i: arr) {
        p->next = new ListNode(i);
        p = p->next;
    }
    
    p = h->next;
    delete h;
    return p;
}
 

TEST(MergekSortedLists, case1) {
    ADD_FAILURE()<< "Not implemented";
}

TEST(MergekTwoLists, mergeTwoLists) {
    auto p = createList(std::array<int,2> {1, 4});
    auto q = createList(std::array<int,2> {2, 3});
    Solution* sln = new Solution();
    auto r = sln->mergeLists(p, q);
    ASSERT_TRUE(listAreEqual(r, std::array<int, 4>{1, 2, 3, 4}));
    
    //std::array<int, 3> temp {3, 4, 5};
    //ASSERT_THAT(temp, ElementsAre(3, 4, 5));
}
    
TEST(MergekTwoLists, listAreEqual) {
    std::array<int, 3> arr {1, 4, 7};
    
    auto p = createList(arr);
    ASSERT_TRUE(listAreEqual(p, arr));
}

}


