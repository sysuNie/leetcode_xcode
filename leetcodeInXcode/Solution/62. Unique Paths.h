//
//  62. Unique Paths.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _2__Unique_Paths_h
#define _2__Unique_Paths_h

class Solution {
public:
    // 思路：动态规划。dp[i][j] 表示从起点到达 (i,j) 的路径数，
    // 只能从上方或左方到达，故状态转移为 dp[i][j] = dp[i-1][j] + dp[i][j-1]。
    int uniquePaths(int m, int n) {
        // dp 数组，下标从 1 开始
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 初始化，使 dp[1][1] 计算正确
        dp[1][0] = 1;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                // 上方和左方路径数之和
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }

    void Test()
    {
        cout << uniquePaths(3, 7) << endl;
    }
};


#endif /* _2__Unique_Paths_h */
