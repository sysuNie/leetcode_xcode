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
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
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