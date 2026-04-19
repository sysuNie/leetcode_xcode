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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;

        backtrack(nums, 0, path, result);
        return result;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result) {
        result.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, result);
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