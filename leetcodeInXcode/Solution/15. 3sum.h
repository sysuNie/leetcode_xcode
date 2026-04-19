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
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                }
                if (nums[left] + nums[right] < target) {
                    while (nums[++left] == nums[left - 1] && left < right) {
                        ;
                    }
                } else {
                    while (nums[--right] == nums[right + 1] && left < right) {
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
