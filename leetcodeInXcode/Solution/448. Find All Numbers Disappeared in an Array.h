//
//  448. Find All Numbers Disappeared in an Array.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _48__Find_All_Numbers_Disappeared_in_an_Array_h
#define _48__Find_All_Numbers_Disappeared_in_an_Array_h

class Solution {
public:
    // 思路：原地标记法。遍历数组，将每个数字对应的下标位置的数置为负数，最后仍为正数的位置下标+1即为缺失的数字。
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int num : nums) {
            // 数字 num 应该出现在下标 idx 处
            int idx = abs(num) - 1;
            if (nums[idx] > 0) {
                // 将对应位置标记为负数，表示数字 idx+1 已出现过
                nums[idx] = -nums[idx];
            }
        }

        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                // 下标 i 处的值仍为正，说明数字 i+1 未出现过
                result.push_back(i + 1);
            }
        }

        return result;
    }

    void Test()
    {
        vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
        vector<int> result = findDisappearedNumbers(nums);
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
};

#endif /* _48__Find_All_Numbers_Disappeared_in_an_Array_h */