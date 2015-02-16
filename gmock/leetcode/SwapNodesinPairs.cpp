//
//  https://oj.leetcode.com/problems/swap-nodes-in-pairs/
//  leetcode
//
//  Created by Jun on 15/2/16.
//
//

#include <gtest/gtest.h>

namespace SwapNodesinPairs {
    
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
    
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr){
            return nullptr;
        }
        
        ListNode* h = new ListNode(0);
        h->next = head;
        
        ListNode* p=h;
        ListNode* q;
        ListNode* r;
        
        while ((q=p->next) != nullptr &&
               (r=q->next) != nullptr) {            
            p->next = r;
            q->next = r->next;
            r->next = q;
            
            p = q;
        }
        
        head = h->next;
        delete h;
        return head;
    }
};
    
    
TEST(SwapNodesinPairs, case1){
    auto n1 = new ListNode(1);
    auto n2 = new ListNode(2);
    n1->next = n2;
    
    Solution* sln = new Solution();
    auto r = sln->swapPairs(n1);
    ASSERT_TRUE(r != nullptr);
    ASSERT_EQ(2, r->val);
    ASSERT_EQ(1, r->next->val);
}

}