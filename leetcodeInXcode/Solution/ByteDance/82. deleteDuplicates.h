//
//  82. deleteDuplicates.h
//  leetcodeInXcode
//
//  Created by niejikang on 24.5.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _2__deleteDuplicates_h
#define _2__deleteDuplicates_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
    
        ListNode* prev = &dummy;
        ListNode* cur = head;
        
        while (cur) {
            bool duplicated = false;
            
            while (cur->next && cur->val == cur->next->val) {
                duplicated = true;
                cur = cur->next;
            }
            
            if (duplicated) {
                prev->next = cur->next;
            } else {
                prev = prev->next;
            }
            
            cur = cur->next;
        }
        
        return dummy.next;
    }
};

#endif /* _2__deleteDuplicates_h */
