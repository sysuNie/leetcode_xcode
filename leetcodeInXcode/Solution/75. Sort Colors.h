//
//  75. Sort Colors.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _5__Sort_Colors_h
#define _5__Sort_Colors_h

class Solution {
public:
    // 思路：计数排序。先统计 0、1、2 的出现次数，再按顺序重写原数组。
    void sortColors(vector<int>& nums) {
        // 计数数组，分别统计 0、1、2 的个数
        vector<int> num012(3);
        for(auto num : nums) {
            // 对应颜色计数 +1
            num012[num]++;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(i < num012[0]) {
                // 前 num012[0] 个位置填 0
                nums[i] = 0;
            }
            else if(i < num012[0] + num012[1]) {
                // 接下来 num012[1] 个位置填 1
                nums[i] = 1;
            }
            else {
                // 剩余位置填 2
                nums[i] = 2;
            }
        }
    }

    void Test()
    {
        vector<int> nums = {2,0,2,1,1,0};
        sortColors(nums);
        for(int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }
};

#endif /* _5__Sort_Colors_h */
