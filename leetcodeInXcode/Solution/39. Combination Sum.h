//
//  39. Combination Sum.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _9__Combination_Sum_h
#define _9__Combination_Sum_h

class Solution {
public:
    void backtrace(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int index) {
        if (index == candidates.size()) {
            // 所有数字都决策完毕，返回
            return;
        }

        if (target == 0) {
            // 目标刚好为0，记录当前组合
            ans.emplace_back(combine);
            return;
        }

        // 不选当前数字，去下一个
        backtrace(candidates, target, ans, combine, index + 1);

        if (target - candidates[index] >= 0) {
            // 选择当前数字
            combine.emplace_back(candidates[index]);
            // 可以重复选，index不变
            backtrace(candidates, target - candidates[index], ans, combine, index);
            // 回溯，撤销选择
            combine.pop_back();
        }
    }
    // 思路：回溯法，对每个数字有“选”或“不选”两种决策，选的话可以重复选取。
    // 当target减到0时记录当前组合。
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        backtrace(candidates, target, ans, combine, 0);
        return ans;
    }

    void Test()
    {
        vector<int> candidates = {2,3,6,7};
        int target = 7;
        vector<vector<int>> result = combinationSum(candidates, target);
        for(const auto& combination : result) {
            for(int num : combination) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};

#endif /* _9__Combination_Sum_h */
