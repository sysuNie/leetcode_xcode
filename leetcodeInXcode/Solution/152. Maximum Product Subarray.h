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
    // 思路：动态规划。由于负数乘负数可能变最大，需同时维护以当前位置结尾的最大乘积和最小乘积。
    int maxProduct(vector<int>& nums) {
        // 以当前位置结尾的最大乘积
        int maxProd = nums[0];
        // 以当前位置结尾的最小乘积（处理负数）
        int minProd = nums[0];
        // 全局最大乘积
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // 先保存旧的最大值
            int tempMax = maxProd;
            // 当前最大值可能来自：nums[i]本身、maxProd*nums[i]、minProd*nums[i]
            maxProd = max({nums[i], maxProd * nums[i], minProd * nums[i]});
            minProd = min({nums[i], tempMax * nums[i], minProd * nums[i]});
            // 更新全局结果
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