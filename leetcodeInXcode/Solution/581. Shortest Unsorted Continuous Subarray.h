//
//  581. Shortest Unsorted Continuous Subarray.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _81__Shortest_Unsorted_Continuous_Subarray_h
#define _81__Shortest_Unsorted_Continuous_Subarray_h

class Solution {
public:
    // 思路：排序对比法。将数组复制并排序，从两端向中间对比原数组和排序后的数组，找到第一个和最后一个不匹配的位置，二者之间的区间即为最短无序连续子数组。
    int findUnsortedSubarray(vector<int>& nums) {
        // 复制原数组
        vector<int> sorted = nums;
        // 排序得到正确顺序
        sort(sorted.begin(), sorted.end());

        int start = 0;
        int end = nums.size() - 1;

        // 从头部找到第一个不匹配的索引
        while (start < nums.size() && nums[start] == sorted[start]) {
            start++;
        }

        // 从尾部找到第一个不匹配的索引
        while (end > start && nums[end] == sorted[end]) {
            end--;
        }

        // 最短无序子数组的长度
        return end - start + 1;
    }

    void Test()
    {
        vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
        cout << findUnsortedSubarray(nums) << endl;
    }
};

#endif /* _81__Shortest_Unsorted_Continuous_Subarray_h */