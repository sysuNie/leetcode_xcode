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
    
    // 思路：DFS回溯 + 去重。l为当前索引，r记录上一次选择的值以保证递增。
    //       当nums[l] != r时跳过同层同值元素，避免产生重复子序列。
    void dfs(vector<int>& nums, int l, int r)
    {
        // 遍历到数组末尾
        if (l == nums.size()) {
            if (temp.size() >= 2) {
                // 长度>=2才加入结果
                ans.push_back(temp);
            }
            return;
        }
        
        // 满足递增条件，选择当前元素
        if (nums[l] >= r) {
            temp.push_back(nums[l]);
            // 递归下一层，更新r为当前值
            dfs(nums, l + 1, nums[l]);
            // 回溯，撤销选择
            temp.pop_back();
        }
        
        // 同层去重：若当前值等于r，则跳过不选（已在上面处理过）
        if (nums[l] != r) {
            // 不选当前元素，递归下一层
            dfs(nums, l + 1, r);
        }
    }
    
    // 思路：对数组进行深度优先搜索，枚举所有长度>=2的递增子序列，用r去重避免重复结果。
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // 初始r为INT_MIN，确保第一个元素可以被选择
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
