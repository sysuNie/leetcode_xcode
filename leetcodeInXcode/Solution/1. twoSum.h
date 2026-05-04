//
//  1. twoSum.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef ___twoSum_h
#define ___twoSum_h

class Solution {
public:
    // 思路：哈希表。遍历数组，对于每个元素，检查哈希表中是否存在目标值与当前元素的差值
    // 如果存在则返回两者的下标，不存在则将当前元素加入哈希表
    vector<int> twoSum(vector<int>& nums, int target) {
        // 存储数值到索引的映射
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); ++i) {
            // 查找互补数
            auto it = map.find(target - nums[i]);
            if(it != map.end()) {
                // 找到解，返回两个下标
                return {it->second, i};
            }
            // 将当前数加入哈希表
            map[nums[i]] = i;
        }
        return {};
    }
    
    void Test()
    {
        int target = 6;
        vector<int> nums = {3, 2, 3};
        vector<int> outs = twoSum(nums, target);
        for(auto out : outs) {
            cout << out << " ";
        }
        cout << endl;
        system("pause");
    }
};

#endif /* ___twoSum_h */
