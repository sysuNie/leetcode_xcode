//
//  21. Merge Two Sorted Lists.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _1__Merge_Two_Sorted_Lists_h
#define _1__Merge_Two_Sorted_Lists_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *sortedList = NULL;
        ListNode unusedEntity(0);
        ListNode *ptr = sortedList = &unusedEntity;
        
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                ptr->next = l1;
                l1 = l1->next;
            }
            else{
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
            
        }
        
        if(l1 == NULL){
            ptr->next = l2;
        }
        else{
            ptr->next = l1;
        }
        
        return sortedList->next;
    }

    void Test()
    {
        // 创建两个有序链表: 1->2->4 和 1->3->4
        ListNode* l1 = new ListNode(1);
        l1->next = new ListNode(2);
        l1->next->next = new ListNode(4);

        ListNode* l2 = new ListNode(1);
        l2->next = new ListNode(3);
        l2->next->next = new ListNode(4);

        ListNode* result = mergeTwoLists(l1, l2);
        ListNode* p = result;
        while(p != nullptr) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};


#endif /* _1__Merge_Two_Sorted_Lists_h */
