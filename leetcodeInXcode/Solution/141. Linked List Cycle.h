//
//  141. Linked List Cycle.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _41__Linked_List_Cycle_h
#define _41__Linked_List_Cycle_h

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // 思路：快慢指针。快指针每次走两步，慢指针每次走一步，若存在环则两者必相遇。
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return false;

        // 慢指针，每次一步
        ListNode* slow = head;
        // 快指针，每次两步
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            // 慢指针前进一步
            slow = slow->next;
            // 快指针前进两步
            fast = fast->next->next;

            // 相遇说明有环
            if (slow == fast) return true;
        }

        // 快指针到达末尾，无环
        return false;
    }

    void Test()
    {
        ListNode* head = new ListNode(3);
        head->next = new ListNode(2);
        head->next->next = new ListNode(0);
        head->next->next->next = new ListNode(-4);
        head->next->next->next->next = head->next;

        cout << (hasCycle(head) ? "true" : "false") << endl;
    }
};

#endif /* _41__Linked_List_Cycle_h */