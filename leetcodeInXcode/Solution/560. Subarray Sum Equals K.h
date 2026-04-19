//
//  560. Subarray Sum Equals K.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _60__Subarray_Sum_Equals_K_h
#define _60__Subarray_Sum_Equals_K_h

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;

        int sum = 0;
        int count = 0;

        for (int num : nums) {
            sum += num;
            if (prefixCount.find(sum - k) != prefixCount.end()) {
                count += prefixCount[sum - k];
            }
            prefixCount[sum]++;
        }

        return count;
    }

    void Test()
    {
        vector<int> nums = {1, 1, 1};
        int k = 2;
        cout << subarraySum(nums, k) << endl;
    }
};

#endif /* _60__Subarray_Sum_Equals_K_h */