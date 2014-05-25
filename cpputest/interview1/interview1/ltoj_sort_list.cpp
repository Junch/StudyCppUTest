//
//  ltoj_sort_list.cpp
//  https://oj.leetcode.com/problems/sort-list/
//
//  Created by Jun on 2014-05-25.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cassert>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_SORT_LIST {
    
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    class Solution {
    public:       
        ListNode *sortList(ListNode *head) {
            ListNode * h = new ListNode(0);
            h->next = head;
            
            int step = 1;
            bool bLoop = true;
            
            while (bLoop) {
                ListNode* p = h;
                
                do{
                    ListNode* q = split(p, step);
                    if (p == h && p->next == nullptr) {
                        bLoop = false;
                        h->next = q;
                        break;
                    }
                    
                    ListNode* r = split(p, step);
                    
                    p = merge(p, q, r);
                }while (p->next != nullptr);

                step *= 2;
            }
            
            head = h->next;
            delete h;
            return head;
        }
        
        ListNode* merge(ListNode* h, ListNode *p, ListNode *q){
            ListNode *tail = h;
            ListNode *r = h->next;
            
            while (p!= nullptr && q != nullptr){
                if (p->val <= q->val){
                    tail->next = p;
                    p = p->next;
                }else{
                    tail->next = q;
                    q = q->next;
                }
                
                tail = tail->next;
            }
            
            if (p != nullptr)
                tail->next = p;
            else if(q !=nullptr)
                tail->next = q;
            
            while (tail->next != nullptr)
                tail = tail->next;
            
            tail->next = r;
            return tail;
        }
        
        ListNode* split(ListNode* h, int step){
            assert(h != nullptr);
            ListNode* p = h;
            ListNode* q = h->next;
            
            for (int i=0; i<step && p != nullptr; i++)
                p = p->next;

            if (p != nullptr){
                h->next = p->next;
                p->next = nullptr;
            }else
                h->next = nullptr;
            
            return q;
        }
    };
    
    TEST_GROUP(LTOJ_SORT_LIST){
        Solution sln;
    };
    
    TEST(LTOJ_SORT_LIST, merge){
        ListNode* p1 = new ListNode(1);
        ListNode* p2 = new ListNode(2);
        ListNode* p3 = new ListNode(3);
        ListNode* p4 = new ListNode(4);
        ListNode* p5 = new ListNode(5);
        ListNode* p6 = new ListNode(6);
        
        p2->next = p3;
        p4->next = p5;
        
        p1->next = p6;
        
        sln.merge(p1, p2, p4);
        LONGS_EQUAL(p1->next->val, 2);
        LONGS_EQUAL(p1->next->next->val, 3);
        LONGS_EQUAL(p1->next->next->next->val, 4);
        LONGS_EQUAL(p1->next->next->next->next->val, 5);
        LONGS_EQUAL(p1->next->next->next->next->next->val, 6);
        
        delete p1;
        delete p2;
        delete p3;
        delete p4;
        delete p5;
        delete p6;
    }
    
    TEST(LTOJ_SORT_LIST, split){
        ListNode* p1 = new ListNode(1);
        ListNode* p2 = new ListNode(2);
        ListNode* p3 = new ListNode(3);
        p1->next = p2;
        p2->next = p3;
        
        auto r = sln.split(p1, 1);
        LONGS_EQUAL(p1->next->val, 3);
        LONGS_EQUAL(r->val, 2);
        
        delete p1;
        delete p2;
        delete p3;
    }
    
    TEST(LTOJ_SORT_LIST, split2){
        ListNode* p1 = new ListNode(1);
        ListNode* p2 = new ListNode(2);
        ListNode* p3 = new ListNode(3);
        p1->next = p2;
        p2->next = p3;
        
        auto r = sln.split(p1, 3);
        LONGS_EQUAL(p1->next, NULL);
        LONGS_EQUAL(r->val, 2);
        LONGS_EQUAL(r->next->val, 3);
        LONGS_EQUAL(r->next->next, NULL);
        
        delete p1;
        delete p2;
        delete p3;
    }
    
    TEST(LTOJ_SORT_LIST, sortlist){
        ListNode* p1 = new ListNode(1);
        ListNode* p2 = new ListNode(2);
        ListNode* p3 = new ListNode(3);
        ListNode* p4 = new ListNode(4);
        p1->next = p2;
        p2->next = p3;
        p3->next = p4;
        
        auto r = sln.sortList(p1);
        LONGS_EQUAL(r->val, 1);
        LONGS_EQUAL(r->next->val, 2);
        LONGS_EQUAL(r->next->next->val, 3);
        LONGS_EQUAL(r->next->next->next->val, 4);

        delete p1;
        delete p2;
        delete p3;
        delete p4;
    }
    
}
