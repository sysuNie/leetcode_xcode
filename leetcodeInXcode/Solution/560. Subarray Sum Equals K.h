//
//  560. Subarray Sum Equals K.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _60__Subarray_Sum_Equals_K_h
#define _60__Subarray_Sum_Equals_K_h

class Solution {
public:
    // 思路：前缀和 + 哈希表。用哈希表记录每个前缀和出现的次数，当前前缀和为 sum 时，若 sum-k 出现过，说明中间存在和为 k 的子数组。
    int subarraySum(vector<int>& nums, int k) {
        // 记录前缀和出现的次数
        unordered_map<int, int> prefixCount;
        // 前缀和为 0 出现 1 次（空子数组）
        prefixCount[0] = 1;

        // 当前前缀和
        int sum = 0;
        // 满足条件的子数组个数
        int count = 0;

        for (int num : nums) {
            // 累加当前前缀和
            sum += num;
            if (prefixCount.find(sum - k) != prefixCount.end()) {
                // 找到以当前元素结尾、和为 k 的子数组
                count += prefixCount[sum - k];
            }
            // 记录当前前缀和的出现次数
            prefixCount[sum]++;
        }

        return count;
    }

    void Test()
    {
        vector<int> nums = {1, 1, 1};
        int k = 2;
        cout << subarraySum(nums, k) << endl;
    }
};

#endif /* _60__Subarray_Sum_Equals_K_h */