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
    int trap(std::vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int res = 0;
        while (left < right) {
            if (height[left] < height[right])
            {
                leftMax = max(leftMax, height[left]);
                res += leftMax - height[left];
                left++;
            }
            else
            {
                rightMax = max(rightMax, height[right]);
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
