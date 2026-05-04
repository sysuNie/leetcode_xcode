//
//  312. Burst Balloons.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _12__Burst_Balloons_h
#define _12__Burst_Balloons_h

class Solution {
public:
    // 思路：区间动态规划。dp[left][right] 表示戳破 (left, right) 开区间内所有气球能获得的最大硬币数。枚举区间内最后戳破的气球 k，将问题分解为左右两个子区间。
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // 在两端添加虚拟气球，值为 1
        vector<int> balloons(n + 2, 1);
        for (int i = 0; i < n; i++) {
            // 将原数组映射到中间位置
            balloons[i + 1] = nums[i];
        }
        balloons[n + 1] = 1;

        // dp[left][right] 表示开区间 (left, right) 的最大收益
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // 枚举区间长度
        for (int len = 2; len <= n + 2; len++) {
            // 枚举左端点
            for (int left = 0; left + len <= n + 2; left++) {
                int right = left + len;
                // 枚举区间内最后戳破的气球 k
                for (int k = left + 1; k < right; k++) {
                    dp[left][right] = max(dp[left][right],
                        // 左右子区间的收益之和
                        dp[left][k] + dp[k][right] +
                        // 戳破 k 时的收益
                        balloons[left] * balloons[k] * balloons[right]);
                }
            }
        }

        // 返回整个区间的最大收益
        return dp[0][n + 1];
    }

    void Test()
    {
        vector<int> nums = {3, 1, 5, 8};
        cout << maxCoins(nums) << endl;
    }
};

#endif /* _12__Burst_Balloons_h */