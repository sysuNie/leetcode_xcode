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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& pair : freq) {
            buckets[pair.second].push_back(pair.first);
        }

        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
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