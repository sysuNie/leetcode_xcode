//
//  53. Maximum Subarray.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _3__Maximum_Subarray_h
#define _3__Maximum_Subarray_h

class Solution {
public:
    // 思路：前缀和 + 最小前缀和。遍历数组维护当前前缀和 sum，同时记录遇到的最小前缀和 minsum，
    // 以当前位置结尾的最大子数组和即为 sum - minsum，不断更新全局最大值。
    int maxSubArray(vector<int>& nums) {
        // 全局最大子数组和
        int maxsub = INT_MIN;
        // 记录遍历过程中遇到的最小前缀和
        int minsum = 0;
        // 当前前缀和
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            // 累加当前元素到前缀和
            sum += nums[i];
            // 用当前前缀和减去最小前缀和得到候选最大子数组和
            maxsub = max(maxsub, sum - minsum);
            // 更新最小前缀和
            minsum = min(minsum, sum);
        }
        return maxsub;
    }

    void Test()
    {
        vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
        cout << maxSubArray(nums) << endl;
    }
};

#endif /* _3__Maximum_Subarray_h */
