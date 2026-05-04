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
    // 思路：使用最小堆（优先队列）维护k个链表当前的头节点，每次取出最小值的节点接到结果链表，
    // 并将该节点的下一个节点放入堆中，直到堆为空。
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto head = ListNode(0);
        // 小顶堆比较器
        auto comp = [](ListNode *const &a, ListNode *const &b) { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> q(comp);
        for (auto &h : lists) {
            if (h != nullptr) {
                // 将各链表头节点入堆
                q.push(h);
            }
        }
        // 结果链表的尾指针
        auto p = &head;
        while (!q.empty()) {
            // 取出堆顶最小节点接到结果链表
            p->next = q.top();
            p = p->next;
            q.pop();
            if (p->next != nullptr) {
                // 将取出节点的下一个节点入堆
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
