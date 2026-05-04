//
//  31. Next Permutation.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _1__Next_Permutation_h
#define _1__Next_Permutation_h

class Solution {
public:
    // 思路：从右往左找第一个降序位置i（即nums[i] < nums[i+1]），
    // 再从右往左找第一个大于nums[i]的数并交换，最后反转i之后的后缀使其升序。
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            // 找到第一个破坏降序的位置i
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                // 从右侧找第一个大于nums[i]的数
                j--;
            }
            // 交换两者，使前缀变大一点
            swap(nums[i], nums[j]);
        }
        // 反转后缀，变成最小升序排列
        reverse(nums.begin() + i + 1, nums.end());
    }
    
    void Test()
    {
        vector<int> nums = {1, 2, 3};
        nextPermutation(nums);
    }
};

#endif /* _1__Next_Permutation_h */
