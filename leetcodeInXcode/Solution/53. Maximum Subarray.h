//
//  53. Maximum Subarray.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _3__Maximum_Subarray_h
#define _3__Maximum_Subarray_h

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsub = INT_MIN;
        int minsum = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            maxsub = max(maxsub, sum - minsum);
            minsum = min(minsum, sum);
        }
        return maxsub;
    }

    void Test()
    {
        vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
        cout << maxSubArray(nums) << endl;
    }
};

#endif /* _3__Maximum_Subarray_h */
