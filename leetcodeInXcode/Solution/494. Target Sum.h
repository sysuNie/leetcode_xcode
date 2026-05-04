//
//  494. Target Sum.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _94__Target_Sum_h
#define _94__Target_Sum_h

class Solution {
public:
    // 思路：动态规划。将问题转化为在数组中分配加减号，使结果等于 target。用 dp[i] 表示当前和为 i 的方案数，范围偏移 sum 以处理负数。
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        // 计算数组绝对值之和，确定 DP 范围
        for (int num : nums) sum += abs(num);

        // target 超出可达范围，方案数为 0
        if (abs(target) > sum) return 0;

        // dp[i] 表示和为 i-sum 的方案数（偏移 sum 处理负数）
        vector<int> dp(2 * sum + 1, 0);
        // 初始和为 0 的方案数为 1
        dp[sum] = 1;

        for (int num : nums) {
            // 用 next 数组保存下一轮状态
            vector<int> next(2 * sum + 1, 0);
            for (int i = 0; i < 2 * sum + 1; i++) {
                if (dp[i] > 0) {
                    // 当前数取正号
                    next[i + num] += dp[i];
                    // 当前数取负号
                    next[i - num] += dp[i];
                }
            }
            // 更新 dp 数组
            dp = next;
        }

        // 返回和为 target 的方案数
        return dp[sum + target];
    }

    void Test()
    {
        vector<int> nums = {1, 1, 1, 1, 1};
        int target = 3;
        cout << findTargetSumWays(nums, target) << endl;
    }
};

#endif /* _94__Target_Sum_h */