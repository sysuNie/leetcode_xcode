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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int num : nums) {
            int idx = abs(num) - 1;
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }

        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
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