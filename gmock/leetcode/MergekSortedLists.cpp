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
        return merge(begin(lists), end(lists));
    }
    
    ListNode *merge(vector<ListNode*>::iterator b, vector<ListNode*>::iterator e){
        if(b==e)    return nullptr;
        if(next(b)==e)  return *b;
    
        auto m=b+(e-b)/2;
        return mergeLists(merge(b, m), merge(m,e));
    }
    
    ListNode* mergeLists(ListNode* p, ListNode* q){
        ListNode h(0);
        ListNode* r = &h;
        
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
        
        return h.next;
    }
    
    ListNode* mergeLists2(ListNode* p, ListNode* q){
        // The optimization seems to be not necessary indeeded.
        
        ListNode h(0);
        ListNode* r = &h;
        
        while (p != nullptr && q != nullptr) {
            if (p->val < q->val){
                r->next = p;
                while (r->next != nullptr &&  r->next->val <= q->val) {
                    r = r->next;
                }

                p = r->next;
            }else{
                r->next = q;
                
                while (r->next != nullptr &&  r->next->val <= p->val) {
                    r = r->next;
                }
             
                q = r->next;
            }
        }
        
        if (p != nullptr) {
            r->next = p;
        }else{
            r->next = q;
        }

        return h.next;
    }
    
    ListNode *mergeKLists2(vector<ListNode *> &lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        
        ListNode* r = lists[0];
        for (int i=1; i<lists.size(); ++i){
            r = mergeLists(r, lists[i]);
        }
        
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
    
TEST(MergekTwoLists, mergeLists) {
    auto p = createList(std::array<int,3> {1, 2, 2});
    auto q = createList(std::array<int,3> {1, 1, 2});
    Solution* sln = new Solution();
    auto r = sln->mergeLists(p, q);
    ASSERT_TRUE(listAreEqual(r, std::array<int, 6>{1, 1, 1, 2, 2, 2}));
}
    
TEST(MergekTwoLists, mergeLists2) {
    auto p = createList(std::array<int,2> {1, 4});
    auto q = createList(std::array<int,2> {2, 3});
    Solution* sln = new Solution();
    auto r = sln->mergeLists2(p, q);
    ASSERT_TRUE(listAreEqual(r, std::array<int, 4>{1, 2, 3, 4}));
}
    
TEST(MergekTwoLists, listAreEqual) {
    std::array<int, 3> arr {1, 4, 7};
    
    auto p = createList(arr);
    ASSERT_TRUE(listAreEqual(p, arr));
}

}


