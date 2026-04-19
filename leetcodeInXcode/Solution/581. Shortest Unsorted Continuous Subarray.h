//
//  581. Shortest Unsorted Continuous Subarray.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _81__Shortest_Unsorted_Continuous_Subarray_h
#define _81__Shortest_Unsorted_Continuous_Subarray_h

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int start = 0;
        int end = nums.size() - 1;

        while (start < nums.size() && nums[start] == sorted[start]) {
            start++;
        }

        while (end > start && nums[end] == sorted[end]) {
            end--;
        }

        return end - start + 1;
    }

    void Test()
    {
        vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
        cout << findUnsortedSubarray(nums) << endl;
    }
};

#endif /* _81__Shortest_Unsorted_Continuous_Subarray_h */