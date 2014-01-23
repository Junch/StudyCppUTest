//
//  ltoj_remove_duplicates_from_sorted_list .cpp
//  interview1
//
//  Created by Jun on 14-1-23.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_REMOVE_DUPLICATES_FROM_SORTED_LIST {

    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            ListNode* p = head;
            ListNode* q = nullptr;
            ListNode* r = nullptr;
            
            while (p != nullptr) {
                for (q = p->next; q != nullptr && p->val == q->val; ) {
                    r = q;
                    q = q->next;
                    delete r;
                }
                
                p->next = q;
                p = q;
            }
            
            return head;
        }
        
        ListNode *deleteDuplicatesII(ListNode *head) {
            ListNode* p = head;
            ListNode* q = nullptr;
            ListNode* r = nullptr;
            
            ListNode* t = new ListNode(0);
            t->next = head;
            head = t;
            
            while (p != nullptr) {
                
                for (q = p->next; q != nullptr && p->val == q->val; ) {
                    r = q;
                    q = q->next;
                    delete r;
                }
                
                if (p->next != q) { // Has duplication
                    delete p;
                    
                    t->next = q;
                }
                else                // No duplication
                    t = p;
            
                p = q;
            }
            
            t = head->next;
            delete head;
            return t;
        }

        
    };
    
    TEST_GROUP(LTOJ_REMOVE_DUPLICATES_FROM_SORTED_LIST){
        Solution sln;
    };
    
    TEST(LTOJ_REMOVE_DUPLICATES_FROM_SORTED_LIST, 0elem){
        POINTERS_EQUAL(nullptr, sln.deleteDuplicates(nullptr));
    }
    
    TEST(LTOJ_REMOVE_DUPLICATES_FROM_SORTED_LIST, 1elem){
        ListNode t(2);
        POINTERS_EQUAL(&t, sln.deleteDuplicates(&t));
    }
    
    TEST(LTOJ_REMOVE_DUPLICATES_FROM_SORTED_LIST, 2differentElem){
        ListNode t1(1);
        ListNode t2(2);
        t1.next = &t2;
        POINTERS_EQUAL(&t1, sln.deleteDuplicates(&t1));
        POINTERS_EQUAL(&t2, t1.next);
    }
    
    TEST(LTOJ_REMOVE_DUPLICATES_FROM_SORTED_LIST, 2SameElem){
        ListNode* t1 = new ListNode(1);
        ListNode* t2 = new ListNode(1);
        t1->next = t2;
        ListNode* p = sln.deleteDuplicates(t1);
        LONGS_EQUAL(1, p->val)
        POINTERS_EQUAL(nullptr, t1->next);
        delete p;
    }
    
    
    TEST_GROUP(LTOJ_REMOVE_DUPLICATES_FROM_SORTED_LIST_II){
        Solution sln;
    };
    
    TEST(LTOJ_REMOVE_DUPLICATES_FROM_SORTED_LIST_II, 0elem){
        POINTERS_EQUAL(nullptr, sln.deleteDuplicatesII(nullptr));
    }
    
    TEST(LTOJ_REMOVE_DUPLICATES_FROM_SORTED_LIST_II, 1elem){
        ListNode t(2);
        POINTERS_EQUAL(&t, sln.deleteDuplicatesII(&t));
    }
    
    TEST(LTOJ_REMOVE_DUPLICATES_FROM_SORTED_LIST_II, 2SameElem){
        ListNode* t1 = new ListNode(1);
        ListNode* t2 = new ListNode(1);
        t1->next = t2;
        ListNode* p = sln.deleteDuplicatesII(t1);
        POINTERS_EQUAL(nullptr, p);
    }
    
    TEST(LTOJ_REMOVE_DUPLICATES_FROM_SORTED_LIST_II, 2differentElem){
        ListNode* t1 = new ListNode(1);
        ListNode* t2 = new ListNode(2);
        t1->next = t2;
        ListNode* p = sln.deleteDuplicatesII(t1);
        POINTERS_EQUAL(t1, p)
        POINTERS_EQUAL(t2, p->next);
        delete t1;
        delete t2;
    }
    
}//namespace

