//
//  136. Single Number.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _36__Single_Number_h
#define _36__Single_Number_h

class Solution {
public:
    // 思路：利用异或运算的性质，a^a=0，a^0=a，且异或满足交换律，所有成对数字异或后为0，再与落单数字异或即得结果。
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            // 异或所有数字，成对的会抵消
            result ^= num;
        }
        return result;
    }

    void Test()
    {
        vector<int> nums = {2, 2, 1};
        cout << singleNumber(nums) << endl;
    }
};

#endif /* _36__Single_Number_h */