//
//  19. removeFromLInkedList.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _9__removeFromLInkedList_h
#define _9__removeFromLInkedList_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 思路：快慢指针。先驱指针先走n步，然后两指针同步后移，
    // 当先驱指针到达末尾时，慢指针正好指向倒数第n个节点，将其删除。
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 先驱指针
        ListNode *ptrPioneer = head;
        // 慢指针，最终将指向待删节点
        ListNode *ptrNth = head;
        // 慢指针的前一个节点，用于删除操作
        ListNode *parent = NULL;
        
        for(int i=0;i<n;i++){
            // 先驱指针先走n步
            ptrPioneer = ptrPioneer->next;
        }
        // 同步移动，直到先驱指针到达链表末尾
        while(ptrPioneer!=NULL){
            ptrPioneer = ptrPioneer->next;
            parent = ptrNth;
            ptrNth = ptrNth->next;
        }
        // 说明要删除的是头节点
        if(parent == NULL){
            head = ptrNth->next;
        }
        else{
            // 跳过待删节点
            parent->next = ptrNth->next;
        }
        
        return head;
    }
    
    void Test()
    {
        // 创建测试链表: 1->2->3->4->5
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
        
        // 删除倒数第2个节点
        head = removeNthFromEnd(head, 2);
        
        // 打印结果应该是: 1 2 3 5
        ListNode* p = head;
        while(p != nullptr) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};

#endif /* _9__removeFromLInkedList_h */
