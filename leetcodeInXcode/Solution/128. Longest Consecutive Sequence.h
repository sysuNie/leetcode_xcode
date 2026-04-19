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
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : nums) {
            if (numSet.find(num - 1) == numSet.end()) {
                int current = num;
                int count = 1;

                while (numSet.find(current + 1) != numSet.end()) {
                    current++;
                    count++;
                }

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