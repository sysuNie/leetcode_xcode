//
//  287. Find the Duplicate Number.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _87__Find_the_Duplicate_Number_h
#define _87__Find_the_Duplicate_Number_h

class Solution {
public:
    // 思路： Floyd 判圈算法（快慢指针）。将数组视为链表，值作为 next 指针，重复元素必然形成环。先用快慢指针找到环内相遇点，再用一个指针从起点和相遇点同步移动，相遇处即为重复数字。
    int findDuplicate(vector<int>& nums) {
        // 慢指针，每次走一步
        int slow = nums[0];
        // 快指针，每次走两步
        int fast = nums[0];

        do {
            // 慢指针走一步
            slow = nums[slow];
            // 快指针走两步
            fast = nums[nums[fast]];
        // 找到环内相遇点
        } while (slow != fast);

        // 一个指针回到起点
        slow = nums[0];
        while (slow != fast) {
            // 两个指针每次都走一步
            slow = nums[slow];
            fast = nums[fast];
        }

        // 再次相遇点即为重复数字
        return slow;
    }

    void Test()
    {
        vector<int> nums = {1, 3, 4, 2, 2};
        cout << findDuplicate(nums) << endl;
    }
};

#endif /* _87__Find_the_Duplicate_Number_h */