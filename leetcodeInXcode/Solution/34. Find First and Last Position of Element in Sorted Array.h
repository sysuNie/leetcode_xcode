//
//  34. Find First and Last Position of Element in Sorted Array.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _4__Find_First_and_Last_Position_of_Element_in_Sorted_Array_h
#define _4__Find_First_and_Last_Position_of_Element_in_Sorted_Array_h

class Solution {
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, right = (int) nums.size() - 1; // 闭区间 [left, right]
        while (left <= right) { // 区间不为空

            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1; // 范围缩小到 [left, mid-1]
            } else {
                left = mid + 1; // 范围缩小到 [mid+1, right]
            }
        }
        return left;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1}; // nums 中没有 target
        }
        // 如果 start 存在，那么 end 必定存在
        int end = lower_bound(nums, target + 1) - 1;
        return {start, end};
    }

    void Test()
    {
        vector<int> nums = {5,7,7,8,8,10};
        int target = 8;
        vector<int> result = searchRange(nums, target);
        cout << result[0] << " " << result[1] << endl;
    }
};

#endif /* _4__Find_First_and_Last_Position_of_Element_in_Sorted_Array_h */
