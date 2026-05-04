//
//  206. Reverse Linked List.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _06__Reverse_Linked_List_h
#define _06__Reverse_Linked_List_h

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // 思路：迭代法，三指针（prev, curr, next）依次反转每个节点的next指向。
    ListNode* reverseList(ListNode* head) {
        // 已反转部分的头节点
        ListNode* prev = nullptr;
        // 当前待反转节点
        ListNode* curr = head;

        while (curr) {
            // 暂存下一个节点
            ListNode* next = curr->next;
            // 反转当前节点的指向
            curr->next = prev;
            // prev前移
            prev = curr;
            // curr前移
            curr = next;
        }

        // 新的头节点
        return prev;
    }

    void Test()
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);

        ListNode* result = reverseList(head);
        ListNode* p = result;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};

#endif /* _06__Reverse_Linked_List_h */