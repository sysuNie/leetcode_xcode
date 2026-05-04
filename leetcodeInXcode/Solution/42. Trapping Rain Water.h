//
//  42. Trapping Rain Water.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _2__Trapping_Rain_Water_h
#define _2__Trapping_Rain_Water_h

class Solution {
public:
    // 思路：双指针向中间靠拢，分别维护左右两侧的最大高度。
    // 每次处理高度较小的一边，因为水量由较矮的边界决定，当前柱子的蓄水量等于边界最大高度减去自身高度。
    int trap(std::vector<int>& height)
    {
        // 左右指针
        int left = 0, right = height.size() - 1;
        // 左右两侧遇到的最大高度
        int leftMax = 0, rightMax = 0;
        int res = 0;
        while (left < right) {
            if (height[left] < height[right])
            {
                // 更新左侧最大高度
                leftMax = max(leftMax, height[left]);
                // 当前柱子可蓄水量
                res += leftMax - height[left];
                left++;
            }
            else
            {
                // 更新右侧最大高度
                rightMax = max(rightMax, height[right]);
                // 当前柱子可蓄水量
                res += rightMax - height[right];
                right--;
            }
        }
        return res;
    }

    void Test()
    {
        vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
        cout << trap(height) << endl;
    }
};

#endif /* _2__Trapping_Rain_Water_h */
