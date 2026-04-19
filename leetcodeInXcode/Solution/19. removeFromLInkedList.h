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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptrPioneer = head, *ptrNth = head, *parent = NULL;
        
        for(int i=0;i<n;i++){
            ptrPioneer = ptrPioneer->next;
        }
        while(ptrPioneer!=NULL){
            ptrPioneer = ptrPioneer->next;
            parent = ptrNth;
            ptrNth = ptrNth->next;
        }
        if(parent == NULL){
            head = ptrNth->next;
        }
        else{
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
