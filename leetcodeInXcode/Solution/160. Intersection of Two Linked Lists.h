//
//  160. Intersection of Two Linked Lists.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _60__Intersection_of_Two_Linked_Lists_h
#define _60__Intersection_of_Two_Linked_Lists_h

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;

        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB) {
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }

        return pA;
    }

    void Test()
    {
        // 创建两个相交的链表用于测试
        ListNode* common = new ListNode(8);
        common->next = new ListNode(4);
        common->next->next = new ListNode(5);

        ListNode* headA = new ListNode(4);
        headA->next = new ListNode(1);
        headA->next->next = common;

        ListNode* headB = new ListNode(5);
        headB->next = new ListNode(0);
        headB->next->next = new ListNode(1);
        headB->next->next->next = common;

        ListNode* result = getIntersectionNode(headA, headB);
        if (result) {
            cout << result->val << endl;
        }
    }
};

#endif /* _60__Intersection_of_Two_Linked_Lists_h */