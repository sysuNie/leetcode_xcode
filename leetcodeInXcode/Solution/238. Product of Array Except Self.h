//
//  238. Product of Array Except Self.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _38__Product_of_Array_Except_Self_h
#define _38__Product_of_Array_Except_Self_h

class Solution {
public:
    // 思路：两次遍历，不用除法。第一次从左到右记录每个位置左侧所有数的乘积；
    // 第二次从右到左乘以每个位置右侧所有数的乘积。
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        int left = 1;
        for (int i = 0; i < n; i++) {
            // 先存入左侧累积乘积
            result[i] = left;
            // 更新左侧乘积
            left *= nums[i];
        }

        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            // 再乘以右侧累积乘积
            result[i] *= right;
            // 更新右侧乘积
            right *= nums[i];
        }

        return result;
    }

    void Test()
    {
        vector<int> nums = {1, 2, 3, 4};
        vector<int> result = productExceptSelf(nums);
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
};

#endif /* _38__Product_of_Array_Except_Self_h */