//
//  347. Top K Frequent Elements.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _47__Top_K_Frequent_Elements_h
#define _47__Top_K_Frequent_Elements_h

class Solution {
public:
    // 思路：桶排序。先统计每个数字的出现频率，然后按频率分桶（下标为频率），从高频到低频收集前 k 个元素。
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计每个数字的出现频率
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // 桶的下标表示频率，最大频率不超过 nums.size()
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& pair : freq) {
            // 将数字放入对应频率的桶中
            buckets[pair.second].push_back(pair.first);
        }

        vector<int> result;
        // 从高频往低频遍历
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                // 已收集 k 个，提前结束
                if (result.size() == k) break;
            }
        }

        return result;
    }

    void Test()
    {
        vector<int> nums = {1, 1, 1, 2, 2, 3};
        int k = 2;
        vector<int> result = topKFrequent(nums, k);
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
};

#endif /* _47__Top_K_Frequent_Elements_h */