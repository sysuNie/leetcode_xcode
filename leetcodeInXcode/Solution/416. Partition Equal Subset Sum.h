//
//  416. Partition Equal Subset Sum.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _16__Partition_Equal_Subset_Sum_h
#define _16__Partition_Equal_Subset_Sum_h

class Solution {
public:
    // 思路：0/1 背包问题。先判断总和是否为偶数，然后转化为能否从数组中选出一些数使其和为 sum/2。使用一维 dp 数组倒序遍历避免重复选取。
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        // 计算数组总和
        for (int num : nums) sum += num;

        // 总和为奇数，无法平分
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        // dp[j] 表示能否组成和为 j
        vector<bool> dp(target + 1, false);
        // 和为 0 总是可以达到（不选任何数）
        dp[0] = true;

        for (int num : nums) {
            // 倒序遍历，避免同一数字被重复使用
            for (int j = target; j >= num; j--) {
                // 状态转移：不选 num 或选 num
                dp[j] = dp[j] || dp[j - num];
            }
        }

        // 返回能否组成目标和
        return dp[target];
    }

    void Test()
    {
        vector<int> nums = {1, 5, 11, 5};
        cout << (canPartition(nums) ? "true" : "false") << endl;
    }
};

#endif /* _16__Partition_Equal_Subset_Sum_h */