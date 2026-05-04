//
//  85. Maximal Rectangle.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _5__Maximal_Rectangle_h
#define _5__Maximal_Rectangle_h

class Solution {
public:
    // 思路：逐行转化为“柱状图中最大的矩形”问题。对每一行，
    // 维护每列向上的连续 '1' 的高度 heights，然后调用单调栈求最大矩形面积。
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        // 每列向上连续 '1' 的高度
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    // 当前为 '1'，高度累加
                    heights[j] += 1;
                } else {
                    // 当前为 '0'，高度清零
                    heights[j] = 0;
                }
            }
            // 计算当前行的最大矩形面积
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

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
        vector<vector<char>> matrix = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
        };
        cout << maximalRectangle(matrix) << endl;
    }
};

#endif /* _5__Maximal_Rectangle_h */