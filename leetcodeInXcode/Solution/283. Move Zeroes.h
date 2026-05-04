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
    // 思路：双指针法。用 idx 指向当前非零元素应放置的位置，遍历数组将所有非零元素前移，最后将 idx 之后的所有位置补零。
    void moveZeroes(vector<int>& nums) {
        // 指向下一个非零元素应存放的位置
        int idx = 0;
        for (int num : nums) {
            if (num != 0) {
                // 将非零元素放到 idx 位置，然后 idx 后移
                nums[idx++] = num;
            }
        }
        while (idx < nums.size()) {
            // 将剩余位置全部填零
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