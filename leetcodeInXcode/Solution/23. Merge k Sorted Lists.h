//
//  23. Merge k Sorted Lists.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _3__Merge_k_Sorted_Lists_h
#define _3__Merge_k_Sorted_Lists_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto head = ListNode(0);
        auto comp = [](ListNode *const &a, ListNode *const &b) { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> q(comp);
        for (auto &h : lists) {
            if (h != nullptr) {
                q.push(h);
            }
        }
        auto p = &head;
        while (!q.empty()) {
            p->next = q.top();
            p = p->next;
            q.pop();
            if (p->next != nullptr) {
                q.push(p->next);
            }
        }
        return head.next;
    }

    void Test() {
        const int listNum = 5;
        ListNode entitys[listNum] = {10, 2, 3, 1, -10};
        vector<ListNode *> lists;
        for (int i = 0; i < listNum; i++) {
            lists.push_back(&entitys[i]);
        }
        mergeKLists(lists);
    }
};

#endif /* _3__Merge_k_Sorted_Lists_h */
