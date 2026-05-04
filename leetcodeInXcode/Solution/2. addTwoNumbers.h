//
//  2. addTwoNumbers.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef ___addTwoNumbers_h
#define ___addTwoNumbers_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 思路：模拟逐位相加。遍历两个链表，对应节点值与进位相加，生成新节点
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 哑节点，简化头节点处理
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        // 进位
        int carry = 0;
        
        while (l1 || l2 || carry) {
            if (l1 != NULL) {
                // 累加l1当前位
                carry += l1->val;
            }
            if (l2 != NULL) {
                // 累加l2当前位
                carry += l2->val;
            }
            
            // 当前位的结果
            ListNode *temp = new ListNode(carry % 10);
            cur->next = temp;
            cur = cur->next;
            
            if (l1 != NULL) {
                l1 = l1->next;
            }
            if (l2 != NULL) {
                l2 = l2->next;
            }
            
            // 更新进位
            carry /= 10;
        }
        
        return head->next;
    }
    
    void Test()
    {
        ListNode *l1 = new ListNode(2);
        l1->next = new ListNode(4);
        l1->next->next = new ListNode(3);

        ListNode *l2 = new ListNode(5);
        l2->next = new ListNode(6);
        l2->next->next = new ListNode(4);
        ListNode *ans = addTwoNumbers(l1, l2);
        ListNode *p = ans;
        while(p != nullptr) {
            cout << p->val << " ";
            p = p->next;
        }

        system("pause");
    }
};

#endif /* ___addTwoNumbers_h */
