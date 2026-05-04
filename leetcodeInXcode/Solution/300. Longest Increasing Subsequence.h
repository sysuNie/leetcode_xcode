//
//  300. Longest Increasing Subsequence.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _00__Longest_Increasing_Subsequence_h
#define _00__Longest_Increasing_Subsequence_h

class Solution {
public:
    // 思路：动态规划。dp[i] 表示以 nums[i] 结尾的最长递增子序列长度。遍历每个元素，检查前面所有比它小的元素，取最大长度加 1。
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] 初始化为 1，每个元素自身构成长度为 1 的子序列
        vector<int> dp(nums.size(), 1);
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            // 枚举 i 之前的所有元素
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    // 状态转移：如果 nums[j] < nums[i]，可以接在后面
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            // 更新全局最大值
            result = max(result, dp[i]);
        }

        return result;
    }

    void Test()
    {
        vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
        cout << lengthOfLIS(nums) << endl;
    }
};

#endif /* _00__Longest_Increasing_Subsequence_h */