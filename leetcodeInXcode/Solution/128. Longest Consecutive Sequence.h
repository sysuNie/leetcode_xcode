//
//  128. Longest Consecutive Sequence.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _28__Longest_Consecutive_Sequence_h
#define _28__Longest_Consecutive_Sequence_h

class Solution {
public:
    // 思路：哈希集合去重后，只从序列的起点（即num-1不存在于集合中）开始向后枚举，避免重复计算。
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        // 将所有数存入哈希集合，支持O(1)查找
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : nums) {
            // 只有当前数是序列起点时才向后枚举
            if (numSet.find(num - 1) == numSet.end()) {
                int current = num;
                int count = 1;

                // 不断查找下一个连续数
                while (numSet.find(current + 1) != numSet.end()) {
                    current++;
                    count++;
                }

                // 更新最长连续序列长度
                longest = max(longest, count);
            }
        }

        return longest;
    }

    void Test()
    {
        vector<int> nums = {100, 4, 200, 1, 3, 2};
        cout << longestConsecutive(nums) << endl;
    }
};

#endif /* _28__Longest_Consecutive_Sequence_h */