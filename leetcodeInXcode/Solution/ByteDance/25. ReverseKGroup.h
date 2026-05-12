//
//  25. ReverseKGroup.h
//  leetcodeInXcode
//
//  Created by niejikang on 12.5.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _5__ReverseKGroup_h
#define _5__ReverseKGroup_h

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// 翻转 [head, tail] 这段链表，返回新头
// tail->next 不动，翻转后 head->next 指向原 tail->next
std::pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {
  ListNode* prev = tail->next; // prev 初始指向 tail->next，作为终止条件
  ListNode* cur = head;
  while (prev != tail) {      // 翻转直到 cur == tail
    ListNode* next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return {tail, head};        // 翻转后 tail 是新头，head 是新尾
}

ListNode* reverseKGroup(ListNode* head, int k) {
  // 哨兵节点，简化头节点处理
  ListNode dummy(0);
  dummy.next = head;
  ListNode* pre = &dummy;   // pre 始终指向待翻转段的前一个节点

  while (head != nullptr) {
    // 找到第 k 个节点作为 tail
    ListNode* tail = pre;
    for (int i = 0; i < k; i++) {
      tail = tail->next;
      if (tail == nullptr) return dummy.next; // 不足 k 个，直接返回
    }

    ListNode* next = tail->next; // 记录下一段的起点

    // 翻转 [head, tail]
    auto [new_head, new_tail] = reverse(head, tail);

    // 接回主链表
    pre->next = new_head;
    new_tail->next = next;

    // 移动指针到下一段
    pre = new_tail;
    head = next;
  }

  return dummy.next;
}

// 测试
int main() {
  // 构造链表 1->2->3->4->5
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  head = reverseKGroup(head, 2); // 期望: 2->1->4->3->5

  for (auto p = head; p; p = p->next)
    std::cout << p->val << " ";
  return 0;
}

#endif /* _5__ReverseKGroup_h */
