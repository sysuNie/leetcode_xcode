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
        ListNode dummy(0);
        ListNode* cur = &dummy;
        
        // 进位
        int addRes = 0;
        
        while (l1 || l2 || addRes) {
            int sum = addRes;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            
            addRes /= 10;
        }
        
        return dummy.next;
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
