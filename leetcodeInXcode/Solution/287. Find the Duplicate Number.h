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
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }

    void Test()
    {
        vector<int> nums = {1, 3, 4, 2, 2};
        cout << findDuplicate(nums) << endl;
    }
};

#endif /* _87__Find_the_Duplicate_Number_h */