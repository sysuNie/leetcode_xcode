//
//  84. Largest Rectangle in Histogram.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _4__Largest_Rectangle_in_Histogram_h
#define _4__Largest_Rectangle_in_Histogram_h

class Solution {
public:
    // 思路：单调栈。遍历每个柱子，栈中保存递增的柱子下标。
    // 遇到更矮柱子时弹出栈顶，计算以弹出柱子为高的矩形面积，
    // 右边界为当前 i，左边界为栈顶下标，宽度 = i - left - 1。末尾补 0 确保全部计算。
    int largestRectangleArea(vector<int>& heights) {
        // 单调递增栈，存放下标
        stack<int> st;
        int maxArea = 0;
        vector<int> h = heights;
        // 末尾补 0，保证栈内所有柱子都被处理
        h.push_back(0);

        for (int i = 0; i < h.size(); i++) {
            // 当前柱子低于栈顶，无法向右扩展
            while (!st.empty() && h[st.top()] > h[i]) {
                // 弹出柱子的高度
                int height = h[st.top()];
                st.pop();
                // 计算宽度
                int width = st.empty() ? i : i - st.top() - 1;
                // 更新最大面积
                maxArea = max(maxArea, height * width);
            }
            // 当前柱子下标入栈
            st.push(i);
        }

        return maxArea;
    }

    void Test()
    {
        vector<int> heights = {2, 1, 5, 6, 2, 3};
        cout << largestRectangleArea(heights) << endl;
    }
};

#endif /* _4__Largest_Rectangle_in_Histogram_h */