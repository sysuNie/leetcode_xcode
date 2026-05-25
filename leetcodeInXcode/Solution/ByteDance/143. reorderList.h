//
//  143. reorderList.h
//  leetcodeInXcode
//
//  Created by niejikang on 24.5.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _43__reorderList_h
#define _43__reorderList_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    
private:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* second = slow->next;
        slow->next = nullptr;
        
        second = reverseList(second);
        
        ListNode* first = head;
        
        while (second) {
            ListNode* nextFirst = first->next;
            ListNode* nextSecond = second->next;
            
            first->next = second;
            second->next = nextFirst;
            
            first = nextFirst;
            second = nextSecond;
        }
    }
};

#endif /* _43__reorderList_h */
