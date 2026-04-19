//
//  283. Move Zeroes.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _83__Move_Zeroes_h
#define _83__Move_Zeroes_h

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for (int num : nums) {
            if (num != 0) {
                nums[idx++] = num;
            }
        }
        while (idx < nums.size()) {
            nums[idx++] = 0;
        }
    }

    void Test()
    {
        vector<int> nums = {0, 1, 0, 3, 12};
        moveZeroes(nums);
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }
};

#endif /* _83__Move_Zeroes_h */