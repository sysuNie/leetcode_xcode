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
        // 闭区间 [left, right]
        int left = 0, right = (int) nums.size() - 1;
        // 区间不为空
        while (left <= right) {

            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                // 范围缩小到 [left, mid-1]
                right = mid - 1;
            } else {
                // 范围缩小到 [mid+1, right]
                left = mid + 1;
            }
        }
        return left;
    }

public:
    // 思路：两次二分查找求下界。第一次找target的起始位置，
    // 若存在则第二次找target+1的下界，减1即为target的结束位置。
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target) {
            // nums 中没有 target
            return {-1, -1};
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
