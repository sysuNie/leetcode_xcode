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
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        int left = 1;
        for (int i = 0; i < n; i++) {
            result[i] = left;
            left *= nums[i];
        }

        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= right;
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