//
//  234. Palindrome Linked List.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _34__Palindrome_Linked_List_h
#define _34__Palindrome_Linked_List_h

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // 思路：快慢指针找到中点，反转后半部分链表，然后与前半部分逐节点比较，最后恢复链表。
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // 快慢指针找中点（slow停在前半部分末尾）
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 反转后半部分
        ListNode* secondHalf = reverseList(slow->next);

        // 逐节点比较前后两部分
        ListNode* p1 = head;
        ListNode* p2 = secondHalf;
        bool result = true;
        while (p2) {
            if (p1->val != p2->val) {
                result = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // 恢复链表原状
        slow->next = reverseList(secondHalf);
        return result;
    }

    // 思路：迭代反转链表，三指针法。
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            // 暂存下一个节点
            ListNode* next = curr->next;
            // 反转指向
            curr->next = prev;
            // 前移prev
            prev = curr;
            // 前移curr
            curr = next;
        }
        // 新头节点
        return prev;
    }

    void Test()
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(2);
        head->next->next->next = new ListNode(1);

        cout << (isPalindrome(head) ? "true" : "false") << endl;
    }
};

#endif /* _34__Palindrome_Linked_List_h */