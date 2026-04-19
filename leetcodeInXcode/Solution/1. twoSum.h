//
//  1. twoSum.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef ___twoSum_h
#define ___twoSum_h

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); ++i) {
            auto it = map.find(target - nums[i]);
            if(it != map.end()) {
                return {it->second, i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
    
    void Test()
    {
        int target = 6;
        vector<int> nums = {3, 2, 3};
        vector<int> outs = twoSum(nums, target);
        for(auto out : outs) {
            cout << out << " ";
        }
        cout << endl;
        system("pause");
    }
};

#endif /* ___twoSum_h */
