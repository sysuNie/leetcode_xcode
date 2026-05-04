//
//  221. Maximal Square.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _21__Maximal_Square_h
#define _21__Maximal_Square_h

class Solution {
public:
    // 思路：动态规划。dp[i][j]表示以(i-1,j-1)为右下角的最大正方形边长，
    // 状态转移：dp[i][j] = min(上方、左方、左上方) + 1。
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        // 多开一行一列简化边界
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        int maxSide = 0;

        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    // 当前正方形边长受限于三个相邻位置的最小值
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    // 更新最大边长
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }

        // 返回面积
        return maxSide * maxSide;
    }

    void Test()
    {
        vector<vector<char>> matrix = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
        };
        cout << maximalSquare(matrix) << endl;
    }
};

#endif /* _21__Maximal_Square_h */