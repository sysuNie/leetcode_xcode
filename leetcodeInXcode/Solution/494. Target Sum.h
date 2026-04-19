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
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) sum += abs(num);

        if (abs(target) > sum) return 0;

        vector<int> dp(2 * sum + 1, 0);
        dp[sum] = 1;

        for (int num : nums) {
            vector<int> next(2 * sum + 1, 0);
            for (int i = 0; i < 2 * sum + 1; i++) {
                if (dp[i] > 0) {
                    next[i + num] += dp[i];
                    next[i - num] += dp[i];
                }
            }
            dp = next;
        }

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