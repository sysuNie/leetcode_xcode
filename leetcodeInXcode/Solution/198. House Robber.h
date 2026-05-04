//
//  198. House Robber.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _98__House_Robber_h
#define _98__House_Robber_h

class Solution {
public:
    // 思路：动态规划。dp[i]表示偷到第i间房时的最大金额，状态转移：不偷i（dp[i-1]）或偷i（dp[i-2]+nums[i]）。
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        vector<int> dp(nums.size(), 0);
        // 只有一间房
        dp[0] = nums[0];
        // 两间房选金额大的
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            // 状态转移方程
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp.back();
    }

    void Test()
    {
        vector<int> nums = {1, 2, 3, 1};
        cout << rob(nums) << endl;
    }
};

#endif /* _98__House_Robber_h */