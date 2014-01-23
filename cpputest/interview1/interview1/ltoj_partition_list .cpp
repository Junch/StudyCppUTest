//
//  ltoj_partition_list .cpp
//  interview1
//  http://oj.leetcode.com/problems/partition-list/
// Created by Jun on 14-1-23.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <memory>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_PARTITION_LIST {
    
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    class Solution {
    public:
        ListNode *partition(ListNode *head, int x) {
            ListNode* p = head;
            ListNode* q = nullptr;
            
            ListNode* r = new ListNode(0);
            ListNode* rt = r;
            
            ListNode* s = new ListNode(0);
            ListNode* st = s;
            
            while (p != nullptr) {
                q = p;
                p = p->next;
                q->next = nullptr;
                
                if (q->val < x) {
                    rt->next = q;
                    rt = rt->next;
                }
                else {
                    st->next = q;
                    st = st->next;
                }
            }
            
            rt->next = s->next;
            head = r->next;
            
            delete r;
            delete s;
            
            return head;
        }
    };
    
    TEST_GROUP(LTOJ_PARTITION_LIST){
        Solution sln;
    };
    
    
    TEST(LTOJ_PARTITION_LIST, oneElem){
        ListNode* pNode = new ListNode(2);
        POINTERS_EQUAL(pNode, sln.partition(pNode, 3));
        POINTERS_EQUAL(pNode, sln.partition(pNode, 1));
        delete pNode;
    }
    
    TEST(LTOJ_PARTITION_LIST, TwoElem){
        ListNode* p = new ListNode(2);
        ListNode* q = new ListNode(4);
        p->next = q;
        POINTERS_EQUAL(p, sln.partition(p, 3));
        POINTERS_EQUAL(q, p->next);
        delete p;
        delete q;
    }
    
    TEST(LTOJ_PARTITION_LIST, TwoElemInverse){
        ListNode* p = new ListNode(4);
        ListNode* q = new ListNode(2);
        p->next = q;
        POINTERS_EQUAL(q, sln.partition(p, 3));
        POINTERS_EQUAL(p, q->next);
        delete p;
        delete q;
    }
}//namespace
