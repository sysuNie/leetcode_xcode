//
//  15. 3sum.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _5__3sum_h
#define _5__3sum_h

class Solution {
  public:
    // 思路：先排序，固定第一个数，用双指针在剩余区间寻找两数之和等于其相反数。
    // 注意跳过重复元素，避免结果中出现重复三元组。
    vector<vector<int>> threeSum(vector<int> &nums) {
        // 排序以便去重和使用双指针
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                // 跳过重复的第一个数
                continue;
            // 转化为两数之和问题
            int target = -nums[i];
            // 双指针
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    // 记录满足条件的三元组
                    ans.push_back({nums[i], nums[left], nums[right]});
                }
                if (nums[left] + nums[right] < target) {
                    while (nums[++left] == nums[left - 1] && left < right) {
                        // 左指针右移并跳过重复值
                        ;
                    }
                } else {
                    while (nums[--right] == nums[right + 1] && left < right) {
                        // 右指针左移并跳过重复值
                        ;
                    }
                }
            }
        }
        return ans;
    }

    void Test() {
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        vector<vector<int>> ans = threeSum(nums);
        for (const auto &row : ans) {
            for (const auto &num : row) {
                cout << num << " ";
            }
            cout << endl;
        }
        cout << endl;
        system("pause");
    }
};

#endif /* _5__3sum_h */
