//
//  78. Subsets.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _8__Subsets_h
#define _8__Subsets_h

class Solution {
public:
    // 思路：回溯法（DFS）。从 start 开始枚举每个元素“选或不选”，
    // 每次进入递归先将当前 path 加入结果，然后依次选择后续元素深入搜索。
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;

        backtrack(nums, 0, path, result);
        return result;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result) {
        // 当前路径构成一个有效子集
        result.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            // 选择 nums[i]
            path.push_back(nums[i]);
            // 递归处理下一个位置
            backtrack(nums, i + 1, path, result);
            // 回溯，撤销选择
            path.pop_back();
        }
    }

    void Test()
    {
        vector<int> nums = {1, 2, 3};
        vector<vector<int>> result = subsets(nums);
        for (const auto& subset : result) {
            for (int num : subset) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};

#endif /* _8__Subsets_h */