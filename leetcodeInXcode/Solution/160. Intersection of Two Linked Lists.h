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
    // 思路：双指针法。两个指针分别遍历A+B和B+A，若有交点则会在交点处相遇，否则同时到达nullptr。
    // 原理：两指针走过的总长度相等（lenA + lenB = lenB + lenA）。
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;

        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB) {
            // A走完切换到B头
            pA = pA ? pA->next : headB;
            // B走完切换到A头
            pB = pB ? pB->next : headA;
        }

        // 相交节点或nullptr
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