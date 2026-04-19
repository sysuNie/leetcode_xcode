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
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
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