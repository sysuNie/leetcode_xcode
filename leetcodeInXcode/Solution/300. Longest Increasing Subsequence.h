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
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
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