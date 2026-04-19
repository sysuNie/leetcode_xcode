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
            return;
        }

        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }

        backtrace(candidates, target, ans, combine, index + 1);

        if (target - candidates[index] >= 0) {
            combine.emplace_back(candidates[index]);
            backtrace(candidates, target - candidates[index], ans, combine, index);
            combine.pop_back();
        }
    }
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
