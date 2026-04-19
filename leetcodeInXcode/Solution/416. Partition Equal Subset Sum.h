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
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;

        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }

    void Test()
    {
        vector<int> nums = {1, 5, 11, 5};
        cout << (canPartition(nums) ? "true" : "false") << endl;
    }
};

#endif /* _16__Partition_Equal_Subset_Sum_h */