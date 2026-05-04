//
//  46. Permutations.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _6__Permutations_h
#define _6__Permutations_h

class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len) {
        // 若果所有数都填完了
        if (first == len)
        {
            res.emplace_back(output);
            return;
        }

        for (int i = first; i < len; i++)
        {
            swap(output[i], output[first]);
            backtrack(res, output, first+1, len);
            swap(output[i], output[first]);
        }
        
        
    }
    // 思路：回溯法，通过交换将每个数字依次放到当前位置，递归处理后续位置，
    // 当first到达末尾时记录一种全排列。
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0, nums.size());
        return res;
    }

    void Test()
    {
        vector<int> nums = {1,2,3};
        vector<vector<int>> result = permute(nums);
        for(const auto& perm : result) {
            for(int num : perm) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};

#endif /* _6__Permutations_h */
