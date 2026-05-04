//
//  120. Mini Path Triangle.h
//  leetcodeInXcode
//
//  Created by niejikang on 20.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _20__Mini_Path_Triangle_h
#define _20__Mini_Path_Triangle_h

class Solution {
public:
    // 思路：动态规划（自底向上）。从倒数第二行开始，每个位置选择下一行相邻两个位置的最小值累加，
    //       最终dp[0]即为从顶点到底边的最小路径和。复用一维数组优化空间。
    int minimumTotal(vector<vector<int>>& triangle) {
        // 初始化dp为最后一行的值
        vector<int> dp(triangle.back());
        // 自底向上遍历每一行
        for (int i = triangle.size() - 2; i >= 0; i--) {
            // 遍历当前行的每个元素
            for (int j = 0; j <= i; j++) {
                // 选择下方相邻较小值累加
                dp[j] = std::min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        // 顶点处的最小路径和
        return dp[0];
    }
};


#endif /* _20__Mini_Path_Triangle_h */
