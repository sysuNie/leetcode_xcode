//
//  148. Sort List.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _48__Sort_List_h
#define _48__Sort_List_h

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // 思路：归并排序，使用快慢指针找到链表中点，递归拆分后合并两个有序链表。
    ListNode* sortList(ListNode* head) {
        // 递归终止条件
        if (!head || !head->next) return head;

        ListNode* slow = head;
        // fast先走一步，确保slow停在中间偏左
        ListNode* fast = head->next;

        // 快慢指针找中点
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        // 断开链表，分成两半
        slow->next = nullptr;

        // 递归排序左半部分
        ListNode* left = sortList(head);
        // 递归排序右半部分
        ListNode* right = sortList(mid);

        // 合并两个有序链表
        return merge(left, right);
    }

    // 思路：双指针遍历两个有序链表，依次取较小节点接到结果链表。
    ListNode* merge(ListNode* l1, ListNode* l2) {
        // 虚拟头节点，简化边界处理
        ListNode dummy(0);
        ListNode* cur = &dummy;

        // 两链表均非空时比较
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        // 拼接剩余部分
        cur->next = l1 ? l1 : l2;
        return dummy.next;
    }

    void Test()
    {
        ListNode* head = new ListNode(4);
        head->next = new ListNode(2);
        head->next->next = new ListNode(1);
        head->next->next->next = new ListNode(3);

        ListNode* result = sortList(head);
        ListNode* p = result;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};

#endif /* _48__Sort_List_h */