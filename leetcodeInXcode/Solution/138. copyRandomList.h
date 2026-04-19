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
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        // 复制一个节点到原来链表中间
        Node* cur = head;
        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }
        
        // 设置random指针
        cur = head;
        while (cur) {
            if (cur->random)
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        
        // 拆分链表和复制
        cur = head;
        Node* dummy = head->next;
        Node* dummyCur = dummy;
        while (cur) {
            cur->next = dummyCur->next;
            cur = cur->next;
            if (cur)
            {
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
        
        head->random = head->next->next;  // 1->3
        head->next->random = head;         // 2->1
        
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
