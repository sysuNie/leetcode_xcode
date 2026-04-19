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
    int maxArea(vector<int> &height) {
        int result = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int area = (right - left) * std::min(height[left], height[right]);
            result = std::max(area, result);
            if (height[left] < height[right]) {
                left++;
            } else {
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
