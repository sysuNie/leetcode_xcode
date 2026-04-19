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
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> balloons(n + 2, 1);
        for (int i = 0; i < n; i++) {
            balloons[i + 1] = nums[i];
        }
        balloons[n + 1] = 1;

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 2; len <= n + 2; len++) {
            for (int left = 0; left + len <= n + 2; left++) {
                int right = left + len;
                for (int k = left + 1; k < right; k++) {
                    dp[left][right] = max(dp[left][right],
                        dp[left][k] + dp[k][right] +
                        balloons[left] * balloons[k] * balloons[right]);
                }
            }
        }

        return dp[0][n + 1];
    }

    void Test()
    {
        vector<int> nums = {3, 1, 5, 8};
        cout << maxCoins(nums) << endl;
    }
};

#endif /* _12__Burst_Balloons_h */