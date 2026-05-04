//
//  169. Majority Element.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _69__Majority_Element_h
#define _69__Majority_Element_h

class Solution {
public:
    // 思路：摩尔投票法。假设第一个数为候选，计数抵消不同元素，剩余的一定是众数（出现次数>n/2）。
    int majorityElement(vector<int>& nums) {
        // 当前候选的票数
        int count = 0;
        // 当前候选元素
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                // 票数为0，更换候选
                candidate = num;
            }
            // 相同加票，不同减票
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }

    void Test()
    {
        vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
        cout << majorityElement(nums) << endl;
    }
};

#endif /* _69__Majority_Element_h */