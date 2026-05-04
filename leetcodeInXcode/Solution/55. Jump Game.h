//
//  55. Jump Game.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _5__Jump_Game_h
#define _5__Jump_Game_h

class Solution {
public:
    // 思路：贪心，从后往前遍历。维护一个能到达终点的最近位置 nearest，
    // 若当前位置 i 能跳到 nearest，则更新 nearest = i，最后判断是否能从起点到达。
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1) {
            return true;
        }
        // 记录能到达终点的最近索引，初始为终点
        int nearest = nums.size() - 1;
        // 从倒数第二个位置反向遍历
        for(int i = nums.size() - 2; i >= 0; --i) {
            // 当前位置能跳到 nearest
            if(i + nums[i] >= nearest) {
                // 更新 nearest 为当前位置
                nearest = i;
            }
        }
        // 若 nearest 被更新到 0，说明起点可达终点
        return nearest == 0;
    }

    void Test()
    {
        vector<int> nums = {2,3,1,1,4};
        cout << (canJump(nums) ? "true" : "false") << endl;
    }
};

#endif /* _5__Jump_Game_h */
