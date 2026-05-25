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
    // 思路：递归分治。每次比较两个链表的头节点，较小者作为当前合并节点，
    //       其next指向剩余元素合并后的结果，递归直至某一链表为空。
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
        {
            // 链表1为空，直接返回链表2
            return list2;
        }

        if (list2 == nullptr)
        {
            // 链表2为空，直接返回链表1
            return list1;
        }
        
        if (list1->val < list2->val)
        {
            // 递归合并list1剩余部分与list2
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else
        {
            // 递归合并list1与list2剩余部分
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
    
    ListNode* mergeTwoListsRecursive(ListNode* list1, ListNode* list2)
    {
        if (list1 == nullptr) {
            return list2;
        }

        if (list2 == nullptr) {
            return list1;
        }
        
        if (list1->val <= list2->val) {
            list1->next = mergeTwoListsRecursive(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoListsRecursive(list1, list2->next);
            return list2;
        }
    }
    
    ListNode* mergeTwoListsIteration(ListNode* list1, ListNode* list2)
    {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        
        cur->next = list1 ? list1 : list2;
        return dummy.next;
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
