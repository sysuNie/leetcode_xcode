//
//  148. sortList.h
//  leetcodeInXcode
//
//  Created by niejikang on 24.5.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _48__sortList_h
#define _48__sortList_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* right = slow->next;
        slow->next = nullptr;

        ListNode* left = sortList(head);
        right = sortList(right);

        return merge(left, right);
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }

            cur = cur->next;
        }

        cur->next = l1 != nullptr ? l1 : l2;

        return dummy.next;
    }
};

#endif /* _48__sortList_h */
