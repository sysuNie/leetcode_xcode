//
//  142. Linked List Cycle II.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _42__Linked_List_Cycle_II_h
#define _42__Linked_List_Cycle_II_h

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // 思路：快慢指针。第一阶段判断是否有环并找到相遇点；第二阶段将慢指针重置到头部，两指针同速前进，再次相遇点即为环入口。
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // 第一阶段：快慢指针找相遇点
        while (fast != nullptr && fast->next != nullptr) {
            // 慢指针一步
            slow = slow->next;
            // 快指针两步
            fast = fast->next->next;

            // 相遇则退出
            if (slow == fast) break;
        }

        // 未相遇说明无环
        if (fast == nullptr || fast->next == nullptr) return nullptr;

        // 第二阶段：慢指针回到头，快慢同速前进，再次相遇点即为环入口
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // 返回环的入口节点
        return slow;
    }

    void Test()
    {
        ListNode* head = new ListNode(3);
        head->next = new ListNode(2);
        head->next->next = new ListNode(0);
        head->next->next->next = new ListNode(-4);
        head->next->next->next->next = head->next;

        ListNode* result = detectCycle(head);
        if (result) {
            cout << result->val << endl;
        }
    }
};

#endif /* _42__Linked_List_Cycle_II_h */