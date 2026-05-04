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
    // 思路：递归合并。每次比较两个链表头节点，较小者作为当前节点，
    // 并将其next指向剩余链表的合并结果，直到其中一个链表为空。
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
        {
            // list1为空，直接返回list2
            return list2;
        }

        if (list2 == nullptr)
        {
            // list2为空，直接返回list1
            return list1;
        }
        
        if (list1->val < list2->val)
        {
            // list1头节点较小，递归合并后续
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else
        {
            // list2头节点较小，递归合并后续
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
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
