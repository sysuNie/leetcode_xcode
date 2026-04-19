//
//  152. Maximum Product Subarray.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _52__Maximum_Product_Subarray_h
#define _52__Maximum_Product_Subarray_h

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int tempMax = maxProd;
            maxProd = max({nums[i], maxProd * nums[i], minProd * nums[i]});
            minProd = min({nums[i], tempMax * nums[i], minProd * nums[i]});
            result = max(result, maxProd);
        }

        return result;
    }

    void Test()
    {
        vector<int> nums = {2, 3, -2, 4};
        cout << maxProduct(nums) << endl;
    }
};

#endif /* _52__Maximum_Product_Subarray_h */