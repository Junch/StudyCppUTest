//
//  ltoj_reorder_list.cpp
//  interview1
//  http://oj.leetcode.com/problems/reorder-list/
//
//  Created by Jun on 14-2-7.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_REORDER_LIST {
    
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    class Solution {
    public:
        void reorderList(ListNode* head) {
            if (head == nullptr)
                return;
            
            int len = 0;
            ListNode* p=head;
            for (; p != nullptr; p = p->next) {
                ++len;
            }
            
            if (len >> 1)
                len = len/2;
            else
                len = len/2 - 1;
            
            p = head;
            for (int i = 0; i < len; ++i) {
                p = p->next;
            }
            
            ListNode* r = p->next;
            p->next = nullptr;
            
            reverseList(r);
            
            p = head;
            ListNode *q = nullptr, *s = nullptr;
            
            while (p != nullptr && r != nullptr) {
                q = p->next;
                s = r->next;
                
                r->next = q;
                p->next = r;
                
                p = q;
                r = s;
            }
        }
        
        void reverseList(ListNode* & head) {
            ListNode* start = new ListNode(-1);
            
            ListNode* p = head;
            ListNode* q = nullptr;
            while (p != nullptr) {
                q = p->next;
                p->next = start->next;
                start->next = p;
                p = q;
            }
            
            head = start->next;
            delete start;
        }
    };
    
    TEST_GROUP(LTOJ_REORDER_LIST){
        Solution sln;
        
        void removeList(ListNode* head){
            ListNode* p = nullptr;
            
            while (head != nullptr) {
                p = head->next;
                delete head;
                head = p;
            }
        }
        
        int lengthList(ListNode* head) {
            int len = 0;
            ListNode* p=head;
            for (; p != nullptr; p = p->next) {
                ++len;
            }
            
            return len;
        }
    };
    
    TEST(LTOJ_REORDER_LIST, reorderList4Elem){
        ListNode* node0 = new ListNode(0);
        ListNode* node1 = new ListNode(1);
        ListNode* node2 = new ListNode(2);
        ListNode* node3 = new ListNode(3);
        node0->next = node1;
        node1->next = node2;
        node2->next = node3;
        
        sln.reorderList(node0);
        
        LONGS_EQUAL(4, lengthList(node0));
        LONGS_EQUAL(0, node0->val);
        LONGS_EQUAL(3, node0->next->val);
        LONGS_EQUAL(1, node0->next->next->val);
        LONGS_EQUAL(2, node0->next->next->next->val);
        
        removeList(node0);
    }
    
    TEST(LTOJ_REORDER_LIST, reorderList3Elem){
        ListNode* node0 = new ListNode(0);
        ListNode* node1 = new ListNode(1);
        ListNode* node2 = new ListNode(2);
        node0->next = node1;
        node1->next = node2;
        
        sln.reorderList(node0);
        
        LONGS_EQUAL(3, lengthList(node0));
        LONGS_EQUAL(0, node0->val);
        LONGS_EQUAL(2, node0->next->val);
        LONGS_EQUAL(1, node0->next->next->val);
        
        removeList(node0);
    }
    
    TEST(LTOJ_REORDER_LIST, reorderList1Elm){
        ListNode* node0 = new ListNode(5);
        sln.reorderList(node0);
        LONGS_EQUAL(1, lengthList(node0));
        LONGS_EQUAL(5, node0->val);
        removeList(node0);
    }
    
    TEST(LTOJ_REORDER_LIST, reorderList0Elm){
        sln.reorderList(nullptr);
    }
    
    TEST(LTOJ_REORDER_LIST, ReverseList){
        ListNode* node0 = new ListNode(0);
        ListNode* node1 = new ListNode(1);
        node0->next = node1;
        
        sln.reverseList(node0);
        LONGS_EQUAL(1, node0->val);
        LONGS_EQUAL(0, node0->next->val);
        
        removeList(node0);
    }
}
