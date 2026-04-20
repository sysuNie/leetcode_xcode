//
//  491. Find Subsequences.h
//  leetcodeInXcode
//
//  Created by niejikang on 20.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _91__Find_Subsequences_h
#define _91__Find_Subsequences_h

class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    
    void dfs(vector<int>& nums, int l, int r)
    {
        if (l == nums.size()) {
            if (temp.size() >= 2) {
                ans.push_back(temp);
            }
            return;
        }
        
        if (nums[l] >= r) {
            temp.push_back(nums[l]);
            dfs(nums, l + 1, nums[l]);
            temp.pop_back();
        }
        
        if (nums[l] != r) {
            dfs(nums, l + 1, r);
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0, INT_MIN);
        return ans;
    }
    
    vector<vector<int>> Test()
    {
        int input[4] = {4,6,7,7};
        vector<int> weights;
        weights.insert(weights.begin(), input, input + 4);
        return findSubsequences(weights);
    }
};

#endif /* _91__Find_Subsequences_h */
