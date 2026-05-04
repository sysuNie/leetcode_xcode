//
//  11. containerWithMostWater.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _1__containerWithMostWater_h
#define _1__containerWithMostWater_h

class Solution {
  public:
    // 思路：双指针法。左右指针向中间移动，每次移动高度较小的那端，
    // 因为宽度在减小，只有可能获得更大的高度才能增大面积。
    int maxArea(vector<int> &height) {
        int result = 0;
        // 左右指针分别指向两端
        int left = 0, right = height.size() - 1;
        while (left < right) {
            // 计算当前面积
            int area = (right - left) * std::min(height[left], height[right]);
            // 更新最大面积
            result = std::max(area, result);
            if (height[left] < height[right]) {
                // 左端高度较小，左指针右移尝试找到更高的边
                left++;
            } else {
                // 右端高度较小，右指针左移尝试找到更高的边
                right--;
            }
        }
        return result;
    }

    void Test() {
        vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        cout << maxArea(height) << endl;
        system("pause");
    }
};

#endif /* _1__containerWithMostWater_h */
