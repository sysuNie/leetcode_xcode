//
//  138. copyRandomList.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _38__copyRandomList_h
#define _38__copyRandomList_h

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    // 思路：三步法。第一步在每个原节点后复制新节点；第二步根据原节点的random设置复制节点的random；第三步拆分两个链表。
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        // 第一步：复制节点并插入到原节点后面，形成交错链表
        Node* cur = head;
        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }
        
        // 第二步：设置复制节点的random指针，原节点random的next即为对应复制节点
        cur = head;
        while (cur) {
            if (cur->random)
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        
        // 第三步：拆分两个链表，恢复原链表并提取复制链表
        cur = head;
        // 复制链表的头节点
        Node* dummy = head->next;
        Node* dummyCur = dummy;
        while (cur) {
            // 恢复原链表next指针
            cur->next = dummyCur->next;
            cur = cur->next;
            if (cur)
            {
                // 连接复制链表的下一个节点
                dummyCur->next = cur->next;
                dummyCur = dummyCur->next;
            }
        }
        return dummy;
    }

    void Test()
    {
        // 创建测试链表: 1->2->3
        Node* head = new Node(1);
        head->next = new Node(2);
        head->next->next = new Node(3);
        
        // 1->3
        head->random = head->next->next;
        // 2->1
        head->next->random = head;
        
        Node* copied = copyRandomList(head);
        
        // 打印复制的链表
        Node* p = copied;
        while(p != nullptr) {
            cout << "val: " << p->val;
            if(p->random) {
                cout << ", random: " << p->random->val;
            }
            cout << endl;
            p = p->next;
        }
    }
};


#endif /* _38__copyRandomList_h */
